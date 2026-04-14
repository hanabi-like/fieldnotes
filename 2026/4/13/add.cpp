#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string add(string num1, string num2)
{
    string ans;
    ans.reserve(max(num1.length(), num2.length()) + 1);
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int c = 0;
    while (i >= 0 || j >= 0 || c)
    {
        int x = (i >= 0) ? num1[i--] - '0' : 0;
        int y = (j >= 0) ? num2[j--] - '0' : 0;
        int sum = x + y + c;
        ans.push_back(sum % 10 + '0');
        c = sum / 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string num1 = "3982744317348234923479324";
    string num2 = "38294329432432";
    cout << add(num1, num2) << endl;
    return 0;
}