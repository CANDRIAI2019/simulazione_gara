#pragma optimizer("O3")
#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define MAXN 1000000


#ifndef in
ifstream in ("input.txt");
#endif
#ifndef out
ofstream out ("output.txt");
#endif
int n;
vi h;
bitset<MAXN> cad;
vector<int> risp;

int main(){
    cad.reset();
    in>>n;
    h.resize(n);
    for(int i=0;i<n;i++){
        in>>h[i];
        h[i]--;
    }
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
