using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;

ll nCr(ll n, llr)
{
	ll ans = 1;
	if(r>n-r)
	{
		r = n-r;
	}
	for(int i=1;i<=r;i++,n--)
	{
		if(n%i==0)
		{
			ans*=n/i;
		}
		else if(ans%i==0)
		{
			ans=(ans/i)*n;
		}
		else
		{
			ans = (ans*n)/i; 
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);

	int m,n,k;
	cin>>m>>n>>k;
	double p;
	cin>>p;

}
