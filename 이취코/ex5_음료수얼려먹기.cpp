#include <bits/stdc++.h>
using namespace std;
int n, m;
int graph[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void bfs(pair<int, int> s) //s : start
{
    int sum = 1;
    queue<pair<int, int>> q;
    q.push(s);
    graph[s.first][s.second]++;
    while (!q.empty())
    {
        sum++;
        pair<int, int> now;
        now = q.front();
        q.pop();
        cout << now.first << ' ' << now.second << '\n';
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + now.first;
            int ny = dy[i] + now.second;
            if (graph[nx][ny] > 0 || nx >= n || nx < 0 || ny >= m || ny < 0)
                continue;
            q.push({nx, ny});
            graph[nx][ny]++;
        }
    }
    //cout << sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);
        for (int j = 0; j < m; j++)
        {
            graph[i][j] = line[j] - '0';
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        // cout << '\n';
        for (int j = 0; j < m; j++)
        {
            //cout << graph[i][j];
            if (graph[i][j] == 0)
            {
                bfs({i, j});
                cnt++;
            }
            else
            {
                continue;
            }
        }
    }
    cout << cnt;
}
/*
15 14
00000111100000
11111101111110
11011101101110
11011101100000
11011111111111
11011111111100
11000000011111
01111111111111
00000000011111
01111111111000
00011111111000
00000001111000
11111111110011
11100011111111
11100011111111
==============
8

3 3
001
010
101
===
3
*/