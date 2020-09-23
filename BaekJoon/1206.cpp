#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
int map[1001];
int main(int argc, char** argv)
{
	int test_case, N, ans=0;
	for(test_case = 1; test_case <= 10; ++test_case)
	{
        cin >> N;
        memset(map, 0, sizeof(map));
        ans = 0;
        for(int i=1; i<=N; i++) cin >> map[i];
        for(int i=3; i<=N-2; i++) {
            int cur = map[i];
            int nearMax = max(map[i-1], map[i-2]);
            nearMax = max(nearMax, map[i+1]);
            nearMax = max(nearMax, map[i+2]);
            if(cur > nearMax) ans += cur-nearMax;
        }
        cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}