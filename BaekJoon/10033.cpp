#include<iostream>
#include<cstring>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	string str;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> str;
		bool flag = false;
		long long ans = 0, cnt = 0;
		for(int i=0; i<str.size(); i++){
			if(str[i] == 'B') flag = true;
			if(flag && str[i] == 'W') {
				ans += i;
				ans -= cnt;
				cnt++;
			}else if(str[i] == 'W') {
				cnt++;
			}
		}
		cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}