#include <iostream>
#include <queue>

using namespace std;
int n, m;
int board[101][101];
bool vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void bfs()
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = 1;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx > n || ny < 0 || ny > m)
                continue;
            if (board[nx][ny] != 1 || vis[nx][ny])
                continue;
            board[nx][ny] += board[cur.first][cur.second];
            q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }
    cout << board[n - 1][m - 1] << '\n';
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    cin.ignore();
    string line;
    for (int i = 0; i < n; i++)
    {
        getline(cin, line);
        for (int j = 0; j < m; j++)
        {
            if (line[j] == '1')
                board[i][j] = 1;
        }
    }
    bfs();
}