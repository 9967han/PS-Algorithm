#include<algorithm>
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
void search();
int x, n;
vector<int> v;
int main(){
	ios::sync_with_stdio(false); cin.tie(); cout.tie();
	while(cin >> x){
		int l;
		cin >> n;
		for(int i=1; i<=n; i++){
			cin >> l;
			v.push_back(l);
		}
		sort(v.begin(), v.end());
		search();
		v.clear();
	}
}

void search(){
	int left = 0, flag = 0;
	int right = v.size()-1;
	while(left < right){
		if(v[left] + v[right] > x*10000000) right--;
		else if(v[left] + v[right] < x*10000000) left++;
		else {
			flag = 1;
			break;
		}
	}
	if(flag) cout << "yes " << v[left] << " " << v[right] << endl;
	else cout << "danger" << endl;
	return;
}