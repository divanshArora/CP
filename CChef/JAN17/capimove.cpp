#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

long long int population[50001];
long long int sorted_popu[50001];

map<long long int , int> hashmap; //popu index

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		hashmap.empty();
		int n;
		cin>>n;
		vector< vector< int> > graph(n+1);

		for(int i=0;i<n;i++)
		{
			cin>>population[i];
			sorted_popu[i] = population[i];
			hashmap.insert(pair<long long int,int>(population[i],i));
		}
		sort(sorted_popu,sorted_popu+n);

		for(int i=0;i<n-1;i++)
		{
			int x,y;
			cin>>x>>y;
			x--;y--;
			graph[x].push_back(y);
			graph[y].push_back(x);

		}
		for(int i=0;i<n;i++)
		{
			set <long long int> myset;
			myset.insert(population[i]);
			for(int j=0;j<graph[i].size();j++)
			{
				myset.insert(population[graph[i][j]]);
			}
			int ans=n-1;
			auto it = myset.find(sorted_popu[ans]);

			while(ans>=0 && it!=myset.end())
			{
				ans--;
				if(ans>=0)
				it= myset.find(sorted_popu[ans]);
			}
			if(ans<0)
			{
				cout<<"0 ";
			}
			else
			{
				cout<<(hashmap.find(sorted_popu[ans]))->second+1<< " ";	
			}
			
		}
		cout<<endl;



	}
	return 0;

} 