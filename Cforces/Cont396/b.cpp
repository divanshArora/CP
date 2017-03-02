#include <iostream>
#include <algorithm>
#define F first
#define S second


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;
	long long int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(int i=2;i<n;i++)
	{
		if(arr[i]<arr[i-1]+arr[i-2])
		{
			cout<<"YES";
			return 0;
		}

	}
	cout<<"NO";
	return 0;

return 0;
} 