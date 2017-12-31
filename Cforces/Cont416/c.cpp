
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;

int arr[5001];

int graph[5001][5001]={{0}};

int count[5002]={0};
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
		count[arr[i]]++;
	}
	for(int i=1;i<=5000;i++)
	{
		if(count[i]>1)
		{
			for(int j=0;j<n;j++)
			{
				if(arr[j]==i)
				{
					j++;
					while(j<n && arr[j]==i)
					{
						graph[i][arr[j]] =1;
						j++;
					}
					i=j-1;
				}
			}
		}
	}
	
	return 0;
}
