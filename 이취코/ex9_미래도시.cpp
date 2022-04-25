#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, m;
int graph[101][101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < 101; i++)
    {
        fill(graph[i], graph[i] + 101, INF); // graph의 모든 값을 INF로 초기화
    }
    // 자기 자신에게 가는 거리는 0으로 초기화
    // a 출발, b 도착
    for (int a = 1; a <= n; a++)
    {
        for (int b = 1; b <= n; b++)
        {
            if (a == b)
            {
                graph[a][b] = 0;
            }
        }
    }
    // 간선에 대한 정보를 입력
    // 각 간선 사이의 거리는 1이므로 1로 초기화
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1; // a->b 시간 1
        graph[b][a] = 1; // b->a 시간 1
    }
    int x, k;
    cin >> x >> k;
    // 1. 우선 a->b로 가는 최단거리를 구한다. d[a][b] = min(d[a][b],d[a][k]+d[k][d])
    // 2. 그 뒤 k를 바꾸면서 다시 최단거리를 최신화 한다. -> 제일 바깥 for문
    for (int k = 1; k <= n; k++)
    { //1~n까지
        for (int a = 1; a <= n; a++)
        {
            for (int b = 1; b <= n; b++)
            {
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }
    int dist = graph[1][k] + graph[k][x];

    if (dist >= INF)
    {
        cout << "-1";
    }
    else
    {
        cout << dist;
    }
}
/*

5 7
1 2
1 3
1 4
2 4
3 4
3 5
4 5
4 5
---
3


4 2
1 3
2 4
3 4
---
-1


*/