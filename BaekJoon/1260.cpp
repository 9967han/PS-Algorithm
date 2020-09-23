#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
void input();
void DFS();
void BFS();
void init();


vector<int> v;
queue<int> q;
stack<int> s;

int N, M, V;
int map[10001][2] = {0};
int check[1001] = {0};


int main() {
	input();
	DFS();
	for(int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	init();
	BFS();
	for(int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
}

void input(){
	cin >> N >> M >> V;
	for(int i=1; i<=M; i++) {
		cin >> map[i][0] >> map[i][1];
	}
}

void DFS(){
	s.push(V);
	int fr;
	vector<int> a;
	while(s.size() != 0){
		fr = s.top();
		s.pop();
		if(check[fr] == 1) continue;
		check[fr] = 1;
		v.push_back(fr);
		for(int i=1; i<=M; i++) {
			if(map[i][0] == fr && !check[map[i][1]]) {
				a.push_back(map[i][1]);
			}else if(map[i][1] == fr && !check[map[i][0]]){
				a.push_back(map[i][0]);
			}
		}
		sort(a.begin(), a.end());
		for(int i=a.size()-1; i>=0; i--) {
			if(check[a[i]] == 0) s.push(a[i]);
		}
		a.clear();
	}
	return;
}

void BFS() {
	q.push(V);
	check[V] = 1;
	int fr;
	vector<int> a;
	while(q.size() != 0){
		fr = q.front();
		q.pop();
		v.push_back(fr);
		for(int i=1; i<=M; i++) {
			if(map[i][0] == fr && !check[map[i][1]]) {
				a.push_back(map[i][1]);
				check[map[i][1]] = 1; 
			}else if(map[i][1] == fr && !check[map[i][0]]){
				a.push_back(map[i][0]);
				check[map[i][0]] = 1; 
			}
		}
		sort(a.begin(), a.end());
		for(int i=0; i<a.size(); i++) q.push(a[i]);
		a.clear();
	}
	return;
}

void init() {
	for(int i=1; i<=N; i++) check[i] = 0;
	v.clear();
}