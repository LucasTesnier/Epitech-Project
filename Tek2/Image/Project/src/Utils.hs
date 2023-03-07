--
-- EPITECH PROJECT, 2022
-- Project
-- File description:
-- utils
--
module Utils where
import Data.Char (isDigit)

myIsNumber :: [Char] -> Bool
myIsNumber [] = True
myIsNumber (a:as)
    | isDigit a = myIsNumber as
    | otherwise = False