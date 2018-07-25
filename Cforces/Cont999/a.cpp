
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

	int n,k;
	cin>>n>>k;
	int u=0,v=n-1;
	int arr[n];
	for(int i=0;i<n;i++)
	{	
		cin>>arr[i];
	}
	ll ans = 0;
	while(u<n)
	{
		if(arr[u]<=k)
		{
			ans++;
			u++;
		}
		else
		{
			break;
		}
	}
	while(v>u)
	{
		if(arr[v]<=k)
		{
			ans++;
			v--;
		}
		else{
			break;
		}
	}
	cout<<ans;

}
