#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    while(getline(cin, str))
    /* getline(cin, str); */
    {
        vector<string> res;
        string temp;
        for(int i = 0; i < str.size(); i++)
        {
            if((str[i] >= 'a' && str[i] <= 'z') || (str[i]) >= 'A' && str[i] <= 'Z')
            {
                temp += str[i];
            }
            else
            {
                if(!temp.empty())
                {
                    res.push_back(temp);
                    temp.clear();
                }

            }
        }
        if(!temp.empty())
        {
            res.push_back(temp);
            temp.clear();
        }
        for(int i = res.size() - 1; i > 0; i--)
        {
            cout << res[i] << ' ';
        }
        cout << res[0] << endl;
    }
    return 0;
}