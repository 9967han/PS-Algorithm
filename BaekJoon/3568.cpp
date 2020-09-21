#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    string str, basicStr, outputStr;
    cin >> basicStr;
    while(1) {
        outputStr = basicStr;
        cin >> str;
        int variableName = 0;
        for(int i=0; i<str.size()-1; i++){
            if(str[i] == '[' || str[i] == '*' || str[i] == '&'){
                variableName = i;
                break;
            }
        }
        if(variableName == 0) variableName = str.size()-1;
        for(int i=str.size()-2; i>=variableName; i--){
            if(str[i] == ']') {
                outputStr += "[]";
                i--;
                continue;
            }
            outputStr += str[i];
        }
        outputStr += " ";
        outputStr += str.substr(0, variableName);
        outputStr += ";";
        cout << outputStr << '\n'; 
        if(str[str.size()-1] == ';') break;
    }
    return 0;
}