
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
	int n,c;
	cin>>n>>c;
	ll d[c][c];
	for(int i=0;i<c;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>d[i][j];
		}
	}
	ll init[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>init[i][j];
			init[i][j]--;
		}
	}
	ll arr[31][3];
	for(int i=0;i<31;i++)for(int j=0;j<3;j++)arr[i][j]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int m = (i+j)%3;
			for(int k=0;k<c;k++)
			{
				arr[k][m]+=d[init[i][j]][k];
			}
		}
	}
	ll ans = 100000000000000000;
	for(int i=0;i<c;i++)
	{
		for(int j=0;j<c;j++)
		{
			for(int k =0;k<c;k++)
			{
				if(i!=j && j!=k && k!=i)
				{
					ll kx = arr[i][0] + arr[j][1] + arr[k][2];
					if(kx<ans)
					{
						ans = kx;
					}
				}
			}
		}
	}
	cout<<ans;


}
