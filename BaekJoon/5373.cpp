#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define U 1 
#define D 2
#define F 3
#define B 4
#define L 5
#define R 6 
#define pl 0
#define mi 1
#define Wh 11
#define Ye 22
#define Re 33
#define Or 44
#define Gr 55
#define Bl 66
void input();
void initCube();
void printCube();
void rotate(int face, int dir);
int temp[4];
int map[7][10];
int main(){
	input();
}

void rotateFace(int face, int dir){
	int temp = map[face][1];
	if(dir == pl){
		map[face][1] = map[face][4];
		map[face][4] = map[face][7];
		map[face][7] = map[face][8];
		map[face][8] = map[face][9];
		map[face][9] = map[face][6];
		map[face][6] = map[face][3];
		map[face][3] = map[face][2];
		map[face][2] = temp;
	} else {
		map[face][1] = map[face][2];
		map[face][2] = map[face][3];
		map[face][3] = map[face][6];
		map[face][6] = map[face][9];
		map[face][9] = map[face][8];
		map[face][8] = map[face][7];
		map[face][7] = map[face][4];
		map[face][4] = temp;
	}
	return;
}

void rotate(int face, int dir){
	rotateFace(face, dir);
	if(face == U && dir == pl) { // 시계 
		for(int i=1; i<=3; i++) temp[i] = map[L][i];
		for(int i=1; i<=3; i++) map[L][i] = map[F][i];
		for(int i=1; i<=3; i++) map[F][i] = map[R][i];
		for(int i=1; i<=3; i++) map[R][i] = map[B][i];
		for(int i=1; i<=3; i++) map[B][i] = temp[i];
	} else if(face == U && dir == mi) { // 반시계
		for(int i=1; i<=3; i++) temp[i] = map[L][i];
		for(int i=1; i<=3; i++) map[L][i] = map[B][i];
		for(int i=1; i<=3; i++) map[B][i] = map[R][i];
		for(int i=1; i<=3; i++) map[R][i] = map[F][i];
		for(int i=1; i<=3; i++) map[F][i] = temp[i];
	} else if(face == D && dir == pl) { // 시계 
		for(int i=1; i<=3; i++) temp[i] = map[F][i+6];
		for(int i=1; i<=3; i++) map[F][i+6] = map[L][i+6];
		for(int i=1; i<=3; i++) map[L][i+6] = map[B][i+6];
		for(int i=1; i<=3; i++) map[B][i+6] = map[R][i+6];
		for(int i=1; i<=3; i++) map[R][i+6] = temp[i];
	} else if(face == D && dir == mi) { // 반시계
		for(int i=1; i<=3; i++) temp[i] = map[R][i+6];
		for(int i=1; i<=3; i++) map[R][i+6] = map[B][i+6];
		for(int i=1; i<=3; i++) map[B][i+6] = map[L][i+6];
		for(int i=1; i<=3; i++) map[L][i+6] = map[F][i+6];
		for(int i=1; i<=3; i++) map[F][i+6] = temp[i];
	}  else if(face == L && dir == pl) { // 시계 
		for(int i=1; i<=3; i++) temp[i] = map[B][12-i*3];
		for(int i=1; i<=3; i++) map[B][12-i*3] = map[D][12-i*3];
		for(int i=1; i<=3; i++) map[D][12-i*3] = map[F][i*3-2];
		for(int i=1; i<=3; i++) map[F][i*3-2] = map[U][i*3-2];
		for(int i=1; i<=3; i++) map[U][i*3-2] = temp[i];
	} else if(face == L && dir == mi) { // 반시계
		for(int i=1; i<=3; i++) temp[i] = map[B][12-i*3];
		for(int i=1; i<=3; i++) map[B][12-i*3] = map[U][i*3-2];
		for(int i=1; i<=3; i++) map[U][i*3-2] = map[F][i*3-2];
		for(int i=1; i<=3; i++) map[F][i*3-2] = map[D][12-i*3];
		for(int i=1; i<=3; i++) map[D][12-i*3] = temp[i];
	} else if(face == R && dir == pl) { // 시계 
		for(int i=1; i<=3; i++) temp[i] = map[B][i*3-2];
		for(int i=1; i<=3; i++) map[B][i*3-2] = map[U][12-i*3];
		for(int i=1; i<=3; i++) map[U][12-i*3] = map[F][12-i*3];
		for(int i=1; i<=3; i++) map[F][12-i*3] = map[D][i*3-2];
		for(int i=1; i<=3; i++) map[D][i*3-2] = temp[i];
	} else if(face == R && dir == mi) { // 반시계
		for(int i=1; i<=3; i++) temp[i] = map[B][i*3-2];
		for(int i=1; i<=3; i++) map[B][i*3-2] = map[D][i*3-2];
		for(int i=1; i<=3; i++) map[D][i*3-2] = map[F][i*3];
		for(int i=1; i<=3; i++) map[F][i*3] = map[U][i*3];
		for(int i=1; i<=3; i++) map[U][i*3] = temp[i];
	}
	return;
}

void input(){
	string str;
	int t, n, face, dir;
	cin >> t;
	for(int i=1; i<=t; i++){
		initCube();
		cin >> n;
		for(int j=1; j<=n; j++){
			cin >> str;
			if(str[1] == '+') dir = pl;
			else if(str[1] == '-') dir = mi;

			if(str[0] == 'U') face = U;
			else if(str[0] == 'D') face = D;
			else if(str[0] == 'F') face = F;
			else if(str[0] == 'B') face = B;
			else if(str[0] == 'L') face = L;
			else if(str[0] == 'R') face = R;
			rotate(face, dir);
			printCube();
		}
	}
	return;
}

void printCube(){
	cout << endl;
	for(int i=1; i<=6; i++){
		if(i == 1) cout << " UP : -------" << endl;
		else if(i == 2) cout << " Down : -------" << endl;
		else if(i == 3) cout << " Front : -------" << endl;
		else if(i == 4) cout << " Back : -------" << endl;
		else if(i == 5) cout << " Left : -------" << endl;
		else cout << " Right : -------" << endl;
		for(int j=1; j<=9; j++){
			if(map[i][j] == Wh) cout << 'w' << " ";
			else if(map[i][j] == Re) cout << 'r' << " ";
			else if(map[i][j] == Bl) cout << 'b' << " ";
			else if(map[i][j] == Gr) cout << 'g' << " ";
			else if(map[i][j] == Ye) cout << 'y' << " ";
			else if(map[i][j] == Or) cout << 'o' << " ";
			if(j % 3 == 0) cout << endl;
		}
		cout << endl;
	}
	return;
}

void initCube(){
	for(int i=1; i<=6; i++){
		for(int j=1; j<=9; j++){
			if(i == U) map[i][j] = Wh;
			else if(i == D) map[i][j] = Ye;
			else if(i == F) map[i][j] = Re;
			else if(i == B) map[i][j] = Or;
			else if(i == L) map[i][j] = Gr;
			else if(i == R) map[i][j] = Bl;
		}
	}
	return;
}