import ArgsGestion
import Wolframe
import System.Environment

main :: IO ()
main = do
    args <- getArgs
    case wolfGetArgs defaultConf args of
        Nothing -> exitBadConfig
        Just conf -> wolfVerifArgs conf >> wolfStart conf