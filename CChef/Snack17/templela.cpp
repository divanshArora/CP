
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;


int main()
{
	ios_base::sync_with_stdio(false);
	int s;
	cin>>s;
	while(s--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)cin>>arr[i];
			int flag =0;
		if(n%2)
		{
			int cnt = 1;
			for(int i=0;i<n/2;i++)
			{
				if(arr[i]!=cnt)
				{
					flag =1;
				}
				cnt++;
			}
			for(int i=n/2;i<n;i++)
			{
				if(arr[i]!=cnt)
				{
					flag =1;
				}
				cnt--;
			}
		}else flag=1;

		if(flag)
		{
			cout<<"no\n";
		}
		else
		{
			cout<<"yes\n";
		}

	}
	return 0;
}
