#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void Union(int x, int y);
bool isSameParent(int x, int y);
int getParent(int x);
int parent[1001];
vector<pair<int, pair<int, int> > > v;
int N, M;
int main(){
	cin >> N >> M;
	for(int i=1; i<=M; i++){
		int from, to, cost;
		cin >> from >> to >> cost;
		v.push_back(make_pair(cost, make_pair(from, to)));
	}

	sort(v.begin(), v.end());

	for(int i=1; i<=N; i++){
		parent[i] = i;
	}

	int ans = 0;
	for(int i=0; i<v.size(); i++){
		int cost = v[i].first;
		int from = v[i].second.first;
		int to = v[i].second.second;
		if(!isSameParent(from, to)){
			ans += cost;
			Union(from, to);
		}
	}
	cout << ans;
}

int getParent(int x){
	if(parent[x] == x) return x;
	else return parent[x] = getParent(parent[x]);
}


bool isSameParent(int x, int y){
	x = getParent(x);
	y = getParent(y);
	if(x == y) return true;
	else return false;
}

void Union(int x, int y){
	x = getParent(x);
	y = getParent(y);
	if(x != y) parent[y] = x;
	return ;
}