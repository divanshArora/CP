#include <iostream>
#include <string>
using namespace std;
/**
 * Greedy solution didn't prove.
 * We have to change as few zeroes as possible to ones so that it is impossible to place a ships on the zeroes.
 * Calculate for the initial configuration how many ships can be placed. After that, greedily remove the 
 * possibility of placing a ship, whenever there are b consecutive zeroes 
 * (i.e. change the b-th consecutive zero to one). Do it until fewer than a ships can be placed.
 */


int main()
{
	ios_base::sync_with_stdio(false);
	int n,a,b,k;
	cin>>n>>a>>b>>k;
	string arr;

	cin>>arr;

	for(int i=0;i<n;i++)
	{
		if(arr[i]!='1')
		{
			bool flag = false;
			for(int j=0;j<b;j++)
			{
				if(i+j>=n || arr[i+j] == '1')
				{
					flag = true;
				}

			}	
			if(flag==false)
			{
				arr[i+b-1] ='2';
				i = i+b-1;
			}
		}

	}
	int two_count = 0;

	//cout<<"arr = "<<arr<<endl;
	for(int i=0;i<n;i++)
	{
		if(arr[i]=='2')
		{
			two_count++;
		}
	}

	int remaining_two_count = two_count;
	int ans =0;
	for(int i=0;i<n&&remaining_two_count>=a;i++)
	{
		if(arr[i]=='2')
		{
			arr[i] = '3';
			remaining_two_count--;
			ans++;
		}
	}
	cout<<ans<<endl;
	for(int i=0;i<n;i++)
	{
		if(arr[i]=='3')
		{
			cout<< i+1<<" ";
		}
	}






	return 0;
}
