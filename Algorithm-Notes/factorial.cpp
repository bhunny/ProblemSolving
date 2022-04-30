#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}
// 꼬리 재귀함수, 위의 함수와 달리 반환값에서 추가 연산을 필요하지 않음
int factorialOpt(int n, int acc) // acc -> accumulator
{
    if (n == 1)
        return acc;
    return factorialOpt(n - 1, n * acc);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << factorial(5) << '\n';
    cout << factorialOpt(5, 1);
}