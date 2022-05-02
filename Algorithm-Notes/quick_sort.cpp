#include <bits/stdc++.h>
using namespace std;

int n = 10;
int arr[] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};
void quickSort(int start, int end)
{
    if (start >= end)
        return;
    int pivot = start;
    int left = start + 1;
    int right = end;
    while (left <= right)
    {
        // 피벗보다 큰 값을 찾을때까지 인덱스 증가 => 왼쪽에 작은 값이 와야하므로 큰값을 저장한 뒤 오른쪽 값과 교체해야한다.
        while (left <= end && arr[left] <= arr[pivot])
            left++;
        // 피벗보다 작은 값을 찾을 때 까지
        while (right > start && arr[right] >= arr[pivot])
            right--;
        // 만약 엇갈렸다면 작은값과 피벗값을 교체
        //=> 엇갈렸다는 것은 왼쪽(Left)에 피벗보다 큰 값이 없는 것이고, 오른쪽(right)에 작은 값이 있다는 것이다.
        if (left > right)
            swap(arr[pivot], arr[right]);
        // 아니라면 작은데이터와 큰 데이터 교체 => left에는 피벗보다 큰값, right에는 작은값이 들어가 있다.
        else
            swap(arr[left], arr[right]);
    }
    // right에 pivot값이 들어간다.
    quickSort(start, right - 1); // right에는 피벗보다 작은 값이 들어가므로 좌측
    quickSort(right + 1, end);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (auto i : arr)
    {
        cout << i << ' '; // 7 5 9 0 3 1 6 2 4 8
    }
    quickSort(0, n - 1);
    cout << '\n';
    for (auto i : arr)
    {
        cout << i << ' '; // 0 1 2 3 4 5 6 7 8 9
    }
}