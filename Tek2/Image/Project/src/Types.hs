--
-- EPITECH PROJECT, 2022
-- Project
-- File description:
-- Types
--

module Types where
import Data.Maybe (isNothing, fromJust)
import Text.Read (readMaybe)

data Arguments = Arguments
  { filePath    :: String
  , colorNumber :: Int
  , convergence :: Float }

newtype Short = Short Int
instance Show Short where
    show (Short x) = show x

readShort :: [Char] -> Maybe Short
readShort [] = Nothing
readShort number = do
    short <- readMaybe number :: Maybe Int
    if short > 0 && short <= 255
    then return $ Short short
    else Nothing

data Point = Point Int Int
instance Show Point where
    show (Point x y) = "(" ++ show x ++ "," ++ show y ++ ")"

createPointFromString :: String -> String -> Maybe Point
createPointFromString x y = do
    px <- readMaybe x :: Maybe Int
    py <- readMaybe y :: Maybe Int
    Just $ Point px py

data ColorInt = ColorInt Int Int Int

data Color = Color Short Short Short
instance Show Color where
    show (Color r g b) = "(" ++ show r ++ "," ++ show g ++ "," ++ show b ++ ")"

createColorFromString :: String -> String -> String -> Maybe Color
createColorFromString r g b = do
    cr <- readShort r
    cg <- readShort g
    cb <- readShort b
    Just $ Color cr cg cb

data Line = Line Point Color
instance Show Line where
    show (Line point color) = show point ++ " " ++ show color

sevenLine :: [Char] -> [Char] -> [Char] -> [Char] -> Maybe Color
sevenLine [')'] r g b = createColorFromString r g b
sevenLine (x:xs) r g b = sevenLine xs r g (b ++ [x])
sevenLine _ _ _ _ = Nothing

sixLine :: [Char] -> [Char] -> [Char] -> Maybe Color
sixLine (',':xs) r g = sevenLine xs r g ""
sixLine (x:xs) r g = sixLine xs r (g ++ [x])
sixLine _ _ _ = Nothing

fiveLine :: [Char] -> [Char] -> Maybe Color
fiveLine (',':xs) r = sixLine xs r ""
fiveLine (x:xs) r = fiveLine xs (r ++ [x])
fiveLine _ _ = Nothing

fourLine :: [Char] -> Maybe Color
fourLine (' ':'(':xs) = fiveLine xs ""
fourLine _ = Nothing

thirdLine :: [Char] -> Maybe Point -> Maybe Line
thirdLine xs Nothing = Nothing
thirdLine xs point
    | isNothing (fourLine xs) = Nothing
    | otherwise = Just (Line (fromJust point) (fromJust (fourLine xs)))

secondLine :: [Char] -> [Char] -> [Char] -> Maybe Line
secondLine (')':xs) numX numY = thirdLine xs (createPointFromString numX numY)
secondLine (x:xs) numX numY = secondLine xs numX (numY ++ [x])
secondLine _ _ _ = Nothing

firstLine :: [Char] -> [Char] -> Maybe Line
firstLine (',':xs) number = secondLine xs number ""
firstLine (x:xs) number = firstLine xs (number ++ [x])
firstLine _ _ = Nothing

createLineFromString :: [Char] -> Maybe Line
createLineFromString ('(':xs) = firstLine xs ""
createLineFromString str = Nothing

newtype In = In [Line]
instance Show In where
    show (In [x]) = show x
    show (In (x:xs)) = show x ++ "\n" ++ show (In xs)
    show (In []) = ""

createInFromString :: [Char] -> [Char] -> [Line] -> Maybe In
createInFromString ('\n':xs) current inputs = do
    line <- createLineFromString current
    createInFromString xs [] (inputs ++ [line])
createInFromString [] [] inputs = Just (In inputs)
createInFromString (x:xs) current inputs =
    createInFromString xs (current ++ [x]) inputs
createInFromString _ _ _ = Nothing

displayLines :: [Line] -> [Char]
displayLines [x] = show x
displayLines (x:xs) = show x ++ "\n" ++ displayLines xs
displayLines [] = []

data Cluster = Cluster Color [Line]
instance Show Cluster where
    show (Cluster color lines) = "--\n" ++ show color ++ "\n-\n" ++ 
        displayLines lines

newtype Out = Out [Cluster]
instance Show Out where
    show (Out [x]) = show x
    show (Out (x:xs)) = show x ++ "\n" ++ show (Out xs)
    show (Out []) = ""


data Centroids = Centroids Line [Line]
instance Show Centroids where
    show (Centroids center lines) = show center ++ "-\n" ++ show lines

newtype AllCentroids = AllCentroids [Centroids]
instance Show AllCentroids where
    show (AllCentroids [x]) = show x
    show (AllCentroids (x:xs)) = show x ++ "\n\n\n" ++ show (AllCentroids xs)
    show (AllCentroids []) = ""

convertCentroidsToCluster :: [Centroids] -> [Cluster] -> [Cluster]
convertCentroidsToCluster ((Centroids (Line points colors) lines):xs) cluster =
    convertCentroidsToCluster xs (cluster ++ [Cluster colors lines])
convertCentroidsToCluster [] clusters = clusters

-- Convertir AllCentroids en Out

convertAllCentroidsToOut :: AllCentroids -> Out
convertAllCentroidsToOut (AllCentroids centroids) =
    Out (convertCentroidsToCluster centroids [])
