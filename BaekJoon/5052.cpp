#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

void input();
void print();

int t, N;
string s;
vector<string> v[51];

int main() {
	input();
	print();
}

void input() {
	cin >> t;
	for(int i=1; i<=t; i++) {
		cin >> N;
		for(int j=1; j<=N; j++) {
			cin >> s;
			v[i].push_back(s);
		}
	}
}

void print(){
	for(int i=1; i<=t; i++) {
		int flag = 0;
		sort(v[i].begin(), v[i].end());
		for(int j=0; j<v[i].size()-1; j++){
			int curlen = v[i][j].length();
			int nextlen = v[i][j+1].length();
			if(curlen > nextlen) continue;
			if(strncmp(v[i][j].c_str(), v[i][j+1].c_str(), curlen) == 0) {
				flag = 1;
				break;
			}
		}
		if(flag == 1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}