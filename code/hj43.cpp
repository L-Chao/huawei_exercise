#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mat;//迷宫矩阵
vector<vector<int>> path_best;//最优路径
vector<vector<int>> path_temp;//当前路径
int N, M;


void bestPath(int i, int j)
{
    mat[i][j] = 1;
    path_temp.push_back({i, j});
    //找最优路径需要比较判断结束位置
    if(i == N - 1 && j == M -1)
    {
        if(path_temp.size() < path_best.size() || path_best.empty())
        path_best = path_temp;
    }
    //走路 回溯
    //上
    if(i - 1 >= 0 && mat[i - 1][j] == 0)
        bestPath(i - 1, j);
    //下
    if(i + 1 < N && mat[i + 1][j] == 0)
        bestPath(i + 1, j);
    //左
    if(j - 1 >= 0 && mat[i][j - 1] == 0)
        bestPath(i, j - 1);
    //右
    if(j + 1 < M && mat[i][j + 1] == 0)
        bestPath(i, j + 1);
    //恢复现场
    mat[i][j] = 0;
    path_temp.pop_back();
};

int main()
{
    while(cin >> N >> M)
    {
        path_best.clear();
        path_temp.clear();
        mat = vector<vector<int>>(N, vector<int>(M,0));
        for(auto &row : mat)
        {
            for(auto &i : row)
            {
                cin >> i;
            }
        }
        //回溯法找路径
        bestPath(0, 0);
        for(auto x : path_best)
            cout << '(' << x[0] << ',' << x[1] << ')' << endl;
    }
    return 0;
}