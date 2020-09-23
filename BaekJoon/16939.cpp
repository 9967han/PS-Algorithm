#include<iostream>
#include<algorithm>
using namespace std;
bool isSolvable(int type);
bool isSolved();
int cube[25], cubeTemp[25], temp[3];

int main(){
    for(int i=1; i<=24; i++) cin >> cubeTemp[i];
    for(int i=1; i<=6; i++) {
        if(isSolvable(i)){
            cout << "1";
            return 0;
        }
    }
    cout << "0";
    return 0;
}

bool isSolvable(int type){
    if(type == 1) { // 오른쪽
        for(int i=1; i<=24; i++) cube[i] = cubeTemp[i];
        temp[1] = cube[2]; temp[2] = cube[4];
        cube[2] = cube[6]; cube[4] = cube[8];
        cube[6] = cube[10]; cube[8] = cube[12];
        cube[10] = cube[23]; cube[12] = cube[21];
        cube[23] = temp[1]; cube[21] = temp[2]; 
        if(isSolved()) return true;

        for(int i=1; i<=24; i++) cube[i] = cubeTemp[i];
        temp[1] = cube[2]; temp[2] = cube[4];
        cube[2] = cube[23]; cube[4] = cube[21];
        cube[23] = cube[10]; cube[21] = cube[12];
        cube[10] = cube[6]; cube[12] = cube[8];
        cube[6] = temp[1]; cube[8] = temp[2]; 
        if(isSolved()) return true;
    } else if(type == 2) { // 왼쪽
        for(int i=1; i<=24; i++) cube[i] = cubeTemp[i];
        temp[1] = cube[1]; temp[2] = cube[3];
        cube[1] = cube[5]; cube[3] = cube[7];
        cube[5] = cube[9]; cube[7] = cube[11];
        cube[9] = cube[24]; cube[11] = cube[22];
        cube[24] = temp[1]; cube[22] = temp[2]; 
        if(isSolved()) return true;

        for(int i=1; i<=24; i++) cube[i] = cubeTemp[i];
        temp[1] = cube[1]; temp[2] = cube[3];
        cube[1] = cube[24]; cube[3] = cube[22];
        cube[24] = cube[9]; cube[22] = cube[11];
        cube[9] = cube[5]; cube[11] = cube[7];
        cube[5] = temp[1]; cube[7] = temp[2]; 
        if(isSolved()) return true;
    } else if(type == 3) { // 앞쪽
        for(int i=1; i<=24; i++) cube[i] = cubeTemp[i];
        temp[1] = cube[7]; temp[2] = cube[8];
        cube[7] = cube[15]; cube[8] = cube[16];
        cube[15] = cube[23]; cube[16] = cube[24];
        cube[23] = cube[19]; cube[24] = cube[20];
        cube[19] = temp[1]; cube[20] = temp[2]; 
        if(isSolved()) return true;

        for(int i=1; i<=24; i++) cube[i] = cubeTemp[i];
        temp[1] = cube[7]; temp[2] = cube[8];
        cube[7] = cube[19]; cube[8] = cube[20];
        cube[19] = cube[23]; cube[20] = cube[24];
        cube[23] = cube[15]; cube[24] = cube[16];
        cube[15] = temp[1]; cube[16] = temp[2]; 
        if(isSolved()) return true;
    } else if(type == 4) { // 뒷쪽
        for(int i=1; i<=24; i++) cube[i] = cubeTemp[i];
        temp[1] = cube[5]; temp[2] = cube[6];
        cube[5] = cube[13]; cube[6] = cube[14];
        cube[13] = cube[21]; cube[14] = cube[22];
        cube[21] = cube[17]; cube[22] = cube[18];
        cube[17] = temp[1]; cube[18] = temp[2]; 
        if(isSolved()) return true;

        for(int i=1; i<=24; i++) cube[i] = cubeTemp[i];
        temp[1] = cube[5]; temp[2] = cube[6];
        cube[5] = cube[17]; cube[6] = cube[18];
        cube[17] = cube[21]; cube[18] = cube[22];
        cube[21] = cube[13]; cube[22] = cube[14];
        cube[13] = temp[1]; cube[14] = temp[2]; 
        if(isSolved()) return true;
    } else if(type == 5) { // 가로돌리기 윗
        for(int i=1; i<=24; i++) cube[i] = cubeTemp[i];
        temp[1] = cube[2]; temp[2] = cube[1];
        cube[2] = cube[13]; cube[1] = cube[15];
        cube[13] = cube[11]; cube[15] = cube[12];
        cube[11] = cube[20]; cube[12] = cube[18];
        cube[20] = temp[1]; cube[18] = temp[2]; 
        if(isSolved()) return true;

        for(int i=1; i<=24; i++) cube[i] = cubeTemp[i];
        temp[1] = cube[2]; temp[2] = cube[1];
        cube[2] = cube[20]; cube[1] = cube[18];
        cube[20] = cube[11]; cube[18] = cube[12];
        cube[11] = cube[13]; cube[12] = cube[15];
        cube[13] = temp[1]; cube[15] = temp[2]; 
        if(isSolved()) return true;
    } else if(type == 6) { // 가로돌리기 아래
        for(int i=1; i<=24; i++) cube[i] = cubeTemp[i];
        temp[1] = cube[4]; temp[2] = cube[3];
        cube[4] = cube[14]; cube[3] = cube[16];
        cube[14] = cube[9]; cube[16] = cube[10];
        cube[9] = cube[19]; cube[10] = cube[17];
        cube[19] = temp[1]; cube[17] = temp[2]; 
        if(isSolved()) return true;

        for(int i=1; i<=24; i++) cube[i] = cubeTemp[i];
        temp[1] = cube[4]; temp[2] = cube[3];
        cube[4] = cube[19]; cube[3] = cube[17];
        cube[19] = cube[9]; cube[17] = cube[10];
        cube[9] = cube[14]; cube[10] = cube[16];
        cube[14] = temp[1]; cube[16] = temp[2]; 
        if(isSolved()) return true;
    }
    return false;
}

bool isSolved(){
    for(int i=0; i<=5; i++){
        if(cube[i*4 + 1] == cube[i*4 + 2] && cube[i*4 + 2] == cube[i*4 + 3] && cube[i*4 + 3] == cube[i*4 + 4]) continue;
        else return false;
    }
    return true;
}