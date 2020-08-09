#include <iostream>
#include <string>
#include <unordered_map>
#include <limits>/* #include <limits.h> */
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string str;
    vector<string> res;
    while(cin >> str)
    {
        unordered_map<char, int> cnt;
        int min_cnt = INT_MAX;
        string temp;
        for(auto s : str)
        {
            cnt[s]++;
        }
        for(auto s : str)
        {
            min_cnt = min(min_cnt, cnt[s]);
        }
        for(auto s : str)
        {
            if(cnt[s] != min_cnt)
            temp += s;
        }
        res.push_back(temp);
    }
    for(auto s : res)
    {
        cout << s << endl;
    }
    return 0;
}