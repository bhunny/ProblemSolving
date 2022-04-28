#include <bits/stdc++.h>
using namespace std;
int n, m;

int parent[100001];
int find_parent(int parent[], int x)
{
    //루트 노드가 아니라면, 루트 노드를 찾을 때 까지 재귀적으로 호출하며 저장
    if (parent[x] != x)
    {
        parent[x] = find_parent(parent, parent[x]);
    }
    return parent[x];
}
// 두 원소 집합 합치기
void union_parent(int parent[], int a, int b)
{
    // cout << a << ' ' << b << '\n';
    // cout << find_parent(parent, a) << ' ' << find_parent(parent, b);
    a = find_parent(parent, a);
    b = find_parent(parent, b);
    if (a < b)
    {
        parent[b] = a;
    }
    else
    {
        parent[a] = b;
    }
    return;
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
    vector<int> result;
    for (int i = 1; i <= m; i++)
    {
        int calc, a, b;
        cin >> calc >> a >> b;
        if (calc == 0)
        {
            //cout << find_parent(parent, a);
            union_parent(parent, a, b);
            continue;
        }
        else if (calc == 1)
        {
            if (find_parent(parent, a) == find_parent(parent, b))
                result.push_back(1);
            else
            {
                result.push_back(0);
            }
        }
    }
    for (auto r : result)
    {
        if (r == 1)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}
/*
7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1
-----
NO
NO
YES
*/