#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	long int t;
	cin>>t;
	while(t--)
	{
		long long int c,d,l;
		cin>>c>>d>>l;
		int cl = l- (4*d);
 
		int ans=0;
		if(l%4==0 && 4*d<=l && cl%4==0 && cl/4<=c &&  (c-cl/4)<=2*d)
		{
			cout<<"yes"<<endl;
		}
		else 
		{
			cout<<"no"<<endl;
		}
	}
 
	return 0;
} 