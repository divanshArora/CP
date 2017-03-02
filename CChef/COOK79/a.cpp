#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
 
long long int dp[100001];
 
int main()
{	
 
 
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		int ba[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			ba[i]=0;
		}
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]>=0)
			{
				if(i-arr[i]+1<0)
				{
					flag=1;
				}
				else
				{
					if(arr[i-arr[i]+1]==-1)
					ba[i-arr[i]+1]=1;
				}
			}
 
		}
		int prev=ba[0];
		long long int ans = 1;
 
		vector<int> v; 
		for(int i=0;i<n;i++)
		{
			if(ba[i]==1)
			{
				int j=i;
				while(j<=n-1 && arr[j]==-1)
				{
					ba[j]=1;
					j++;
				}
				i=j-1;
			}
		}
 		
		for(int i=0;i<n;i++)
		{
			if(ba[i]==0)
			{
				int j=i;
				int countx = 0;
				while(j<=n-1 && arr[j]==-1 && ba[j]==0)
				{
					j++;
					countx++;
					cout<<"countx "<<countx<<endl;
				}
				v.push_back(countx);
				i=j-1;
			}
		}


		// for(int i=0;i<n;i++)
		// {
		// 	cout<<ba[i]<<" ";
		// }
 
 
 
 
		for(int i=0;i<n;i++)
		{	
			if(ba[i]==0&&arr[i]==-1&&i!=0)
			{
				
				ans%=MOD;
				ans*=2;
				ans%=MOD;
			}
 
		}
		int flag2 = 0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]==-1)flag2=1;
		}
		if(flag2==0)flag =1;
		if(flag==0)
		cout<<ans%MOD<<endl;
		else
		cout<<0<<endl;
	}	
 
 
	return 0;
} 