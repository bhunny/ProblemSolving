#include <bits/stdc++.h>
using namespace std;
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
    int n;
    int result = 0;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            for (int k = 0; k < 60; k++)
            {
                if (check(i, j, k))
                    result++;
            }
        }
    }
    cout << result;
    return 0;
}