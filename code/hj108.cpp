#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int num1, num2;
    cin >> num1 >> num2;
    int res = num1 * num2;
    for(int i = 2; i <= min(num1, num2) / 2 + 1; i++)
    {
        if(num1 % i == 0 && num2 % i == 0)
        {
            res /= i;
        }
    }
    cout << res << endl;
    return 0;
}