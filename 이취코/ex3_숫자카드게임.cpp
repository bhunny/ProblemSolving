#include <bits/stdc++.h>
using namespace std;

int n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        int minNum = 10001;
        for (int j = 0; j < m; j++)
        {
            cin >> num;
            minNum = min(minNum, num);
        }
        answer = max(minNum, answer);
    }
    cout << answer;
}

/*
3 3
3 1 2
4 1 4
2 2 2
=====
2


2 4
7 3 1 8
3 3 3 4
======
3


4 3
1 1 2
3 5 9
2 1 0
3 4 2
=====
3
*/