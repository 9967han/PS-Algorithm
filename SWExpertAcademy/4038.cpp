#include<iostream>
#include<vector>
using namespace std;
vector<int> getPi(string p);
vector<int> kmp(string s, string p);

int main(int argc, char** argv)
{
	int test_case, T;
	cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string B, S;
        cin >> B >> S;
        auto matched = kmp(B,S);
        cout << "#" << test_case << " " << matched.size()  << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

vector<int> getPi(string p){
    int m = p.size(), j=0;
    vector<int> pi(m, 0);
    for(int i=1; i<m; i++){
        while(j > 0 && p[i] != p[j])
            j = pi[j-1];
        if(p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

vector<int> kmp(string s, string p){
    vector<int> ans;
    auto pi = getPi(p);
    int n = s.size(), m = p.size(), j=0;
    for(int i=0; i<n; i++){
        while(j>0 && s[i] != p[j])
            j = pi[j-1];
        if(s[i] == p[j]){
            if(j == m-1){
                ans.push_back(i-m+1);
                j = pi[j];
            }else{
                j++;
            }
        }
    }
    return ans;
}