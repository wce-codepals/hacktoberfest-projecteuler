import math

def main():
    
   a = 100;
   b = 100;
   
   numbers = []
   
   #Calculates all the numbers
   for i in range (2,a+1):
       for j in range (2,b+1):
           numbers.append(pow(i,j))
           
   #Transfomrs into a set so we get no repetitions
   numbersSet = set(numbers)
   
   print("The number of elements is ", len(numbersSet))
   
   pass

if __name__ == "__main__":
    main()