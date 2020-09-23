#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
using namespace std;

int N, countType=1;
int house[26][26];
int houseType[26][26];

void input();
void printHouseType();
bool insert();
void divide();
int printResult(int a);

std::queue<pair<int,int> > q;
std::vector<int> v;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

int main() {
	input();
	while(insert()) {
		divide();	
		// printHouseType();
	}

	printf("%d\n", countType-1);
	for(int i=1; i<countType; i++) {
		v.push_back(printResult(i));
	}
	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); i++) {
		printf("%d\n", v[i]);
	}
}

void input() {
	char houseTemp[26];
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			houseType[i][j] = 0;
		}
	}

	for(int i=1; i<=N; i++) {
		scanf("%s", houseTemp);
		for(int j=1; j<=N; j++) {
			house[i][j] = houseTemp[j-1] - 48;
		}
	}
}

void divide() {
	std::pair <int, int> temp;
	int nx, ny;
	int currentType;
	while(q.size() != 0) {
		temp = q.front();
		for(int i=0; i<4; i++) {
			nx = temp.first + dx[i];
			ny = temp.second + dy[i];
			currentType = houseType[temp.first][temp.second];
			if (house[nx][ny] == 1 && nx >= 1 && ny >= 1 && nx <= N && ny <= N) {
				if(houseType[nx][ny] == 0) {
					houseType[nx][ny] = currentType;
					q.push(make_pair(nx, ny));
				} 
			}
		}
		q.pop();
	}
}

bool insert() {
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			if(house[i][j] == 1 && houseType[i][j] == 0) {
				q.push(make_pair(i, j));
				houseType[i][j] = countType;
				countType++;
				return true;
			}
		}
	}
	return false;
}

void printHouseType() {
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			printf("%d ", houseType[i][j]);
		}
		printf("\n");	
	}
}

int printResult(int a) {
	int num=0;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			if(houseType[i][j] == a) num++;
		}
	}
	return num;
}
