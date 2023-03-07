--
-- EPITECH PROJECT, 2022
-- Project
-- File description:
-- Cluster
--
module Cluster where
import Types
import System.Random

createOutsFromIn :: Arguments -> In -> Int -> Out
createOutsFromIn argument input number = convertAllCentroidsToOut
    (loop argument (initAllCentroids number input))

selectLinesWithIndex :: Int -> Int -> [Line] -> Line
selectLinesWithIndex count index (x:xs)
    | count == index = x
    | otherwise = selectLinesWithIndex (count + 1) index xs
selectLinesWithIndex _ _ [] =
    Line (Point 0 0) (Color (Short 0) (Short 0) (Short 0))

getLineSize :: Int -> [Line] -> Int
getLineSize count (x:xs) = getLineSize (count + 1) xs
getLineSize count [] = count

getRandomLine :: In -> Int -> Line
getRandomLine (In lines) rand = selectLinesWithIndex 0
    (fst (randomR (0, (length lines - 1)) (mkStdGen rand))) lines

randomizeCentroids :: Int -> In -> [Centroids] -> [Centroids]
randomizeCentroids n input centroids
    | n > 0 = randomizeCentroids (n - 1) input (centroids ++
        [Centroids (getRandomLine input n) []])
    | otherwise = centroids

-- Init AllCentroids -> N cluster (Boucle se servir aléatoirement dans IN) -> Line = Aléatoire In && [Line] = []

initAllCentroids :: Int -> In -> AllCentroids
initAllCentroids n (In lines) = setLineToCentroids
    ((randomizeCentroids n (In lines) [])) lines

-- A CODER

-- boucle global

loop :: Arguments -> AllCentroids -> AllCentroids
loop (Arguments f n l) allCentroids =
    if variance > l
        then loop (Arguments f n l) newCentroids
        else newCentroids
    where
        newCentroids = getNewAllCentroids allCentroids
        variance = computeVariance newCentroids allCentroids l



-- Calculer la variance

computeVarianceCluster :: Centroids -> Centroids -> Float
computeVarianceCluster (Centroids new _) (Centroids old _) = 
    computeSquaredDistance new old

computeVarianceCentroids :: [Centroids] -> [Centroids] -> Float -> Float
computeVarianceCentroids [x] [y] l = computeVarianceCluster x y
computeVarianceCentroids (x:xs) (y:ys) l = 
    if var <= l
        then l
        else computeVarianceCentroids xs ys l
    where
        var = computeVarianceCluster x y

computeVariance :: AllCentroids -> AllCentroids -> Float -> Float
computeVariance (AllCentroids newCentroids) (AllCentroids oldCentroids) l =
    computeVarianceCentroids newCentroids oldCentroids l

-- LUCAS

-- | Calcul distance entre deux points -> Formule du PDF
computeSquaredDistance :: Line -> Line -> Float
computeSquaredDistance (Line _ c1) (Line _ c2) =
    sqrt (fromIntegral (((r1 - r2) ^ 2) + ((g1 - g2) ^ 2) + (b1 - b2) ^ 2))
    where
        (Color (Short r1) (Short g1) (Short b1)) = c1
        (Color (Short r2) (Short g2) (Short b2)) = c2

-- Attribuer le point au Centroids le plus proche -> Calcul distance pour AllCentroids -> AllCentroids[plusProche][Lines].add data

getIndexByFloat :: [Float] -> Float -> Int -> Int
getIndexByFloat (x:xs) res count
    | x == res = count
    | otherwise = getIndexByFloat xs res (count + 1)
getIndexByFloat _ _ _ = 0

findClosetCentroids :: Line -> [Centroids] -> [Float] -> Int
findClosetCentroids line ((Centroids center colors):xs) res =
    findClosetCentroids line xs (res ++ [computeSquaredDistance line center])
findClosetCentroids line [] res = getIndexByFloat res (minimum res) 0

addLineToCentroid :: Centroids -> Line -> Centroids
addLineToCentroid (Centroids center array) line =
    (Centroids center ([line] ++ array))

