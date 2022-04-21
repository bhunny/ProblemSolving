#include <bits/stdc++.h>
using namespace std;
int n, k;
// sol #1 모든 원소 비교
void func1(int a[], int b[])
{
    for (int i = 0; i < n; i++)
    {
        if (k == 0)
            break;
        for (int j = 0; j < n; j++)
        {
            if (a[i] < b[j])
            {
                int temp = a[i];
                a[i] = b[j];
                b[j] = temp;
                k--;
                break;
            }
        }
    }
}

// sol #2
// k번만 비교
void func2(int a[], int b[])
{
    for (int i = 0; i < k; i++)
    {
        if (a[i] < b[i])
        {
            // int temp = a[i];
            // a[i] = b[i];
            // b[i] = temp;
            swap(a[i], b[i]);
        }
        else
            break;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(a, a + n);                 // 오름차순
    sort(b, b + n, greater<int>()); // 내림차순
    func1(a, b);
    //func2(a, b);
    long long result = 0;
    for (int i = 0; i < n; i++)
    {
        result += a[i];
        //cout << a[i] << ' ';
    }
    cout << result;
}

/*
TEST CASE
5 3
1 2 5 4 3
5 5 6 6 5
---------
26


5 3
1 2 5 4 3
5 6 9 1 2
---------
29

5 5
1 2 5 4 3
6 6 6 6 6
---------
30

5 4
1 2 5 4 3
6 6 6 6 6
---------
29
*/