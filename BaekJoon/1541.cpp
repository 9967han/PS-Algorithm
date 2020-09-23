#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void calculate();
void print();

string str;
int main(){
	cin >> str;
	for(int i=0; i<str.size(); i++){
		if(str[i] == '-'){
			for(int j=i+1; j<str.size(); j++){
				if(str[j] == '+') str[j] = '-';
				if(str[j] == '-') break;
			}
		}
	}
	calculate();

	return 0;
}

void print(){
	for(int i=0; i<str.size(); i++){
		cout << str[i];
	}
}

void calculate(){
	int ans = atoi(str.c_str());
	for(int i=1; i<str.size(); i++){
		if(str[i] == '-' || str[i] == '+'){
			ans += atoi(str.substr(i).c_str());
		}
	}
	cout << ans;
}