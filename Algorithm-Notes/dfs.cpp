#include <bits/stdc++.h>
using namespace std;
const int N = 9;
bool visited[N];
vector<int> graph[N];
void dfs(int n)
{
    visited[n] = true;
    cout << n << ' ';
    for (int i = 0; i < graph[n].size(); i++)
    {
        int x = graph[n][i]; // n노드에 연결된 노드
        if (!visited[x])
            dfs(x);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // 노드 1에 연결된 노드 정보 저장
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);

    // 노드 2에 연결된 노드 정보 저장
    graph[2].push_back(1);
    graph[2].push_back(7);

    // 노드 3에 연결된 노드 정보 저장
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    // 노드 4에 연결된 노드 정보 저장
    graph[4].push_back(3);
    graph[4].push_back(5);

    // 노드 5에 연결된 노드 정보 저장
    graph[5].push_back(3);
    graph[5].push_back(4);

    // 노드 6에 연결된 노드 정보 저장
    graph[6].push_back(7);

    // 노드 7에 연결된 노드 정보 저장
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    // 노드 8에 연결된 노드 정보 저장
    graph[8].push_back(1);
    graph[8].push_back(7);
    dfs(1); // 1 2 7 6 8 3 4 5
}