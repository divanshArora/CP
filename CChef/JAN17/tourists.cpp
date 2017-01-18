//problem: https://www.codechef.com/JAN17/problems/TOURISTS
//DFS application
//tested correct
/**
Algorithm link: 
http://e-maxx.ru/algo/euler_path
but this doesn't work gives TLE -_-

use normal dfs as done in dfs_again, dfs() checks if connected or not



**/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <stack>
using namespace std;



long long int degree[100001];

multiset < pair <int , int > > edge_set;
multiset < pair <int , int > > full_edge_set;

vector< pair < int , int > > input_set;
stack < int > mystack;


int visited[100001];

void dfs(vector < vector < int > > &graph , int start_vertex )
{	
	visited[start_vertex] = 1;
	for(int i=0;i<graph[start_vertex].size();i++)
	{
		if(visited[graph[start_vertex][i]]==0)
		{
			dfs(graph,graph[start_vertex][i]);
		}
	}
}	




void dfs_again(vector < vector < int > > &graph , int start_vertex , int target)
{
	visited[start_vertex]++;
	for(int i=0;i<graph[start_vertex].size();i++)
	{
		int b =graph[start_vertex][i];

		if(visited[b]==0 && full_edge_set.find(make_pair(start_vertex,graph[start_vertex][i]))!=full_edge_set.end())
		{
			pair<int , int > mp =make_pair(start_vertex,graph[start_vertex][i]); 
			edge_set.insert(mp);
			auto itx = full_edge_set.find(mp);
			full_edge_set.erase(itx);
			mp  = make_pair(graph[start_vertex][i],start_vertex);
			itx = full_edge_set.find(mp);
			full_edge_set.erase(itx);
			
			dfs_again(graph,graph[start_vertex][i],target);
			
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	int n,E;
	cin>>n>>E;
	
	vector < vector <int> >  graph(n+1);
	for(int i=0;i<n;i++)
		{
			visited[i]=0;
			degree[i]=0;
		}
	for(int i=0;i<E;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;b--;
		degree[a]++;
		degree[b]++;
		graph[a].push_back(b);
		graph[b].push_back(a);
		full_edge_set.insert(make_pair(a,b));
		full_edge_set.insert(make_pair(b,a));
		input_set.push_back(make_pair(a,b));
	}
	//cout<<"initial edge set "<<endl; print_edge_set();
	for(int i=0;i<n;i++)
	{
		if(graph[i].size()==0)
		{
			cout<<"NO"<<endl;
			return 0;
		}		
	}
	dfs(graph,0);
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			cout<< "NO"<<endl;
			return 0;
		}
 
	}

	for(int i=0;i<n;i++)
	{
		if(degree[i]%2!=0 || degree[i]==1 )
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	int first =0;
	mystack.push(first);
	vector <int > res;
	
	/*cout<<"GRAPH"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j = 0 ;j< graph[i].size();j++)
		{
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}*/
/*	while(!mystack.empty())
	{
		int v =mystack.top();
		//cout<<"edge set = "<<endl;print_edge_set();
		//cout<< "stack top = "<< mystack.top()<<endl;
		int i=0;
		int b;
		for( i=0;i<graph[v].size() ;i++)
		{
			b = graph[v][i];
			if(edge_set.find(make_pair(v,graph[v][i]))!=edge_set.end())
			{
				break;
			}
		}
		//cout<<"B = "<< b<<endl;
			if(i==graph[v].size())
			{
				res.push_back(v);
				mystack.pop();
			}
			else 
			{
				auto itx = edge_set.find(make_pair(b,v));
				edge_set.erase(itx);
				itx = edge_set.find(make_pair(v,b));
				edge_set.erase(itx);
				mystack.push(b);
			}
	}
			if(!edge_set.empty())
			{
				cout<<"NO"<<endl;
				return 0;
			}
		if(res[res.size()-1]!=res[0])
		{
			cout<<"NO"<<endl;
			return 0;
		}



	for(int i=0;i<res.size()-1;i++)
	{
		edge_set.insert(make_pair(res[i],res[i+1]));
	}
*/
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
	}

		dfs_again(graph,0,0);	
		
	cout<<"YES"<<endl;
	for(auto it=input_set.begin();it!=input_set.end();it++)
	{
		int a = (*it).first;
		int b = (*it).second;
		
		if(edge_set.find(make_pair(b,a))!=edge_set.end())
		{
			cout<< ( *it ).second+1<<" "<<(*it).first+1<<endl;	
		}
		else 
		{
			cout<< ( *it ).first+1<<" "<<(*it).second+1<<endl;
		}
	}

	return 0;
}