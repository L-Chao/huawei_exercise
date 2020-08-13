#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool isBrother(string word, string str)
{
    if (str.size() == word.size() && str != word)
    {
        for (int i = 0; i < word.size(); i++)
        {
            int pos = str.find(word[i]);
            int cnt1 = count(str.begin(), str.end(), word[i]);
            int cnt2 = count(word.begin(), word.end(), word[i]);
            if (pos == -1 || cnt1 != cnt2)
                return false;
        }
        return true;
    }
    return false;
}

int main()
{
    int num;
    vector<string> str;
    while (cin >> num)
    {
        str.clear();
        while (num--)
        {
            string temp;
            cin >> temp;
            str.push_back(temp);
        }
        string word;
        int n;
        cin >> word;
        cin >> n;
        vector<string> res;
        int cnt = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (isBrother(word, str[i]))
            {
                cnt++;
                res.push_back(str[i]);
            }
        }
        sort(res.begin(), res.end());
        //res.erase(unique(res.begin(), res.end()), res.end());
        cout << cnt << endl;
        //for(int i = 0; i < n; i++)
        if(n - 1 < res.size())
        cout << res[n - 1] << endl;
    }

    /* sort(str.begin(), str.end()); */

    return 0;
}