#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<sstream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<map>
#include<set>
using namespace std;
#define N 90000000

bool prime[N];
vector<int>p;
vector<double>h;
vector<double>w;
deque<int> Q[2500009];
int ans=0;

double cross(int a, int b, int c) {
    return (w[b]-w[a])*(h[c]-h[a]) - (w[c]-w[a])*(h[b]-h[a]);
}


//similar to lower hull
void f(int i, int j) {
    while (!Q[i].empty() && cross(Q[i].front(), i, j) > 0) {
        f(Q[i].front(), j);
        Q[i].pop_front();
    }
    
    Q[j].push_back(i);
    ans++;
}

int main(){
		
	memset(prime,1,sizeof(prime));
	
	for(long long i=2;i*i<=N;i++)
		if(prime[i])
			for(long long j=i*i;j<=N;j+=i)
				prime[j]=0;
	
	int cont=0;
	for(long long i=2;i<=N;i++)
		if(prime[i]){
			cont++;
			p.push_back(i);
		}
		
	h.push_back(2);
	w.push_back(0);
	int auxh=2;
	long long sum=0;
	
	for(int i=1;i<p.size();i+=2){
		auxh-=p[i];
		auxh+=p[i+1];
		sum+=p[i]+p[i+1];
		w.push_back(sum);
		h.push_back(auxh);
	}
	
    for(int i=1;i<=2500000;i++) 
        Q[i].clear();

    for(int i=0;i<2500000-1;++i)
        f(i,i+1);

    cout<<ans<<endl;
	//21025060
	//Run time: 6 seconds
	return 0;
}
