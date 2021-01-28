#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int N, map[4000001];
vector<int> v;
int main(){
    memset(map, 0, sizeof(map));
    cin >> N;
    for(int i=2; i<=sqrt(N); i++){
        for(int j=i+i; j<=N; j+=i){
            map[j] = 1;
        }
    }

    for(int i=2; i<=N; i++){
        if(!map[i]) v.push_back(i);
    }
    
    int low, high, sum = 0, ans = 0;
    while(low <= high && low < v.size() && high <= v.size()){
        if(sum < N){
            sum+=v[high];
            high++;
        } else {
            if(sum == N) ans++; 
            sum-=v[low];
            low++;
        }
    }
    cout << ans;
    return 0;
}