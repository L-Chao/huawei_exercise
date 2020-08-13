#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> incount(vector<int> height)
{
    int len = height.size();
    vector<int> incnt(len, 1);
    for (int i = 1; i < len; i++)
    {
        int j = 0;
        for (int j = i - 1; j >= 0 ; j--)
        {
            if (height[j] < height[i] && incnt[i] < incnt[j] + 1)/*  */
            {
                incnt[i] = 1 + incnt[j];
            }
        }
    }
    return incnt;
};

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> height(n);
        for (int i = 0; i < n; i++)
            cin >> height[i];
        vector<int> incnt;
        vector<int> decnt;
        incnt = incount(height);
        reverse(height.begin(), height.end());
        decnt = incount(height);
        reverse(decnt.begin(), decnt.end());
        vector<int> cnt(n);
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            cnt[i] = incnt[i] + decnt[i] - 1;
            res = max(res, cnt[i]);
        }
        cout << n - res << endl;
    }
    return 0;
}