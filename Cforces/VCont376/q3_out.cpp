#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace std;
bool visited[200001]={0};
int colors[200001];
map< int , long long int > mp;

int  dfs_util(vector< vector <int > > &graph, int n, int src)
{
	stack<int> st;
	st.push(src);
	int max_color =-1;
	int total=0;
	mp.clear();
	// mp.insert(make_pair(src,1));
	// max_color = colors[src];
	while(!st.empty())
	{
		int s = st.top();
		st.pop();
		if(visited[s]==false)
		{
			visited[s] = true;
		// color_dp[colors[s]]++;
		// if(color_dp[s]>=max_color)
		// {
		// 	max_color = color_dp[s];
		// }
			total++;
			//cout<<" s  = "<<mp[s]<<endl;
			mp[colors[s]]++;
			//cout<<"mps = "<<mp[s]<<endl;
			if(mp[colors[s]]>=max_color)
				max_color = mp[colors[s]];

		}

		for(int i=0;i<graph[s].size();i++)
		{
			int b = graph[s][i];
			if(visited[b]==false)
			{
				st.push(b);	
			}
		}
	}
	//cout<<"total = "<<total<<"max_color = "<<max_color<<endl;
	return total- max_color;
}



int main()
{
	ios_base::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m>>k;
	vector< vector <int > > graph(n+1);
	for(int i=0;i<n;i++)
	{
		cin>>colors[i];
	}
	for(int i=0;i<m;i++)
	{
		int l,r;
		cin>>l>>r;
		l--;r--;
		graph[l].push_back(r);
		graph[r].push_back(l);
	}
	long long int ans =0;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			ans+=dfs_util(graph,n,i);
		}
	}
	cout<<ans<<endl;


	return 0;
}