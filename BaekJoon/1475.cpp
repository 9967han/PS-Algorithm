#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int arr[10] = {0, };
int main(){
	string str;
	cin >> str;
	for(int i=0; i<str.size(); i++){
		int idx = str[i] - '0';
		arr[idx]++;
	}	
	int sixNum = arr[6] + arr[9];
	if(sixNum % 2 == 1) sixNum++;
	arr[6] = sixNum / 2;
	arr[9] = sixNum / 2;

	int ans = 0;
	for(int i=0; i<10; i++){
		ans = max(arr[i], ans);
	}
	cout << ans;
}
