#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void input();
void print();
int N;
vector<pair<int, int> > v;
int s[100001];
int f[100001];
int main(){
	input();
	sort(v.begin(), v.end());
	int cnt = 0, curTime = 0;
	for(int i=0; i<v.size(); i++){
		if(v[i].first >= curTime && v[i].second >= curTime){ // 끝나는 시간이 
			curTime = v[i].first;
			cnt++;
		}
	}
	cout << cnt;
	// print();
}

void input(){
	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> s[i] >> f[i];
		v.push_back(make_pair(f[i], s[i]));
	}
}

void print(){
	for(int i=0; i<v.size(); i++){
		cout << v[i].first << " " << v[i].second << endl;
	}
}