#include <iostream>
#include <string>
#include <vector>

using namespace std;
char letterToNum(const char &c)
{
    /* char num; */
    if(c >= 'a' && c <= 'c')
        return '2';
    if(c >= 'd' && c <= 'f')
        return '3';
    if(c >= 'g' && c <= 'i')
        return '4';
    if(c >= 'j' && c <= 'l')
        return '5';
    if(c >= 'm' && c <= 'o')
        return '6';
    if(c >= 'p' && c <= 's')
        return '7';
    if(c >= 't' && c <= 'v')
        return '8';
    if(c >= 'w' && c <= 'z')
        return '9';
};

int main()
{
    string str;
    vector<string> res;
    while(cin >> str)
    {
        string temp;
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
            temp += letterToNum(str[i]);
            else if(str[i] >= 'A' && str[i] <= 'Z')
            {
                if(str[i] != 'Z')
                    temp += str[i] + 32 + 1;
                else
                    temp += 'a';

            }
            else
                temp += str[i];
            
        }
        res.push_back(temp);
    }
    for(auto s : res)
    {
        cout << s << endl;
    }
    return 0;
}