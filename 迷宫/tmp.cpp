#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int maze[15][15];
int vis[15][15];
int aa[50], bb[50];
int d[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int kx = 0, ky = 0, ex = 4, ey = 4; //开始坐标为（0，0），结束坐标为（4，4）
int len;

struct node
{
    int x, y, step;
} a, nxt, path[105][105]; //a为当前点，next为下一个点，
//path记录路径 path[][].step记录此点是否已经走过，未走过：0，已走过：1

int check(int s, int t)
{
    if (s < 0 || s > 4 || t < 0 || t > 4)
        return 0;
    if (maze[s][t] == 1)
        return 0;
    //	if(vis[s][t]==1)          可以用path[][]数组来记录访问过的点，所以不再单独判断是否访问过
    //		return 0;
    return 1;
}

void shuchu()
{ //从后向前寻找访问过的点，若正向输出，先存储后输出即可
    int X, Y, x1, y1;
    int i = 0;
    X = ex;
    Y = ey;
    aa[i] = X;
    bb[i] = Y;
    i++;
    while (i != len)
    {
        x1 = path[X][Y].x;
        y1 = path[X][Y].y;
        X = x1;
        Y = y1;
        aa[i] = X;
        bb[i] = Y;
        i++;
    }
    for (i = len; i >= 0; i--)
    {
        printf("(%d, %d)\n", aa[i], bb[i]);
    }
}

void bfs()
{
    queue<node> q;
    a.x = kx;
    a.y = ky;
    a.step = 0;
    //	vis[kx][ky]=1;
    q.push(a);
    while (!q.empty())
    {
        a = q.front();
        q.pop();
        for (int l = 0; l < 4; l++)
        {
            nxt.x = a.x + d[l][0];
            nxt.y = a.y + d[l][1];
            if (!check(nxt.x, nxt.y) || path[nxt.x][nxt.y].step == 1)
                continue;
            nxt.step = a.step + 1;
            path[nxt.x][nxt.y].step = 1; //记录是否走过
            path[nxt.x][nxt.y].x = a.x;  //到达当前点的前一点的x坐标
            path[nxt.x][nxt.y].y = a.y;  //到达当前点的前一点的y坐标
                                         //		vis[nxt.x][nxt.y]=1;
            q.push(nxt);
            if (nxt.x == ex && nxt.y == ey)
            {
                len = nxt.step; //当前步数
                shuchu();
                return;
            }
        }
    }
}

int main()
{
    //	memset(vis,0,sizeof(vis));
    memset(path, 0, sizeof(path));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> maze[i][j];
        }
    }
    path[kx][ky].step = 0;
    bfs();
    return 0;
}