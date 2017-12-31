
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
		int arr[7];
		ll sm=0;
		for(int i=0;i<6;i++)
		{
			cin>>arr[i];
			sm+=arr[i];
		}
		for(int i=0;i<6;i++)
		{
			for(int j=i+1;j<6;j++)
			{
				for(int k=j+1;k<6;k++)
				{
					if(arr[i]+arr[j]+arr[k]==sm/2 && sm%2==0)
					{
						cout<<"YES";
						return 0;
					}
				}
			}
		}
		cout<<"NO";


		return 0;
	}
