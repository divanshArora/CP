#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	string s;
	cin>>s;
	int n = s.length();
	char current_letter = 'a';
	long long  int count = 0;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<26;j++)
		{
			if( 97 + ((current_letter+j-97)%26)==(int)s[i])
			{
				if(j>=13)
				{
					count+=26-j;
				}
				else
				{
					count+=j;
				}
				current_letter =  97 + ((current_letter+j-97)%26);
				break;
			}
		}
	}
	cout<<count;



	return 0;
}