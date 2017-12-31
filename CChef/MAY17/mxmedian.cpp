
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
	int t;
	cin>>t;
	while(t--)
	{

		int n;
		cin>>n;
		ll arr[(2*n)+2];
		arr[0]=-1;
		for(int i=1;i<=2*n;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+(2*n)+1);
		vll ans;
		for(int i=1;i<=n;i++)
		{
			ans.pb(arr[i+n]);
		}
		cout<<ans[ans.size()/2]<<endl;
		for(int i=1;i<=n;i++)
		{
			cout<<arr[i]<<" "<<arr[i+n]<<" ";
		}	
		cout<<endl;


	}





	return 0;
}
