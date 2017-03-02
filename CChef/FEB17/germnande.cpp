#include <iostream>
#define ll long long 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int o1,o2;
		cin>>o1>>o2;
		int n = o1*o2;
		int arr[n+o2+1];
		int val[n+o2+1];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}

		for(int i=0;i<o2;i++)
		{
			arr[n+i]=arr[i];
		}

		val[0]=0;
		for(int i=0;i<n+o2;i++)
		{
			val[i]=0;
			if(arr[i]==1)
			{
				val[i]++;
			}
			if(i>=1)
			val[i]+=val[i-1];
		}


		int dp[n+o2];for(int i=0;i<n+o2;i++)dp[i]=0;
		for(int i=o2;i<n+o2;i++)
		{
			dp[i]+=dp[i-o2];
			if(val[i]-val[i-o2]>o2/2)
			{
				dp[i]++;
			}
		}
		// cout<<"DP = "<<endl;
		// for(int i=0;i<n+o2;i++)
		// {
		// 	cout<<dp[i]<<" ";
		// }
		// cout<<endl<<endl;
		// cout<<"VAL = "<<endl;
		// for(int i=0;i<n+o2;i++)
		// {
		// 	cout<<val[i]<<" ";
		// }
		// cout<<endl<<endl;
		// cout<<"arr = "<<endl;
		// for(int i=0;i<n+o2;i++)
		// {
		// 	cout<<arr[i]<<" ";
		// }
		// cout<<endl<<endl;
		int maxi = -1;
		for(int i=0;i<n+o2;i++)
		{
			maxi = max(dp[i],maxi);
		}
		if(maxi>o1/2)
		{
			cout<<1<<endl;
		}
		else 
		{
			cout<<0<<endl;
		}
	}


	return 0;
}