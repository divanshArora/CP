
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;


bool fn(ll s, ll rank)
{
	ll i = (s/50)%475;
	for(int  j=0;j<25;j++)
	{
		i = (i*96 + 42)%475;
		if(rank==i+26)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	ll p,x,y;
	cin>>p>>x>>y;
	ll rank = p;
	ll fact = (x-y)/50;
	ll mini = x - fact*50;
	ll ans  =-1;
	for(ll i=mini;i<=50*20000000;i+=50)
	{
		if(fn(i,rank)==true)
		{
			 ans = i;
			 break;
		}
	}
	if(ans-x<=0)
	{
		cout<<0;return 0;
	}

	if((ans-x)%100==0)
	{
		cout<<max((ans-x)/100,0LL);
	}
	else
	{
		cout<<max(((ans-x)/100) +1,0LL);
	}

	return 0;
}
