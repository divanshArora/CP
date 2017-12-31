
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
	int n,k;
	cin>>n>>k;
	ll sum = 0;
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x;
		sum+=x;
	}
	for(int i=0;;i++)
	{
		ll top = sum+k*i;
		ll down = (n+i);
		//cout<<"top = "<<top<<" down = "<<down<<endl;
		long double t = ((long double)top)/((long double)down);
		//cout<<"t = "<<t<<endl;
		double final =(round(t));
		if(round(((float)(sum+k*i))/((n+i)))>=k)
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}
