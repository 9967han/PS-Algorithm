#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
void getPostOrder(int st, int en);
int tree[10001];

int main(){
    memset(tree, 0, sizeof(tree));
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x, en=1;
    while(!cin.eof()){
        cin >> x;
        tree[en++] = x;
    }
    en-=2;
    getPostOrder(1, en);
    return 0;
}

void getPostOrder(int st, int en){
    if(st > en) return;
    if(st == en) {
        cout << tree[st] << " ";
        return;
    }
    int idx = st+1;
    for(int i=idx; i<=en; i++){
        if(tree[i] > tree[st]) {
            idx = i;
            break;
        }  
    }   
    getPostOrder(st+1, idx-1);
    getPostOrder(idx, en);
    cout << tree[st] << " ";
    return;
}