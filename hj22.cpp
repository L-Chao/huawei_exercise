#include <iostream>
#include <vector>

using namespace std;

int simulate(const int &n)
{
    if(n < 2)
        return 0;
    if( n == 2)
        return 1;
    if(n == 3)
        return 1;
    int cnt = n / 3;
    return cnt + simulate(n - 3 * cnt + cnt);

}

int main()
{
    int n;
    vector<int> res;
    while(cin >> n)
    {
        if(n != 0)
        {
            res.push_back(simulate(n));
        }
        else 
            break;
    }
    for(auto i : res)
    {
        cout << i << endl;
    }
    return 0;
}