#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
void DFS(int idx);
bool isCorrect(int idx);
int N, arr[11];
char map[11][11];
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            cin >> map[i][j];
        }
    }
    DFS(0);
    return 0;
}


void DFS(int idx){
    if(idx == N) {
        for(int i=0; i<N; i++) cout << arr[i] << " ";
        exit(0);
    }
    for(int i=-10; i<=10; i++){
        arr[idx] = i;
        if(isCorrect(idx)) DFS(idx+1);
    }
    return ;
}

bool isCorrect(int idx){
    int sum = 0;
    for(int i=idx; i>=0; i--){
        sum+=arr[i];
        if(map[i][idx] == '-' && sum >= 0) return false;
        if(map[i][idx] == '+' && sum <= 0) return false;
        if(map[i][idx] == '0' && sum != 0) return false;
    }
    return true;
}