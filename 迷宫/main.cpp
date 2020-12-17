/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-12-16 11:37:19
 * @Description: 
 * @Website: https://grimoire.cn
 * @Copyright (c) Mr.Sen All rights reserved.
 */

/*
    迷宫这题真是啥也没给啊...
    算了，还是自己定义一下吧
    ! 假设地图大小 最大 100x100 pixel
    ! 假设迷宫起点为左上角 迷宫出口在右下角
    ! 假设只能向四个方向移动（上下左右）
*/
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int x;
    int y;
};

struct mem
{
    int befx; // 前置x值
    int befy; // 后置y值
};

queue<node> todo;
int maps[105][105];
int vis[105][105];
mem pre[105][105];

int lenx, leny; // 地图长度，宽度

int x2[5] = {1, -1, 0, 0};
int y2[5] = {0, 0, 1, -1};
template <typename tt>
class require
{
private:
    /* data */
public:
    void log(tt a, string style)
    {
        if (style == "red")
        {
            cout << "\033[31m" << a;
        }
        if (style == "blue")
        {
            cout << "\033[32m" << a;
        }
        if (style == "yellow")
        {
            cout << "\033[33m" << a;
        }
        if (style == "green")
        {
            cout << "\033[34m" << a;
        }
        if (style == "purple")
        {
            cout << "\033[35m" << a;
        }
        if (style == "normal")
        {
            cout << a;
        }
        cout << "\033[0m" << endl;
    }
};

int result(int bgx, int bgy, int edx, int edy)
{
    require<int> console; // javascript 直呼内行 ！！！
    int a, b;
    cout << "路径：" << endl;
    stack<node> s;
    s.push({edx, edy});
    for (int xp = edx, yp = edy;; xp = a, yp = b)
    {
        a = pre[xp][yp].befx;
        b = pre[xp][yp].befy;
        // s.push({a, b});
        vis[a][b] = 1;

        if (a == bgx && b == bgy)
            break;
    }
    // while (s.size())
    // {
    //     cout << s.top().x << "," << s.top().y << endl;
    //     s.pop();
    // }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            // cout << "{" << pre[i][j].befx << "," << pre[i][j].befy << "} ";
            // // string output = ;
            // console.log(pre[i][j].befx, "red");
            // console.log()
            // console.log(pre[i][j].befy, "red");
            console.log()
        }
        cout << endl;
    }

    return 0;
}

void bfs(int bgx, int bgy, int edx, int edy)
{
    cout << "我开始摇滚了" << endl;
    /* 
    * bgx 起点的x值
    * bgy 终点的y值
    * edx 起点的x值
    * edy 终点的y值
    */
    todo.push({bgx, bgy});
    maps[bgx][bgy] = 0;
    pre[bgx][bgy].befx = -1;
    pre[bgx][bgy].befy = -1;

    while (todo.size())
    {
        // cout << "cao" << endl;

        node tmp = todo.front();
        todo.pop();
        int curx = tmp.x;
        int cury = tmp.y;

        cout << curx << " " << cury << endl;

        if (curx == edx && cury == edy)
        {
            result(bgx, bgy, edx, edy);
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int x = x2[i] + curx;
            int y = y2[i] + cury;
            if (x >= 0 && x < lenx && y >= 0 && y < leny && maps[x][y] == 0)
            {
                todo.push({x, y});
                cout << "添加：" << x << " " << y << endl;

                maps[x][y] = 1;
                pre[x][y].befx = curx;
                pre[x][y].befy = cury;
            }
        }
    }
}

int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out","w", stdout);
    int bgx, bgy, edx, edy;
    cin >> lenx >> leny;

    for (int i = 0; i < lenx; i++)
    {
        for (int j = 0; j < leny; j++)
        {
            scanf("%d", &maps[i][j]);
        }
    }
    cout << "请输入起点啥的" << endl;
    cin >> bgx >> bgy >> edx >> edy;
    bfs(bgx, bgy, edx, edy);

    return 0;
}