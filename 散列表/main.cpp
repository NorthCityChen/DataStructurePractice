/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-12-22 09:59:04
 * @Description: 散列表
 * @Website: https://grimoire.cn
 * @Copyright (c) Mr.Sen All rights reserved.
 */

#include <bits/stdc++.h>
#include "hashMap.hpp"
using namespace std;

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    hashMap<string, string> hsMap;
    welcome("welcome");
    while (1)
    {
        // cout << "\nWhat operation do you want to take\n1.insert a key_value\n2.search a value by a key\n3.delete a value by a key\n4.exit\n";
        cout << "\033[32m" <<"admin@coolQuery: # " << "\033[0m";
        int opr;
        while (cin >> opr, opr <= 0 || opr >= 5);
        string ky; // * 键
        string vl; // * 值
        switch (opr)
        {
        case 1:
            // cout << "please enter a key and a value divided by a space" << endl;
            cout << "[INPUT] 请输入用空格分开的键值对:" << endl;
            cin >> ky >> vl;
            hsMap.insert(ky, vl);
            cout << "[INFO] 插入成功" << endl;
            break;
        case 2:
            cout << "[INPUT] 请输入查询的key" << endl;
            cin >> ky;
            cout << "[INFO] 查询到的值为: " << hsMap.find(ky) << endl;
            break;
        case 3:
            cout << "[INPUT] 请输入删除的key" << endl;
            cin >> ky;
            hsMap.erase(ky);
            cout << "[INFO] 删除成功" << endl;
            break;
        case 4:
            return 0;
            break;
        }
    }
    return 0;
}