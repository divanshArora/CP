
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

	int t;cin>>t;
	while(t--)
	{	
		int n;
		cin>>n;
		ll sum=0;ll prod = 1;
		for(int i=0;i<n;i++)
		{
			int x;cin>>x;
			sum%+MOD;
			sum+=x;
			sum%=MOD;
			prod%=MOD;
			prod*=x;
			prod%=MOD;
		}
		ll ans = (((prod + sum)%MOD )*modpower(2,max(n-2,0),MOD))%MOD;
		cout<<ans<<'\n';
	}

	return 0;
}
