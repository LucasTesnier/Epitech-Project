module ArgsGestion where
import System.Exit
import Data.Maybe
import My
import DoOp

data Conf = Conf {
    rule :: Maybe Int,
    start :: Maybe Int,
    wlines :: Maybe Int,
    window :: Maybe Int,
    move :: Maybe Int
}

defaultConf :: Conf
defaultConf = Conf {
    rule = Nothing,
    start = Just 0,
    wlines = Nothing,
    window = Just 80,
    move = Nothing
}

exitBadConfig :: IO()
exitBadConfig = putStrLn "Invalid Config Args !" >> exitWith (ExitFailure 84)

wolfGetArgsBis:: Conf -> [String] -> Maybe Conf
wolfGetArgsBis currentConf ("--lines":y:xs) = wolfGetArgs 
    ((currentConf {wlines = readInt y})) xs
wolfGetArgsBis currentConf ("--window":y:xs) = wolfGetArgs 
    ((currentConf {window = readInt y})) xs
wolfGetArgsBis currentConf ("--move":y:xs) = wolfGetArgs 
    ((currentConf {move = readInt y})) xs
wolfGetArgsBis currentConf (x:y:xs) = Nothing
wolfGetArgsBis currentConf args = Nothing

wolfGetArgs :: Conf -> [String] -> Maybe Conf
wolfGetArgs currentConf [] = Just currentConf
wolfGetArgs currentConf [x] = Nothing
wolfGetArgs currentConf ("--rule":y:xs) = wolfGetArgs 
    ((currentConf {rule = readInt y})) xs
wolfGetArgs currentConf ("--start":y:xs) = wolfGetArgs 
    ((currentConf {start = readInt y})) xs
wolfGetArgs currentConf args = wolfGetArgsBis currentConf args


wolfVerifArgs :: Conf -> IO()
wolfVerifArgs (Conf rule start wlines window move)
    | isNothing rule = exitBadConfig
    | isNothing start = exitBadConfig
    | isNothing window = exitBadConfig
    | otherwise = return ()
