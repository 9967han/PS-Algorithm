#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int N, K;
pair<int, int> jewel[300000];
int bag[300000];
priority_queue<int> pq;
long long sum=0;

int main(){
	cin >> N >> K;
	int ci, mi, vi, res=0;
	for(int i=0; i<N; i++){
		cin >> jewel[i].first >> jewel[i].second;
	}
	for(int j=0; j<K; j++){
		cin >> bag[j];
	}

	sort(jewel, jewel+N);
	sort(bag, bag+K);
	int idx = 0;
	for(int i=0; i<K; i++){
		while(idx < N && jewel[idx].first <= bag[i]){
			pq.push(jewel[idx++].second);
		}

		if(!pq.empty()){
			sum += pq.top();
			pq.pop();
		}
	}

	cout << sum;
}