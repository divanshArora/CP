
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	ll dp[3][n+1];
	for(int i=0;i<3;i++){
		dp[i][0]=0;
		dp[i][1] = 0;
		dp[i][2] = 1;
	}
	ll mod = (ll)1e9 + 7;
	for(int i=3;i<=n;i++)
	{
		
	}
}