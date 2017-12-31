
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

vector<ll> v;


ll pp(int x)
{
	if(x==0)return 1;
	ll temp = (pp(x/2)%MOD)%MOD;
	temp%=MOD;
	if(x%2==0)
	{
		return (((temp%MOD)*(temp%MOD))%MOD)%MOD;
	}
	else
	{
		return (((((temp%MOD)*(temp%MOD))%MOD)%MOD)*2)%MOD;	
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ll a;
		cin>>a;
		v.pb(a);
	}
	sort(v.begin(),v.end());
	ll sm1  =0;
	for(int i=0;i<n;i++)
	{	
		sm1%=MOD;
		sm1+=((v[i]%MOD)*(pp(n-i-1)%MOD))%MOD;
		sm1%=MOD;
	}

	ll sm2 = 0;
	for(int i=0;i<n;i++)
	{
		sm2%=MOD;
		sm2+=((v[i]%MOD)*(pp(i)%MOD))%MOD;
		sm2%=MOD;
	}
	ll fan = ((sm2+MOD)%MOD - sm1%MOD)%MOD;
	cout<<(fan+MOD)%MOD;
	return 0;
}
