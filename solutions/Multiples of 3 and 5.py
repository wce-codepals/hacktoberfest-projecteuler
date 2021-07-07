def mult_3n5():
    return (sum(filter(lambda x: x%3==0 or x%5==0,range(1,1000))))

print(mult_3n5())     # gives us 233168


# filter returns a list to the memory having only those values which are true in return values of lambda ( x%3==0 or x%5==0 )
#than we sum the list using sum