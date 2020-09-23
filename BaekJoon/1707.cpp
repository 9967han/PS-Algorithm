#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void DFS(int from, int color);
bool isBipartiteGraph();
void init();
int nodeColor[20001];
vector<int> v[20001];
int K, V, E;
int main(){
	int from, to;
	cin >> K;
	for(int i=1; i<=K; i++){
		init();
		cin >> V >> E;
		for(int j=1; j<=E; j++){
			cin >> from >> to;
			v[from].push_back(to);
			v[to].push_back(from);
		}

		for(int j=1; j<=V; j++){
			if(!nodeColor[j]) DFS(j, 1);
		}
		
		if(isBipartiteGraph()) cout << "YES" << endl;
		else cout << "NO" << endl; 

	}
}

void DFS(int from, int color){
	nodeColor[from] = color;
	for(int i=0; i<v[from].size(); i++){
		int to = v[from][i];
		if(!nodeColor[to]) DFS(to, 3-color);
	}
	return;
}

bool isBipartiteGraph(){
	for(int i=1; i<=V; i++){
		for(int j=0; j<v[i].size(); j++){
			if(nodeColor[v[i][j]] == nodeColor[i]) return false;
		}
	}
	return true;
}	

void init(){
	for(int i=0; i<=20000; i++){
		nodeColor[i] = 0;
	}
	for(int i=0; i<=20000; i++){
		v[i].clear();
	}
}