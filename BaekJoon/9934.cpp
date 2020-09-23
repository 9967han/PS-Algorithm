#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int main(){
    vector<int> v[11];
    int K, node[1025];
    cin >> K;
    for(int i=1; i<=pow(2, K)-1; i++){
        cin >> node[i];
        int rest = i, lev = 1;
        while(! (rest % 2)) {
            rest /= 2;
            lev++;
        }
        v[lev].push_back(node[i]);
    }
    for(int i=K; i>=1; i--){
        for(int j=0; j<v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}