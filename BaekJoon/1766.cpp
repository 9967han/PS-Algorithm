#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void input();
void trace(int x);
void pushZero();

int N, M;
int check[32001];
int map[100001][2];
priority_queue<int, vector<int>, greater<int> > pq;
vector<int> v;
int main(){
	input();
	while(1) {
		int cnt = 0;
		for(int i=1; i<=N; i++){
			if(check[i] == -1) cnt++;
		}
		if (cnt == N) break;
		else {
			pushZero();
		}
	}
	for(int i=0; i<v.size(); i++){
		cout << v[i] << ' ';
	}
}

void input(){
	cin >> N >> M;
	for(int i=1; i<=M; i++){
		cin >> map[i][0] >> map[i][1];
		check[map[i][1]]++;
	}
}

void pushZero(){
	for(int i=1; i<=N; i++){
		if(check[i] == 0) {
			trace(i);
			check[i] = -1;
			break;
		}
	}
}

void trace(int x){
	pq.push(x);
	int a;
	while(pq.size() != 0){
		a = pq.top();
		pq.pop();
		for(int i=1; i<=M; i++){
			if(map[i][0] == a && check[map[i][1]] == 1) {
				check[map[i][1]] = -1;
				pq.push(map[i][1]);
			} else if(map[i][0] == a) {
				check[map[i][1]]--;
			}
		}
		v.push_back(a);
	}
	// cout << "end" << endl;
}
