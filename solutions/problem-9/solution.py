a,b,c = 0,0,0
max = int(input("Max: ")) #Euler asks for 1000
for x in range(1, max):
    for y in range(x+1, max):
        for z in range(y+1, max):
            if x**2 + y**2 == z**2 and x+y+z == 1000:
                print("a = ", x)
                print("b = ", y)
                print("c = ", z)
                print("Product abc = ", x*y*z)
                found = True
                exit()
