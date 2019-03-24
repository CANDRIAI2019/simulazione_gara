#pragma optimize ("O3")
#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using vi = vector<int>;
const int MAXN=1000000;

ifstream in{"input.txt"};
ofstream out{"output.txt"};
int n; vi h;
bitset<MAXN> cad;
vector<int> risp;

int main(){
    cad.reset();
    in>>n;
    h.resize(n);
    for(int i=0;i<n;i++)
        in>>h[i],
        h[i]--;
    h.push_back(0);
    int s1=0;
    for(int i=0;i<n;i++){
        int i0=i;
        int l=h[i]+i;
        while(i<l){
            i++;
            if(i==n){
                i--;
                break;
            }
            l=max(l,h[i]+i);
        }
        s1=(i-i0+1);
        risp.push_back(s1);
    }
    sort(risp.rbegin(),risp.rend());
    int p=0;
    for(auto r :risp){
        p+=r;
        if(p>n)break;
        out<<p<<" ";
    }

    int nPr= risp.size();
    while(nPr<n){
        nPr++;
        out<<n<<" ";
    }
    out<<endl;
    return 0;
}
