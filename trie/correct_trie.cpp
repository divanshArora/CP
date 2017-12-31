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
#define pb push_back
#define ALPHABET_SZ 27
 
using namespace std;

const char  first_letter = 'a';


typedef struct trie{
		int wt;
		trie * alpabet_arr[ALPHABET_SZ];
}trie;

trie * create_node(int weight)
{
	trie * tp = new trie;
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
			tp->wt= max(tp->wt,weight);
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
			return -1;
		}
	}
	return tp->wt;
}


int main() {
	
	ios_base::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	trie * root = create_node(-1);
	for(int i=0;i<n;i++)
	{
		string s;int weight;
		cin>>s;cin>>weight;
		insert_string(s,root,weight);
	}
	while(q--)	
	{
		string s;cin>>s;
		cout<<find_string(s,root)<<'\n';
	}
	return 0;
}