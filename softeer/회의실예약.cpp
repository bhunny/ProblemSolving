#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
string roomName[51];
bool booked[51][19];

int main(int argc, char **argv)
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> roomName[i];
        // cout << roomName[i] << '\n';
    }
    sort(roomName, roomName + n);
    string input;
    int s, t;
    for (int i = 0; i < m; i++)
    {
        cin >> input >> s >> t;
        // check number of roomname
        // begin iterator를 빼서 index를 구할 수 있다.
        int index = find(roomName, roomName + n, input) - begin(roomName);
        for (int i = s; i < t; i++)
        {
            booked[index][i] = true;
        }
    }
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        vector<string> line;
        for (int j = 9; j < 18; j++)
        {
            string a = "";
            if (!booked[i][j])
            {
                if (j == 9)
                {
                    a += '0';
                }
                a += to_string(j);
                a += '-';
                while (j <= 18)
                {
                    if (j == 18)
                    {
                        a += to_string(j);
                        break;
                    }
                    if (booked[i][j])
                    {
                        a += to_string(j);
                        break;
                    }
                    j++;
                }
            }
            if (a == "")
                continue;
            line.push_back(a);
        }
        // cout << '\n';
        cout << "Room " << roomName[i] << ":" << '\n';
        if (line.empty())
        {
            cout << "Not available" << '\n';
        }
        else
        {
            cout << line.size() << " available:" << '\n';
        }
        for (auto i : line)
        {
            cout << i << '\n';
        }
        if (i == n - 1)
            continue;
        cout << "-----" << '\n';
    }

    return 0;
}