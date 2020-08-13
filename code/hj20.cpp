#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;/* C++ 14(g++5.4) 通过，C++ 11 (clang++ 3.9) 不通过 */
bool validCode(string str)/* 使用函数，满足条件返回 true, 不满足的情况都返回 false */
{

    if (str.size() > 8)
    {
        int flag1 = 0;
        int flag2 = 0;
        int flag3 = 0;
        int flag4 = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
                flag1 = 1;
            else if (str[i] >= 'a' && str[i] <= 'z')
                flag2 = 1;
            else if (str[i] >= '0' && str[i] <= '9')
                flag3 = 1;
            else
                flag4 = 1;
        }
        if (flag1 + flag2 + flag3 + flag4 >= 3)
        {
            vector<string> temp;
            for (int i = 0; i < str.size(); i++)
            {
                temp.push_back(str.substr(i, 3));
            }
            std::sort(temp.begin(), temp.end());
            int i = 0;
            for (i = 0; i < temp.size() - 1; i++)
            {
                if (temp[i] == temp[i + 1])
                    return false;
            }
            if (i == temp.size() - 1)
            {
                return true;
            }
        }
        return false;
    }
}

int main()
{
    string str;
    vector<string> vec;
    while (getline(cin, str))
    {
        vec.push_back(str);
    }
    for (int i = 0; i < vec.size(); i++)
    {
        bool isvalid = validCode(vec[i]);
        if (isvalid)
            cout << "OK" << endl;
        else
            cout << "NG" << endl;
    }
    return 0;
}