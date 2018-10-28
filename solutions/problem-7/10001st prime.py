ap = [2]

def is_prime(number):
    for i in ap:
        if(number%i==0):
            return False
    else:
        ap.append(number)

def main_prime(num):
    current_num=2
    while(len(ap)<num):
        is_prime(current_num)
        current_num+=1
    return ap[-1]

print(main_prime(10))  #put 10001 instead of 10