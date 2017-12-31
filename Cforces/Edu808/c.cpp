
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007


vector< pair<int, int> > v;

bool mycomp( pair<int,int> a, pair<int,int> b)
{
	return a.SS < b.SS;
}

int main()
{
	ios_base::sync_with_stdio(false);

	int n,w;
	cin>>n>>w;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.pb({x,i});
	}
	sort(v.begin(),v.end());
	int arr[103];
	for(int i=0;i<n;i++)
	{	
		arr[i] = (v[i].FF+1)/2;
		w-=arr[i];
		if(w<0)
		{
			cout<<"-1";
			return 0;
		}
	}
	int i=n-1;
//	cout<<"arr====\n";
// 	for(int i=0;i<n;i++)
// 	{
// 		cout<<arr[i]<<" ";
// 	}
// //	cout<<"w = "<<w<<endl;
	while(i>=0 && w>0)
	{
//		cout<<"w in = "<<w<<endl;
		int to_pour = min(v[i].FF-arr[i],w);
//		cout<<"to pour = "<<to_pour<<endl;
		w-=to_pour;
		arr[i]+=to_pour;
		v[i].FF = arr[i];
		i--;
	}
	while(i>=0)
	{
		v[i].FF=arr[i];
		i--; 
	}
	sort(v.begin(),v.end(),mycomp);
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i].FF<<" ";
	}


	return 0;
}
