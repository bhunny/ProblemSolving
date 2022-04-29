#include <bits/stdc++.h>
using namespace std;

int n, k;
int answer;
void func1()
{
    while (n != 1)
    {
        if (n % k != 0)
        {
            n--;
            answer++;
        }
        else
        {
            n = n / k;
            answer++;
        }
    }
}
void func2()
{
    while (1)
    {
        int target = (n / k) * k; // k로 나눠지는 최댓값 찾기
        answer += (n - target);   // n - 나눠지는 최대값 == 1로 빼야하는 횟수
        n = target;
        if (n < k)
            break; // 더 이상 나눌 수 없으면 break;
        n = n / k;
        answer += 1;
    }
    //func2의 마지막 더 하는 수 n을 -1 해줘야한다. -> 그대로 두면 0이 될떄까지 의 값
    answer -= 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    //func1();
    func2();
    cout << answer;
}