#pragma optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

int N,M;
ifstream fin{"input.txt"}
ofstream fout{"output.txt"}
vector<vector<int>> ad, iad;
vector<int> lose, risp;

void spread(int p,int v){
    if(risp[p]==0){
        for(auto near : iad[p])
            spread(p,-1*v)
    }
}

main(){
    fin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;
        fin>>a>>b;
        ad[a].push_back(b); // adiacenza
        iad[b].push_back(a); // adiacenza invertita
    }

    for(int i=0;i<N;i++) // trovo nodi persi
        if (ad[i].size()==0)
            lose.push_back(i);

    for(auto los : lose)
        spread(los,-1);
}
