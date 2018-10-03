#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main () {
	fstream file;
	string filename,i;
	filename = "names.txt";
	file.open(filename.c_str());
	vector<string> vect;

	while(file.good()) {
		string substr;
		getline(file,substr,',');
		vect.push_back(substr);
	}
	for (lli i=0;i<vect.size();i++)
		{vect[i].erase(0,1); vect[i].erase(vect[i].size() - 1);}
	sort(vect.begin(), vect.end());
	lli ans=0;
	for (lli i=0;i<vect.size();i++) {
		lli sum=0;
		for (lli j=0;j<vect[i].length();j++) {
			sum += (vect[i][j]-64);
		}
		// cout<<vect[i]<<" "<<sum<<endl;
		ans += (sum*(i+1));
		// cout<<ans<<endl;
	}
	cout<<ans<<endl;
	// for (lli i=0;i<vect.size();i++)
		// {cout<<vect[i]<<endl;}
	return 0;
}