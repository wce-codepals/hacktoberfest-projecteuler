// ==========================================
// Solution for problem 14 using brute force
// ==========================================
#include <iostream>
#include <iomanip>

using namespace std;

void Collatzify(long long int num,long int &count);

int main()
{
   long int count,startingValue,largestTerms = 0;
   int max = 1000000;
   
   for(int i = 2; i < max; i++)
   {
      count = 1;
      Collatzify(i,count);
      if(largestTerms < count)
      {
         largestTerms = count;
         startingValue = i;
      }
   }
   
   cout << "Value with the most terms between 1 and " << max << " is " 
        << startingValue << " with " << largestTerms << " terms." << endl;
}
//num must be long long because it can go over 1000000
void Collatzify(long long int num, long int &count)
{
   while(num != 1)
   {
      if(num % 2 == 0)
      {
         num /= 2;
      }
      else
      {
         num = 3 * num + 1;
      }
      count++;
   }
}
