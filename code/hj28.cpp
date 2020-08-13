#include <iostream>
#include <vector>

using namespace std;

int t[100][100] = {0};
vector<int> ji(100, -1);
vector<int> ou(100, -1);
vector<int> vistit(100, 0);

bool isPrime(int n)
{
    //int m = n / 2 + 1;
    for(int i = 2; i <= n / i; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
};

int dfs(int i)
{
    for(int j = 0; j < 100; ++j)
    {
        if(t[i][j] == 1 && !vistit[j])
        {
            vistit[j] = 1;
            if(ou[j] == -1 || dfs(ou[j]))
            {
                ji[i] = j;
                ou[j] = i;
                return 1;
            }
        }

    }
    return 0;
}

int main()
{
    vector<int> cou, cji;
    int n;
    while(cin >> n)
    {
        for(int i =0; i < n; i++)
        {
            int temp;
            cin >> temp;
            if(temp % 2 == 0) cou.push_back(temp);
            else cji.push_back(temp);
        }
        for(int i = 0; i < cji.size(); ++i)
            for(int j = 0; j < cou.size(); ++j)
                if(isPrime(cji[i] + cou[j]))
                    t[i][j] = 1;
        //匈牙利算法
        int res = 0;
        for(int i = 0; i < cji.size(); ++i)
        {
            if(ji[i] == -1)
            {
                for(int j = 0; j < vistit.size(); ++j) vistit[j] = 0;
                res += dfs(i);
            }
        }
        cout << res << endl;
        cji.clear();
        cou.clear();
        for(int i = 0; i < 100; i++)
        {
            for(int j = 0; j < 100; j++)
            {
                t[i][j] = 0;
            }
        }
        for(int i = 0; i < 100; i++)
        ji[i] = ou[i] = -1;
    }

    return 0;
}