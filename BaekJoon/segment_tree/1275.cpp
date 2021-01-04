#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
struct cmd{
    int x, y, a, b;
};
vector<ll> segTree;
vector<cmd> cmdv;
ll selection_sum(int node, int st, int en, int left, int right);
void update_tree(int node, int st, int en, int idx, ll diff);
ll make_tree(int node, int st, int en);
void printTree();
int arr[100001];
int N, Q, tree_height, tree_size;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
    tree_height = (int)ceil(log2(N));
    tree_size = (1 << (tree_height + 1))+1;
    segTree.resize(tree_size);
    for(int i=1; i<=N; i++) cin >> arr[i];
    make_tree(1, 1, N);
    int x, y, a, b;
    cmdv.push_back({0, 0, 0, 0});
    for(int i=1; i<=Q; i++) {
        cin >> x >> y >> a >> b;
        cmdv.push_back({x, y, a, b});
    }
    for(int i=1; i<=Q; i++){
        x = cmdv[i].x, y = cmdv[i].y, a = cmdv[i].a, b = cmdv[i].b;
        if(x > y) swap(x, y);
        cout << selection_sum(1, 1, N, x, y) << "\n";
        ll diff = (ll)b - (ll)arr[a];
        arr[a] = b;
        update_tree(1, 1, N, a, diff);
    }
    return 0;
}

ll make_tree(int node, int st, int en){
    if(st == en) return segTree[node] = (ll)arr[st];
    int mid = (st + en)/2;
    ll left_result = make_tree(node*2, st, mid);
    ll right_result = make_tree(node*2+1, mid+1, en);
    return segTree[node] = left_result + right_result;
}

ll selection_sum(int node, int st, int en, int left, int right){
    if(right < st || left > en) return 0;
    if(left <= st && en <= right) return segTree[node];
    int mid = (st+en)/2;
    ll left_result = selection_sum(node*2, st, mid, left, right);
    ll right_result = selection_sum(node*2+1, mid+1, en, left, right);
    return left_result+right_result;
}

void update_tree(int node, int st, int en, int idx, ll diff){
    if(idx < st || idx > en) return;
    segTree[node] += diff;
    if(st != en) {
        int mid = (st+en)/2;
        update_tree(node*2, st, mid, idx, diff);
        update_tree(node*2+1, mid+1, en, idx, diff);
    }
    return;
}

void printTree(){
    for(int i=1; i<tree_size; i++){
        cout << segTree[i] << " ";
    }
    cout << endl;
    return;
}