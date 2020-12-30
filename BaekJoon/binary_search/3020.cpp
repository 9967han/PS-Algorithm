#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, H, height;
vector<int> low, high;
bool compare(int A, int B) {
    return A > B;
}

int main(){
    cin >> N >> H;
    for(int i=0; i<N; i++){
        cin >> height;
        if(i%2) high.push_back(height);
        else low.push_back(height);
    }
    sort(low.begin(), low.end());
    sort(high.begin(), high.end());

    int min = 987654321, cnt = 0;
    for(int i=1; i<=H; i++){
        int lowNum = N/2 - (lower_bound(low.begin(), low.end(), i) - low.begin());
        int highNum = N/2 - (upper_bound(high.begin(), high.end(), (H-i)) - high.begin());
        if(min > lowNum + highNum){
            min = lowNum + highNum;
            cnt = 1;
        } else if(min == lowNum + highNum){
            cnt++;
        }
    }
    cout << min << " " << cnt;
    return 0;
}