/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-12-14 16:00:30
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
    freopen("input.in", "r", stdin);
    //freopen("output.out","w", stdout);
    string cmd;
    System<int> s;
    s.Welcome();
    while (cout << "admin@coolQuery: # ", cin >> cmd && cmd != "exit")
    {
        if (cmd == "1")
            s.add(4);
        if (cmd == "2")
            s.forEach();
        if (cmd == "3")
            s.forEach();
        if (cmd == "4")
            s.info();
        if (cmd == "help")
            cout << cmd << endl;
    }
    cout << "Bye" << endl;
    return 0;
}