#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
typedef long long ll;
using namespace std;
void update(vector<ll> &tree, int node, int start, int end, int idx, ll diff);
ll sum(vector<ll> &tree, int node, int left, int right, int start, int end);
ll init(ll arr[], vector<ll> &tree, int node, int start, int end);
ll arr[1000001];
vector<ll> tree;
int N, M, K, flag=0;
int main(){
	ll changeNum;
	cin >> N >> M >> K;
	for(int i=1; i<=N; i++) cin >> arr[i];
	tree.resize(4*N+1);
	init(arr, tree, 1, 1, N);
    ll idx, left, right;
	for(int i=1; i<=M+K; i++){
		cin >> flag;
		if(flag == 1) { //update
			cin >> idx >> changeNum;
			ll diff = changeNum - arr[idx];
            arr[idx] = changeNum;
			update(tree, 1, 1, N, idx, diff);
		} else { //sum
			cin >> left >> right;
			cout << sum(tree, 1, left, right, 1, N) << '\n';
		}
	}
    return 0;
}

ll init(ll arr[], vector<ll> &tree, int node, int start, int end){
	if(start == end) return tree[node] = arr[start];
	else return tree[node] = init(arr, tree, node*2, start, (start+end)/2) + init(arr, tree, node*2+1, (start+end)/2+1, end);
}

void update(vector<ll> &tree, int node, int start, int end, int idx, ll diff){
	if(idx > end || start > idx) return;
	tree[node] += diff;
	if(start != end){
		update(tree, node*2, start, (start+end)/2, idx, diff);
		update(tree, node*2+1, (start+end)/2+1, end, idx, diff);
	}	
	return;
}

ll sum(vector<ll> &tree, int node, int left, int right, int start, int end){
	if(left > end || start > right) return 0;
	if(left <= start && end <= right) return tree[node];
	return sum(tree, node*2, left, right, start, (start+end)/2) + sum(tree, node*2+1, left, right, (start+end)/2+1, end);
}