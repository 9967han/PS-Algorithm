#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
using namespace std;
struct stone{
    int x, y, z;
};
void change(int A, int B, int C);
stone getStone(int A, int B, int C);
set<pair<int, pair<int, int> > > s;
queue<stone> q;
int main(){
    int x, y, z;
    cin >> x >> y >> z;
    stone f = getStone(x, y, z);
    s.insert(make_pair(x, make_pair(y, z)));
    q.push({f.x, f.y, f.z});
    while(!q.empty()){
        stone cur = q.front(); q.pop();
        if(cur.x == cur.y && cur.y == cur.z) {
            cout << "1";
            return 0;
        }
        change(cur.x, cur.y, cur.z);
        change(cur.y, cur.z, cur.x);
        change(cur.x, cur.z, cur.y);
    }
    cout << "0";
    return 0;
}

void change(int A, int B, int C){
    int nA = 2*A;
    int nB = B-A;
    stone newStone = getStone(nA, nB, C);
    int before = s.size();
    s.insert(make_pair(nA, make_pair(nB, C)));
    int after = s.size();
    if(before == after) return;
    else q.push(newStone);
}

stone getStone(int A, int B, int C){
    stone newStone;
    vector<int> v;
    v.push_back(A);
    v.push_back(B);
    v.push_back(C);
    sort(v.begin(), v.end());
    newStone.x = v[0];
    newStone.y = v[1];
    newStone.z = v[2];
    v.clear();
    return newStone;
}