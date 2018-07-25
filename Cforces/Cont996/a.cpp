
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin>>n;
	ll ans =0;
	ll tx = n/100;
	ans+=tx;
	n-=100*(n/100);

	tx = n/20;
	ans+=tx;
	n-=20*(n/20);

	tx = n/10;
	ans+=tx;
	n-=10*(n/10);

	tx = n/5;
	ans+=tx;
	n-=5*(n/5);

	tx = n/1;
	ans+=tx;
	n-=1*(n/1);
	cout<<ans;
}
