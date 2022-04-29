#include <bits/stdc++.h>
using namespace std;
int arr[8][8]; //0~7
int n = 8;
int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    cin >> line;
    int cnt = 0;
    int x = line[0] - 'a'; // 'a'-> 0
    int y = line[1] - '1'; //'1'-> 0
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        cnt++;
    }
    cout << cnt;
}