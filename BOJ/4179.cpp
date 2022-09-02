#include <bits/stdc++.h>
using namespace std;
int r, c;
char board[1001][1001];
int visit_j[1001][1001];
int visit_f[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q_f;
queue<pair<int, int>> q_j;

void bfs_f()
{
    while (!q_f.empty())
    {
        pair<int, int> now;
        now = q_f.front();
        q_f.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = dx[dir] + now.first;
            int ny = dy[dir] + now.second;
            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (board[nx][ny] == '#' || visit_f[nx][ny])
            {
                continue;
            }
            visit_f[nx][ny] = visit_f[now.first][now.second] + 1;
            q_f.push({nx, ny});
        }
    }
}
void bfs_j()
{
    while (!q_j.empty())
    {
        pair<int, int> now;
        now = q_j.front();
        q_j.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = dx[dir] + now.first;
            int ny = dy[dir] + now.second;
            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
            {
                cout << visit_j[now.first][now.second];
                return;
            }
            if (board[nx][ny] == '#' || visit_j[nx][ny])
            {
                continue;
            }
            if (visit_f[nx][ny] != 0 && visit_f[nx][ny] <= visit_j[now.first][now.second] + 1) // 일단 visit-f가 0이 아니어야한다. -> 벽을 못 넘음, 그 뒤 비교
                continue;
            visit_j[nx][ny] = visit_j[now.first][now.second] + 1;
            q_j.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
}
void bfs()
{
    bfs_f();
    bfs_j();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    string line;
    cin.ignore();
    for (int i = 0; i < r; i++)
    {
        getline(cin, line);
        for (int j = 0; j < c; j++)
        {
            board[i][j] = line[j];
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == 'F')
            {
                q_f.push({i, j});
                visit_f[i][j] = 1;
            }

            if (board[i][j] == 'J')
            {
                q_j.push({i, j});
                visit_j[i][j] = 1;
            }
        }
    }
    bfs();
}