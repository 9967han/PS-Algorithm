#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
void divide(int x, int y, int d1, int d2);
void printMap();
void input();
int N, ans = 987654321;
int map[21][21], popMap[21][21], sum[6];
int main(){
	input();
	for(int x=1; x<=N; x++){
		for(int y=2; y<=N; y++){
			for(int d1=1; x+d1<=N-1; d1++){
				int d2 = 1;
				if(x+d1+d2 > N) continue;
				for(d2=1; 1<=y-d1 && y-d1 < y && y < y+d2 && y+d2<=N && x+d1+d2<=N; d2++){ // (d1, d2 ≥ 1, 1 ≤ x < x+d1+d2 ≤ N, 1 ≤ y-d1 < y < y+d2 ≤ N)
					divide(x, y, d1, d2);
				}
			}
		}
	}
	cout << ans;
}

void divide(int x, int y, int d1, int d2){
	memset(map, 0, sizeof(map));
	memset(sum, 0, sizeof(sum));
	for(int i=0; i<=d1; i++) map[x+i][y-i] = 5; // (x, y), (x+1, y-1), ..., (x+d1, y-d1)
	for(int i=0; i<=d2; i++) map[x+i][y+i] = 5; // (x, y), (x+1, y+1), ..., (x+d2, y+d2)
	for(int i=0; i<=d2; i++) map[x+d1+i][y-d1+i] = 5; // (x+d1, y-d1), (x+d1+1, y-d1+1), ... (x+d1+d2, y-d1+d2)
	for(int i=0; i<=d1; i++) map[x+d2+i][y+d2-i] = 5; // (x+d2, y+d2), (x+d2+1, y+d2-1), ..., (x+d2+d1, y+d2-d1)

	for(int r=1; r<=N; r++){
		int before5 = 0;
		for(int c=1; c<=N; c++){
			if(!before5 && map[r][c]) before5 = c;
			else if(before5 && map[r][c]) {
				for(int k=before5; k<=c; k++) map[r][k] = 5;
			} else {
				if(1 <= r && r < x+d1 && 1 <= c && c <= y) map[r][c] = 1;//1 ≤ r < x+d1, 1 ≤ c ≤ y
				else if(1 <= r && r <= x+d2 && y < c && y <= N) map[r][c] = 2;//1 ≤ r ≤ x+d2, y < c ≤ N
				else if(x+d1 <= r && r <= N && 1 <= c && c < y-d1+d2) map[r][c] = 3;// x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
				else if(x+d2 < r && r<= N && y-d1+d2 <= c && c <= N) map[r][c] = 4;// x+d2 < r ≤ N, y-d1+d2 ≤ c ≤ N
			}
			
		}
	}

	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(map[i][j] == 1) sum[1] += popMap[i][j];
			else if(map[i][j] == 2) sum[2] += popMap[i][j];
			else if(map[i][j] == 3) sum[3] += popMap[i][j];
			else if(map[i][j] == 4) sum[4] += popMap[i][j];
			else sum[5] += popMap[i][j];
		}
	}
 	sort(sum+1, sum+6); 
	ans = min(ans, abs(sum[5] - sum[1]));
	return;
}

void printMap(){
	cout << endl;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void input(){
	cin >> N;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin >> popMap[i][j];
		}
	}
	return;
}