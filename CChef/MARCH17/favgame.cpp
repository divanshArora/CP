#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

int t[1001];
ll ans=0;
bool visited[1001];
ll dist[1001];

ll dfs(vector<vector < ll > > &graph,  int src)
{


	visited[src]= true;

	vector< int > temp;

	for(int i=0;i<graph[src].size();i++)
	{
		
	}



















}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int tcases;
	cin>>tcases;
	while(tcases--){
		ans=0;
		int n,h;
		vector< vector < ll > > graph(n+1);
		for(int i=0;i<n;i++)
		{	
			dist[i]=0;
			visited[i]=false;
			int x;
			cin>>x;
			while(x--)
			{
				ll a;
				cin>>a;a--;
				graph[i][a] = t[i];
			}
		}
	}	



	return 0;
}


