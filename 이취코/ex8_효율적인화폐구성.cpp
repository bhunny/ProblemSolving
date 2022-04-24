#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }

    vector<int> d(k + 1, 10001);
    d[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = arr[i]; j <= k; j++)
        {
            // (i - k)원을 만드는 방법이 존재하는 경우
            if (d[j - arr[i]] != 10001)
            {
                //현재 저장된 값(d[j]) 과 d[j-arr[i]]+1를 비교하여 작은값을 저장
                d[j] = min(d[j], d[j - arr[i]] + 1);
            }
        }
    }
    // 계산된 결과 출력
    if (d[k] == 10001)
    { // 최종적으로 M원을 만드는 방법이 없는 경우
        cout << -1 << '\n';
    }
    else
    {
        cout << d[k] << '\n';
    }
}
