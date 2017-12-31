
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007


vector < int > v(30);
stack < char > st;
int main()
{
	ios_base::sync_with_stdio(false);
	string str,ans;
	cin>>str;
	for(int i=0;i<30;i++)v[i]=0;
	int last = -1;
	for(int i=0;i<str.size();i++)
	{
		v[str[i]-'a']++;
	}
	//cout<<"VEC ----------\n";
	// for (int i = 0; i < v.size(); ++i)
	// {
	// 	//cout<<v[i]<<" ";
	// }
	for(char i='a';i<='z';i++)
	{
		for(int j=0;j<str.size();j++)
		{
			////cout<<"last  = "<<last<<endl;

			if(i==str[j])
			{
					last = j;
					ans+=i;
					v[i-'a']--;
					str[j]= '-';				
			}
			else
			{
				if(v[i-'a']>0)
				{
					if(str[j]!='-')
					{
						st.push(str[j]);
						v[str[j]-'a']--;
						str[j]='-';
					}
				}
			}
		}
	}
	while(!st.empty()){ans+=st.top();
	st.pop();}


	cout<<ans<<endl;
}

	