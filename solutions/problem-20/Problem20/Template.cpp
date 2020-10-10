#include <bits/stdc++.h> 
#define pb push_back
#define mp make_pair 
#define fr first
#define sc second
#define MOD 1000000007
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define alla(a,n) a, a + n
  
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

void multiply(vector<int> &v, int x) 
{ 
    int carry = 0, res; 
    int size = v.size(); 
    for (int i = 0 ; i < size ; i++) 
    { 
         
        int res = carry + v[i] * x; 
   
        v[i] = res % 10; 
        carry = res / 10; 
    } 
    while (carry != 0) 
    { 
        v.push_back(carry % 10); 
        carry /= 10; 
    } 
}

int findSumOfDigits(int n) 
{ 
	vector<int> v;
	v.push_back(1);

	for (int i=1; i<=n; i++) 
		multiply(v, i); 

	int sum = 0; 
	int size = v.size(); 
	for (int i = 0 ; i < size ; i++) 
		sum += v[i]; 
	return sum; 
} 
  
int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int t ;
    cin >> t ;

    while( t-- ) {

    int n;
    cin>>n; 
    cout << findSumOfDigits(n); 
    }
    return 0 ;
}