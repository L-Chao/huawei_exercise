#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])/* 背包问题 */
{
    int n;
    while(cin >> n)
    {
        int w[10] = {0};//1-2000
        int num[10] = {0};//1-6
        for(int i = 0; i < n; ++i)
            cin >> w[i];
        for(int i = 0; i < n; ++i)
            cin >> num[i];
/*         int v[120000] = {0};
        v[0] = 1; */
        int maxw = 0;
        for(int i = 0; i < n; ++i)
            maxw += w[i] * num[i];
        vector<int> v(maxw + 1, 0);
        v[0] = 1;
        for(int i = 0; i < n; ++i)
            for(int j = maxw; j >= 0; --j)
                for(int k = 1; k <= num[i]; ++k)
                {
                    if(v[j] == 1)
                        v[j + k * w[i]] = 1;/* 如果可以称出重量 j, 那么 j + k * w[i]也可以 */
                }
        int cnt = 0;
        for(int i = 0; i <= maxw; ++i)
        {
            cnt += v[i];
        }
        cout << cnt << endl;
    }
    return 0;
}