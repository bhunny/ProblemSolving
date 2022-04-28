#include <bits/stdc++.h>
using namespace std;
int n, m;

int parent[100001];
int findParent(int parent[], int x)
{
    if (parent[x] != x)
    {
        parent[x] = findParent(parent, parent[x]);
    }
    return parent[x];
}

void unionParent(int parent[], int a, int b)
{
    a = findParent(parent, a);
    b = findParent(parent, b);
    if (a < b)
    {
        parent[b] = a;
    }
    else
    {
        parent[a] = b;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    vector<pair<int, pair<int, int>>> v;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }
    sort(v.begin(), v.end()); //c(유지비)를 기준으로 오름차순 정렬
    int last = 0;
    int result = 0;
    for (auto i : v)
    {
        if (findParent(parent, i.second.first) != findParent(parent, i.second.second))
        {
            unionParent(parent, i.second.first, i.second.second);
            result += i.first;
            last = i.first; //제일 마지막 간선(비용이 제일 높은 간선)
        }
    }
    cout << result - last;
}
/*
7 12
1 2 3
1 3 2
3 2 1
2 5 2
3 4 4
7 3 6
5 1 5
1 6 2
6 4 1
6 5 3
4 5 3
6 7 4
=====
3
*/
