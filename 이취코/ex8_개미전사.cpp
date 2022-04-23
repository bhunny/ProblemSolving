#include <bits/stdc++.h>
using namespace std;
int n;
int d[101];

int arr[101];
// 잘못된 풀이
// 무조건 한칸씩 띄우도록 구현함
void func1()
{
    d[0] = arr[0];
    d[1] = arr[1];
    for (int i = n - 1; i >= 3; i--)
    {
        d[i] = d[i - 2] + arr[i];
        d[i - 1] = d[i - 3] + arr[i - 1];
    }
    cout << max(d[n - 1], d[n - 2]); // n-1이 배열의 마지막
}
// sol
void func2()
{
    d[0] = arr[0];
    d[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
    {
        d[i] = max(d[i - 1], d[i - 2] + arr[i]);
    }
    cout << d[n - 1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        arr[i] = k;
    }
    func2();
}