--putIntoClosetCentroids :: Line -> [Centroids] -> [Centroids]

addLineToGivenCentroid :: [Centroids] -> Line -> Int -> Int -> [Centroids]
addLineToGivenCentroid [x] line index it
    | index == it = [addLineToCentroid x line]
    | otherwise = [x]
addLineToGivenCentroid (x:xs) line index it
    | index == it = (addLineToCentroid x line : xs)
    | otherwise = ([x] ++ addLineToGivenCentroid xs line index (it + 1))

setLineToCentroids :: [Centroids] -> [Line] -> AllCentroids
setLineToCentroids centroids [line] = newCentroids
    where
        closest = findClosetCentroids line centroids []
        newCentroids = AllCentroids
            (addLineToGivenCentroid centroids line closest 0)
setLineToCentroids centroids (l:ls) =
    setLineToCentroids newCentroids ls
    where
        closest = findClosetCentroids l centroids []
        newCentroids = addLineToGivenCentroid centroids l closest 0

updateCentroidColor :: Centroids -> Color -> Centroids
updateCentroidColor  (Centroids (Line point oldColor) lines) newColor =
    Centroids (Line point newColor) lines

getColorAverageFromCentroid :: Centroids -> ColorInt -> Int -> Color
getColorAverageFromCentroid (Centroids (Line _ color) []) _ 0 = 
    color
getColorAverageFromCentroid (Centroids line []) (ColorInt rI gI bI) it =
    (Color (Short (rI `div` it)) (Short (gI `div` it)) (Short (bI `div` it)))
getColorAverageFromCentroid (Centroids line ((Line p (Color (Short r) (Short g)
    (Short b))):ls)) (ColorInt rI gI bI) it =
    getColorAverageFromCentroid (Centroids line ls) (ColorInt
        (r + rI) (g + gI) (b + bI)) (it + 1)


-- Récupérer [Line] from AllCentroids
-- Mettre à jour les AllCentroids

getLinesFromCentroid :: [Centroids] -> [Line]
getLinesFromCentroid [] = []
getLinesFromCentroid ((Centroids _ ls):xs) = ls ++ getLinesFromCentroid xs

getNewCentroids :: [Centroids] -> [Centroids]
getNewCentroids [] = []
getNewCentroids (x:xs) = [updateCentroidColor x $ 
    getColorAverageFromCentroid x (ColorInt 0 0 0) 0] ++ getNewCentroids xs

reinitializeAllLineFromCentroids :: [Centroids] -> [Centroids]
reinitializeAllLineFromCentroids [] = []
reinitializeAllLineFromCentroids ((Centroids line _):xs) = 
    [(Centroids line [])] ++ reinitializeAllLineFromCentroids xs

selectLineR :: [Line] -> Line
selectLineR lines = selectLinesWithIndex 0
    (fst (randomR (0, (length lines - 1)) (mkStdGen 14))) lines

replaceEmptyCentroids :: [Centroids] -> [Line] -> [Centroids]
replaceEmptyCentroids [] _ = []
replaceEmptyCentroids ((Centroids line []):xs) lines =
    [(Centroids current [])] ++ (replaceEmptyCentroids xs lines)
    where
        current = selectLineR lines
replaceEmptyCentroids (x:xs) lines = [x] ++ (replaceEmptyCentroids xs lines)

checkIntegrity :: AllCentroids -> [Line] -> AllCentroids
checkIntegrity (AllCentroids oldCentroids) lines =
    setLineToCentroids temp lines
    where
        newCentroids = replaceEmptyCentroids oldCentroids lines
        temp = reinitializeAllLineFromCentroids newCentroids

getNewAllCentroids :: AllCentroids -> AllCentroids
getNewAllCentroids (AllCentroids centroids) = 
    checkIntegrity newCentroids oldLines
    where
        oldCentroids = 
            reinitializeAllLineFromCentroids (getNewCentroids centroids)
        oldLines = getLinesFromCentroid centroids
        newCentroids = setLineToCentroids oldCentroids oldLines
