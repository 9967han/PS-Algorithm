#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void printMap();
void DFS(int x, int y, int cnt);
bool isCorrect(int x, int y, int num);
vector<pair<int, int> > v;
int map[10][10];
int check[10][10][10];
int main(){
	for(int i=1; i<=9; i++){
		for(int j=1; j<=9; j++){
			cin >> map[i][j];
			if(!map[i][j]) v.push_back(make_pair(i, j));
		}
	}

	DFS(0, 0, 0);
	return 0;
}

void DFS(int x, int y, int cnt){
	if(cnt == v.size()){
		printMap();
		exit(0);
	}

	x = v[cnt].first;
	y = v[cnt].second;
	for(int j=1; j<=9; j++){
		if(isCorrect(x, y, j)){
			map[x][y] = j;
			DFS(x, y, cnt+1);
			map[x][y] = 0;
		}
	}
	return;
}

bool isCorrect(int x, int y, int num){
	for(int i=1; i<=9; i++){
		if(map[x][i] == num) return false;
	}
	for(int i=1; i<=9; i++){
		if(map[i][y] == num) return false;
	}

	x = (x-1)/3;
    y = (y-1)/3; 
    for(int i=x*3+1; i<=x*3+3; i++){
        for(int j=y*3+1; j<=y*3+3; j++){
            if(map[i][j] == num) return false;
        }
    }
	return true;
}

void printMap(){
	for(int i=1; i<=9; i++){
		for(int j=1; j<=9; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return;
}
