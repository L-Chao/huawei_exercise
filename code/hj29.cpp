#include <iostream>
#include <string>

using namespace std;

string code(const string str)
{
    string res;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            if(str[i] == 'z')
                res += 'A';
            else
                res += str[i] - 32 + 1;
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            if(str[i] == 'Z')
                res += 'a';
            else
                res += str[i] + 32 + 1;
        }
        else if(str[i] >= '0' && str[i] <= '9')
        {
            if(str[i] == '9')
                res += '0';
            else
                res += str[i] + 1;
        }
        else
        {
            res += str[i];
        }
    }
    return res;
};

string deCode(const string str)
{
    string res;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '\0') 
            break;
        else if(str[i] >= 'a' && str[i] <= 'z')
        {
            if(str[i] == 'a')
                res += 'Z';
            else
                res += str[i] - 32 - 1;
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            if(str[i] == 'A')
                res += 'z';
            else
                res += str[i] + 32 - 1;
        }
        else if(str[i] >= '0' && str[i] <= '9')
        {
            if(str[i] == '0')
                res += '9';
            else
                res += str[i] - 1;
        }
        else
        {
            res += str[i];
        }
    }

    return res;
}

int main()
{
    string str1;
    string str2;
    while(cin >> str1 >> str2)/* 连续输入 */
    {
        string s1 = code(str1);
        string s2 = deCode(str2);
        cout << s1 << endl;
        cout << s2 << endl;
    }
    return 0;
}