#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	//Sieve of erostststst
	vector <bool> isprime(n+1,true);isprime[0] = 1;isprime[1] = 1;
	for(int i=2;i*i<=n;i++)
	{
		if(isprime[i]==true)
		{
			for(int j= i*i;j<=n;j+=i)
			{
				isprime[j] = false;
			}
		}
	}

	vector<int> ans;
	
	for(int i=2;i<=n;i++)
	{
		if(isprime[i]==true)
		{
			int x =i;
			while(x<=n)
			{
				ans.pb(x);
				x*=i;
			}
		}
	}
	cout<<ans.size()<<endl;
	for(auto it  = ans.begin();it!=ans.end();it++)cout<<*it<<" ";


    return 0;
}


