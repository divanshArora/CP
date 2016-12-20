#include <iostream>
#include <vector>
using namespace std;

/**
 * Greedy lgorithm read editorial easy.
 * bad implementation
 */ 

int a[(int)2e5 + 10];
int dp[(int )2e5+10]={0};
vector<int> missing_links;

void adjust_last_leaf(int * last_leaf);

int main()
{
	ios_base::sync_with_stdio(false);
	int n,s;
	cin>>n>>s;	
	s--;
	int last_leaf = 0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		dp[a[i]]++;
		last_leaf= max(last_leaf,a[i]);
	}

	int chief_mistake = 0;
	if(a[s]!=0)
	{
		dp[a[s]]--;
		dp[0]++;
		a[s]=0;
		chief_mistake++;
		adjust_last_leaf(&last_leaf);
	}


	for(int i=last_leaf;i>=0;i--)
	{
		if(dp[i]==0)
		{
			missing_links.push_back(i);
		}
	}
	int mistakes  = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==0 && i!=s)
		{
			if(!missing_links.empty())
			{
				dp[missing_links.back()]++;
				missing_links.pop_back();
			}
			mistakes++;
		}
	}

	if(missing_links.empty())
	{
		cout<<mistakes+chief_mistake;
		return 0;
	}
	adjust_last_leaf(&last_leaf);
	while(!missing_links.empty() && missing_links.back()<last_leaf)
	{
		//cout<<"back of missing link = "<<missing_links.back() << " last leaf = "<< last_leaf<<endl;
		//cout<< "dp last leaf = "<<dp[last_leaf]<<endl;
		//adjust_last_leaf(&last_leaf);
		dp[last_leaf]--;
		mistakes++;
		missing_links.pop_back();
		adjust_last_leaf(&last_leaf);

	}	

	cout<<mistakes+chief_mistake;

	return 0;
}

void adjust_last_leaf(int * last_leaf)
{
	while(dp[*last_leaf]==0)
		{
			(*last_leaf)= (*last_leaf)-1;
		}
}
