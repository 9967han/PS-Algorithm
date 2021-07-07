#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int N;
string getMin(string A, string B);
string maxdp[101], mindp[101];
// 성냥개비
// 2개 : 1
// 3개 : 7
// 4개 : 4
// 5개 : 2, 3, 5
// 6개 : 6, 9, 0
// 7개 : 8
int main(){
    cin >> N;
    maxdp[2] = "1", maxdp[3] = "7";
    for(int i=4; i<=100; i++) maxdp[i] = maxdp[i-2] + "1";
    mindp[2] = "1", mindp[3] = "7", mindp[4] = "4", mindp[5] = "2", mindp[6] = "6", mindp[7] = "8", mindp[8] = "10", mindp[9] = "18";
    for(int i=10; i<=100; i++){
        mindp[i] = "999999999999999999";
        mindp[i] = getMin(mindp[i], mindp[i-2]+"1");
        mindp[i] = getMin(mindp[i], mindp[i-3]+"7");
        mindp[i] = getMin(mindp[i], mindp[i-4]+"4");
        mindp[i] = getMin(mindp[i], mindp[i-5]+"2");
        mindp[i] = getMin(mindp[i], mindp[i-6]+"0");
        mindp[i] = getMin(mindp[i], mindp[i-7]+"8");
    }
    int tmp;
    for(int i=1; i<=N; i++){
        cin >> tmp;
        cout << mindp[tmp] << " " << maxdp[tmp] << '\n';
    }
    
}

string getMin(string A, string B){
    if(A.size() > B.size()) return B;
    else if(A.size() < B.size()) return A;
    else return min(A, B);
}