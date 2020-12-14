/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-12-14 10:33:18
 * @Description: 行车路线 dj 解法
 * @Website: https://grimoire.cn
 * @Copyright (c) Mr.Sen All rights reserved.
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node
{
    LL to, w, type;
};

vector<node> V[505];
bool vis[505];
LL dis[505], smallRoad[505], n;

void dij(LL s)
{
    LL i, j, k;
    for (i = 1; i <= n; i++)
    {
        vis[i] = 0;
        smallRoad[i] = 0;
        dis[i] = 1e9;
    }
    dis[1] = 0;
    for (j = 1; j < n; j++)
    {
        LL min1 = 1e9;
        for (i = 1; i <= n; i++)
        {
            if (min1 >= dis[i] && !vis[i])
            {
                min1 = dis[i];
                k = i;
            }
        }
        vis[k] = 1;
        for (i = 0; i < V[k].size(); i++)
        {

            LL v = V[k][i].to, len = V[k][i].w, t = V[k][i].type;
            if (vis[v])
                continue;
            if (t == 0) // * 走大路 直接增加疲劳值
            {
                if (dis[v] > dis[k] + len)
                {
                    dis[v] = dis[k] + len;
                    smallRoad[v] = 0;
                }
            }
            else // * 走小路 需要使用smallRoad数组来缓存已走的小路长度
            {
                if (!smallRoad[k]) // * 第一次走小路 前一次没有走小路
                {
                    if (dis[v] > dis[k] + len * len)
                    {
                        dis[v] = dis[k] + len * len;
                        smallRoad[v] = len;
                    }
                }
                else
                {
                    LL len1 = (smallRoad[k] + len) * (smallRoad[k] + len) - smallRoad[k] * smallRoad[k];
                    // * (smallRoad + len) ** 2 - smallRoad ** 2
                    // * 选择增加的疲劳
                    if (dis[v] > dis[k] + len1)
                    {
                        dis[v] = dis[k] + len1;
                        smallRoad[v] = smallRoad[k] + len;
                    }
                }
            }
        }
    }
}
int main()
{
    LL m, a, b;
    node tmp;
    // * 重定向输入
    // freopen("input.in", "r", stdin);
    scanf("%lld%lld", &n, &m);
    while (m--)
    {
        scanf("%lld%lld%lld%lld", &tmp.type, &a, &b, &tmp.w);
        tmp.to = b;
        V[a].push_back(tmp);
        tmp.to = a;
        V[b].push_back(tmp);
        // * 无向图
    }
    dij(1);
    cout << dis[n] << endl;
    return 0;
}