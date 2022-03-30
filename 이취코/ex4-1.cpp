#include <bits/stdc++.h>
using namespace std;
void func(string move, int N)
{
    pair<int, int> cur;
    cur.first = 1;
    cur.second = 1;
    for (int i = 0; i < move.size(); i++)
    {
        if (move[i] == 'U' && cur.first > 1)
            cur.first--;
        else if (move[i] == 'D' && cur.first < N)
            cur.first++;
        else if (move[i] == 'L' && cur.second > 1)
            cur.second--;
        else if (move[i] == 'R' && cur.second < N)
            cur.second++;
    }
    cout << cur.first << ',' << cur.second;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string move;
    cin >> n;
    cin.ignore();
    getline(cin, move);
    func(move, n);
}