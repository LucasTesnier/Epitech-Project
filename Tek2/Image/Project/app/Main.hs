import System.Environment
import System.Exit
import Data.Maybe (isNothing, fromJust)
import Options.Applicative
import Data.Bool
import Utils
import Types
import Cluster
import Argument

-- ARGUMENT HANDLING

main :: IO()
main = launch =<< execParser opts
    where
        opts = info (argHandling <**> helper)
            ( fullDesc
            <> progDesc "Compress a picture PICTURE_FILEPATH with COLOR_NUMBER"
            <> header "Image Compressor - EPITECH Project" )
----------------------------------

{- main :: IO()
main = do
    args <- getArgs
    fileContent <- openFile args
    let temp = createInFromString fileContent "" []
    if isNothing temp
        then exitWith (ExitFailure 84)
        else print (createOutsFromIn (fromJust temp))
 -}
-- Choisir aléatoirement N centre de cluster
-- Boucler tant que tout les points ne sont pas immobiles :
    -- Somme de la squared distance entre tout les points et les centroides
    -- Assigner tout les points au centroide le plus proche
    -- Mettre à jour le centroid en fonction de la moyenne de tout les point du cluster (Couleur et position :) )