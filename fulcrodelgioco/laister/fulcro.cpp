#pragma optimizer("O3")
#include<bits/stdc++.h>
using namespace std;
#define PB push_back
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
int n,a,b;
vector<int> ad[12];
bitset<12> coll;

int dfs(int senza,int p){
    if(coll[p] or p==senza)return 0;
    coll[p]=true;
    int c=1;
    for(auto v : ad[p]){
        c+=dfs(senza,v);
    }
    return c;
}

/*
int bfs(int senza){
    queue<int> q;

    coll.reset();
    q.push(1);

    while(!q.empty()){
        int curr=q.front();
        q.pop();
        if(curr==senza)continue;

        for(auto v : ad[curr]){
            if(!coll[v]){
                coll[curr]=true;
                q.push(v);
            }
        }
    }
    return coll.count()-1;
}*/

int main(){
    in>>n;
    int f=-3, bf=15;
    while(--n){
        in>>a>>b;
        ad[a].PB(b);
    }
    for(int i=2;i<=11;++i){
        coll.reset();
        int tmp=dfs(i,1);//bfs(i);
        //cout<<i<<" "<<tmp<<endl;
        if(tmp<bf){
            bf=tmp;
            f=i;
        }
    }
    out<<f<<endl;
    return 0;
}
