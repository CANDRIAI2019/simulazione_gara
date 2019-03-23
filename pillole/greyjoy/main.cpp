#include <fstream>
#include <iostream>

using namespace std;

int N;
long long mat[32][64];		//righe=intere colonne=mezze

long long pil(int M, int I){
	if (mat[I][M] == -1) {
		if(I==0)
			return mat[I][M] =1;
		
		if(M==0)
			return mat[I][M] =pil(M+1, I-1);
		
		return mat[I][M] =pil(M+1, I-1) + pil(M-1, I);
	}
	else {
		return mat[I][M];
	}
}

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N;
	
	
	for(int i=0; i<32; i++)
		for(int j=0; j<64; j++)
			mat[i][j] = -1;
	out << pil(0, N);

	
}
