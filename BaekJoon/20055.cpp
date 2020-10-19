#include<iostream>
#include<algorithm>
using namespace std;
struct bottom{
    int num;
    int person;
};
bottom map[201], temp[201];
int cnt=0, N, K, x;
int main(){
    cin >> N >> K;
    for(int i=1; i<=2*N; i++){
        cin >> map[i].num;
        map[i].person = 0;
    }
    for(int t=1;;t++){
        //Step 1
        temp[1] = map[2*N];
        for(int i=2; i<=2*N; i++) temp[i] = map[i-1];
        for(int i=1; i<=2*N; i++) map[i] = temp[i];
        if(map[N].person) map[N].person = 0;
        
        //Step 2
        for(int i=N-1; i>=1; i--) {
            if(map[i].person) {
                if(!map[i+1].person && map[i+1].num >= 1) {
                    map[i+1].person = map[i].person;
                    map[i+1].num--;
                    if(map[i+1].num == 0) cnt++;
                    map[i].person = 0;
                }
            }
        }
        if(map[N].person) map[N].person = 0;

        //Step 3
        if(map[1].num >= 1 && !map[1].person) {
            map[1].person = 1;
            map[1].num--;
            if(map[1].num == 0) cnt++;
        }

        //Step 4
        if(cnt >= K) {
            cout << t;
            return 0;
        }
    }
    return 0;
}

