
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
	n = 2*n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int go[n];fill(go,go+n,0);
	for(int i=0;i<n;i++)
	{
		if(go[i]==0)
		{
			for(int j=i+1;j<n;j++)
			{
				if(arr[j]==arr[i])
				{
					go[i]=1;
					go[j]=-1;
				}
			}
			for(int j=i-1;j>=0;j--)
			{
				if(arr[j]==arr[i])
				{
					go[i]=-1;
					go[j]=1;
				}
			}
		}
	}
	ll move[n];
	fill(move,move+n,0);
	for(int i=0;i<n;i++)
	{
		if(arr[i]==-1)
		{
			int j=i-1;
			ll cost = 0;
			while(arr[j]!=arr[i])
			{
				move[i]+=
			}
		}
		else
		{

		}
	}
}
