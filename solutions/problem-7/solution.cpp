#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int count = 1;
    long int val = 1;
    bool flag;
    while(val!=10001)
    {
        count += 1;
        if(count%2 == 1)
        {
            flag = true;
            for(int i =2; i<(int)sqrt(count)+1; i++)
            {
                if(count%i == 0)
                    flag = false;
            }
            if(flag == true)
            {
                val += 1;
            }
        }
    }
    cout << endl << count << endl;
    return 0;
}
