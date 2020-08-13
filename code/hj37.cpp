#include <iostream>

using namespace std;

int main()
{
    int month;
    while(cin >> month)
    {
        int first = 1, second = 0, third = 0;
        while(--month)
        {
            third += second;
            second = first;
            first = third;
        }
        cout << first + second + third << endl;
    }
    return 0;
}