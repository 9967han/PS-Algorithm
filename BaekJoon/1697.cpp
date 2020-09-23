#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int check[100001];
struct position{
	int pos;
	int lev;
};
queue<position> q;
int cnt = 0;
int ans = 987654321;
int main(){
	int N, K;
	cin >> N >> K;
	position p = {N, 0};
	q.push(p);

	while(!q.empty()){
		position cur = q.front(); q.pop();
		if(cur.pos == K && cur.lev <=) {
			ans = cur.lev;
			cnt++;
			continue;
		} 
		position newPos;
		if(cur.lev >= ans) continue;
		if(cur.pos*2 <= 100000) {
			newPos.pos = cur.pos*2; newPos.lev = cur.lev+1;
			q.push(newPos);
		} 
		if(cur.pos+1 <= 100000){
			newPos.pos = cur.pos+1; newPos.lev = cur.lev+1;
			q.push(newPos);
		} 
		if(cur.pos-1 >= 0){
			newPos.pos = cur.pos-1; newPos.lev = cur.lev+1;
			q.push(newPos);
		}
	}
	cout << ans << endl << cnt;
}