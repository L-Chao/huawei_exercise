#include <iostream>

using namespace std;

int main()
{
    double high;
    while(cin >> high)
    {
        double high5 = high/32.0;
        double s = 0;
        for(int i = 0; i < 5; i++)
        {
            if(i == 0)
            {
                s += high;
                high /= 2;
            }
            else
            {
                s += high * 2;
                high /= 2;
            }
            
        }
        cout << s << endl << high5 << endl;
    }

    return 0;
}