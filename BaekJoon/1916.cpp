#include<iostream>
#include<algorithm>
#include<queue>
#define INF 987654321
using namespace std;
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
vector<pair<int, int> > arr[1001];
int dist[1001];
int N, M, st, en, cur;
int main(){
	cin >> N >> M;
	for(int i=1; i<=M; i++){
		int from, to, cost;
		cin >> from >> to >> cost;
		arr[from].push_back(make_pair(cost, to));
	}
	cin >> st >> en;
	
	fill(dist, dist+1002, INF);

	q.push(make_pair(0, st));
	dist[st] = 0;
	
	while(!q.empty()){
		int cur = q.top().second;
		q.pop();

		for(int i=0; i<arr[cur].size(); i++){
			int cost = arr[cur][i].first;
			int next = arr[cur][i].second;

			if(dist[next] > dist[cur] + cost){
				dist[next] = dist[cur] + cost;
				q.push(make_pair(dist[next], next));
			}
		}
	}

	cout << dist[en];
}