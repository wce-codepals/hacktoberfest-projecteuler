#include <bits/stdc++.h>
using namespace std;
#define lli long long int

lli sumdiv(lli num) {
	lli k = sqrt(num);
	lli sum=0;
	for (lli i=1;i<=k;i++)
	{
		if ((num%i) == 0)
		{
			if (i == (num/i))
				{sum += i;}
			else
				{sum += (i+(num/i));}
		}
	}
	return (sum-num);
}

int main ()
{
	// lli t;
	// cin>>t;
	lli ans=0;
	// cin>>n;
	lli n = 10000;
	for (lli i=2;i<=n;i++) {
		lli s = sumdiv(i);
		if (s!=i) {
			lli p = sumdiv(s);
			if (p==i)
				{ans += (p+s);}
		}
	}
	cout<<ans/2<<endl;
	return 0;
}