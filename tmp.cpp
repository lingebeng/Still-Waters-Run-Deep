#include<iostream>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 5e3 + 5;
using namespace std;
int e[N][3];
int dp[N][N],from[N][N],t,ans,n,m,path[N];
void solve()
{
	int maxT;
	cin >> n >> m >> maxT;
	for(int i = 0;i < m;i++) cin >> e[i][0] >> e[i][1] >> e[i][2];
	for(int i = 0;i < n;i++) for(int j = 1;j <= n;j++) dp[i][j] = maxT + 1;
	dp[0][1] = 0;
	for(int i = 1;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			int u = e[j][0],v = e[j][1],w = e[j][2];
			int tmp = dp[i - 1][u] + w;
			if(tmp < dp[i][v])
			{
				dp[i][v] = tmp;
				from[i][v] = u;
			}
		}
		if(dp[i][n] <= maxT) ans = i;
	}
	cout << ans + 1 << '\n';
	int u = n;
	for(int i = ans;i >= 0;i--)
	{
		path[i] = u;
		u = from[i][u]; 
	}
	for(int i = 0;i <= ans;i++)
	{
		cout << path[i] << ' ';
	}
	cout << '\n';
}
signed main()
{
	fast
	t = 1;
	while(t--) solve();
}