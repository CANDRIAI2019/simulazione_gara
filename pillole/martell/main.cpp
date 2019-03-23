#include <fstream>
#include <string>
#include <iostream>

using namespace std;

long long int ris[1000][1000];
long long int f(int i, int m) {
    if (ris[i][m] != -1) {
        return ris[i][m];
    }
    if((i==1)&&(m==0)) {
        ris[1][0] = 1;
        return 1;
    }
    if((i==0)&&(m==0)){
        ris[0][0] = 1;
        return 1;
    }
    if(m==0) {
        return f(i-1,m+1);
    }
    if(i==0) {
        return f(0,m-1);
    }

    ris[i][m] = f(i-1,m+1)+f(i,m-1);
    return f(i-1,m+1)+f(i,m-1);
}


int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    in>>n;
    for(int i=0;i<1000;i++) {
        for(int j=0;j<1000;j++) {
            ris[i][j] = -1;
        }
    }
    
    cout<<f(n,0);
    out<<f(n,0);



    return 0;
}
