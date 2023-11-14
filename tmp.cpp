#include<iostream>
#include<cstring>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
const int N = 4e4 + 1,MOD = 1e9 + 7;
using namespace std;
int dp[N],t;
void solve()
{
	int x;cin >> x;
	cout << dp[x] << '\n';
}
signed main()
{
	fast
	dp[0] = 1;
	for(int i = 1;i <= N;i++)
	{
		string s = to_string(i);
		if(string(s.rbegin(),s.rend()) == s)
		{
			for(int j = i;j <= N;j++)
			dp[j] = (dp[j] + dp[j - i]) % MOD;
		}
	}
	cin >> t;
	while(t--) solve();
}