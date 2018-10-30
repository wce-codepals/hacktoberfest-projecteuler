# Solution 1
answer <- 0
for (i in 1:999) {
    if (i%%3 == 0 | i%%5 == 0) 
        answer <- answer + i
}