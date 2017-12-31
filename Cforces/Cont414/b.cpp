
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;

vector<long double> v;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n,h;
	cin>>n>>h;
	long double area = ((long double)h)*0.5;
	long double pa = area/(long double )n;	

	for(ll i=1;i<=n-1;i++)
	{
		long double ans = sqrt((long double)i/(long double)n)*h;
		cout<<setprecision(15)<<ans<<" ";
	}

	return 0;
}
