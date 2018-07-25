
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

ll gcd(ll a, ll b) {
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
    return res%p;
}

int main()
{
	ios_base::sync_with_stdio(false);
	ll x,k;
	ll mod = 1000000007;
	cin>>x>>k;
	if(x==0){cout<<0;return 0;}
	if(k==0){cout<<(2*(x%mod))%mod;return 0;}
	ll twopk = modpower(2,k,mod)%mod;
//	cout<<"twopk = "<<twopk;
	ll ans = ((twopk%mod)*(twopk%mod))%mod;
	ans%=mod;ans*=(x%mod);
	//cout<<"init ans = "<<ans<<'\n';

	ll b = modpower(2,k-1,mod)%mod;
	b = (((twopk -1)%mod)*(b%mod))%mod;
	ll minv = modpower(twopk,mod-2,mod)%mod;
	ans = 2*(((((ans+mod-b)%mod)*minv)%mod))%mod;
	cout<<ans%mod;
}
