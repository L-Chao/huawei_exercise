#include <iostream>

using namespace std;

/* bool isCode(string str)//判断是否为回文串，没用上，思路错了
{
    if(str.size() == 1 || str.empty())
        return true;
    bool temp = str[0] == str[str.size() - 1];
    str = str.substr(1, str.size() - 2);
    return isCode(str) && temp;
}
 */
int main()
{
    string str;
    while(cin >> str)
    {
        int res = 1;
        int len = str.size();
        for(int i = 1; i < len; i++)
        {
            int low = i - 1, high = i;/* 寻找以 i-1、i 为中心 长度为偶数的回文串 */
            while(low >= 0 && high < len && str[low] == str[high])
            {
                low--;
                high++;
            }
            if(high - low - 1 > res)
                res = high - low - 1;
            low = i - 1; high = i + 1;/* 寻找以 i 为中心 长度为奇数的回文串 */
            while(low >= 0 && high < len && str[low] == str[high])
            {
                low--;
                high++;
            }
            if(high - low - 1 > res)
                res = high - low - 1;            
        }
        cout << res << endl;
    }
    return 0;
}