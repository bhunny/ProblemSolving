#include <bits/stdc++.h>
using namespace std;
int n, m;
int dist[100002];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    fill(dist, dist + 100001, -1);
    dist[n] = 0;
    queue<int> q;
    q.push(n);
    while (dist[m] == -1)
    {
        int now = q.front();
        q.pop();
        for (int nxt : {now - 1, now + 1, now * 2})
        {
            if (nxt < 0 || nxt > 100000)
                continue;
            if (dist[nxt] != -1)
                continue;
            dist[nxt] = dist[now] + 1;
            q.push(nxt);
        }
    }
    cout << dist[m];
}