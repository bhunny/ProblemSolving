#include <string>
#include <vector>
using namespace std;
bool chk[46];
int cnt_zero;
int cnt_same;
int result[2];
int func(int n)
{
    if (n < 2)
        return 6;
    else
        return (7 - n);
}
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
    for (auto num : win_nums)
    {
        if (chk[num])
        {
            cnt_same++;
        }
    }
    result[0] = cnt_same + cnt_zero;
    result[1] = cnt_same;
    for (auto num : result)
    {
        answer.push_back(func(num));
    }
    return answer;
}