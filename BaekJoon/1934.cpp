#include<iostream>
using namespace std;

int gcd(int x, int y){
    if(y == 0) return x;
    int temp;
    if(x<y){
        temp = y;
        y = x;
        x = temp;
    }
    return gcd(y, x%y);
}

int lcm(int x, int y){
    return x*y/gcd(x,y);
}

int main(){
    int T, A, B;
    cin >> T;
    for(int i=1; i<=T; i++){
        cin >> A >> B;
        cout << lcm(A, B) << endl;
    }    
}