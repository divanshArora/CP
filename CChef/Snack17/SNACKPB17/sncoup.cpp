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
		int n;
		cin>>n;
		string mat[2];
		cin>>mat[0];
		cin>>mat[1];
		int top=0,bottom=0;
		for(int i=0;i<n;i++)
		{
			if(mat[0][i]=='*')
			{
				top++;
			}
			if(mat[1][i]=='*')
			{
				bottom++;
			}
		}
		ll ans = 0;
		set<int>s;
		if(top!=0 && bottom!=0)
		{
			ans++;
			for(int i=0;i<n;i++)
			{
				if(mat[0][i]=='*')
				{
					s.insert(i);
				}
				if(mat[1][i]=='*')
				{
					s.insert(i);
				}
			}
			ans+=s.size()-1;
		}
		else
		{
			if(bottom==0)ans+=top-1;
			else ans+=bottom-1;
		}	
		cout<<ans<<'\n';
	}


	return 0;
}
