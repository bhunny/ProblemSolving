#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int arr[1001];

int answer;
//반복문으로 계산하는 방식
//m의 크기가 매우 크게 된다면 시간초과가 발생할 수 있다.
void func1()
{
    while (m)
    {
        if (m == 0)
            break;
        for (int i = 0; i < k; i++)
        {
            if (m == 0)
                break;
            answer += arr[0];
            m--;
        }
        answer += arr[1];
        m--;
    }
}
// 반복수열으로 생각하고 해결
// 제일 큰수가 k번 반복하고 그 다음 수가 나온다. -> 이 수열이 반복됨 => 따라서 k+1이 수열의 길이
// m / k+1 : 반복되는 수열의 횟수
// m % k+1 : 나머지, 제일 큰수가 반복되는 횟수(온전한 수열이 안되므로)
void func2()
{
    int count = 0;
    count = (m / (k + 1)) * k;
    count += m % (k + 1);
    answer += arr[0] * count;       // 제일 큰 수가 등장하는 횟수
    answer += arr[1] * (m - count); // 그 다움 수가 등장하는 횟수
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }
    sort(arr, arr + n, greater<int>()); //내림차순 정렬
    //func1();
    func2();
    cout << answer;
}
/*

5 8 3
2 4 5 4 6
46

5 7 2
3 4 3 4 3
28 ( 4 4 4 4 4 4 4)

*/