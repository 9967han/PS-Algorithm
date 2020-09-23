#include<iostream>
#include<algorithm>
using namespace std;
string str;
int main(){
	cin >> str;
	long long sum=0, zero=0;
	for(int i=0; i<str.size(); i++){
		sum+=str[i]-'0';
		if(str[i] == '0') zero=1; 
	}

	if(sum%3 == 0 && zero){
		sort(str.rbegin(), str.rend());
		cout << str;
	}else{
		cout << "-1";
	}
	return 0;
}