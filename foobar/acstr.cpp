#include <iostream>
//incorrect
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);

		long long int dp1[100]={0};
	long long int dp2[100]={0};
	long long int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		for(int i=0;i<a.length();i++)
		{
			dp1[a[i]-65]++;
		}
		for(int i=0;i<b.length();i++)
		{
			dp2[b[i]-65]++;
		}
		for(int i=0;i<100;i++){
			long long int x = min(dp1[i],dp2[i]);
			while(x--)
			{
				cout<< (char)(i+65);
			}
		}
		cout<<endl;
	}
	return 0;
}