module Wolframe where
import My
import DoOp
import ArgsGestion
import Data.Bool (Bool(True))
import Data.Maybe

rule30Calcul :: [Bool] -> Bool
rule30Calcul (True:True:_) = False
rule30Calcul (True:False:False:_) = True
rule30Calcul (True:False:True:_) = False
rule30Calcul (False:True:_) = True
rule30Calcul (False:False:True:_) = True
rule30Calcul (False:False:False:_) = False
rule30Calcul (False:False:_) = True
rule30Calcul next = True

rule90Calcul :: [Bool] -> Bool
rule90Calcul (True:True:True:_) = False
rule90Calcul (True:True:False:_) = True
rule90Calcul (True:False:True:_) = False
rule90Calcul (True:False:False:_) = True
rule90Calcul (False:True:True:_) = True
rule90Calcul (False:True:False:_) = False
rule90Calcul (False:False:True:_) = True
rule90Calcul (False:False:False:_) = False
rule90Calcul next = True

rule110Calcul :: [Bool] -> Bool
rule110Calcul (True:True:True:_) = False
rule110Calcul (True:True:False:_) = True
rule110Calcul (True:False:True:_) = True
rule110Calcul (True:False:False:_) = False
rule110Calcul (False:True:_) = True
rule110Calcul (False:False:True:_) = True
rule110Calcul (False:False:False:_) = False
rule110Calcul next = True

ruleCalcul :: Conf -> [Bool] -> Bool
ruleCalcul (Conf rule start wlines window move) next
    | fromJust rule == 30 = rule30Calcul next
    | fromJust rule == 90 = rule90Calcul next
    | fromJust rule == 110 = rule110Calcul next
    | otherwise = False

displaySomeSpace :: Int -> IO()
displaySomeSpace 0 = return ()
displaySomeSpace count
    | count > 0 = putStr " " >> displaySomeSpace (count -1)
    | otherwise = return ()

wolfDisplay :: [Bool] -> IO()
wolfDisplay [] = return ()
wolfDisplay (True:xs) = putStr "*" >> wolfDisplay xs
wolfDisplay (False:xs) = putStr " " >> wolfDisplay xs

wolfComputeFirstDec :: Conf -> Int -> Int -> Int
wolfComputeFirstDec (Conf rule start wlines window move) count length =
    if fromJust window < dec + length
        then fromJust window - length
        else dec
    where
        dec
            | isNothing move = (div (fromJust window) 2 -
                div (count * 2 + 1) 2)
            | otherwise = (div (fromJust window) 2 - div 
                (count * 2 + 1) 2 + fromJust move)

wolfMod :: Int -> Int
wolfMod number =
    if div (number + 2) 2 > 0
        then 1
        else 0

wolfComputeSecondDec :: Conf -> Int -> Int -> Int
wolfComputeSecondDec (Conf rule start wlines window move) count length =
    if fromJust window < dec + length
            then fromJust window - length
            else dec
    where
        dec
            | isNothing move = (div (fromJust window) 2 -
                div (count * 2 + 1) 2 - 1)
            | otherwise = (div (fromJust window) 2 - div 
            (count * 2 + 1) 2 - fromJust move - 1)

wolfGetAListPart :: [Bool] -> Int -> Int -> [Bool]
wolfGetAListPart list from to = take (to - from + 1) (drop from list)

wolfComputeFirstPart :: Conf -> Int -> Int
wolfComputeFirstPart (Conf rule start wlines window move) length =
    if length <= (fromJust window)
        then 0
        else (div (length - (fromJust window)) 2)

wolfComputeSecondPart :: Conf -> Int -> Int
wolfComputeSecondPart (Conf rule start wlines window move) length =
    if length < (fromJust window)
        then length
        else length - ((div (length - (fromJust window)) 2) + 1 +
            (wolfMod (length - (fromJust window))))

wolfCanDisplay :: Conf -> Int -> Bool
wolfCanDisplay (Conf rule start wlines window move) actual
    | isNothing start = True
    | otherwise = if (fromJust start) < actual + 1
                    then True
                    else False

wolfHoldDisplay :: Conf -> [Bool] -> Int -> IO()
wolfHoldDisplay conf line count =
        if (wolfCanDisplay conf count)
            then displaySomeSpace first >> wolfDisplay content >>
                displaySomeSpace second >> putStr "\n"
            else putStr ""
        where
            first = wolfComputeFirstDec conf count (length line)
            second = wolfComputeSecondDec conf count (length line)
            content = wolfGetAListPart line
                (wolfComputeFirstPart conf (length line))
                (wolfComputeSecondPart conf (length line))

wolfIsEnd :: Conf -> Int -> Bool
wolfIsEnd (Conf rule start wlines window move) count
    | isNothing wlines = False
    | isNothing start && fromJust wlines <= count + 1 = True
    | fromJust wlines + fromJust start <= count + 1 = True
    | otherwise = False

wolfRunBis :: Conf -> [Bool] -> [Bool] -> Int -> IO()
wolfRunBis conf [p] next count = wolfRun conf [] 
    (next ++ [ruleCalcul conf [p, False, False]]) count
wolfRunBis conf [p,q] next count = wolfRun conf [q] 
    (next ++ [ruleCalcul conf [p, q, False]]) count
wolfRunBis conf (p:ps) next count = wolfRun conf ps 
    (next ++ [ruleCalcul conf (p:ps)]) count
wolfRunBis conf previous next count = return ();

wolfRun :: Conf -> [Bool] -> [Bool] -> Int -> IO()
wolfRun conf [] next count
    | wolfIsEnd conf count = wolfHoldDisplay conf next count
    | otherwise = wolfHoldDisplay conf next count >> 
    wolfRun conf next [] (count + 1)
wolfRun conf previous [] count = wolfRun conf previous 
    [ruleCalcul conf ([False, False] ++ previous)] count
wolfRun conf previous [x] count = wolfRun conf previous 
    (x : [ruleCalcul conf (False : previous ++ [False])]) count
wolfRun conf previous next count = wolfRunBis conf previous next count


wolfStartValue :: Conf -> [Bool]
wolfStartValue (Conf rule start wlines window move)
    | fromJust rule == 30 = [True]
    | fromJust rule == 90 = [True]
    | fromJust rule == 110 = [True]
    | otherwise = [False]

wolfStart :: Conf -> IO()
wolfStart conf = wolfHoldDisplay conf (wolfStartValue conf) 0 >>
    wolfRun conf (wolfStartValue conf) [] 1