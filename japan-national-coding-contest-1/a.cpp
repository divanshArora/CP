
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;

ll pow(int x)
{
	if(x<0)return 0LL;
	if(x==0)return 1LL;
	if(x==2)return 4LL;
	ll temp = pow(x/2)%MOD;
	if(x%2==0)
	{
		return ((temp%MOD) * (temp%MOD))%MOD;
	}
	else
	{
		return ((temp%MOD) * (temp%MOD) * 2)%MOD;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int r,n;
		cin>>n>>r;
		if(n==1){cout<<0<<endl;continue;}
		ll ans =0;
		ll x=-1,y=-1;
		if(n%2==0)
		{
			 x = pow((n-1)/2)%MOD; //blue
			 y = pow((n/2) -1) %MOD;
		}
		else
		{
			 x = pow(n/2)%MOD;
			 y = pow((n-1)/2 -1)%MOD; 
		}
		if(r==1) //red
		{
			ans = y;	
		}
		else if(r==2) //blue
		{
			ans = x-1;
		}
		else
		{
			ans = (x+y-1)%MOD;
		}
		cout<<ans%MOD<<endl;
	}

}
