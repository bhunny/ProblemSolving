#include <string>
#include <vector>
#include <deque>
#include <numeric>
#include <iostream>
using namespace std;
int solution1(vector<int> queue1, vector<int> queue2)
{
    int answer = 0;
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0);
    long long sumHalf = (sum1 + sum2) / 2;
    int qSize = queue1.size() * 3;
    int num = 0;
    deque<int> deq1, deq2;
    for (auto i : queue1)
    {
        deq1.push_back(i);
    }
    for (auto i : queue2)
    {
        deq2.push_back(i);
    }

    while (qSize--)
    {
        if (sum1 == sumHalf)
        {
            return num;
        }
        else if (deq1.size() == 1)
            return -1;
        else if (sum1 > sumHalf)
        {
            int e = deq1.front();
            deq1.pop_front();
            sum1 -= e;
            sum2 += e;
            deq2.push_back(e);
        }
        else
        {
            int e = deq2.front();
            deq2.pop_front();
            sum1 += e;
            sum2 - +e;
            deq1.push_back(e);
        }
        num++;
    }
    return -1;
}
int solution2(vector<int> queue1, vector<int> queue2)
{
    int answer = 0;
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0);
    long long sumHalf = (sum1 + sum2) / 2;
    int qSize = queue1.size() * 3;
    int num1 = 0;
    int num2 = 0;
    while (qSize--)
    {
        if (sum1 == sumHalf)
        {
            return answer;
        }
        else if (queue1.size() == 1)
            return -1;
        else if (sum1 > sumHalf)
        {
            int e = queue1[num1++];
            sum1 -= e;
            sum2 += e;
            queue2.push_back(e);
        }
        else
        {
            int e = queue2[num2++];
            sum1 += e;
            sum2 -= e;
            queue1.push_back(e);
        }
        answer++;
    }
    return -1;
}
