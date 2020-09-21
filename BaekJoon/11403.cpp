#include<iostream>
#include<algorithm>
using namespace std;
void DFS();
int map[101][101];
int N;
int main(){
	cin >> N;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin >> map[i][j];
		}
	}

	DFS();

	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void DFS(){
	for(int k=1; k<=N; k++){
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				if(!map[i][j]) map[i][j] = map[i][k] && map[k][j];
			}
		}
	}
}