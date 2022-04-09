//실전문제 3 게임 개발
#include <bits/stdc++.h>
using namespace std;
int n, m;
int x, y, dir;
bool arr[51][51];
bool visit[51][51];
void turnL()
{
    dir -= 1;
    if (dir == -1)
    {
        dir = 3;
    }
}
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    cin >> x >> y >> dir;
    visit[x][y] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            bool m;
            cin >> m;
            arr[i][j] = m;
        }
    }
    int cnt = 1;
    int turn = 0;

    while (1)
    {
        turnL();
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (visit[nx][ny] == 0 && arr[nx][ny] == 0)
        {
            visit[nx][ny] = 1;
            x = nx;
            y = ny;
            cnt += 1;
            turn = 0;
            continue;
        }
        else
        {
            turn += 1;
        }
        if (turn == 4)
        {
            nx = x - dx[dir];
            ny = y - dy[dir];
            if (arr[nx][ny] == 0)
            {
                x = nx;
                y = ny;
            }
            else
            {
                break;
            }
            turn = 0;
        }
    }
    cout << cnt;
}