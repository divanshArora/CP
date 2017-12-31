
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

int mat[n][m];

int slide(int k, int j)
{
	std::deque<int> v;
	//k = min(k,n-i+1);
	int ones = 0;
	int ans = 0;
	for(int i=0;i<k;i++)
	{
		v.pb(mat[i][j]);
		if(mat[i][j]==1)
		{
			ones++;
			ans = max(ans,ones);
		}
	}
	for(int i=k;i<n;i++)
	{
		v.pb(mat[i][j]);
		if(mat[i][j]==1)
		{
			ones++;
		}
		if(v.front()==1)ones--;
		v.pop_front();
		ans = max(ans, ones);

	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>mat[i][j];
		}
	}
	int max_change = 0;
	for(int i=0;i<m;i++)
	{

	}
}
