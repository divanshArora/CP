#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define ll long long int

using namespace std;

int a[210];

int main()
{
	int n,ans=0,in;
	cin>>n;
	for(int i=0;i<2*n;i++)
		cin>>a[i];
	for(int i=0;i<2*n;i+=2)
	{
		for(int j=i+1;j<2*n;j++)
			if(a[j] == a[i])
			{
				in=j;
				break;
			}
		while(a[i+1] != a[i])
		{
			swap(a[in], a[in-1]);
			in--;
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}