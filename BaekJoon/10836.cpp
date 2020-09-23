#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int map[1401];
    int N, M;
    cin >> N >> M;
    for(int i=1; i<=1400; i++) map[i] = 1;
    for(int i=1; i<=M; i++){
        int idx = 1;
        for(int j=0; j<=2; j++){
            int x; cin >> x;
            for(int k=0; k<x; k++, idx++) map[idx] += j; 
        }
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(j == 1) cout << map[N-i+1];
            else cout << map[N+j-1];
            cout << " ";
        }
        cout << '\n';
    }
}