
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

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	ll arr[n];
	ll sm=0;
	for(int i=0;i<n;i++)cin>>arr[i],arr[i]-=i,sm+=arr[i];
	sort(arr,arr+n);
	ll ans = 0;
	if(n%2!=0)
	{
		ans = arr[n/2];
	}
	else
	{
		ll mini = 0;
		for(int i=0;i<n;i++)
		{
			mini+=abs(arr[i]-arr[n/2]);
		}
		ll tmp= 0;
		for(int i=0;i<n;i++)
		{
			tmp+=abs(arr[i]-arr[n/2-1]);
		}
		if(tmp>mini)
		{
			ans = arr[n/2];
		}else ans = arr[n/2-1];
	}
	ll tt = 0;
	for(int i=0;i<n;i++)tt+=abs(arr[i]-ans);
	cout<<tt;
}
`