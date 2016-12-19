#include <iostream>

using namespace std;

int main()
{
	
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
	{

		if(i+2<=n-1 && s[i]=='o'&& s[i+1]=='g'&& s[i+2]=='o')
		{
			cout<<"***";
			i+=2;
			if(i+2<=n-1 && s[i+1]=='g'&&s[i+2]=='o')
			{
				i++;
				while(i<=n-2 && s[i]=='g'&&s[i+1]=='o')
				{
					i+=2;
				}
				i--;
			}
		}
		else
		{
			cout<<s[i];
		}

	}


	return 0;
}

