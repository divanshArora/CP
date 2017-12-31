
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
		int ans= 1000000;
		int n;
		cin>>n;
		vector<pair<int,int>> vstart;
		vector<pair<int,int>> vend;		
		for(int i=0;i<n;i++)
		{
			int x,y;cin>>x>>y;
			vstart.pb({x,y});
			cin>>x>>y;
			vend.pb({x,y});
		}
		int x,y;
		for(int x=1;x<=50;x++)
		{
			for(int y=1;y<=50;y++)
			{
				int maxi=-1;
				for(int i=0;i<vstart.size();i++)
				{
					int temp = 0;
					if((x>=vstart[i].FF && x<=vend[i].FF) ||(x<=vstart[i].FF && x>=vend[i].FF) )
					{

					}
					else
					{
						temp+=min(abs(x-vstart[i].FF),abs(x-vend[i].FF));
					}
					if((y>=vstart[i].SS && y<=vend[i].SS) ||(y<=vstart[i].SS && y>=vend[i].SS) )
					{
					}
					else
					{
						temp+=min(abs(y-vstart[i].SS),abs(y-vend[i].SS));
					}
					maxi = max(temp,maxi);
				}
				ans = min(maxi,ans);
			}
		}
		if(ans==1000000)assert(1);

		cout<<ans<<'\n';

	}

	return 0;
}
