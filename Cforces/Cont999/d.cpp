
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
	int n,m;
	cin>>n>>m;
	ll arr[n];
	int marr[m];
	fill(marr,marr+m,0);
	int init[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		init[i]=arr[i];
		arr[i]%=m;
		marr[arr[i]]++;
	}
//	cout<<"HERE 1\n";
	int target = n/m;
	multiset<int> ms;
	for(int i=0;i<m;i++)
	{
		if(marr[i]>target)
		{
			int excess = marr[i]-target;
//			cout<<"excess = "<<excess<<" i = "<<i<<"\n";
			for(int j=0;j<excess;j++)
			{
				ms.insert(i);
			}
			marr[i]=target;
		}
	}
	vector<multiset<int>> ans(m+1);
	ll moves = 0;
	for(int i=0;i<m;i++)
	{
		while(marr[i]<target)
		{
//			cout<<" less than target i= "<<i<<'\n';
			auto up = ms.upper_bound(i);
			if(up==ms.begin())
			{
//				cout<<"up was begin(\n";
				up = ms.end();
				up--;
//				moves+=abs(m-*up)+abs(i);
			}
			else
			{
				up--;
//				moves+=abs((*up)-i);
			}
//			cout<<"myup = "<<*up<<"\n";
			ans[*up].insert(i);
			marr[i]++;
//			cout<<"new marri = "<<marr[i]<<" \n";
			ms.erase(up);
		}
	}
//	cout<<"ERE 2\n";
	ll final_mvs = 0;
	for(int i=0;i<n;i++)
	{

		int rem = arr[i];
		if(!ans[rem].empty()){
		auto tg = ans[rem].begin();
		int tgt = *tg;
//		cout<<"TGT = "<<tgt<<" rem = "<<rem<<"\n";
		ans[rem].erase(tg);
		if(tgt>rem)
		{
			init[i]+=tgt-rem;
			final_mvs+=tgt-rem;
		}
		else
		{
			init[i]+=tgt+m-rem;
			final_mvs+=tgt+m-rem;
		}
	}
	}
	cout<<final_mvs<<'\n';
	for(int i=0;i<n;i++)
	{
		cout<<init[i]<<" ";
	}

}
