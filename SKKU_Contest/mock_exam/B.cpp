#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
string str;
int main(){
    cin >> str;
    for(int i=0; i<str.size(); i++){
        if(str[i] == 'H' || str[i] == 'I' || str[i] == 'N' || str[i] == 'O' || str[i] == 'S' || str[i] == 'Z' || str[i] == 'X') continue;
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}