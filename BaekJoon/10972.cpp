#include<algorithm>
#include<iostream>
using namespace std;
int arr[10001];
int N;

int main(){
	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> arr[i];
	}

	if(prev_permutation(arr+1, arr+N+1)){
		for(int i=1; i<=N; i++) cout << arr[i] << " ";
	} else cout << "-1";
}
