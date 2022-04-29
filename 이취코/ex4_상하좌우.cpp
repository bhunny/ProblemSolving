#include <bits/stdc++.h>
using namespace std;
int n;
int x = 1, y = 1;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char moveTypes[] = {'L', 'R', 'U', 'D'};
void func(char dir)
{
    if (dir == 'R' && y < n)
        y++;
    else if (dir == 'L' && y > 1)
        y--;
    else if (dir == 'U' && x > 1)
        x--;
    else if (dir == 'D' && x < n)
        x++;
}
void func2(char dir)
{
    int nx;
    int ny;
    for (int i = 0; i < 4; i++)
    {
        if (dir == moveTypes[i])
        {
            nx = x + dx[i];
            ny = y + dy[i];
        }
        if (nx < 1 || nx > n || ny < 1 || ny > n)
            continue;

        x = nx;
        y = ny;
        break;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin.ignore();
    string line;
    getline(cin, line);
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ' ')
            continue;
        //cout << line[i];
        //func(line[i]);
        func2(line[i]);
    }
    cout << x << ' ' << y;
}
/*
5
R R R U D D
============
3 4
*/