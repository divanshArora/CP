using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;


ll wt[(int)1e5+2];
bool visited[(int)1e5+2]={false};
ll dist[(int)1e5+2] = {0};
bool sad[(int)1e5+2] = {false};
ll ans = 0;
void dfs(int src,vector<vector<pair<int,ll> >>  &tree, bool isSad)
{
	//cout<<"src = "<<src<<" is sad = "<<isSad<<endl;
	visited[src] = true;
	
	if(dist[src]>wt[src])
	{
		sad[src] = 1;
		isSad= true;
		//ans++;
		// cout<<"src "<<src<<" became sad"<<endl;
		//cout<<"ans = "<<ans<<endl;
	}
	if(isSad==true)
	{
		ans++;
		//cout<<"ans = xx "<<ans<<endl;
	}
	for(int i=0;i<tree[src].size();i++)
	{
		pair<int , ll> p = tree[src][i];
		int u = p.FF;
		if(visited[u]==0)
		{
			dist[u] = dist[src] + tree[src][i].SS;
			dist[u]= max(dist[u],0LL);
			dfs(u,tree,isSad);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>wt[i];
	}
	vector<vector<pair <int,ll > >  > tree(n+1);
	for(int i=0;i<n-1;i++)
	{
		int a;
		ll b;
		cin>>a;cin>>b;
		a--;
		tree[a].pb({i+1,b});
		tree[i+1].pb({a,b});
		// tree[a][i] = b;
		// tree[i][a] = b;
	}
	// cout<<"tree = "<<endl;
	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<tree[i].size();j++)
	// 	{
	// 		cout<<tree[i][j].FF<<" ";
	// 	}
	// 	cout<<endl;
	// }
 	dfs(0,tree,false);

	cout<<ans;
}