#include <bits/stdc++.h>
using namespace std;
int n, m;
int graph[1001][1001];
bool dfs(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return false;
    }
    // 해당 노드를 아직 방문하지 않았다면
    if (graph[x][y] == 0)
    {
        graph[x][y] = 1;
        dfs(x - 1, y); // up
        dfs(x + 1, y); //down
        dfs(x, y - 1); //left
        dfs(x, y + 1); //right
        return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++)
        {
            graph[i][j] = line[j] - '0'; // char to int
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dfs(i, j))
            {
                result += 1;
            }
        }
    }
    cout << result;
}