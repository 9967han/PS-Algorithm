#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
long long minNum, maxNum;
long long a[1001001];
long long nums[1000001];
int main(){
	cin >> minNum >> maxNum;

	//init
	long long diff = maxNum-minNum;
	for(long long i=1; i<=diff+1; i++){
		nums[i] = minNum+i-1;
	}

	for(long long i=2; i<=sqrt(maxNum); i++){
		long long a = i*i;
		long long st = minNum/a;
		for(long long j=st; a*j <= maxNum; j++){
			if(minNum <= a*j) {
				nums[a*j-minNum+1] = 0;
			} else if(a*j > maxNum){
				break;
			}
		}
	}

	long long cnt = 0;
	for(long long i=1; i<=diff+1; i++){
		if(nums[i]) cnt++;
	}
	cout << cnt;
}