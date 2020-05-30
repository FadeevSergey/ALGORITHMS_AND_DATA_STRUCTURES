import System.IO
 
toInt :: String -> Integer
toInt x = (read x) :: Integer
 
main = do
         first <- getLine
         second <- getLine
         putStrLn $ (show $ (toInt first)*(toInt second))
