--
-- EPITECH PROJECT, 2022
-- Project
-- File description:
-- Argument
--

module Argument where
import Options.Applicative
import System.Environment
import System.Exit
import Data.Maybe (isNothing, fromJust)
import Types
import Cluster

argHandling :: Parser Arguments
argHandling = Arguments
    <$> strOption (short 'f' <> metavar "PICTURE_FILEPATH"
       <> help "path to the file containing the colors of the pixels")
    <*> option auto (short 'n' <> metavar "COLOR_NUMBER"
       <> help "number of colors in the final image")
    <*> option auto (short 'l' <> metavar "LIMIT"
       <> help "convergence limit")

argErrorHandling :: Arguments -> Bool
argErrorHandling (Arguments f n l)
    | n < 1 = False
    | l < 0 = False
    | otherwise = True


launch :: Arguments -> IO()
launch (Arguments f n l)
    | not (argErrorHandling (Arguments f n l)) = exitWith (ExitFailure 84)
    | otherwise = do
        fileContent <- readFile f
        let myIn = createInFromString fileContent "" []
        if isNothing myIn
            then exitWith (ExitFailure 84)
            else print (createOutsFromIn (Arguments f n l) (fromJust myIn) n)