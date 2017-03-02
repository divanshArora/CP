#include <iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}

		long long int ans = 0;
		int offset=n;
		for(int i=0;i<n;i++)
			{
				if(arr[i]==0)
				{
					offset= i;
					break;
				}
			}
		for(int i=0;i<n;i++)
		{
			if(arr[i]==0)
			{
				ans+=1000;
			}
			
		}
		cout<<ans+((n-offset)*100)<<endl;

	}

}