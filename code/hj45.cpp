#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int maxBeauty(string &str)
{
    unordered_map<char, int> charCnt;
    for(auto s : str)
    {
        if(s >= 'A' && s <= 'Z')
        {
            s += 32;
        }
        charCnt[s]++;
    }
    sort(str.begin(), str.end());
    str.erase(unique(str.begin(), str.end()), str.end());
    for(int i = 0; i < str.size() - 1; ++i)
    {
        for(int j = i; j < str.size(); ++j)
        {
            if(charCnt[str[i]] < charCnt[str[j]])
            swap(str[i], str[j]);
        }
    }
    int beauty = 26;
    int res = 0;
    for(auto s : str)
    {
        res += beauty * charCnt[s];
        --beauty;
    }
    return res;
}

int main(int argc, char *argv[])
{
    int N;
    while(cin >> N)
    {
        string str;
        vector<int> res;
        for(int i = 0; i < N; ++i)
        {
            cin >> str;
            res.push_back(maxBeauty(str));

        }
        for(auto i : res)
        cout << i << endl;
    }
    return 0;
}