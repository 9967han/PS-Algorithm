#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool sameParent(int x, int y);
int findParent(int x);
void Union(int x, int y);
int parent[10001];
vector<pair<int, pair<int, int> > > v;

int main(){
	int V, E;
	int st, en, edge, answer = 0;
	cin >> V >> E;
	for(int i=1; i<=E; i++){
		cin >> st >> en >> edge;
		v.push_back(make_pair(edge, make_pair(st, en)));
	}

	sort(v.begin(), v.end());

	for(int i=1; i<=V; i++){
		parent[i] = i;
	}

	for(int i=0; i<E; i++){
		int cost = v[i].first;
		int from = v[i].second.first;
		int to = v[i].second.second;
		if(!sameParent(from, to)){
			Union(from, to);
			answer += cost;
		}
	}
	cout << answer;
}

bool sameParent(int x, int y){
	x = findParent(x);
	y = findParent(y);
	if(x == y) return true;
	else return false;
}

int findParent(int x){
	if(parent[x] == x) return x;
	else {
		return parent[x] = findParent(parent[x]);
	}
}

void Union(int x, int y){
	x = findParent(x);
	y = findParent(y);
	if(x != y) parent[y] = x;
	return;
}