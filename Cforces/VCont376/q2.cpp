#include <iostream>
#include <vector>
using namespace std;

int arr[(int )2e5+5];

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;

	for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}

	for(int i=0;i<n;i++)
	{
		if(arr[i]<0)
		{
			cout<<"NO";
			return 0;
		}
		else if(arr[i]%2==0)
		{
			arr[i] =0;
		}
		else if(arr[i]%2!=0)
		{
			if(i==n-1)
			{
				cout<<"NO";
				return 0;
			}
			else 
			{
				arr[i]=0;
				arr[i+1]--;
			}

		}
	}
	cout<<"YES";






	return 0;
}