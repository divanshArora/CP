#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

ll arr[3*((int)1e5)+4];

int main()
{
	ios_base::sync_with_stdio(false);
	map< string, int> ms;

	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		auto it = ms.find(s);
		if(it!=ms.end())
		{
			ms[s] = ms[s]+1;
			cout<<s+to_string(ms[s])<<'\n';
		}
		else
		{
			ms.insert({s,0});
			cout<<"OK"<<'\n';
		}

	}

}






