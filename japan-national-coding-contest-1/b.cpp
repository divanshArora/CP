
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;


int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		ll l,r;
		cin>>l>>r;
		if(l==r)
		{
			ll c = (ll)pow(l+1,0.5);
			if(c*c==l)
			{
				cout<<1<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
		}
		else
		{
			cout<<(ll)pow(r,0.5) - (ll)pow(l-1,0.5)<<endl;

		}
	}
}
