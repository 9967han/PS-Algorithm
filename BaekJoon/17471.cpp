#include<iostream>
#include<algorithm>
using namespace std;
void input();
void showMap();

int map[11][11];
int number[11];
int N;
int main(){
	input();
	
}

void input(){
	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> number[i];
	} 
	for(int from=1; from<=N; from++){
		int M, to;
		cin >> M;
		for(int j=1; j<=M; j++){
			cin >> to;
			map[from][to] = 1;
		} 
	}
	return;
}

void showMap(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return;
}