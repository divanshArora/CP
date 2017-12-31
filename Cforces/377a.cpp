
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;

int x[4] = {1,-1,0,0};
int y[4] = {0,0,1,-1};

string mat[510];


vector< vector < pair<int , int > > > vpp(500*500+5);

int k;
void dfs(int srcx, int srcy, int n, int m, int depth)
{
	(mat[srcx])[srcy] = '-';
	vpp[depth].pb({srcx,srcy});
	for(int i=0;i<4;i++)
	{
		if(srcx+x[i]<n &&  srcx+x[i]>=0 && srcy+y[i]<m && srcy+y[i]>=0 &&  (mat[srcx+x[i]])[srcy+y[i]]=='.')
		{
			dfs(srcx+x[i],srcy+y[i],n,m, depth+1);
		}
	}
	if(k>0)
	{
		mat[srcx][srcy]='X';
		k--;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);

	int n,m;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		mat[i] = s;
	}


	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if((mat[i])[j]=='.')
			{
				dfs(i,j,n,m,0);
				i=n+1;
				break;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if((mat[i])[j]=='-')
			{
				cout<<'.';
			}
			else
			{
				cout<<mat[i][j];
			}
			//cout<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
