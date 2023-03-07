#!/usr/bin/python3
# -*- coding: iso-8859-1 -*
""" Python starter bot for the Crypto Trader games, from ex-Riddles.io """
__version__ = "1.0"

import sys

class Bot:
    def __init__(self):
        self.botState = BotState()

    def run(self):
        while True:
            reading = input()
            if len(reading) == 0:
                continue
            self.parse(reading)

    def parse(self, info: str):
        tmp = info.split(" ")
        if tmp[0] == "settings":
            self.botState.update_settings(tmp[1], tmp[2])
        if tmp[0] == "update":
            if tmp[1] == "game":
                self.botState.update_game(tmp[2], tmp[3])
        if tmp[0] == "action":
            # This won't work every time, but it works sometimes!
            dollars = self.botState.stacks["USDT"]
            current_closing_price = self.botState.charts["USDT_BTC"].closes[-1]
            old_closing_price = self.botState.charts["USDT_BTC"].closes[-2]
            affordable = dollars / current_closing_price
            moyenne = sum(self.botState.charts["USDT_BTC"].closes)/float(len(self.botState.charts["USDT_BTC"].closes))
            #print(f'My stacks are {dollars}. The current closing price is {current_closing_price}. So I can afford {affordable}', file=sys.stderr)
            print(f'Len : {len(self.botState.charts["USDT_BTC"].rdata)} R : {self.botState.charts["USDT_BTC"].rdata[-1]}', file=sys.stderr, flush=True)

            print(f'Money : {dollars}', flush=True, file=sys.stderr)

            if dollars < 100:
                print("no_moves", flush=True)
            else:
                if self.botState.charts["USDT_BTC"].rdata[-1] <= 0 and self.botState.charts["USDT_BTC"].rdata[-2] > 0:
                    if self.botState.stacks["BTC"] != 0:
                        for i in self.botState.charts["USDT_BTC"].adata:
                            print(f'CLOSING pRICE : {current_closing_price * i[0] - (self.botState.transactionFee * current_closing_price * i[0])} prix : {current_closing_price}', flush=True, file=sys.stderr)
                            if i[1] < current_closing_price * i[0] - (self.botState.transactionFee * current_closing_price * i[0]):
                                print(f'sell USDT_BTC {i[0]}', flush=True)
                                print(f'Selling n : {i[0]} for : {current_closing_price * i[0] - (self.botState.transactionFee * current_closing_price * i[0])}', flush=True, file=sys.stderr)
                                self.botState.charts["USDT_BTC"].adata.remove(i)
                                return
                        print("no_moves", flush=True)
                    else:
                        print("no_moves", flush=True)
                elif self.botState.charts["USDT_BTC"].rdata[-1] > 0 and self.botState.charts["USDT_BTC"].rdata[-2] <= 0:
                    coef = self.botState.charts["USDT_BTC"].rdata[-1] * 0.1
                    if coef > 1:
                        coef = 1
                    print(f'Coef : {coef}', flush=True, file=sys.stderr)
                    print(f'buy USDT_BTC {coef * affordable}', flush=True)
                    self.botState.charts["USDT_BTC"].adata.append(((coef * affordable) - (coef * affordable) * self.botState.transactionFee, coef * affordable * current_closing_price))
                    print(f'BUYYYY N : {self.botState.charts["USDT_BTC"].adata[-1][0]}, p : {self.botState.charts["USDT_BTC"].adata[-1][1]}, price : {current_closing_price}', flush=True, file=sys.stderr)
                else:
                    print("no_moves", flush=True)

# Calcul R with period of 7
# When R frole changement de signe switch !
# R va devenir positif acheter !
# R va devenir négatif vendre !


class Candle:
    def __init__(self, format, intel):
        tmp = intel.split(",")
        for (i, key) in enumerate(format):
            value = tmp[i]
            if key == "pair":
                self.pair = value
            if key == "date":
                self.date = int(value)
            if key == "high":
                self.high = float(value)
            if key == "low":
                self.low = float(value)
            if key == "open":
                self.open = float(value)
            if key == "close":
                self.close = float(value)
            if key == "volume":
                self.volume = float(value)

    def __repr__(self):
        return str(self.pair) + str(self.date) + str(self.close) + str(self.volume)


class Chart:
    def __init__(self):
        self.dates = []
        self.opens = []
        self.highs = []
        self.lows = []
        self.closes = []
        self.volumes = []
        self.rdata = []
        self.adata = []
        self.indicators = {}

    def add_candle(self, candle: Candle):
        period = 15
        self.dates.append(candle.date)
        self.opens.append(candle.open)
        self.highs.append(candle.high)
        self.lows.append(candle.low)
        self.closes.append(candle.close)
        self.volumes.append(candle.volume)


        if len(self.closes) < period:
            self.rdata.append(float("nan"))
            return
        if self.closes[-period] == 0:
            if (self.closes[-1] - self.closes[-period]) < 0:
                self.rdata.append(float(-1000))
                return
            else:
                self.rdata.append(float(1000))
                return
        self.rdata.append(float((self.closes[-1] - self.closes[-period]) / abs(self.closes[-period]) * 100))


class BotState:
    def __init__(self):
        self.timeBank = 0
        self.maxTimeBank = 0
        self.timePerMove = 1
        self.candleInterval = 1
        self.candleFormat = []
        self.candlesTotal = 0
        self.candlesGiven = 0
        self.initialStack = 0
        self.transactionFee = 0.1
        self.date = 0
        self.stacks = dict()
        self.charts = dict()

    def update_chart(self, pair: str, new_candle_str: str):
        if not (pair in self.charts):
            self.charts[pair] = Chart()
        new_candle_obj = Candle(self.candleFormat, new_candle_str)
        self.charts[pair].add_candle(new_candle_obj)

    def update_stack(self, key: str, value: float):
        self.stacks[key] = value

    def update_settings(self, key: str, value: str):
        if key == "timebank":
            self.maxTimeBank = int(value)
            self.timeBank = int(value)
        if key == "time_per_move":
            self.timePerMove = int(value)
        if key == "candle_interval":
            self.candleInterval = int(value)
        if key == "candle_format":
            self.candleFormat = value.split(",")
        if key == "candles_total":
            self.candlesTotal = int(value)
        if key == "candles_given":
            self.candlesGiven = int(value)
        if key == "initial_stack":
            self.initialStack = int(value)
        if key == "transaction_fee_percent":
            self.transactionFee = float(value) / 100

    def update_game(self, key: str, value: str):
        if key == "next_candles":
            new_candles = value.split(";")
            self.date = int(new_candles[0].split(",")[1])
            for candle_str in new_candles:
                candle_infos = candle_str.strip().split(",")
                self.update_chart(candle_infos[0], candle_str)
        if key == "stacks":
            new_stacks = value.split(",")
            for stack_str in new_stacks:
                stack_infos = stack_str.strip().split(":")
                self.update_stack(stack_infos[0], float(stack_infos[1]))


if __name__ == "__main__":
    mybot = Bot()
    mybot.run()
