#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool isTicTakTo(string str);
bool isPossible(int c);
int map[3][3];
string str;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(1){
        cin >> str;
        if(!str.compare("end")) break;
        if(isTicTakTo(str)) cout << "valid\n";
        else cout << "invalid\n";
    }
    return 0;
}

bool isTicTakTo(string str){
    int Ocnt=0, Xcnt=0, Ncnt=0;
    for(int i=0; i<9; i++){
        if(str[i] == 'O') {
            map[i/3][i%3] = 1;
            Ocnt++;
        } else if(str[i] == 'X') {
            map[i/3][i%3] = 2;
            Xcnt++;
        } else {
            map[i/3][i%3] = 0;
            Ncnt++;
        }
    }
    if(Xcnt != Ocnt && Xcnt != Ocnt+1) return false;
    if(Xcnt == Ocnt+1) { // X 승
        if(isPossible(2) && !isPossible(1)) return true;
        if((Xcnt+Ocnt == 9) && !isPossible(0) && !isPossible(1)) return true;
    } else { // O 승
        if(isPossible(1) && !isPossible(2)) return true;
    }
    return false;
}

bool isPossible(int c){
    for(int i=0; i<3; i++){
        if(map[i][0] == c && map[i][1] == c && map[i][2] == c) return true;
        if(map[0][i] == c && map[1][i] == c && map[2][i] == c) return true;
    }
    if(map[0][0] == c && map[1][1] == c && map[2][2] == c) return true;
    if(map[2][0] == c && map[1][1] == c && map[0][2] == c) return true;
    return false;
}