#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct loc{
	int pos;
	int level;
};
int visit[1000001];
int F,S,G,U,D;
queue<loc> q;
int main(){
	cin >> F >> S >> G >> U >> D;
	q.push({S, 0});
	visit[S] = 1;
	while(!q.empty()){
		loc cur = q.front(); q.pop();
		// cout << cur.pos << " " << cur.level << endl;
		if(cur.pos == G) {
			cout << cur.level;
			return 0;
		}
		if(cur.pos + U <= F && !visit[cur.pos + U]){
			visit[cur.pos + U] = 1;
			q.push({cur.pos + U, cur.level+1});
		}
		if(cur.pos - D >= 1 && !visit[cur.pos - D]){
			visit[cur.pos - D] = 1;
			q.push({cur.pos - D, cur.level+1});
		}
	}
	cout << "use the stairs";
	return 0;
}