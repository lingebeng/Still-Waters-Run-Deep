#include<iostream>
#include<cstring>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9 + 7;
using namespace std;
int t,cnt,ans;
void solve()
{
	string a;
	cin >> a;
	for(int i = a.size() - 1;i >= 0;i--)
	{
		if(a[i] == 'b') ++cnt;
		else ans = (ans + cnt) % MOD,cnt = (cnt * 2) % MOD;
	}
	cout << ans << '\n';
	
}
signed main()
{
	fast
	t = 1;
	while(t--) solve();
}