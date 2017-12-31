
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;

ll pp(int x)
{
	ll ret = 1;
	for(int i=0;i<x;i++)
	{
		ret*=10;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	ll n,x;
	cin>>x;
	n = x;
	int num_digits = 0;
	while(n>0)
	{
		num_digits++;
		n/=10;
	}
	n = x;
	ll px = pp(num_digits-1);
	for(int i=1;i<=9;i++)
	{
		if(i*px>n)
		{
			cout<<(i*px)-n;
			return 0;
		}
	}
	px*=10;
	for(int i=1;i<=9;i++)
	{
		if(i*px>n)
		{
			cout<<(i*px)-n;
			return 0;
		}
	}
	
	return 0;
}
