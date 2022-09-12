#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int lim[101];
int test[101];
int main(int argc, char **argv)
{
    int m, n;
    cin >> n >> m;
    int sect = 0;
    int speed = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> sect >> speed;
        fill(lim + sum, lim + sum + sect, speed);
        sum += sect;
    }
    sum = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> sect >> speed;
        fill(test + sum, test + sum + sect, speed);
        sum += sect;
    }
    int mx = 0;
    for (int i = 0; i < 101; i++)
    {
        if (lim[i] < test[i])
            mx = max(mx, test[i] - lim[i]);
    }
    cout << mx;
    return 0;
}