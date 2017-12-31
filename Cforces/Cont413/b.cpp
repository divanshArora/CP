
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;

ll arr[200001];
int a[200001];
int b[200001];
int main()
{
	ios_base::sync_with_stdio(false);

	multiset<ll> mat[4][4];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<n;i++)
	{
		mat[a[i]][b[i]].insert(arr[i]);
	}

	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int c;
		cin>>c;
		pair<int,int> ans;
		ll mini=100000000000000; 
		for(int i=1;i<=3;i++)
		{
			if(mat[c][i].size()>0){
			if(  *(mat[c][i].begin())<mini)
			{	
				mini = *(mat[c][i].begin());
				ans = {c,i};
			}}
		}
		for(int i=1;i<=3;i++)
		{
			if(mat[i][c].size()>0){
			if(*(mat[i][c].begin())<mini)
			{	
				mini = *(mat[i][c].begin());
				ans = {i,c};
			}}
		}
		if(mini==100000000000000)
		{
			cout<<"-1 ";
		}
		else
		{
			cout<<mini<<" ";
			auto it = mat[ans.FF][ans.SS].begin();
			mat[ans.FF][ans.SS].erase(it);
		}
	}


	return 0;
}
