#include <iostream>
/* #include <math.h> */

using namespace std;

int main()
{
    double num;
    cin >> num;
    double left = 0;
    double right = num;
    double mid = 0;
    double ans;
    while(mid * mid * mid - num > 0.001 || mid * mid * mid - num < -0.001)
    {
        mid = left + (right - left) / 2;
        if(mid * mid * mid > num) right = mid;
        if(mid * mid * mid < num) left = mid;
/*         if(mid * mid * mid - num < 0.001 || mid * mid * mid - num > -0.001)
        {
            ans = mid;
            break;
        } */
    }
    ans = mid;
    cout.flags(ios::fixed);
    cout.precision(1);
    cout << ans << endl;
    return 0;
    
}