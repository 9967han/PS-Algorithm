#include<iostream>
#include<string>
using namespace std;
void print();
int N, M;
string map[101];
int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		string s;
		cin >> s;
		for(int j=0; j<M; j++){
			if(s[j] == 45) s[j] = 124;
			else if(s[j] == 124) s[j] = 45;
			else if(s[j] == 47) s[j] = 92;
			else if(s[j] == 92) s[j] = 47;
			else if(s[j] == 94) s[j] = 60;
			else if(s[j] == 60) s[j] = 118; 
			else if(s[j] == 118) s[j] = 62; 
			else if(s[j] == 62) s[j] = 94; 
		}
		map[i] = s;
	}
	print();
}

void print(){
	for(int i=M-1; i>=0; i--){
		for(int j=0; j<N; j++){
			printf("%c", map[j][i]);
		}
		printf("\n");
	}
}