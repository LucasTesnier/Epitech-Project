module DoOp where
import My
import Data.Maybe
import Data.Char

myElem :: Eq a => a -> [a] -> Bool
myElem equa [] = False
myElem equa (a:as)
    | equa == a = True
    | otherwise = myElem equa as

safeDiv :: Int -> Int -> Maybe Int
safeDiv x 0 = Nothing
safeDiv x y = Just (x `div` y)

safeMod :: Int -> Int -> Maybe Int
safeMod x 0 = Nothing
safeMod x y = Just (x `mod` y)

safeNth :: [a] -> Int -> Maybe a
safeNth a pos
    | pos < 0 = Nothing
    | myLength a <= pos = Nothing
    | otherwise = Just (myNthRec a pos 0)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc x = fmap (+1) (x) :: Maybe Int

myLookup :: Eq a => a -> [(a , b)] -> Maybe b
myLookup equa [] = Nothing
myLookup equa (a:as)
    | equa == (myFst a) = Just (mySnd a)
    | otherwise = myLookup equa as

maybeDo :: ( a -> b -> c ) -> Maybe a -> Maybe b -> Maybe c
maybeDo fct Nothing b = Nothing
maybeDo fct a Nothing = Nothing
maybeDo fct (Just a) (Just b) = Just (fct a b)

myIsNumber :: [Char] -> Bool -> Bool
myIsNumber [] neg = True
myIsNumber ('-':as) True
    | myLength ('-':as) /= 1 = myIsNumber as False
    | otherwise = False
myIsNumber (a:as) neg
    | isDigit a = myIsNumber as False
    | otherwise = False

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt str
    | myIsNumber str True = Just (read str :: Int)
    | otherwise = Nothing

getLineLength :: IO Int
getLineLength = do
    line <- getLine
    return (length line)

printAndGetLength :: String -> IO Int
printAndGetLength str = putStrLn str >>
    return (length str)

printBox :: Int -> IO ()
printBox size = printBoxExe size 0

printBoxExe :: Int -> Int -> IO ()
printBoxExe size actual
    | actual > (size -1) = return ()
printBoxExe size actual
    | (size - 1) == actual || actual <= 0 = printBoxUp size 0 >>
    printBoxExe size (actual + 1)
    | otherwise = printBoxSide size 0 >>
    printBoxExe size (actual + 1)

printBoxSide :: Int -> Int -> IO ()
printBoxSide size 0 = putChar '|' >>
    printBoxSide size 1
printBoxSide size actual
    | actual == (size * 2) - 1 = putChar '|' >> putChar '\n' >> return ()
printBoxSide size actual = putChar ' ' >>
    printBoxSide size (actual + 1)

printBoxUp :: Int -> Int -> IO ()
printBoxUp size 0 = putChar '+' >> printBoxUp size 1
printBoxUp size actual
    | actual == (size * 2) - 1 = putChar '+' >> putChar '\n' >> return ()
printBoxUp size actual = putChar '-' >>
    printBoxUp size (actual + 1)

concatLines :: Int -> IO String
concatLines i
    | i <= 0 = return []
concatLines i = do
    line <- getLine
    temp <- concatLines (i - 1)
    return (myAppend line temp)

getInt :: IO (Maybe Int)
getInt = do
    line <- getLine
    return (readInt line)

readChar :: [Char] -> Maybe Char
readChar [] = Nothing
readChar (a:as)
    | (myLength (a:as)) == 1 = Just a
    | otherwise = Nothing

doop :: Maybe Int -> Maybe Char -> Maybe Int -> IO Int
doop Nothing op y = return 84
doop x Nothing y = return 84
doop x op Nothing = return 84
doop (Just x) (Just op) (Just y) = printDoOp (doDoop x op y doopExe)

doDoop :: Int -> Char -> Int -> (Int -> Char -> Int -> Maybe Int) -> Int
doDoop x op z fct
    | (fct x op z) == Nothing = 84
    | otherwise = fromJust (fct x op z)

printDoOp :: Int -> IO Int
printDoOp 84 = return 84
printDoOp value = print value >> return 0

doopExe :: Int -> Char -> Int -> Maybe Int
doopExe x '+' y = Just (x + y)
doopExe x '-' y = Just (x - y)
doopExe x '*' y = Just (x * y)
doopExe x '/' y = safeDiv x y
doopExe x '%' y = safeMod x y
doopExe x a y = Nothing