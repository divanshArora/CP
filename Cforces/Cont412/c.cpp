
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		ll x,y,p,q;
		cin>>x>>y>>p>>q;
		// if(p>=x)
		// {

		// }
		// else if(p<x)
		// {
		// 	if()
		// }
		// ll num =  p*y - q*x;
		// ll den = q-p;
		// if(den==num)
		// {
		// 	cout<<0<<'\n';continue;
		// }
		// if(den!=0 && num/den>=0 && (abs(num))%(abs(den))==0)
		// {
		// 	cout<<(abs(num))%(abs(den))<<'\n';
		// }
		// else
		// {
		// 	cout<<"-1\n";
		// }
		ll mv = q-p;
		if(mv==0)
		{
			if(x!=y)
			{
				cout<<-1<<'\n';
				continue;
			}
			else
			{
				cout<<0<<'\n';
				continue;
			}
		}
		ll num = p*y - q*x;
		
			if(num<0)
			{
				if((abs(num))/p==0)
				{
					num=0;
				}
				else
				{
					num+= (((abs(num))/p)+1)*p;
				}
			}
		
		ll ans= 0;
		if(num%mv==0)
		{
			ans = num/mv;
		}
		else
		{	
			cout<<"here -1\n";

		}

	}
	return 0;
}
