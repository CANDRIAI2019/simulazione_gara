#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

void test(int n){
    return factorial(2*n)/(factorial(n)*factorial(n+1))
}

int main(){

    return 0;
}
