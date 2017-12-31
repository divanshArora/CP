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

ll a[(int)7e6]={0};

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;
	int x[n],y[n];
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
		a[x[i]]=1;
	}		
	for(int i=0;i<n;i++)
	{
		cin>>y[i];
		a[y[i]]=1;
	}
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[x[i]^y[j]]==1)
			{
				ans+=2;
				if(x[i]==y[j])ans--;
			}
		}
	}
	if(ans%2==0)
	{
		cout<<"Karen";
	}
	else
	{
		cout<<"Koyomi";
	}
	return 0;
}
