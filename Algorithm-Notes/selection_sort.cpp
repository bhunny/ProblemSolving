#include <bits/stdc++.h>
using namespace std;
int n = 10;
int arr[] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};
void selectionSort()
{
    for (int i = 0; i < n; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
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
    selectionSort();
    cout << '\n';
    for (auto i : arr)
    {
        cout << i << ' '; // 0 1 2 3 4 5 6 7 8 9
    }
}