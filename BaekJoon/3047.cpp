#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

vector<int> v;
int main() {
	int x;
	string str;
	for(int i=1; i<=3; i++) {
		cin >> x;
		v.push_back(x); 
	}
	cin >> str;
	sort(v.begin(), v.end());
	if(str == "ABC") {
		cout << v[0] << ' ';
		cout << v[1] << ' ';
		cout << v[2] << ' ';
	}else if (str == "ACB") {
		cout << v[0] << ' ';
		cout << v[2] << ' ';
		cout << v[1] << ' ';

	}else if (str == "BAC") {
		cout << v[1] << ' ';
		cout << v[0] << ' ';
		cout << v[2] << ' ';

	}else if (str == "BCA") {
		cout << v[1] << ' ';
		cout << v[2] << ' ';
		cout << v[0] << ' ';

	}else if (str == "CAB") {
		cout << v[2] << ' ';
		cout << v[0] << ' ';
		cout << v[1] << ' ';

	}else if (str == "CBA") {
		cout << v[2] << ' ';
		cout << v[1] << ' ';
		cout << v[0] << ' ';
	}
	return 0;
}
