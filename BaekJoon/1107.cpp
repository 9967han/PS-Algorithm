#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int isEnterable(int a);
int K, N, ans=987654321;
int button[10];
int main(){
	memset(button, 1, sizeof(button));
	cin >> N >> K;
	for(int i=1; i<=K; i++){
		int num;
		cin >> num;
		button[num] = 0; //사용불가능
	}
	for(int i=0; i<=999999; i++){
		int len = isEnterable(i);
		if(len) ans = min(ans, len+abs(i-N));
	}
	ans = min(ans, abs(100 - N));
	cout << ans;
}

int isEnterable(int a){
	string str;
	str = to_string(a);
	for(int i=0; i<str.size(); i++){
		if(!button[str[i]-'0']) return 0;
	}
	return str.size();
}
