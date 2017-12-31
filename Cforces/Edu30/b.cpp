
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

int gcd(int a, int b) {
  while (a > 0 && b > 0)
    if (a > b) a %= b;
    else b %= a;
  return a + b;
}

ll modpower(ll x, ll y, ll p) //x^y mod p
{
    ll res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y %2!= 0)
            res = (res*x) % p;
 
        // y must be even now
        y = y/2;
        x = (x*x) % p;  
    }
    return res;
}
int arr[1000002]={0};
int dp[1000002]={0};
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		arr[i]= s[i]-'0';
		if(arr[i]==	0)arr[i]=-1;
		dp[i]= arr[i];	
		if(i!=0)
		dp[i]+=dp[i-1];
	}
	int ans= 0;
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
		{
		if(dp[i]==0)
		{
			ans = max(i+1,ans);
		}
		if(mp.find(dp[i])==mp.end())
		{
			mp[dp[i]]=i;
		}
		else
		{	
			mp[dp[i]]=min(i,mp[dp[i]]);
		}
		}		

	for(int i=0;i<n;i++)
	{
		if(mp.find(dp[i])!=mp.end())
		{
			//cout<<" --> "<<i<<" "<< mp[dp[i]]<<endl;
			ans = max(ans,abs(i-mp[dp[i]]));
		}
	}	
	cout<<ans;
	return 0;
}
