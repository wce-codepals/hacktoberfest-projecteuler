import Data.List

main :: IO ()
main =  print ((!! 999999) . sort $ permutations ['0'..'9'])
