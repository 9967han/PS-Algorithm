#include<iostream>
#include<queue>
#include<string>
using namespace std;
void input();
int N;
string str;
queue<int> q;

int main(){
	input();
}

void input(){
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> str;
		if(str == "push") {
			int num;
			cin >> num;
			q.push(num);
		} else if(str == "pop") {
			if(q.empty()){
				cout << "-1" << endl;
				continue;
			}
			int deleteNum;
			deleteNum = q.front();
			q.pop();
			cout << deleteNum << endl;
		} else if(str == "size") {
			cout << q.size() << endl;
		} else if(str == "empty") {
			cout << q.empty() << endl;
		} else if(str == "front") {
			if(q.empty()) cout << "-1" << endl;
			else cout << q.front() << endl;
		} else if(str == "back") {
			if(q.empty()) cout << "-1" << endl;
			else cout << q.back() << endl;
		}
	}
}