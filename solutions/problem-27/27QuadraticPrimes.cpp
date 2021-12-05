#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

double maxAbs (double x, double y) {
 	return (abs(x)<abs(y))?y:x;
}

int isPrime(int number){
	int limit;
	if (number <=1){
		return 0;
	}

	if (number==2){
		return 1;
	}
	limit=(int)sqrt(float(number));
	for(int i=2; i<=limit; ++i){
		if (number%i==0){
			return 0;
		}
	}
	return 1;
}


int main(int argc, char *argv[]){
	if (argc != 3){
		cerr<<"argument error: max a and max b."<<endl;
	}
	int maxa=atoi(argv[1]); int maxb=atoi(argv[2]);
	int a=1; int b=3;
	int compteur=0; int recordCompteur=0; double product=0;
	int n=0;
	while (a < maxa){
		b=a+2;
		while (b<maxb){
			//test max consecutive prime number for a and b and then for -a and b
			while (isPrime(n*n+n*a+b)) {
				++compteur;
				++n;
			}
			if (recordCompteur<=compteur){
				recordCompteur=compteur;
				product=maxAbs(product, (double)a*b);
			}
			compteur=0; n=0;
//			cout << a << " ; " << b << endl;
			while (isPrime(n*n-n*a+b)) {
				++compteur;
				++n;
			}
			if (recordCompteur<=compteur){
				recordCompteur=compteur;
				product=maxAbs(product, (double)-a*b);
			}
			compteur=0; n=0;

			//prime for b
			b+=2;
			while (!isPrime(b)) {
				b+=2;
			}
//			cout << a << " ; " << b << endl;
		}
		//odd for a
		a+=2;
	}

	cout << "Max product: " << product << " for compteur: " << recordCompteur << endl;

	return 0;
}
