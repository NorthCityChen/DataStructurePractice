/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-12-17 21:59:52
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

// * 定义了一个用来输出的模板类
template <typename tt>
class require
{
private:
    /* data */
public:
    void log(tt a, string style, string ed)
    {
        if (style == "red")
        {
            cout << "\033[31m" << a;
        }
        if (style == "green")
        {
            cout << "\033[32m" << a;
        }
        if (style == "yellow")
        {
            cout << "\033[33m" << a;
        }
        if (style == "blue")
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
        if (style == "red-g")
        {
            cout << "\033[41m" << a;
        }
        if (style == "green-g")
        {
            cout << "\033[42m" << a;
        }
        if (style == "yellow-g")
        {
            cout << "\033[43m" << a;
        }
        if (style == "blue-g")
        {
            cout << "\033[44m" << a;
        }
        if (style == "purple-g")
        {
            cout << "\033[45m" << a;
        }
        cout << "\033[0m";
        if (ed == "endl")
            cout << endl;
    }
};

int result(int bgx, int bgy, int edx, int edy)
{
    require<string> console; // javascript 直呼内行 ！！！
    int a, b;
    console.log("\n路径演示：\n", "green", "endl");
    stack<node> s;
    s.push({edx, edy});
    vis[edx][edy] = 1;
    for (int xp = edx, yp = edy;; xp = a, yp = b)
    {
        a = pre[xp][yp].befx;
        b = pre[xp][yp].befy;
        vis[a][b] = 1;

        if (a == bgx && b == bgy)
            break;
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (vis[i][j] == 1)
            {
                console.log(" * ", "green-g", "");
            }
            else if (vis[i][j] == 0)
            {
                console.log(" * ", "blue-g", "");
            }
            else
            {
                console.log(" * ", "yellow-g", "");
            }
        }
        cout << endl;
    }

    cout << endl;
    console.log("* 黄色图块为墙壁", "yellow", "endl");
    console.log("* 蓝色图块为未通过路径", "blue", "endl");
    console.log("* 绿色图块为通过路径", "green", "endl");

    return 0;
}

void bfs(int bgx, int bgy, int edx, int edy)
{
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
        node tmp = todo.front();
        todo.pop();
        int curx = tmp.x;
        int cury = tmp.y;

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
    cout << "请输入地图的长和宽：" << endl;
    cin >> lenx >> leny;
    cout << "请输入地图：" << endl;
    for (int i = 0; i < lenx; i++)
    {
        for (int j = 0; j < leny; j++)
        {
            scanf("%d", &maps[i][j]);
            if (maps[i][j] == 1)
                vis[i][j] = -1;
        }
    }

    cout << "请输入起点和终点坐标：{例如：1 1 4 4}" << endl;
    cin >> bgx >> bgy >> edx >> edy;
    bfs(bgx, bgy, edx, edy);

    return 0;
}