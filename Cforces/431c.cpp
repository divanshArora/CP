
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;


ll dp[101][2]={{0}};


int main()
{
	ios_base::sync_with_stdio(false);
	int n,k,d;
	cin>>n>>k>>d;	
	for(int i=0;i<=n;i++){dp[0][1]=0;dp[0][0]=0;}
		dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k&&i-j>=0;j++)
		{
			dp[i][0]%=MOD;
			dp[i][1]%=MOD;
			dp[i][0] += dp[i-j][0];
			if(j>=d)
			{
				dp[i][1] += dp[i-j][0]%MOD;
			}
			else
			{
				dp[i][1] += dp[i-j][1]%MOD;
			}
		}
	}
	// for(int i=0;i<=n;i++)
	// {
	// 	cout<<dp[i][0]<<" ";
	// }
	// cout<<'\n';
	// for(int i=0;i<=n;i++)
	// {
	// 	cout<<dp[i][1]<<" ";
	// }
	cout<<dp[n][1]%MOD;
}
