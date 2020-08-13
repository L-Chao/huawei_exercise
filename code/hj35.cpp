#include <iostream>

#include <vector>

using namespace std;


int main()
{
    int n;
    while(cin >> n)
    {
        vector< vector<int> > res(1, vector<int>(1, 1));
        for(int i = 2; i <= n; i++)/* 迭代，每次迭代把多出来的元素依次加到 数组中每一行的最后一个元素，元素个数为 n*(n + 1)/2; */
        {
            int row = i - 1;
            for(int j = i * (i - 1) / 2 + 1; j <= i * (i + 1) / 2; j++)
            {
                if(j == i * (i - 1) / 2 + 1)
                {
                    res.push_back({j});
                    row--;
                }
                else
                {
                    if(row >= 0)
                    {
                        res[row].push_back(j);
                        row--;
                    }

                }
            }
        }
        for(int i = 0; i < res.size(); i++)/* 输出 */
        {
            for(int j = 0; j < res[i].size(); j++)
            {
                if(j < res[i].size() - 1)
                    cout << res[i][j] << ' ';
                else
                    cout << res[i][j];
            }
            cout << endl;
        }

    }
    return 0;
}