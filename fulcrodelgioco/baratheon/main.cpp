#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define pii pair<int, int>
#ifdef taulants_mbp
#define in cin
#define out cout
#else 
ifstream in("input.txt");
ofstream out("output.txt");
#endif

vector<int> graph[12];
bool vis[12];
int visited;
int min_vis=11;
int min_player=0;

void dfs(int i, int locked){
	vis[i]=1;
	for(int j:graph[i]) if(vis[j]==0 && j!=locked) dfs(j, locked);
}

int main(){
	int m; in >> m;
	for(int i=0; i<m; ++i){
		int a, b; in >> a >> b;
		graph[a].pb(b);
	}
	for(int rm=2; rm<=11; ++rm){
		visited=0;
		for(int i=0; i<=11; ++i) vis[i]=0;
		dfs(1, rm);
		for(int i=2; i<12; ++i) if(vis[i]) ++visited;
		if(visited<min_vis){
			min_vis=visited;
			min_player=rm;
		}
	}
	out << min_player << endl;
	return 0;
}
