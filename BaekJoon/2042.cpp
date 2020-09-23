#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
long long init(long long arr[], vector<long long> &tree, int node, int start, int end);
void update(vector<long long> &tree, int node, int start, int end, int idx, int diff);
long long sum(vector<long long> &tree, int node, int left, int right, int start, int end);
int N, M, K, flag=0;
int main(){
	int idx, left, right;
	long long changeNum;
	long long arr[1000001];
	cin >> N >> M >> K;
	for(int i=1; i<=N; i++){
		cin >> arr[i];
	}
	vector<long long> tree(N+1);
	init(arr, tree, 1, 1, N);
	for(int i=1; i<=M+K; i++){
		cin >> flag;
		if(flag == 1) { //update
			cin >> idx >> changeNum;
			long long diff = arr[idx] - changeNum;
			update(tree, 1, 1, N, idx, diff);
		} else { //sum
			cin >> left >> right;
			cout << sum(tree, 1, left, right, 1, N);
		}
	}
}
long long init(long long arr[], vector<long long> &tree, int node, int start, int end){
	if(start == end) return tree[node] = arr[start];
	else return tree[node] = init(arr, tree, node*2, start, (start+end)/2) + init(arr, tree, node*2+1, (start+end)/2+1, end);
}

void update(vector<long long> &tree, int node, int start, int end, int idx, int diff){
	if(idx > end || start > idx) return;
	tree[node] += diff;
	if(start != end){
		update(tree, node*2, start, (start+end)/2, idx, diff);
		update(tree, node*2+1, (start+end)/2+1, end, idx, diff);
	}	
	return;
}

long long sum(vector<long long> &tree, int node, int left, int right, int start, int end){
	if(left > end || start > right) return 0;
	if(left <= start && end <= right) return tree[node];
	return sum(tree, node*2, left, right, start, (start+end)/2) + sum(tree, node*2+1, left, right, (start+end)/2+1, end);
}