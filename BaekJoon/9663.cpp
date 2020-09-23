#include<iostream>
#include<algorithm>
using namespace std;
int map[16];
int dx[30];//왼쪽이 위 대각선
int dy[30];//오른쪽이 위 대각선
int result=0, N;
void NQueen(int x);

int main(){
	cin >> N;

	NQueen(0);

	cout << result << endl;
}

//0,0 0,1 0,2 0,3
//1,0 1,1 1,2 1,3
//2,0 2,1 2,2 2,3
//3,0 3,1 3,2 3,3

void NQueen(int x){
	if(x == N) result++;

	for(int i=0; i<N; i++){
		if(map[i]) continue; //같은열에 있으면
		if(dx[N-1+(x-i)] || dy[x+i]) continue; //대각선에 있으면

		map[i] = dx[N-1+(x-i)] = dy[x+i] = 1;
		NQueen(x+1);
		map[i] = dx[N-1+(x-i)] = dy[x+i] = 0;
	}
}