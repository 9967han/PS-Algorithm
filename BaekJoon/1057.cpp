#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int N, x, y, temp, turn=1;
	cin >> N >> x >> y;
    if(x > y) {
        temp = y;
        y = x;
        x = temp;
    } // x < y로 설정
	while(1){
        if(y-x == 1){
            if(x%2 == 1 && (x/2 == (y/2-1))) break;
        } 
        turn++;
        if(x % 2 == 1) {
            x /= 2;
            x++;
        } else if(x % 2 == 0) {
            x /= 2;
        }
        if(y % 2 == 1) {
            y /= 2;
            y++;
        } else if(y % 2 == 0) {
            y /= 2;
        }
    }
    cout << turn;
}

