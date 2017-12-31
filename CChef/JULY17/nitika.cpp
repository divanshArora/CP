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
	//cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	string garb;
	getline(cin,garb);
	while(t--)
	{
//		getchar_unlocked();
		string inp;
		// string w;
		getline(cin,inp);
		istringstream iss(inp);
		vector<string> v{istream_iterator<string>{iss}, istream_iterator<string>{} };
		if(v.size()==1)
		{
			cout<<((char)toupper(v[0][0]));
			for(int i=1;i<v[0].length();i++)
			{	
				cout<<((char)tolower(v[0][i]));
			}
		}
		else if(v.size()==2)
		{
			cout<<((char)toupper(v[0][0]))<<". ";
			cout<<((char)toupper(v[1][0]));
			for(int i=1;i<v[1].length();i++)
			{
				cout<<((char)tolower(v[1][i]));
			}
		}
		else
		{
			cout<<((char)toupper(v[0][0]))<<". "<<((char)toupper(v[1	][0]))<<". ";
			cout<<((char)toupper(v[2][0]));
			for(int i=1;i<v[2].length();i++)
			{
				cout<<((char)tolower(v[2][i]));
			}
		}
		cout<<'\n';
	}
}
