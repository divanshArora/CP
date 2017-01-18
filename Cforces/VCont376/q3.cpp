#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int c[(int)2e5+4];
int dp[(int)2e5+5]={0};
 int l_arr[(int)2e5 + 4];
 int r_arr[(int)2e5 + 4];
int main()
{
	ios_base::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	long long int ans=0;
	for(int i=0;i<m;i++)
	{
		int l,r;
		cin>>l>>r;
		l--;r--;
		l_arr[i] = l;
		r_arr[i] = r;
		if(l!=r)
		{
			dp[l]++;
			dp[r]++;

		}
	}

	for(int i=0;i<m;i++)
	{
		if(c[l_arr[i]]!=c[r_arr[i]])
		{
			if(dp[l_arr[i]]<=dp[r_arr[i]])
			{
				c[l_arr[i]]= c[r_arr[i]];
			}
			else
			{
				c[r_arr[i]]= c[l_arr[i]];	
			}
			ans++;
	
		}
	}
	cout<<ans;

	return 0;
}