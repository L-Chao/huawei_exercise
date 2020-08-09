#include <iostream>
#include <vector>

using namespace std;
bool isPrime(int n)
{
    int m = n / 2 + 1;
    for(int i = 2; i <= m; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
};

int main()
{
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    int mat[num][num] = {0};
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
        {
            if(isPrime(arr[i] + arr[j]))
                mat[i][j] = 1;
        }
    }
    return 0;

}