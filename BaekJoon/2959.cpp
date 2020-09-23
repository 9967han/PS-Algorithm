#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	vector<int> v;
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	v.push_back(A);
	v.push_back(B);
	v.push_back(C);
	v.push_back(D);
	sort(v.begin(), v.end());
	cout << v[0] * v[2];
}