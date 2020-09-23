#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int abs(int a);
int getResult();
void DFS(int cnt);
void print();
int N, maxNum=0;
int map[9], check[9], resultArr[9];

int main(){
	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> map[i];
	}
	DFS(1);
	cout << maxNum << endl;
}

int getResult(){
	int result = 0;
	for(int i=2; i<=N; i++){
		result += abs(resultArr[i] - resultArr[i-1]);
	}
	return result;
}

int abs(int a){
	if(a > 0) return a;
	else return a*(-1);
}

void DFS(int cnt){
	if(cnt > N){
		maxNum = max(maxNum, getResult());
		return;
	} 

	for(int i=1; i<=N; i++){
		if(!check[i]){
			resultArr[cnt] = map[i];
			check[i] = 1;
			DFS(cnt+1);
			check[i] = 0;
		}
	}
}

void print(){
	for(int i=1; i<=N; i++){
		cout << resultArr[i] << " ";
	}
	cout << endl;
}