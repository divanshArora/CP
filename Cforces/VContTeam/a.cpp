
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

vector< vector< int > > levels(5001);


bool visited[5001]={0};


void dfs(int node, int level,	vector< vector< int> >& graph)
{
	cout<<"level = "<<level<< " node = "<<node<<endl; 
	levels[level].pb(node);
	cout<<"pushed "<<node << " to level "<<level<<endl;
	visited[node] = true;
	for(int i=0;i<graph[node].size();i++)
	{
		int mynode = graph[node][i];
		if(visited[i]==false)
		{
			dfs(mynode,level+1,graph);
		}
	}
}

pair<int,int> numprom(int cnt)
{
	ll ans =0;
	int i=0;	
	for(i=0;i<levels.size();i++)
	{
		if(levels[i].size()<=cnt)
		{
			cnt-=levels[i].size();
			ans+=levels[i].size();
		}
		else
		{
			break;
		}
	}
	return {ans,i};
}

int main()
{
	ios_base::sync_with_stdio(false);
	int a,b,e,p;
	cin>>a>>b>>e>>p;
	vector< vector< int> > graph(e+1);
	for(int i=0;i<p;i++)	
	{
		int a,b;
		cin>>a>>b;
		graph[a].pb(b);
	}
	for(int i=0;i<e;i++)
	{
		if(!visited[i])
		dfs(i,0,graph);
	}
	pair<int,int> myl= numprom(b); 
	ll ans2 =0;
	cout<<numprom(a).FF<<'\n'<<myl.FF<<'\n';
	for(int i=myl.SS+1;i<e;i++)
	{
		ans2+=levels[i].size();
	} 
	cout<<ans2<<'\n';
	return 0;
}
