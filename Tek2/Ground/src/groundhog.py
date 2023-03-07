#!/usr/bin/python3
from ast import Not
import sys
import math
import csv
import re
import time


#       %4 == 0 :   valeur recupere
#       %4 == 1 :   g
#       %4 == 2 :   r
#       %4 == 3 :   s

def compute_bollinger(tab_t, tab_s, tab_b, period, actual):
    mean = 0
    for i in range(actual - period + 1, actual + 1):
        mean += tab_t[i]
    mean /= period

    up = mean + 2 * tab_s[actual]
    down = mean - 2 * tab_s[actual]

    if (up - down > 0):
        bol = (tab_t[actual] - down) / (up - down)
        if (bol > 0.5):
            tab_b.append(1 - bol)
        else:
            tab_b.append(bol)
    else:
        tab_b.append(tab_t[actual] - mean)

def find_weirdest_value(all_data, tab_w, period):
    tab_t = []
    tab_s = []
    tab_b = []
    index = 0

    for i in range(0, len(all_data), 4):
        tab_t.append(all_data[i])
        tab_s.append(all_data[i + 3])
    for i in range (period, len(tab_t)):
        compute_bollinger(tab_t, tab_s, tab_b, period, i)

    if len(tab_t) <= int(sys.argv[1]) + 5:
        exit (84)
    for i in range(0, 5):
        temp = 100000000
        for j in range(0, len(tab_b)):
            if temp > tab_b[j]:
                temp = tab_b[j]
                index = j
        tab_w.append(tab_t[index + period])
        tab_t.pop(index + period)
        tab_b.pop(index)

def stop_programm(all_data, switch_number, period):
    tab_w = []
    find_weirdest_value(all_data, tab_w, period)
    print("Global tendency switched %i times" % (switch_number))
    if len(tab_w) < 5:
        exit (0)
    print("5 weirdest values are [%.1f, %.1f, %.1f, %.1f, %.1f]" % (tab_w[0], tab_w[1], tab_w[2], tab_w[3], tab_w[4]))
    exit (0)

def display_res(g, r, s):
    print("g=%.2f\t\tr=%.0f%%\t\ts=%.2f" % (round(g, 2), round(r, 0), round(s, 2)), end = "")

def get_data(all_data, switch_number, period):
    try:
        value = input()
    except:
        exit (84)
    if value == "STOP":
        stop_programm(all_data, switch_number, period)
    try:
        value = float(value)
    except:
        exit (84)
    return value

def compute_g(all_data, actual_user_data_pos, period):
    if actual_user_data_pos / 4 < period:
        return float("nan")
    tmp = 0.0
    for i in range(actual_user_data_pos - period * 4, actual_user_data_pos, 4):
        if all_data[i + 4] - all_data[i] > 0:
            tmp += all_data[i + 4] - all_data[i]
    return float(float(tmp) / period)

def compute_r(all_data, actual_user_data_pos, period):
    if actual_user_data_pos / 4 < period:
        return float("nan")
    if all_data[actual_user_data_pos - (4 * period)] == 0:
        if (all_data[actual_user_data_pos] - all_data[actual_user_data_pos - (4 * period)]) < 0:
            return float(-1000)
        else:
            return float(1000)
    return float((all_data[actual_user_data_pos] - all_data[actual_user_data_pos - (4 * period)]) / abs(all_data[actual_user_data_pos - (4 * period)])) * 100

def compute_s(all_data, actual_user_data_pos, period):
    if actual_user_data_pos / 4 < period - 1:
        return float("nan")
    value1 = 0.0
    value2 = 0.0
    for i in range(actual_user_data_pos - (period - 1) * 4, actual_user_data_pos + 4, 4):
        value1 += all_data[i]
        value2 += math.pow(all_data[i], 2)
    return float(math.sqrt(value2 / period - (value1 / period) * (value1 / period)))

def detect_a_switch(all_data, actual_user_data_pos):
    if (actual_user_data_pos == 0):
        print("")
        return 0
    if (all_data[actual_user_data_pos + 2] <= 0 and all_data[actual_user_data_pos - 2] > 0):
        print("\t\ta switch occurs")
        return 1
    if (all_data[actual_user_data_pos + 2] >= 0 and all_data[actual_user_data_pos - 2] < 0):
        print("\t\ta switch occurs")
        return 1
    print("")
    return 0

def loop(period, all_data, switch_number):
    actual_user_data_pos = len(all_data)

    all_data.append(get_data(all_data, switch_number, period))
    all_data.append(compute_g(all_data, actual_user_data_pos, period))
    all_data.append(compute_r(all_data, actual_user_data_pos, period))
    all_data.append(compute_s(all_data, actual_user_data_pos, period))

    display_res(all_data[actual_user_data_pos + 1], all_data[actual_user_data_pos + 2], all_data[actual_user_data_pos + 3])
    switch_number += detect_a_switch(all_data, actual_user_data_pos)
    loop(period, all_data, switch_number)

def main():
    if (len(sys.argv) == 2 and sys.argv[1] == "-h"):
        exit (0)
    if (len(sys.argv) != 2):
        exit (84)
    period = 0
    try:
        period = int(sys.argv[1])
        if (period <= 0):
            exit (84)
    except:
        exit (84)
    all_data = []
    loop (period, all_data, 0)

if __name__ == '__main__':
    exit(main())
