module My where

mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x
    | x < 0     = True
    | otherwise = False

myAbs :: Int -> Int
myAbs x
    | x < 0     = -x
    | otherwise = x

myMin :: Int -> Int -> Int
myMin x y
    | x < y     = x
    | otherwise = y

myMax :: Int -> Int -> Int
myMax x y
    | x < y     = y
    | otherwise = x

myTuple :: a -> b -> (a , b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a , b, c)
myTruple a b c = (a, b, c)

myFst :: (a , b) -> a
myFst (a, b) = a

mySnd :: (a , b) -> b
mySnd (a, b) = b

mySwap :: (a , b ) -> (b , a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead [] = error "empty_list"
myHead (a:_) = a

myTail :: [a] -> [a]
myTail [] = error "empty_list"
myTail (_:a) = a

myLength :: [a] -> Int
myLength a = myLengthRec a 0

myLengthRec :: [a] -> Int -> Int
myLengthRec [] size = size
myLengthRec (_:a) size = myLengthRec a (size + 1)

myNth :: [a] -> Int -> a
myNth a pos
    | pos < 0 = error "Invalid_pos_size"
    | myLength a <= pos = error "Invalid_pos_size"
    | otherwise = myNthRec a pos 0

myNthRec :: [a] -> Int -> Int -> a
myNthRec (_:a) pos act
    | pos == (act + 1) = myHead a
    | otherwise = myNthRec a pos (act + 1)

myTake :: Int -> [a] -> [a]
myTake n [] = []
myTake 0 a = []
myTake n a |
    n < 0 = error "Invalid Number"
myTake n (a:as) = a:(myTake(n - 1) as)

myDrop :: Int -> [a] -> [a]
myDrop n [] = []
myDrop 0 a = myTake (myLength a) a
myDrop n (a:as)
    | n <= 0 = myTake (myLength (a:as)) (a:as)
    | otherwise = myDrop (n - 1) as

myAppend :: [a] -> [a] -> [a]
myAppend [] (b:bs) = b:(myAppend [] bs)
myAppend a [] = a
myAppend (a:as) b = a:(myAppend as b)

myReverse :: [a] -> [a]
myReverse [] = []
myReverse a = (myHead (myDrop ((myLength a) - 1) a)):
    (myReverse (myTake ((myLength a) -1) a))

myInit :: [a] -> [a]
myInit [] = error "Empty_List"
myInit a = myTake ((myLength a) -1) a

myLast :: [a] -> a
myLast [] = error "Empty_List"
myLast a = myHead (myDrop ((myLength a) - 1) a)

myZip :: [a] -> [b] -> [( a , b )]
myZip [] b = []
myZip a [] = []
myZip (a:as) (b:bs) = (a, b):(myZip as bs)

myUnzip :: [( a , b )] -> ([a] , [b])
myUnzip a = (myUnzipLeft a, myUnzipRight a)

myUnzipLeft :: [( a , b )] -> [a]
myUnzipLeft [] = []
myUnzipLeft (a:as) = (myFst a):myUnzipLeft as

myUnzipRight :: [( a , b )] -> [b]
myUnzipRight [] = []
myUnzipRight (a:as) = (mySnd a):myUnzipRight as

myMap :: (a -> b) -> [a] -> [b]
myMap fct [] = []
myMap fct (a:as) = (fct a):myMap fct as

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter fct [] = []
myFilter fct (a:as) 
    | (fct a) = a:myFilter fct as
    | otherwise = myFilter fct as

myFilterInv :: (a -> Bool) -> [a] -> [a]
myFilterInv fct [] = []
myFilterInv fct (a:as) 
    | (fct a) == False = a:myFilterInv fct as
    | otherwise = myFilterInv fct as

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl fct b [] = b
myFoldl fct b (a:as) = myFoldl fct (fct b a) as

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr fct b a = myFoldrExe fct b (myReverse a)

myFoldrExe :: (a -> b -> b) -> b -> [a] -> b
myFoldrExe fct b [] = b
myFoldrExe fct b (a:as) = myFoldrExe fct (fct a b) as

myPartition :: (a -> Bool) -> [a] -> ([a] , [a])
myPartition fct a = ((myFilter fct a),(myFilterInv fct a))