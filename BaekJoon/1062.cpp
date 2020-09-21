#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
void printMap();
void input();
void DFS(int idx, int cnt);
int N, K, ans = 0;
int map[51][16];
int visit[27];
vector<int> v;
int main(){
	input();
	if(K >= v.size()) {
		cout << N;
		return 0;
	}else if(K < 5) {
		cout << "0";
		return 0;
	}
	visit[1] = 1;
	visit[14] = 1;
	visit[20] = 1;
	visit[9] = 1;
	visit[3] = 1;
	DFS(0, 0);
	cout << ans;
}

void DFS(int idx, int cnt){
	if(cnt == K-5){
		int sum = 0;
		for(int i=1; i<=N; i++){
			int flag = 0;
			for(int j=1; j<=map[i][0]; j++){
				if(!visit[map[i][j]]) {
					flag = 1;
					break;
				}
			}
			if(!flag) sum++;
		}
		ans = max(ans, sum);
		return;
	}

	for(int i=idx; i<v.size(); i++){
		if(visit[v[i]]) continue;
		visit[v[i]] = 1;
		DFS(i, cnt+1);
		visit[v[i]] = 0;
	}
}

void input(){
	cin >> N >> K;
	string str;
	for(int i=1; i<=N; i++){
		cin >> str;
		map[i][0] = str.size();
		for(int j=0; j<str.size(); j++){
			map[i][j+1] = str[j] - 'a' + 1;
			if(!visit[map[i][j+1]]) v.push_back(map[i][j+1]);
			visit[map[i][j+1]] = 1;
		}
	}
	memset(visit, 0, sizeof(visit));
	return;
}

void printMap(){
	cout << endl;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=map[i][0]; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return;
}