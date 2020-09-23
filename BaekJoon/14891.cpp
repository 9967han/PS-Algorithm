#include<iostream>
#include<math.h>
#include<algorithm>
#define N 0
#define S 1
using namespace std;
void turnRight(int number, int arr[][9]);
void turnLeft(int number, int arr[][9]);
void input();
void initCheck();
void printGear();
int temp[9], check[5];
int gear[5][9];
int K;
int turn[3][101];
int main(){
	input();

	for(int i=1; i<=K; i++){
		initCheck();
		check[turn[1][i]] = 1;
		if(turn[2][i] == 1) {
			turnRight(turn[1][i], gear);
		}else{
			turnLeft(turn[1][i], gear);
		}
		// printGear();
	}
	int answer = 0;
	for(int i=1; i<=4; i++){
		answer += pow(2, i-1) * gear[i][1];
	}
	cout << answer;

}

void input(){
	string str;
	for(int i=1; i<=4; i++){
		cin >> str;
		for(int j=1; j<=8; j++){
			gear[i][j] = str[j-1] - '0';
		}
	}
	cin >> K;
	for(int i=1; i<=K; i++){
		cin >> turn[1][i] >> turn[2][i];
	}
}

void turnRight(int number, int arr[][9]){
	if(number+1 <= 4 && !check[number+1] && arr[number][3] != arr[number+1][7]) {
		check[number+1] = 1;
		turnLeft(number+1, arr);
	}

	if(number-1 >= 1 && !check[number-1] && arr[number][7] != arr[number-1][3]) {
		check[number-1] = 1;
		turnLeft(number-1, arr);
	}

	temp[1] = arr[number][8];
	for(int i=2; i<=8; i++){
		temp[i] = arr[number][i-1];
	}
	for(int i=1; i<=8; i++){
		arr[number][i] = temp[i];
	}
	return;
}

void turnLeft(int number, int arr[][9]){
	if(number+1 <= 4 && !check[number+1] && arr[number][3] != arr[number+1][7]) {
		check[number+1] = 1;
		turnRight(number+1, arr);
	}

	if(number-1 >= 1 && !check[number-1] && arr[number][7] != arr[number-1][3]) {
		check[number-1] = 1;
		turnRight(number-1, arr);
	}

	temp[8] = arr[number][1];
	for(int i=1; i<=7; i++){
		temp[i] = arr[number][i+1];
	}
	for(int i=1; i<=8; i++){
		arr[number][i] = temp[i];
	}
	return;
}

void printGear(){
	for(int i=1; i<=4; i++){
		for(int j=1; j<=8; j++){
			cout << gear[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void initCheck(){
	for(int i=1; i<=4; i++){
		check[i] = 0;
	}
	return;
}