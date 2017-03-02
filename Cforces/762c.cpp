#include <bits/stdc++.h>
#define INF (int)1e5+10
using namespace std;

vector< vector<int> > char_to_index(27);

void pv()
{
	for(int i=0;i<char_to_index.size();i++)
	{
		for(int j=0;j<char_to_index[i].size();j++)
		{
			cout<<char_to_index[i][j]<<" ";
		}
		cout<<endl;
	}

}

int main()
{

	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	string a,b;
	cin>>a>>b;
	int n=a.length();
	int m= b.length();
	int prefix[m+1];
	int suffix[m+1];

	//make map
	for(int i=0;i<n;i++)
	{
		char_to_index[a[i]-97].push_back(i);
	}
	//make prefix
	int prev = -1;
	for(int i=0;i<m;i++)
	{
		auto vec = 	char_to_index[b[i]-'a'];
		if(vec.empty())
		{
			prev = INF;
		}
		else
		{

			auto up = upper_bound(vec.begin(),vec.end(),prev);
			prev = vec[up-vec.begin()];
			if(up==vec.end())
			{
				prev=INF;
			}
		}
		prefix[i] = prev;
	}
	//reverse map

	for(int i=0;i<char_to_index.size();i++)
	{
		for(int j=0;j<char_to_index[i].size();j++)
		{
			char_to_index[i][j] = n- char_to_index[i][j]-1;
		}
	//	cout<<"HERE"<<endl;
		reverse(char_to_index[i].begin(),char_to_index[i].end());
	}

	//make suffix
	string temp = b;
	reverse(temp.begin(),temp.end());
	prev = -1;
	for(int i=0;i<m;i++)
	{
		auto vec = 	char_to_index[temp[i]-'a'];
		if(vec.empty())
		{
			prev = INF;
		}
		else
		{

			auto up = upper_bound(vec.begin(),vec.end(),prev);
			prev = vec[up-vec.begin()];
			if(up==vec.end())
			{
				prev=INF;
			}
		}
		suffix[i] = prev;
	}
	for(int i=0;i<m;i++)
	{
		cout<<prefix[i]<<" ";
	}
	cout<<endl;
	int tempx[m+1];
	int j=0;
	for(int i=m-1;i>=0;i--)
	{
		if(suffix[i]==INF)
		tempx[j]=suffix[i],j++;
	else
		//tempx[j]=m-suffix[i]-1,j++;
		tempx[j]=suffix[i],j++;
	}
	for(int i=0;i<m;i++)
	{
		cout<<tempx[i]<<" ";
	}

	int l=0,r=0;
	pair<int , int> mans;
	while(l<=m-1 && r<=m-1)
	{
		if(prefix[l]+tempx[r]<m)
		{
			cout<<"ans= "<<prefix[l]<<" "<<tempx[r]<<endl;
			break;
		}
		else
		{
			if(prefix[l]>tempx[r])
			{
				l++;
			}
			else
			{
				r++;
			}
		}

	}	
	cout<<"l = "<<l<<" r = "<<r<<endl;

}