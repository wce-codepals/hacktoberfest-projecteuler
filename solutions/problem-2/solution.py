def all(arr,n): #function that checks if the number is prime.
    for j in arr :
        if(n%j==0):
            return False
    else:
        return True

def largest_prime(num):
    arr_prime=[]
    for i in range(2,int(num/2+1)):
        if(num%i == 0 and all(arr_prime,i)):
            arr_prime.append(i)
    return arr_prime[-1]

print(largest_prime(13195))
