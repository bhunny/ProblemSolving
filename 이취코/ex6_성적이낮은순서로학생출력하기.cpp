#include <bits/stdc++.h>
using namespace std;
int n;

// sol #1 기본 정렬 라이브러리를 이용하여 구현
vector<pair<string, int>> v;
// compare() 함수로 원하는 조건으로 정렬
bool compare(pair<string, int> a, pair<string, int> b)
{
    return a.second < b.second;
}
void func1()
{
    for (int i = 0; i < n; i++)
    {
        string name;
        int score;
        cin >> name >> score;
        v.push_back({name, score});
    }
    sort(v.begin(), v.end(), compare);
    for (auto i : v)
    {
        cout << i.first << ' ';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    func1();
}

/*
test case

2
홍길동 95
이순신 77

3
홍길동 95
세종대왕 76
이순신 77
*/