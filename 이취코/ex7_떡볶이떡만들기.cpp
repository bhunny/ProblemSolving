#include <bits/stdc++.h>
using namespace std;
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }

    int start = 0;
    int end = 1e9; //10의 9승, array의 최대값
    int result = 0;
    int mid = 0;
    while (start <= end)
    {
        long long sum = 0;
        mid = (start + end) / 2;
        for (auto i : arr)
        {
            if (i > mid)
            {
                sum += (i - mid);
            }
        }
        //떡의 양이 부족한 경우
        //더 많이 자르기
        if (sum < m)
        {
            end = mid - 1;
        }
        //떡의 양이 충분한 경우
        else
        {
            result = mid; //절단기 높이의 최댓값을 찾는 것이므로, mid가 end에 가까울 수록 최댓값
            start = mid + 1;
        }
    }
    cout << result;
}

/*
4 6
19 15 10 17
------------
15

*/