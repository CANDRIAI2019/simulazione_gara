#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define pii pair<int, int>
#ifdef taulants_mbp
#define in cin
#define out cout
#else 
ifstream in("input.txt");
ofstream out("output.txt");
#endif

ll memo[31][31];

ll func(int i, int m){
	if(memo[i][m]) return memo[i][m];
	if(i==1 && m==1) return memo[i][m]=1;
	if(!i) return memo[i][m]=1;
	if(i==m) return memo[i][m]=func(i-1, m);
	return memo[i][m]=func(i-1, m) + func(i, m-1);
}

int main(){
	int n; in >> n;
	ll ans=func(n, n);
	out << ans;
	return 0;
}
