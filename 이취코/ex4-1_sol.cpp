#include <bits/stdc++.h>
using namespace std;

int n;
string plans;
int x = 1, y = 1;

char moveTypes[4] = {'L', 'R', 'U', 'D'};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin.ignore();
    getline(cin, plans);
    int nx, ny = 0;
    for (int i = 0; i < plans.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (plans[i] == moveTypes[j])
            {
                nx = x + dx[j];
                ny = y + dy[j];
            }
        }
        if (nx < 1 || ny < 1 || nx > n || ny > n)
            continue;
        x = nx;
        y = ny;
    }

    cout << x << ' ' << y << '\n';
}