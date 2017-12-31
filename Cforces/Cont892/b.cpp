
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;
int ans[1000002]={0};

int runx(int a, int b)
{
	for(int i=a;i>=b;i--)ans[i]=-1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int arr[n];
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=n-1;i>=0;i--)
	{
		if(arr[i]>0)
		v.pb({i-1,max(0,i-arr[i])});
	}
	pair<int,int> prev = v[n-1];

	for(int i=prev.FF;i>=prev.SS;i--)
	{
		ans[i]=-1;
	}
	for(int i=n-2;i>=0;i--)
	{
			if(v[i].SS<=prev.SS)
			{
				if (v[i].FF>prev.SS)
				{
					prev.SS = v[i].SS;
				}
				else
				{
					runx(prev.FF,prev.SS);
					prev.FF = v[i].FF;
					prev.SS = v[i].SS;
				}
			}
	}
					runx(prev.FF,prev.SS);

	int cnt=0;
	for(int i=0;i<n;i++)if(ans[i]==0)cnt++;
	cout<<cnt;
	return 0;
}
