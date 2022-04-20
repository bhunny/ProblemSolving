#include <bits/stdc++.h>
using namespace std;
int n, m;
int graph[201][201];
bool visit[201][201];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int bfs(int x, int y)
{
    queue<pair<int, int>> Q;
    // 방문했는지 확인
    visit[x][y] = 1;
    Q.push({x, y});
    while (!Q.empty())
    {
        pair<int, int> now = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            //제한 범위를 넘어가지 않도록
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            // 방문했는지, 벽인지 확인
            if (visit[nx][ny] || graph[nx][ny] == 0)
                continue;
            visit[nx][ny] = 1;
            Q.push({nx, ny});
            //방문한 곳은 이전값 +1
            graph[nx][ny] = graph[now.first][now.second] + 1;
        }
    }
    return graph[n - 1][m - 1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++)
        {
            graph[i][j] = line[j] - '0';
        }
    }
    cout << bfs(0, 0);

    // 결과 확인을 위한 코드

    //cout << '\n';
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << graph[i][j];
    //     }
    //     cout << '\n';
    // }

    /*
    test case 1
    5 6
    101010
    111111
    000001
    111111
    111111

    test case 2
    3 3
    110
    010
    011

    */
}