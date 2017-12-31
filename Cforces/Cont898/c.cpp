
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

int gcd(int a, int b) {
  while (a > 0 && b > 0)
    if (a > b) a %= b;
    else b %= a;
  return a + b;
}

ll modpower(ll x, ll y, ll p) //x^y mod p
{
    ll res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y %2!= 0)
            res = (res*x) % p;
 
        // y must be even now
        y = y/2;
        x = (x*x) % p;  
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;
	unordered_map< string, unordered_set<string> >arr;
	string names[n];
	for(int i=0;i<n;i++)
	{
		string name;
		cin>>name;
		names[i] = name;
		int x;
		cin>>x;
		for(int i=0;i<x;i++)
		{
			string number;
			cin>>number;
			arr[name].insert( number);
		}
	}
	cout<<arr.size()<<"\n";
	for(auto it=arr.begin(); it!=arr.end(); it++)
	{
		unordered_set< string> ms = (*it).SS;
		string name = (*it).FF;
		vector< string> v;
		copy(ms.begin(), ms.end(), back_inserter(v));
		for(int i=0;i<v.size();i++)
		{
			for(int j=0;j<v.size();j++)
			{
				if(v[j]!="" && (v[i].length()) < v[j].length() && (v[j].substr((v[j].length()-v[i].length()), v[i].length()))==v[i])
				{
					v[i]="";
					break;
				}
			}
		}
		cout<<name<<" ";
		int cnt = 0;
		for(int i=0;i<v.size();i++)
		{
			if(v[i]!="")cnt++;
		}
		cout<<cnt<<" ";
		for(int i=0;i<v.size();i++)
		{
			if(v[i]!="")cout<<v[i]<<" ";
		}
		cout<<"\n";
	}


}
