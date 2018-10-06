'''as a+b+c = 1000 all a ,b,c < 500'''
def pythagorean_triplet(N=1000):
    S=N
    N=N//2
    for a in range(1,N+1):
        b=a+1
        c=b+1
        while c <= N :
            while c*c < a*a + b*b:
                c+=1
            if c*c == a*a + b*b and c<N:
                if a+b+c==S:
                    return (a,b,c)
            b+=1



if __name__=='__main__':
    print(pythagorean_triplet())

    
        
