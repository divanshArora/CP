#include <iostream>
#define ll long long
#define F first
#define S second
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

		ll n;
		cin>>n;
		pair<int, int> arr[n];
		ll dp[n];
		ll rating[n];
		for(int i=0;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			arr[i] = {a,b};
		}
		dp[0] = arr[0].F;
		int index =-1;
		for(int i=1;i<n;i++)
		{
			dp[i]=0;
			if(arr[i].S==arr[i-1].S)
			{
				dp[i]=dp[i-1]+arr[i].F;
			}
			else
			{
				dp[i]=dp[i-1]+arr[i].F;
				if(arr[i].S==2)
				{
					if(dp[i]>=dp[i-1])
					{
						cout<<"Impossible\n";
						return 0;
					}
					else
					{
						rating[i]=1899;
						index=i;
						break;
					}
				}
				else 
				{
					if(dp[i]<=dp[i-1])
					{
						cout<<"Impossible\n";
					}
					else
					{
						rating[i]=1899+arr[i].F;
						index= i;
						break;
					}
				}
			}


		}

		if(index==-1)
		{
			if(arr[0].S==2)
			{
				ll a = 0;
				for(int i=0;i<n;i++)
				{
					a+=arr[i].F;
				}
				cout<<1899+a<<'\n';
			}
			else
			{
				cout<<"Infinity\n";
			}
		}
		else
		{
			ll a = rating[index];
			for(int i=index+1;i<n;i++)
			{
				a+=arr[i].F;
				if((a<1900 && arr[i].S==1) || (a>=1900 && arr[i].S==2) )
				{
					cout<<"Impossible\n";
					return 0;
				}
			}
			cout<<a<<'\n';
		}


return 0;
}