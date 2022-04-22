#include <bits/stdc++.h>
using namespace std;
int n, m;
int store[1000001];
// 계수정렬을 이용한 방식
void func1()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        store[s]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int o;
        cin >> o;
        if (store[o] > 0)
            cout << "yes" << ' ';
        else
            cout << "no" << ' ';
    }
}
// 이중탐색을 이용한 방식
int binary_search(int data[], int target, int start, int end)
{
    int mid = start;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (data[mid] == target)
            return mid;
        else if (data[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
void func2()
{
    cin >> n;
    int data[n];
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        data[i] = s;
    }
    //이진탐색 전 데이터 오름차순 정렬
    sort(data, data + n);

    cin >> m;

    int result = 0;
    for (int i = 0; i < m; i++)
    {
        int o;
        cin >> o;
        result = binary_search(data, o, 0, n - 1);
        if (result == -1)
        {
            cout << "no" << ' ';
        }
        else
        {
            cout << "yes" << ' ';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //func1();
    func2();
}

/*
5
8 3 7 9 2
3
5 7 9
----------
no yes yes

*/