#include <bits/stdc++.h>
using namespace std;
int n;
int indegree[501];
int times[501];
int result[501];
vector<int> graph[501];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int time;
        cin >> time;
        times[i] = time;
        result[i] = time;
        for (int j = 1; j <= n; j++)
        {
            int sub;
            cin >> sub;
            if (sub == -1)
                break;
            indegree[i]++;
            // 간선 연결
            graph[sub].push_back(i);
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (auto i : graph[now])
        {
            result[i] = max(result[i], result[now] + times[i]);
            indegree[i] -= 1;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << '\n';
    }
}

/*

5
10 -1
10 1 -1
4 1 -1
4 3 1 -1
3 3 -1
=======
10
20
14
18
17
*/