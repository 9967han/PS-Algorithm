#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
double arr[7];
int main(){
	int T;
	cin >> T;
	for(int i=1; i<=T; i++){
		for(int j=1; j<=6; j++){
			cin >> arr[j];
		}
		double disX = (arr[1]-arr[4])*(arr[1]-arr[4]);
		double disY = (arr[2]-arr[5])*(arr[2]-arr[5]);
		double d = sqrt(disX + disY);
		double rPrime = max(arr[3], arr[6]);
		double r = min(arr[3], arr[6]);
		
		if(d == 0 && rPrime == r) {
			cout << "-1" << endl;
		} else if(rPrime - r < d && d < rPrime + r) {
			cout << "2" << endl;
		} else if(rPrime + r == d || rPrime - r == d) {
			cout << "1" << endl;
		} else if(r + rPrime < d || d < rPrime - r){
			cout << "0" << endl;
		} 
	}	
}