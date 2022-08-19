#include <bits/stdc++.h>
using namespace std;
int board[501][501];
bool vis[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int areaMax;
int num;
void bfs(int i, int j)
{
    int area = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = 1;
    while (!q.empty())
    {
        area++;
        pair<int, int> cur = q.front();
        q.pop();
        for (i = 0; i < 4; i++)
        {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;
            if (nx < 0 || nx > m || ny < 0 || ny > m)
                continue;
            if (board[nx][ny] != 1 || vis[nx][ny])
                continue;
            // board[nx][ny] += board[cur.first][cur.second];
            q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }
    areaMax = max(area, areaMax);
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int input;
            cin >> input;
            board[i][j] = input;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)

        {
            if (board[i][j] == 1 && !vis[i][j])
            {
                num++;
                bfs(i, j);
            }
        }
    }
    cout << num << '\n'
         << areaMax;
}