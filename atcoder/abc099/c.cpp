
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
	vector<ll> v;
	v.pb(1);
	int n;
	cin>>n;	
	int k = 9;
	ll c = k;
	while(c<=n)
	{
		v.pb(c);
		c*=k;
	}
	k = 6;
	c = k;
	while(c<=n)
	{
		v.pb(c);
		c*=k;
	}
	sort(v.begin(),v.end());
	// ll arr[v.size()][2];
	// for(int j=0;j<=n;j++)
	// {
	// 	arr[0][j]=j;
	// }
	// for(int i=0;i<v.size();i++)
	// {
	// 	arr[i][0]=0;
	// }

	// for(int i=1;i<v.size();i++)
	// {
	// 	for(int j=1;j<=n;j++)
	// 	{
	// 		if(j-)
	// 		arr[i][j] = 1 + arr[i-1][j-]
	// 	}	
	// }
	//src: https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/
	ll V = n;
	ll table[n+1];
    table[0] = 0;
 
    // Initialize all table values as Infinite
    for (int i=1; i<=V; i++)
        table[i] = INT_MAX;
 
    // Compute minimum coins required for all
    // values from 1 to V
    for (int i=1; i<=V; i++)
    {
        // Go through all coins smaller than i
        for (int j=0; j<v.size(); j++)
          if (v[j] <= i)
          {
              ll sub_res = table[i-v[j]];
              if (sub_res != INT_MAX && sub_res + 1 < table[i])
                  table[i] = sub_res + 1;
          }
    }
	cout<<table[V];

}
