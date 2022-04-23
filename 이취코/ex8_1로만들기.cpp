#include <bits/stdc++.h>
using namespace std;
int n;
int d[30001]; //0으로 초기화
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        // 4가지 연산을 min 비교하면서 d[i]값을 최신화함
        d[i] = d[i - 1] + 1; // +1은 횟수를 추가하는 것
        if (i % 5 == 0)
            d[i] = min(d[i], d[i / 5] + 1);
        if (i % 3 == 0)
            d[i] = min(d[i], d[i / 3] + 1);
        if (i % 2 == 0)
            d[i] = min(d[i], d[i / 2] + 1);
    }
    cout << d[n];
}