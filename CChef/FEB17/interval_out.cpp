/*
Hanit Banga
*/

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 3e5 + 5, M = 210;
const ll inf = 1e17;

ll dp[N][2], prefix[N];
deque <pll> s;
int a[N], b[M];

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);

		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		for (int i = 1; i <= m; ++i)
			scanf("%d", &b[i]);

		prefix[0] = 0;
		for (int i = 1; i <= n; ++i)
			prefix[i] = prefix[i - 1] + a[i];

		for (int i = 1; i <= n; ++i)
		{
			if (i + b[m] - 1 <= n)
				dp[i][1] = prefix[i + b[m] - 1] - prefix[i - 1];
			else
				dp[i][1] = -inf;
		}

		int cur = 0, prev = 1;
		for (int j = m - 1; j >= 1; --j)
		{	
			int temp = b[j] - b[j + 1] - 1;
			for (int i = j + 1; i <= temp + j; ++i)
			{
				while (!s.empty() and s.front().first <= dp[i][prev])
					s.pop_front();

				s.push_front({dp[i][prev], i});
			}

			for (int i = 1; i <= n; ++i)
				dp[i][cur] = -inf;

			int mx = n + 2 - b[j] - j;
			for (int i = j; i <= mx; ++i)
			{
				dp[i][cur] = prefix[i + b[j] - 1] - prefix[i - 1] - s.back().first;

				while (!s.empty() and (s.front().first <= dp[i + temp + 1][prev] or s.front().second <= i + 1))
					s.pop_front();

				while (!s.empty() and s.back().second <= i + 1)
					s.pop_back();

				s.push_front({dp[i + temp + 1][prev], i + temp + 1});
			}

			while (!s.empty())
				s.pop_back();

			swap(cur, prev);
		}

		ll ans = -inf;
		for (int i = 1; i <= n; ++i)
			ans = max(ans, dp[i][prev]);

		printf("%lld\n", ans);
	}	
}