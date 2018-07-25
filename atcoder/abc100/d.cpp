
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
const int maxn = 1001;
ll x[maxn],y[maxn],z[maxn];
	
ll arr[1000][1000];

ll fn(int curr, ll n, ll m, ll b, ll t, ll p)
{
	if(n-curr<m)
	{
		arr[curr][m]= 0;
		return arr[curr][m];
	}
	if(curr>=n)
	{
		if(m>0)
		{
			arr[curr][m]= 0;
			return arr[curr][m];
		}
		else
		{
			arr[curr][m]= abs(b)+abs(t)+abs(p);
			return arr[curr][m];			
		}
	}
	if(m==0)
	{
		arr[curr][m]= abs(b)+abs(t)+abs(p);
		return arr[curr][m];
	}
	ll u,v;
	if(arr[curr+1][m-1]>=0)u = arr[curr+1][m-1];
	else u = (fn(curr+1,n,m-1,b+x[curr],t+y[curr],p+z[curr]));
	if(arr[curr+1][m]>=0) v= arr[curr+1][m];
	else v = fn(curr+1,n,m,b,t,p);
	arr[curr][m]= max((v),(u));
	return arr[curr][m];
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i]>>z[i];
		for(int j=0;j<m;j++)arr[i][j]=-1;
	}
	ll ans  =  fn(0,n,m,0LL,0LL,0LL);
	cout<<ans;
}
