#include <string>
#include <vector>
//#include <iostream>
using namespace std;
bool chk[46];
int cnt_zero;
int cnt_same;
int result[2];
vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;
    for (auto num : lottos)
    {
        if (num == 0)
        {
            cnt_zero++;
            continue;
        }
        chk[num] = 1;
    }
    //cout << cnt_zero;
    for (auto num : win_nums)
    {
        if (chk[num])
        {
            cnt_same++;
        }
    }
    //cout << cnt_same;
    result[0] = cnt_same + cnt_zero;
    result[1] = cnt_same;
    for (auto num : result)
    {
        if (num == 6)
        {
            answer.push_back(1);
        }
        else if (num == 5)
        {
            answer.push_back(2);
        }
        else if (num == 4)
        {
            answer.push_back(3);
        }
        else if (num == 3)
        {
            answer.push_back(4);
        }
        else if (num == 2)
        {
            answer.push_back(5);
        }
        else
        {
            answer.push_back(6);
        }
    }
    return answer;
}