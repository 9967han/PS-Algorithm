#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, M, arr[1001];
struct photo{
    int num, good, turn;
};
int cnt = 1;
bool compare(photo p1, photo p2);
bool compare2(photo p1, photo p2);
vector<photo> v;
int main(){
    cin >> N >> M;
    for(int i=1; i<=M; i++){
        cin >> arr[i];
        bool flag = false;
        for(int j=0; j<v.size(); j++){
            if(v[j].num == arr[i]) {
                v[j].good++;
                flag = true;
            }
        }
        if(!flag){
            if(v.size() < N) {
                v.push_back({arr[i], 1, cnt++});
            } else {
                v.pop_back();
                v.push_back({arr[i], 1, cnt++});
            }
        }
        sort(v.begin(), v.end(), compare);
    }
    sort(v.begin(), v.end(), compare2);
    for(int i=0; i<v.size(); i++) {
        cout << v[i].num << " ";
    }

}
bool compare2(photo p1, photo p2){
    return p1.num < p2.num;
}

bool compare(photo p1, photo p2){
    if(p1.good == p2.good) return p1.turn > p2.turn;
    else return p1.good > p2.good;
}