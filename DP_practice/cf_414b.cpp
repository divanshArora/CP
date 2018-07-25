/**
Sort of difficult. Good problem. Standard. Good. Tested
**/
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

ll dp[2001][2001];

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){for(int j=1;j<=k;j++){dp[i][j]=0;}}
	ll ans = 0;
	for(int i=0;i<=n;i++)
	dp[i][1]=1,dp[i][0]=0;
	ll mod = (ll)1e9 +7;
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=1;
	}
	for(int i=2;i<=k;i++)
	{
		/** BELOW LOOP RUNS IN NlogN **/
		for(int j=1;j<=n;j++)
		{
			for(int u=j;u<=n;u+=j)
			{
				dp[j][i]+=dp[u][i-1]%mod;
				dp[j][i]%=mod;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans+=dp[i][k]%mod;
		ans%=mod;
	}
//	for(int i=1;i<=n;i++){for(int j=1;j<=k;j++){cout<<dp[i][j]<<" ";}cout<<"\n";}
	cout<<ans%mod;
}
