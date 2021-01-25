#include<iostream>
#include<algorithm>
using namespace std;
void unite(int x, int y);
int find(int x);
int N, M;
int p[201], plan[1001], map[201][201];
int main(){
    cin >> N >> M;
    for(int i=1; i<=N; i++) p[i] = i;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
            if(map[i][j]) unite(i, j);
        }
    }
    int flag;
    cin >> flag;
    flag = find(flag);
    for(int i=1; i<M; i++) {
        cin >> plan[i];
        if(find(plan[i]) != flag) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y) p[x] = y;
    return;
}

int find(int x){
    if(x == p[x]) return x;
    return find(p[x]);
}