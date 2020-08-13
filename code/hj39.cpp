#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{

    string imask, iip1, iip2;
    stringstream ss;
    while(cin >> imask >> iip1 >> iip2)
    {
        int mask1 = 0, mask2 = 0, mask3 = 0, mask4 = 0;
        int ip1a = 0, ip1b = 0, ip1c = 0, ip1d = 0;
        int ip2a = 0, ip2b = 0, ip2c = 0, ip2d = 0;
        char ch;
        ss << imask;
        ss >> mask1 >> ch >> mask2 >> ch >> mask3 >> ch >> mask3;
        ss.clear();

        ss << iip1;
        ss >> ip1a >> ch >> ip1b >> ch >> ip1c >> ch >> ip1d;
        ss.clear();

        ss << iip2;
        ss >> ip2a >> ch >> ip2b >> ch >> ip2c >> ch >> ip2d;
        ss.clear();

        if(mask1 > 255 || mask1 < 0 || mask2 > 255 || mask2 < 0 || mask3 > 255 || mask3 < 0 || mask4 > 255 || mask4 < 0
           || ip1a > 255 || ip1a < 0 || ip1a > 255 || ip1a < 0 || ip1a > 255 || ip1a < 0 || ip1a > 255 || ip1a < 0
           || ip2a > 255 || ip2a < 0 || ip2a > 255 || ip2a < 0 || ip2a > 255 || ip2a < 0 || ip2a > 255 || ip2a < 0)
           cout << 1 << endl;
        else if(ip1a & mask1 == ip2a & mask1 && ip1b & mask1 == ip2b & mask1 && ip1c & mask1 == ip2c & mask1 && ip1d & mask1 == ip2d & mask1)
            cout << 0 << endl;
        else
            cout << 2 << endl;
    }
    return 0;
}