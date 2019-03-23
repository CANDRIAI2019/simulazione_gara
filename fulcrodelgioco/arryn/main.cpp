#pragma optimize ("O3")
#include <bits/stdc++.h>
//#include "grader.cpp"
using namespace std;

constexpr int MAXG=11;
int M,tmp1,tmp2;
vector<vector<int>> ad;
ifstream fin("input.txt");
ofstream fout("output.txt");

vector<bool> ra;

void passa(int g, int d){
    for(int i=0;i<ad[g].size();i++){
        int ric=ad[g][i];
        if(ra[ric]==false && ric!=d){
            ra[ric]=true;
            //cout<<" # "<<g+1<<" -> "<<ric+1<<endl;
            passa(ric,d);
        }
    }
}

int test(){
    int maxc=0, ret=0;
    for (int i=1;i<MAXG;i++){
        int sum=0;
        for (auto n : ra)
            n = false;
        //cout<<"Escludo il n "<<i+1<<endl;
        passa(0,i);

        for (auto n : ra)
            sum += n;
        sum=MAXG-sum;
        //cout<<"> il mio max è "<<maxc<<" e ho trovato "<<sum<<endl;
        if(maxc<sum) maxc=sum, ret=i;
    }
    return ret+1;
}

int main(){
    fin>>M;
    ad.resize(MAXG);
    ra.resize(MAXG);
    for(int i=0;i<M;i++)
        fin>>tmp1>>tmp2,
        ad[tmp1-1].push_back(tmp2-1);
    /*for(auto l:ad){
        for(auto r:l)
            cout<<r+1<<" ";
        cout<<endl;
    }*/
    fout<<test()<<endl;
    return 0;
}
