#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<limits.h>
using namespace std;
int calculate(int a, char c, int b);
void DFS(int idx, int res);
int N, ans;
string str;

int main(){
	cin >> N;
	cin >> str;
	ans = INT_MIN;
	DFS(0, 0);
	cout << ans;
	return 0;
}
// 9
// 3+8*7-9*2
void DFS(int idx, int res){
	// cout << "idx : " << idx << " res : " << res << endl;
	if(idx >= N){//종료
		ans = max(ans, res);
		return;
	}
	char oper = (idx == 0) ? '+' : str[idx-1];

	if(idx + 2 <= N-1){//괄호 -> 이전것 + 괄호계산값
		int bracket = calculate(str[idx]-'0', str[idx+1], str[idx+2]-'0'); //괄호계산
		DFS(idx+4, calculate(res, oper, bracket)); // 이전것 + 괄호계산
	} 

	DFS(idx+2, calculate(res, oper, str[idx]-'0')); // 이전것 + 현재것 
}

int calculate(int a, char c, int b){
	if(c == '+') return a+b;
	else if(c == '*') return a*b;
	else if(c == '-') return a-b;
	return 0;
}