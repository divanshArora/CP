
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
	int x,y,z,m;
	cin>>x>>y>>z>>m;
	for(int i=1;i<=2*x;i++)
	{
		for(int j=1;j<=2*y;j++)
		{
			for(int k=1;k<=2*z;k++)
			{
				if(x<=i && 2*x>=i && y<=j && 2*y>=j && z<=k && 2*z>=k && m<=i && m<=j && m<=k && 2*m>=k && i>j && j>k && 2*m<i && 2*m<j)
				{
					cout<<i<<'\n'<<j<<'\n'<<k;
					return 0;
				}
			}
		}
	}
	cout<<"-1";
	return 0;
}
