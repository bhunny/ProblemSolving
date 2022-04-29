#include <bits/stdc++.h>
using namespace std;
int n, m;
int visit[51][51];
int arr[51][51];
int dir;
// 북(0) 동(1) 남(2) 서(3)
// a 북쪽으로 부터 떨어진 거리
int dx[] = {-1, 0, 1, 0};
// b 서쪽으로 부터 떨어진 거리
int dy[] = {0, 1, 0, -1};
void turnLeft()
{
    dir--;
    if (dir == -1)
        dir = 3;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int x, y;
    cin >> x >> y >> dir;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int num;
            cin >> num;
            arr[i][j] = num;
        }
    }
    int cnt = 1; //방문한 칸의 수, 첫번째칸을 포함하므로 1부터 시작
    int turn = 0;
    visit[x][y] = 1;
    while (1)
    {
        turnLeft();
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (visit[nx][ny] == 0 && arr[nx][ny] == 0)
        {
            visit[nx][ny] = 1;
            x = nx;
            y = ny;
            cnt++;
            turn = 0;
            continue;
        }
        else
            turn++;
        if (turn == 4)
        {
            //현재 방향 반대방향으로 한 칸 이동
            nx = x - dx[dir];
            ny = y - dx[dir];
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
/*
4 4
1 1 0
1 1 1 1
1 0 0 1
1 1 0 1
1 1 1 1
=======
3
*/