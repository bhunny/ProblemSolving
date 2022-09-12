#include <iostream>
#include <string>
using namespace std;
void print(string::size_type n)
{
    if (n == string::npos) // if not found
    {
        cout << "normal";
    }
    else // is substr of 'user'
    {
        cout << "secret";
    }
}

string secret;
string user;
int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 0; i < m; i++)
    {
        char s;
        cin >> s;
        secret += s;
    }
    for (int i = 0; i < n; i++)
    {
        char u;
        cin >> u;
        user += u;
    }
    string::size_type result;
    result = user.find(secret);
    print(result);
    return 0;
}