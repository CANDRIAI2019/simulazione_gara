#include <bits/stdc++.h>

using namespace std;

int main(){

    ifstream in;
    in.open("input.txt");
    ofstream out;
    out.open("output.txt");

    int M;
    in>>M;
    vector<int> S(12, 0);
    forward_list<int> adj[12];
    int T1, T2;

    for(int i=0; i<M; ++i){
        in>>T1>>T2;
        adj[T1].push_front(T2);
    }

    for(int i=2; i<12; ++i){
        vector<bool> V(12, false);
        queue<int> BFS;
        BFS.push(1);
        while(!BFS.empty()){
            int v=BFS.front();
            BFS.pop();
            if(!V[v]){
                V[v]=true;
                for(auto& it : adj[v]) {
                    if(it!=i){
                        BFS.push(it);
                    }
                }
            }
        }
        //cout<<"Levando il giocatore: "<<i<<' ';
        for(int j=2; j<12; ++j){
            S[i]+=int(!V[j]);
            //cout<<j<<'-'<<V[j]<<' ';
        }
        //cout<<'\n';*/
    }

    /*for(int i=2; i<12; ++i){
        cout<<S[i]<<' ';
    }
    cout<<'\n';*/
    int sol=2;

    for(int i=3; i<12; ++i){
        if(S[i]>S[sol])
            sol=i;
    }

    out<<sol;
    return 0;
}