using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007
#define INF 1000000000000
typedef vector<ll> vll;

vector<pair<ll,ll>> vp;




int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int tt=0;tt<t;tt++)
	{
		vp.clear();
		ll d,n;
		cin>>d>>n;

		for(int i=0;i<n;i++)
		{
			ll k,s;
			cin>>k>>s;
			vp.pb({k,s});
		}
		double metting_pt = (double)d;
		double last_time = ((double)(d-vp[n-1].FF))/((double)(vp[n-1].SS));
		for(int i=n-2;i>=0;i--)
		{
			if(vp[i].SS<vp[i+1].SS)
			{
				metting_pt = (double)d;
				last_time = ((double)(d-vp[i].FF))/((double)(vp[i].SS));	
			}
			else
			{
				metting_pt =  
			}
		}





			cout<<"Case #"<<tt	+1<<": "<<"IMPOSSIBLE"<<endl;	
		


	}
}	
