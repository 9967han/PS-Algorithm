#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
using namespace std;
set<string> s;
vector<string> v;
int N, M;
int main(){
	cin >> N >> M;
	string str;
	for(int i=1; i<=N; i++){
		cin >> str;
		s.insert(str);
	}
	for(int j=1; j<=M; j++){
		cin >> str;
		if(s.find(str) != s.end()) v.push_back(str);
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for(int i=0; i<v.size(); i++) {
		cout << v[i] << endl;
	}
}