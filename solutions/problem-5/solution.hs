main :: IO ()
main = print (foldr1 lcm [1..20])
