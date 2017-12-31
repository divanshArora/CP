
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

void help(vector< vector< pair< int,int> > > & graph, int n, int root, vector< bool> & visited,vector< bool> & outofvisited)
{
	visited[root] = true;
	for(int i=0;i<graph[root].size();i++)
	{
		if((graph[root][i]).SS==0 && visited[graph[root][i].FF]==false && outofvisited[graph[root][i].FF]==false)
		{
			help(graph, n,graph[root][i].FF,visited,outofvisited);
		}
	}

}

int count_components(vector< vector< pair< int,int>>> & graph, int n, 	vector<bool> & visited, vector<bool> & outofvisited)
{	
	int ans =0;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false && outofvisited[i]==false)
		{
			ans++;
			help(graph, n,i,visited, outofvisited);
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector<vector<pair<int, int> > > graph(n+1);
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			graph[a].pb({b,0});
			graph[b].pb({a,0});
		}
		vector< vector <int> > deg(n+1);
		for(int i=0;i<n;i++)
		{
			int mydeg =graph[i].size();
			deg[mydeg].pb(i);
		}
		// for(int i=0;i<n+1;i++)
		// {
		// 	cout<<deg[i].size()<<" ";
		// }
		// cout<<"\n\n";
		vector<int> ansvec(n+1,0);
		vector< bool> outofvisited(n+1, false);
		vector< bool> idaho(n+1, false);
		int cnt = count_components(graph,n,idaho,outofvisited);
		ansvec[0] = cnt-1;
		for(int i=1;i<n;i++)
		{
			if(deg[i].size()>0){
				int man=0;
				vector< bool> visited(n+1, false);
				int fan=deg[i].size();
				for(int j=0;j<deg[i].size();j++)
				{
					int u  = deg[i][j];
					outofvisited[u]= true;			
				}
				int cnt = count_components(graph,n,visited,outofvisited);
				if(fan>0 && cnt>0)	
				{
					man = fan+cnt-1;
				}
				else if(fan==0 && cnt==0)
				{
				}
				else if(fan==0)
				{
					man = cnt-1;
				}
				else if(cnt==0)
				{
					man = fan-1;
				}
				//cout<<"fan = "<<fan<<" cnt = "<<cnt<<'\n';
				ansvec[i]=man;
			}
		}
		for(int i=1;i<n;i++)
		{
			ansvec[i]+=ansvec[i-1];
		}
		for(int i=0;i<n;i++)
		{
			cout<<ansvec[i]<<" ";
		}cout<<'\n';


	}
	return 0;
}
