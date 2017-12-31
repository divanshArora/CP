
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

int dp[200001]={0};
int dp2[200001]={0};
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	dp[n-1]+=1;
	dp2[arr[n-1]]=1;
	for(int i=n-2;i>=0;i--)
	{
		dp[i]= dp[i+1];
		if(dp2[arr[i]]==0)
		{
			dp[i]++;
		}
		dp2[arr[i]]++;
	}
	int tot = 0;
	for(int i=0;i<200001;i++)
	{
		if(dp2[i]!=0)
		{
			tot++;
		}
	}	
	for(int i=n-1;i>=0;i--)
	{	
		if(dp[i]==tot)
		{
			cout<<arr[i];
			return 0;
		}
	}

	return 0;
}
