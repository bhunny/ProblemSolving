#include <bits/stdc++.h>
using namespace std;

int n;
int cnt;
// 특정한 시각 안에 '3'이 포함되어 있는지의 여부
bool check(int h, int m, int s)
{
    if (h % 10 == 3 || m / 10 == 3 || m % 10 == 3 || s / 10 == 3 || s % 10 == 3)
        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int answer = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= 59; j++)
        {
            for (int k = 0; k <= 59; k++)
            {
                if (check(i, j, k))
                    cnt++;
            }
        }
    }
    cout << cnt;
}