#include <iostream>
#include <string>
using namespace std;

/*
0 : 1110111
1 : 0010010
2 : 1011101
3 : 1011011
4 : 0111010
5 : 1101011
6 : 1101111
7 : 1110010
8 : 1111111
9 : 1111011
*/
string setLamp(int num)
{
    string result;
    switch (num)
    {
    case 0:
        result = "1110111";
        break;
    case 1:
        result = "0010010";
        break;
    case 2:
        result = "1011101";
        break;
    case 3:
        result = "1011011";
        break;
    case 4:
        result = "0111010";
        break;
    case 5:
        result = "1101011";
        break;
    case 6:
        result = "1101111";
        break;
    case 7:
        result = "1110010";
        break;
    case 8:
        result = "1111111";
        break;
    case 9:
        result = "1111011";
        break;
    case -1:
        result = "0000000";
        break;
    }
    return result;
}
int checkDiff(int a, int b)
{
    string aa = setLamp(a);
    string bb = setLamp(b);
    int result = 0;
    for (int i = 0; i < aa.length(); i++)
    {
        if (aa[i] != bb[i])
            result++;
    }
    return result;
}
string led[5];
int main(int argc, char **argv)
{
    int t, a, b;
    cin >> t;
    // cout <<	checkDiff(0,9);
    for (int i = 0; i < t; i++)
    {
        int answer = 0;
        cin >> a >> b;
        // cout << a << ' ' << b << '\n';
        int num1 = a;
        int num2 = b;
        for (int i = 10; i < 1000000; i *= 10)
        {
            //  cout <<i<<' '<< num1 <<' ' << num2 <<'\n';
            if (num1 == num2)
                continue;
            else if (num1 % 10 == 0 && num1 / 10 == 0)
            {
                answer += checkDiff(-1, num2 % 10);
            }
            else if (num2 % 10 == 0 && num2 / 10 == 0)
            {
                answer += checkDiff(num1 % 10, -1);
            }
            else
            {
                answer += checkDiff(num1 % 10, num2 % 10);
            }
            // cout << answer << '\n';
            num1 = a / i;
            num2 = b / i;
        }
        cout << answer << '\n';
    }
    return 0;
}