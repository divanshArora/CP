//TRIE SIMPLE link--> https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/tutorial/
//Take care: First letter 'A' or 'a' , alphabet size


#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cassert>
#define pb push_back
#define ALPHABET_SZ 75
 	
using namespace std;

const char  first_letter = '0';


typedef struct trie{
		int wt;
		bool isleaf;
		trie * alpabet_arr[ALPHABET_SZ];
}trie;

trie * create_node(int weight)
{
	trie * tp = new trie;
	tp->isleaf = false;
	for(int i=0;i<ALPHABET_SZ;i++)
	{
		tp->alpabet_arr[i]=NULL;
	}
	tp->wt=weight;
	return tp;
}

void insert_string(string s, trie * root, int weight)
{
	trie * tp = root;
	for(int i=0;i<s.length();i++)
	{
		//cout<<"s_i =  "<<s[i];
		if(tp->alpabet_arr[s[i]-first_letter]==NULL)
		{
			tp->alpabet_arr[s[i]-first_letter] = create_node(weight);
			tp = tp->alpabet_arr[s[i]-first_letter];
			tp->wt= weight;
		}
		else
		{
			tp = tp->alpabet_arr[s[i]-first_letter];
		}
	}
}

int find_string(string s, trie * root)
{
	trie * tp = root;
	for(int i=0;i<s.length();i++)
	{
		int index = s[i]-first_letter;
		if(tp->alpabet_arr[index]!=NULL)
		{
			tp = tp->alpabet_arr[index];
		}
		else
		{
			assert(1);
		}
	}
	if(tp->wt==-1)
	{
		tp->wt=0;
		return -1;
	}
	else
	{
		(tp->wt)++;
	}	
	return tp->wt;
}

int solve(string s, trie * root)
{
	trie * tp = root;
	for(int i=0;i<s.length()-1;i++)
	{
		int index = s[i]-first_letter;
		if(tp->alpabet_arr[index]==NULL)
		{	
			tp->alpabet_arr[index]= create_node(-1);
		}
		tp = tp->alpabet_arr[index];
	}
	int i = s.length()-1;
		int index = s[i]-first_letter;
		if(tp->alpabet_arr[index]==NULL || tp->alpabet_arr[index]->isleaf==false)
		{	
			//cout<<"HERE1\n";
			if(tp->alpabet_arr[index]==NULL)
			tp->alpabet_arr[index]= create_node(-1);
			tp->alpabet_arr[index]->isleaf = true;
			return -1;
		}
		else
		{
			//cout<<"HERE2\n";
			tp = tp->alpabet_arr[index];	
			for(int i=0;i<=9;i++)
			{
				if(tp->alpabet_arr[i]==NULL)
				{
					//cout<<"in1\n";
					tp->alpabet_arr[i] = create_node(-1);
					tp->alpabet_arr[i]->isleaf = true;	
					return i;
				}
				else if(tp->alpabet_arr[i]->isleaf==false)
				{	
					//cout<<"in2\n";
					tp->alpabet_arr[i]->isleaf = true;	
					return i;
				}
				//cout<<"i = "<<i<<'\n';
			}
		}
} 

int main() {
	
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	trie * root = create_node(-1);
	for(int i=0;i<n;i++)
	{
		string s;int weight;
		cin>>s;
		cout<<s;
		int x = solve(s,root);
		if(x!=-1)cout<<x;
		cout<<'\n';
	}
	return 0;
}