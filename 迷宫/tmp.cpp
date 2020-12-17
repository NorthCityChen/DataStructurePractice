/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-12-16 10:26:50
 * @Description: 
 * @Website: https://grimoire.cn
 * @Copyright (c) Mr.Sen All rights reserved.
 */

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int x;
    int y;
};

queue<node> todo;
queue<node> bg;
int n, m;
int x2[5] = {1, -1, 0, 0};
int y2[5] = {0, 0, 1, -1};
int maps[105][105];
int walked[105][105];
//creat a map
int bfs(int bx, int by)
{
    int ans = 0;
    maps[bx][by] = 0;
    todo.push({bx, by});
    while (!todo.empty())
    {
        node tmp;
        tmp = todo.front();
        todo.pop();
        ans++;
        int x3 = tmp.x;
        int y3 = tmp.y;
        // cout<<x3<<" "<<y3<<endl;
        for (int i = 0; i < 4; i++)
        {
            int x = x2[i] + x3;
            int y = y2[i] + y3;
            if (x >= 0 && x < n && y >= 0 && y < m && maps[x][y] == 1)
            {
                todo.push({x, y});
                maps[x][y] = 0;
            }
        }
    }
    return ans;
}
int main()
{
    int ans = 0;
    int bx, by;
    //load the map
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &maps[i][j]);
            if (maps[i][j])
            {
                bg.push({i, j});
            }
        }
    }
    while (!bg.empty())
    {
        node tmp = bg.front();
        bg.pop();
        if (maps[tmp.x][tmp.y])
        {
            int res = bfs(tmp.x, tmp.y);
            ans = max(res, ans);
        }
    }
    cout << ans << endl;
    return 0;
}