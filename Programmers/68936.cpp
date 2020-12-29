#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> getNum(int sx, int sy, int ex, int ey, int n);
int map[1025][1025];

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    for(int i=1; i<=arr.size(); i++){
        for(int j=1; j<=arr.size(); j++){
            map[i][j] = arr[i-1][j-1];
        }
    }
    answer = getNum(1, 1, arr.size(), arr.size(), arr.size());
    return answer;
}

vector<int> getNum(int sx, int sy, int ex, int ey, int n){
    vector<int> res;
    bool flag = false;
    int first = map[sx][sy];
    for(int i=sx; i<=ex; i++){
        for(int j=sy; j<=ey; j++){
            if(first != map[i][j]) flag = true;
        }
    }
    if(!flag){
        if(first) {
            res.push_back(0);
            res.push_back(1);
        } else {
            res.push_back(1);
            res.push_back(0);
        }
        return res;
    }
    int zeroNum = 0, oneNum = 0;
    zeroNum += getNum(sx, sy, sx+n/2-1, sy+n/2-1, n/2)[0]; // 1,1 ~ 4,4
    oneNum += getNum(sx, sy, sx+n/2-1, sy+n/2-1, n/2)[1]; 
    
    zeroNum += getNum(sx+n/2, sy+n/2, ex, ey, n/2)[0]; // 5,5~8,8
    oneNum += getNum(sx+n/2, sy+n/2, ex, ey, n/2)[1];
    
    zeroNum += getNum(sx, sy+n/2, sx+n/2-1, ey, n/2)[0]; //1,5~4,8
    oneNum += getNum(sx, sy+n/2, sx+n/2-1, ey, n/2)[1];
    
    zeroNum += getNum(sx+n/2, sy, ex, sy+n/2-1, n/2)[0]; //5,1~8,4
    oneNum += getNum(sx+n/2, sy, ex, sy+n/2-1, n/2)[1]; 
    
    res.push_back(zeroNum);
    res.push_back(oneNum);
    return res;
}