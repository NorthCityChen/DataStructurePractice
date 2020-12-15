/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-12-15 10:04:39
 * @Description: 
 * @Website: https://grimoire.cn
 * @Copyright (c) Mr.Sen All rights reserved.
 */
#include <bits/stdc++.h>
#include "cj.hpp"
using namespace std;

const int N = 1e6 + 10;
const int M = 1e9 + 10;

int main()
{
    // freopen("input.in", "r", stdin);
    //freopen("output.out","w", stdout);
    string cmd;
    System s;
    s.Welcome("welcome");
    while (cout << "admin@coolQuery: # ", cin >> cmd && cmd != "exit")
    {
        if (cmd == "1")
            s.add(4);
        if (cmd == "2")
            s.forEach(1);
        if (cmd == "3")
            s.forEach(0);
        if (cmd == "4")
            s.info();
        if (cmd == "help")
            s.Welcome("help");
    }
    cout << "Good Bye ~" << endl;
    return 0;
}