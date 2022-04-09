//실전 문제 왕실의 나이트
#include <bits/stdc++.h>
using namespace std;
int cnt;
int dx[8] = {-2, -1, -2, -1, 1, 2, 1, 2};
int dy[8] = {-1, -2, 1, 2, 2, 1, -2, -1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    getline(cin, input);
    for (int i = 0; i < 8; i++)
    {
        //int nx = input[0] - 96 + dx[i]; //a-> 1~
        //int ny = input[1] - 48 + dy[i];
        int nx = input[0] - 'a' + 1 + dx[i]; //a-> 1~
        int ny = input[1] - '1' + 1 + dy[i];

        //cout << nx << ' ' << ny << '\n';

        if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8)
        {

            //cout << nx << ' ' << ny << '\n';
            //cout << "----" << '\n';
            cnt += 1;
            //cout << cnt << '\n';
            //cout << "----" << '\n';
        }
    }
    cout << cnt;
}