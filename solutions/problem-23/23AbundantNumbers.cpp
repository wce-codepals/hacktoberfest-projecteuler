#include <cmath>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

int SumOfDivisors(double numberToTest);

vector<double> m_abundants;
vector<double> m_sumOfTwoAbundants;
double sumTotal, number;
int maxNb, indice;
ofstream divisors ("sumdivisors.log", std::ios::out);
ofstream abundant ("abundantNbs.log", std::ios::out);

int main (int argc, char * argv[]){
	if (argc !=1){
		cerr<<"argument warning: no argument needed."<<endl;
	}
	maxNb=28123;
	sumTotal=((maxNb+1)*maxNb)/2;
	m_sumOfTwoAbundants.assign(maxNb, 1);

	divisors.precision(20);	abundant.precision(20);	cout.precision(20);
	for(int i=12; i<=maxNb; ++i){
		number=SumOfDivisors(i);
		if(number>i){
			m_abundants.push_back(i);
			//somme de 2 abundants
			for (int it=0; it<m_abundants.size(); ++it){
				indice=m_abundants[it]+i;
				if (indice<=28123){
					sumTotal-=m_sumOfTwoAbundants[indice-1]*indice;
					m_sumOfTwoAbundants[indice-1]=0;
				}
			}
		}
	}

	cout<<"Total sum of all the positive integers which cannot be written as the sum of two abundant numbers\n"<<sumTotal<<endl;
	cout<<"See sumdivisors.log and abundantsNb.log for more details."<<endl;
	
	return 0;


}


int SumOfDivisors(double numberToTest){
	double sumDivisors=1;
	double bound=floor(sqrt(numberToTest)), divisionInt=0;

	divisors<<"For "<<numberToTest<<":"<<endl;
	divisors << "1-";
	for (int i=2; i<=bound; ++i){
		divisionInt=floor(numberToTest/(double)i);
		if (divisionInt*i==numberToTest){
			if (divisionInt==i){
				sumDivisors+=divisionInt;
				divisors<<divisionInt<<"-";

			}
			else {
				sumDivisors+=i;
				sumDivisors+=divisionInt;				
				divisors<<divisionInt<<"-"<<i<<"-";
			}
		}
	}
	divisors<<"ok sum:" << sumDivisors << "\n"<<endl;
	return sumDivisors;
}
