#include <bits/stdc++.h>
using namespace std;

bool CheckLine(string line)
{
    stack<char> s;
    for (auto e : line)
    {
        if (e == '(' || e == '[')
        {
            s.push(e);
        }
        else if (e == ')')
        {
            if (s.empty() || s.top() != '(')
                return 0;
            s.pop();
        }
        else if (e == ']')
        {
            if (s.empty() || s.top() != '[')
                return 0;
            s.pop();
        }
    }
    if (!s.empty())
        return 0;
    else
        return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string line;
    vector<string> v;
    while (1)
    {
        getline(cin, line);
        if (line == ".")
            break;
        if (CheckLine(line))
        {
            v.push_back("yes");
        }
        else
            v.push_back("no");
    }
    for (auto e : v)
    {
        cout << e << '\n';
    }
}