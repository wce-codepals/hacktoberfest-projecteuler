#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define maxn 2000009
bool primes[maxn];

void sieve(){
	primes[0]=0;
	primes[1]=0;
	for(int i=2;i<maxn;i++){
		if(primes[i]){
			for(int j=2*i;j<maxn;j+=i)
				primes[j]=0;
		}
	}
}

int main(){
	fill(primes,primes+maxn,1);
	sieve();
	ll ans=0;
	for(int i=1;i<=2000000;i++){
		if(primes[i])ans+=i;
	}
	cout<<ans<<endl;

}
