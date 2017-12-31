
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define MOD 1000000007

typedef vector<ll> vll;


int main()
{
	ios_base::sync_with_stdio(false);
	string a,b;
	cin>>a>>b;
	int n = b.length();
	multiset<char> olegset;
	multiset<char> egorset;
	int first = 0,last = n-1;
	for(int i=0;i<n;i++)
	{	
		olegset.insert(a[i]);
		egorset.insert(b[i]);
	}
	vector<char> ans(n+1);
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			if(*(olegset,rbegin())<*(egorset.begin()))
		}
		else	
		{
		}

	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i];
	}

}
