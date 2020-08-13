#include <iostream>

using namespace std;

int num[9][9];
int flag = false;

//1.行不重复
//2.列不重复
//3. 3*3的宫格不重复
bool check(int n)
{
    int h = n / 9;
    int l = n % 9;

    for (int i = 0; i < 9; i++)
        if (i != h && num[i][l] == num[h][l]) //发现重复列 元素
            return false;

    for (int j = 0; j < 9; j++)
        if (j != l && num[h][j] == num[h][l]) //行重复
            return false;

    //3*3宫格 1-9
    for (int i = h / 3 * 3; i < h / 3 * 3 + 3; i++)
        for (int j = l / 3 * 3; j < l / 3 * 3 + 3; j++)
            if ((i != h || j != l) && num[i][j] == num[h][l])
                return false;

    return true;
}

void dfs(int n)
{
    if (n == 81)
    {
        //输出9宫格
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cout << num[i][j] << " ";
            }
            cout << num[i][8] << endl;
        }
        flag = true;
        return;
    }

    int h = n / 9; //行
    int l = n % 9; //列

    if (num[h][l] == 0)
    {
        //填数字
        //回溯法/ 深度优先
        for (int i = 1; i <= 9; i++)
        {
            num[h][l] = i; //填数字
            if (check(n))
            {
                dfs(n + 1);
                if (flag == true)
                    return;
                num[h][l] = 0;
            }
        }
        num[h][l] = 0;
    }
    else
    {
        dfs(n + 1);
    }
}

int main()
{
    //9宫格输入
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> num[i][j];

    dfs(0);
    return 0;
}