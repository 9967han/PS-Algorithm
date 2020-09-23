#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int N, M;
int order[2][100001];
int student[32001]; 
priority_queue<int, vector<int>, greater<int> > pq;

int main(){
	cin >> N >> M;
	for(int i=1; i<=M; i++){
		cin >> order[0][i] >> order[1][i];
		student[order[1][i]]++;
	}

	for(int i=1; i<=N; i++){
		if(student[i] == 0) pq.push(i);
	}

	while(!pq.empty()){
		int a = pq.top(); pq.pop();
		for(int i=1; i<=M; i++){
			if(order[0][i] == a) {
				student[order[1][i]]--;
				if(student[order[1][i]] == 0) pq.push(order[1][i]);
			}
		} 
		cout << a << " ";
	}
}