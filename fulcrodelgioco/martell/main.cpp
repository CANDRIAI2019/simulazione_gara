#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > gioc;
bool visited[11]={0};
int persi[11]={0};

int visita (int n, int xx) {
    visited[n]=true;

    int t;
    for (int i=0; i<gioc[n].size(); i++){
        t=gioc[n][i];
        if (!visited[t] && t!=xx)
            visita(t, xx);
    }
}

int main () {

    ifstream in ("input.txt");
    ofstream out ("output.txt");

    gioc.resize(11);
    int a,b,c;
    in>>a;
    for (int i=0; i<a; i++){
        in>>b;
        in>>c;
        gioc[b-1].push_back(c-1); //indici giocatori da 0 a 10
    }

    persi[0]=0;
    for (int i=1; i<11; i++) { //0 non lo toglie
        
        for (int k=0; k<11; k++) visited[k]=false; //prima di iniziare visita iniz a zero
        visita(0, i); //portiere=0          togliendo giocatorre i visita gioc
        for (int j=0; j<11; j++)            //avendo visitato dimmi quanti non sono stati visitati
            if (!visited[j]) persi[i]++;
    }


    //chi perde più giocatori
    int maxx=0, pos=0;
    for (int i=1; i<11; i++)  {
        if (persi[i]>maxx) {
            maxx=persi[i];
            pos=i;
        }
    }

    out<<pos+1;
}
