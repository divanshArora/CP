
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
	int t;
	cin>>t;
	while(t--)
	{
		int n,num_d;
		cin>>n>>num_d;
		priority_queue<pair<ll , ll>> pq;//sadness s, num lectures t 
		vector< vector< pair< ll, ll > > > days(num_d+1);
		for(int i=0;i<n;i++)
		{
			ll d,t,s;
			cin>>d>>t>>s;
			d--;
			days[d].pb({s,t});
		}	
		for(int i=0;i<num_d;i++)
		{
			for(int j=0;j<days[i].size();j++)
			{
				pq.push(days[i][j]);
			}
			if(!pq.empty())
			{
				pair<ll,ll> tp = pq.top();
				pq.pop();
				tp.second--;
				if(tp.second!=0)
				{
					pq.push(tp);
				}
			}
		}
		ll ans = 0;
		while(!pq.empty())
		{
			pair<ll, ll> tp = pq.top();
			pq.pop(); 	
			ans+= tp.first*tp.second;
		}
		cout<<ans<<'\n'	;
	}
	return 0;
}
