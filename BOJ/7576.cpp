#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int board[1001][1001];
queue<pair<int, int>> q;
void bfs()
{
    while (!q.empty())
    {
        pair<int, int> cur;
        cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = dx[dir] + cur.first;
            int ny = dy[dir] + cur.second;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] != 0)
                continue;
            board[nx][ny] = board[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
}
int check()
{
    int maxNum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)
                return -1;
            if (board[i][j] > maxNum)
                maxNum = board[i][j];
        }
    }
    return maxNum - 1;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 1)
                q.push({i, j});
        }
    }
    bfs();
    // check result of bfs
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << board[i][j];
    //     }
    //     cout << '\n';
    // }
    cout << check();
}