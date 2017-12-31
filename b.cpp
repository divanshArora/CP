
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;
	char g;cin.get(g);
	vector< vector< string> > v(n+1);
	for(int i=0;i<n;)
	{
//		cout<<"i = "<<i<<'\n';
		string a;
		cin>>a;
		v[i].pb(a);
		char c='a';
		cin.get(c);
		while(c!='\n')
		{
			string b;
			cin>>b;v[i].pb(b);
			cin.get(c);
//			cout<<"c = "<<c;
		}
		i++;
	}
	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<v[i].size();i++)
	// 	{
	// 		cout<<v[i][j]<<" ";
	// 	}
	// 	cout<<'\n';
	// }
	int key;
	string reversed, ctype;
	cin>>key;
	cin>>reversed>>ctype;
	if(ctype[0]=='l')
	{
		vector< pair< string, int> > pv;

		for(int i=0;i<n;i++)
		{
			pv.pb({v[i][key-1],i});
		}
		sort(pv.begin(), pv.end());
		if(reversed[0]=='f')
		for(int i=0;i<pv.size();i++)
		{
			for(int j=0;j<v[pv[i].second].size();j++)
			{
				cout<<v[pv[i].second][j]<<" ";
			}
			cout<<'\n';
		}
		else
		{
		for(int i=((int)pv.size())-1;i>=0;i--)
		{
			for(int j=0;j<v[pv[i].second].size();j++)
			{
				cout<<v[pv[i].second][j]<<" ";
			}
			cout<<'\n';
		}

		}
	}
	else
	{
		vector< pair< int, int> > pv;
		for(int i=0;i<n;i++)
		{
			pv.pb({stoi(v[i][key-1],nullptr,10),i});
		}
		sort(pv.begin(), pv.end());
		if(reversed[0]=='f')
		for(int i=0;i<pv.size();i++)
		{
			for(int j=0;j<v[pv[i].second].size();j++)
			{
				cout<<v[pv[i].second][j]<<" ";
			}
			cout<<'\n';
		}
		else
		{
		for(int i=((int)pv.size())-1;i>=0;i--)
		{
			for(int j=0;j<v[pv[i].second].size();j++)
			{
				cout<<v[pv[i].second][j]<<" ";
			}
			cout<<'\n';
		}
		}

	}



	return 0;
}
	