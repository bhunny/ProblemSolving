#include <bits/stdc++.h>
using namespace std;
int n = 10;
int arr[] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};
void insertionSort()
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
            else
                break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (auto i : arr)
    {
        cout << i << ' '; // 7 5 9 0 3 1 6 2 4 8
    }
    insertionSort();
    cout << '\n';
    for (auto i : arr)
    {
        cout << i << ' '; // 0 1 2 3 4 5 6 7 8 9
    }
}