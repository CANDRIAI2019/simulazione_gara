#pragma optimizer("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;


#ifndef in
ifstream in ("input.txt");
#endif
#ifndef out
ofstream out ("output.txt");
#endif
#define MAXN 31
int N;
ll memo[MAXN][MAXN];

ll prova(int intere, int meta){
    if(memo[intere][meta]==-1){
        memo[intere][meta]=prova(intere-1,meta+1);
        if(meta>0)memo[intere][meta]+=prova(intere,meta-1);
    }
    return memo[intere][meta];
}

int main(){
    in>>N;
    for(int i=0;i<=N;++i){
        memo[0][i]=1;
        for(int j=1;j<=N;++j){
            memo[j][i]=-1;
        }
    }
    out<<prova(N,0)<<endl;
    return 0;
}
