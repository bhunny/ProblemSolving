#include <bits/stdc++.h>
using namespace std;
int n;

// 계수행렬
int nums[100001];
void func1()
{
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums[num]++;
    }
    for (int i = 100001 - 1; i >= 0; i--)
    {
        while (nums[i] >= 1)
        {
            cout << i << ' ';
            nums[i]--;
        }
    }
}

//기본 라이브러리 이용
vector<int> nums2;
bool compare(int a, int b)
{
    return a > b;
}
void func2()
{
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums2.push_back(num);
    }
    sort(nums2.begin(), nums2.end()); //, compare);
    for (int i = 0; i < n; i++)
    {
        cout << nums2[i] << ' ';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    func1();
    //func2();
}