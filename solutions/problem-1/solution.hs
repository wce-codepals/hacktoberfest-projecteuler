prob1 limit = sum [i | i <- [1 .. limit], i `mod` 3 == 0 || i `mod` 5 == 0, i<limit]

main = print (prob1 1000)