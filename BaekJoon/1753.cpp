#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define MAX 987654321
#define PAIR pair<int, int>
void dijkstra();
int V, E, start;
int u, v, w;
vector<PAIR> edges[20001];
int d[20001];

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(0); 

	cin >> V >> E >> start;
	for(int i=1; i<=V; i++){
		d[i] = MAX;
	}
	for(int i=1; i<=E; i++) {
		cin >> u >> v >> w;
		edges[u].push_back(make_pair(v, w));
	}
	d[start]=0;

	dijkstra();

	for(int i=1; i<=V; i++){
		if (d[i] == MAX) cout << "INF" << endl;
		else cout << d[i] << endl;
	}
}

void dijkstra(){
    priority_queue<PAIR, vector<PAIR >, greater<PAIR > > pq;
	pq.push(make_pair(0, start));
	while(!pq.empty()){
		int cost = pq.top().first;
		int curVertex = pq.top().second;
		pq.pop();

		if(d[curVertex] < cost) continue;

		for(int i=0; i<edges[curVertex].size(); i++){
			int neighbor = edges[curVertex][i].first;
			int neighborDs = d[curVertex] + edges[curVertex][i].second;
			if(d[neighbor] > neighborDs) {
				d[neighbor] = neighborDs;
				pq.push(make_pair(neighborDs, neighbor));
			}
		}
	}
}