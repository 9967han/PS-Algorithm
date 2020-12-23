#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
set<int> node;
vector<pair<int, int> > edge;
int main(){
    int st, en, idx = 1;
    while(1){
        cin >> st >> en;
        if(st == -1 && en == -1) break;
        if(st == 0 && en == 0){
            if((node.size() == edge.size()+1) || edge.size() == 0) cout << "Case " << idx << " is a tree." << '\n';
            else cout << "Case " << idx << " is not a tree." << '\n';
            node.clear();
            edge.clear();
            idx++;
            continue;
        }
        node.insert(st);
        node.insert(en);
        edge.push_back(make_pair(st, en));
    }
    return 0;
}