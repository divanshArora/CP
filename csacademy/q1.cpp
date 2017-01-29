#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000;
 
int dist[MAX][MAX];
 
void nearestOne(int mat[][MAX], int m, int n)
{
    int newx[] = {-1, 0, 1, 0,1,-1,-1,1};
    int newy[] = {0, -1, 0, 1,1,-1,1,-1};
    queue< pair<int,int> > q;
 
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            dist[i][j] = INT_MAX;
 
            if (mat[i][j] == 1)
            {
                dist[i][j] = 0;
 
                q.push(make_pair(i, j));
            }
        }
    }
 
    pair<int ,int> poped;
    while (!q.empty())
    {
        poped = q.front();
        q.pop();
 
        int x = poped.first;
        int y = poped.second;
 
        for (int i=0; i<8; i++)
        {
            int adjx = x + newx[i];
            int adjy = y + newy[i];
 
            if (adjx>=0 && adjx<m && adjy>=0 && adjy<n &&
                    dist[adjx][adjy] > dist[x][y] + 1)
            {
                dist[adjx][adjy] = dist[x][y] + 1;
                q.push(make_pair(adjx,adjy));
            }
        }
    }
}
 
int main()
{
	int m,n;
	cin>>m>>n;
	int mat[m][MAX];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j];
		}
	}
  
    nearestOne(mat, m, n);
 	int ans = -1;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        if(dist[i][j]>ans)
        {
        	ans = dist[i][j];
        }
    }
    	
    cout<<ans<<endl;
    return 0;
}