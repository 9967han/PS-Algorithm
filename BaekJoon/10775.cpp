#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool unite(int x);
int find(int x);
int G, P, x, ans=0, parent[100001];
int main(){
    memset(parent, -1, sizeof(parent));
    cin >> G >> P;
    for(int i=1; i<=P; i++){
        cin >> x;
        if(unite(x)) ans++;
        else break;
    }
    cout << ans;
    return 0;
}

int find(int x){
    if(parent[x] < 0) return x;
    else return parent[x] = find(parent[x]);
}

bool unite(int x) {
    int px = find(x); // 앉을 자리
    if(px == 0) return false;
    parent[px] = find(px-1);
    return true;
}