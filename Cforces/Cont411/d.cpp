
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;


ll num_a_before[int(1e6)+5]={0};
ll num_b_before[int(1e6)+5]={0};



ll pp(ll x)
{
	if(x==0)
	{
		return 1;
	}
	ll temp = pp(x/2)%MOD;
	if(x%2==0)
		{
			return ( (temp%MOD) * (temp%MOD) )%MOD; 
		}
		else
		{

			return ( (((temp%MOD) * (temp%MOD) )%MOD)* 2 )%MOD;	
		}
}



int main()
{
	ios_base::sync_with_stdio(false);
	string str;
	cin>>str;
	ll aa = 0;
	ll ans = 0;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='b')
		{
			ans%=MOD;
			ans+=pp(aa)-1;
			ans%=MOD;
		}
		else
		{
			aa++;
		}
	}
	cout<<ans%MOD;

}
