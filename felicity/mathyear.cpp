
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

ll expi(int i, int j)
{
	return modpower(i,j,MOD) + modpower(i+j,j,MOD) + modpower(i+j -1,j,MOD) + modpower(i+j,j,MOD);
}

int main()
{
	ios_base::sync_with_stdio(false);
	ll mini = 1000000000;
	ll ans =0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(expi(i,j)==2018)
			{
				if(i+j<mini)mini=i+j, ans = modpower(i,j, MOD);

			}
		}
	}		
	cout<<ans;
}
