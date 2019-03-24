#pragma optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
using si = int;

ifstream fin{"input.txt"};
ofstream fout{"output.txt"};
vector<si> d,res;
si N,sum,i=-1;

si group(si& i){
    si power=d[i]-1,c=1;
    while(power>=1 && i<N){
        power=max(d[++i],power)-1;
        if(i<N) c++;
    }
    return c;
}

main(){
    fin>>N;
    d.resize(N);
    for (auto& el : d) fin>>el;
    while(i<N-1) res.push_back(group(++i));
    sort(res.rbegin(),res.rend());
    res.resize(N,0);
    for (auto& el : res) fout<<(sum+=el)<<" ";
    fout<<endl;
}
