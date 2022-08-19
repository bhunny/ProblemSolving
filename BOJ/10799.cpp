#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input;
    stack<char> s;
    int answer = 0;
    char last = ' ';
    getline(cin, input);
    for (auto i : input)
    {
        if (i == '(')
        {
            s.push(i);
            last = i;
        }
        else
        {
            if (last == ')')
            {
                s.pop();
                answer++;
                // cout << answer << '\n';
                last = i;
                continue;
            }
            s.pop();
            answer += s.size();
            // cout << s.size() << ' ' << answer << '\n';
            last = i;
        }
    }
    cout << answer;
}