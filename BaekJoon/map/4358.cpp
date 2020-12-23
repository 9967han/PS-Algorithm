#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<cmath>
using namespace std;
map<string, int> m;
int main(){
    string str;
    int size = 0;
    while(getline(cin, str)){
        if(m[str]) m[str]++;
        else m[str] = 1;
        size++;
    }
    map<string, int>::iterator iter;
    for(iter=m.begin(); iter!=m.end(); iter++){
        double per = (double)iter->second*100 / size;
        per = round(per * pow(10, 4))/pow(10, 4);
        cout << iter->first << " ";
        cout << fixed;
        cout.precision(4);
        cout << per << "\n"; 
    }
    return 0;
}