#include <iostream>
#define F first
#define S second


typedef long long int ll;

using namespace std;

ll arr[(int)1e5+3];

pair< int, int> dp[(int)1e5 +3];


int main()
{
	ios_base::sync_with_stdio(false);

	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	for(int i=0;i<n;i++)
	{
		int start = i;
		int end = i;
		int flag=0;
		while(end<n && arr[end]==arr[start])
		{
			end++;
		}
		for(int j=start;j<end;j++)
		{
			dp[j]=make_pair(start,end-1);
		}
		i = end-1;
	}
	for(int i=0;i<m;i++)
	{
		int l,r,k;cin>>l>>r>>k;
		int mid = (l+r+1)/2;
		int mid_index = mid-1;
		l--;r--;
		int left = max(l,dp[mid_index].F);
		int right = min(r,dp[mid_index].S);
		if(right-left+1>=k)
		{
			cout<<arr[mid_index]<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
	}









	return 0;
}