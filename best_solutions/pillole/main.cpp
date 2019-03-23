#pragma optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
using ui = unsigned int;

constexpr ui operator"" _(const unsigned long long int v) {return v;}

ull binomialCoeff(ui n, ui k){
    ull r=1;
    if (k>n-k) k=n-k;
    for (auto i=0_;i<k;++i)
        r*=(n-i),
        r/=(i+1);
    return r;
}
ull catalan(ui n) { return binomialCoeff(2*n, n)/(n+1); }
// Con Python avrebbe fatto 100%
/*unsigned long long catnumber(int n){
     double ans = 1;
    for (int k=2;k<n+1;k++)
        ans=ans*(n+k)/k;
    return ans;
}*/
ifstream fin{"input.txt"};
ofstream fout{"output.txt"};
template<class T> T input(istream& is) { T t; is >> t; return t; };
main(){ fout<<catalan(input<ui>(fin))<<endl; }
