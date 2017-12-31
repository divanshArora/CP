
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

int day[1000002]={0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int prev =-1;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		int j=x;
		while(day[j]==1 || j<prev)
		{	
			j+=y;
		}	
		day[j] = 1;
		prev = j;
	}
	for(int i=1000001;i>=0;i--)
	{
		if(day[i]>0)
		{
			cout<<i;
			return 0;
		}
	}


	return 0;
}
