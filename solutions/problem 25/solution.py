def func():
    x=1
    y=1
    while(True):
        x = x+y
        if len(str(x))==1000:
            print('The number is :', x)
            break
        
func()
