#include <algorithm>;
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    vector<char> alp;
    while (getline(cin, str))
    {
        alp.clear();
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < str.size(); j++)
            {
                if (str[j] - 'a' == i || str[j] - 'A' == i)
                    alp.push_back(str[j]);
            }
        }
        for (int m = 0, n = 0; m < str.size() && n < alp.size(); m++)
        {
            if ((str[m] >= 'a' && str[m] <= 'z') || (str[m] >= 'A' && str[m] <= 'Z'))
            {
                str[m] = alp[n];
                n++;
            }
        }
        cout << str << endl;
    }
}