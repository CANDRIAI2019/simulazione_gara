#pragma optimize ("O3")
#include <bits/stdc++.h>
#include "grader.cpp"
using namespace std;

//int N;
//long long L, maxk, D[],P[];

long long pn(int index){
    if(index==N-1) return L-D[index];
    return min(P[index],
               pn(index)+D[index+1]-D[index]
               );

}



long long percorri(int N, long long L, long long D[], long long P[]){
    ::N=N; ::L=L; ::D=D; ::P = P;
    long long k=D[0],p,d,maxk=D[0];
    int indice=0;
    for(int i=0;i<N;i++){
        p = P[i];
        d = i<N-1?D[i+1]-D[i]:L-D[i];
        //cout<<i<<"° k="<<k<<" d="<<d<<" p="<<p<<" maxk="<<maxk<<endl;

        if (k+d+pn(indice)<max(k+p,p+d+pn(indice))){
            maxk=max(maxk,k+d);
            k+=d;
            //cout<<"\t s"<<endl;
        } else {
            maxk=max(maxk,max(k+p,p+d));
            k=p+d;
            //cout<<"\t NOs"<<endl;
        }
        indice++;
    }
    return maxk;
}
