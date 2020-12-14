/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-12-14 15:59:01
 * @Description: 成绩管理系统的头文件
 * @Website: https://grimoire.cn
 * @Copyright (c) Mr.Sen All rights reserved.
 */

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class System
{
private:
    typedef struct student
    {
        int num;          //学号
        char name[20];    //姓名
        int foxscore;     //fox成绩
        int cscore;       //C语言
        int englishscore; //英语成绩
        struct student *next;
    } student, *LinkNode;
    LinkNode Head;

public:
    System()
    {

        Head = new student;
        Head->next = NULL;
        // Head.
    }

    ~System()
    {
        LinkNode p = this->Head, q = p;
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
            // cout << sum(p) << " ";
            delete q;
        }
        delete p;
        // cout << "Class Destroyed" << endl;
    }

    void forEach()
    {
        LinkNode p = this->Head;
        while (p->next != NULL)
        {
            p = p->next;
            cout << sum(p) << " ";
        }
        cout << endl;
    }

    int sum(LinkNode s)
    {
        if (s == NULL)
            return 0;
        return s->cscore + s->englishscore + s->foxscore;
    }
    void add(int n)
    {
        while (n--)
        {
            LinkNode tmp = new student;
            cout << "学号：";
            cin >> tmp->num;
            cout << "姓名：";
            cin >> tmp->name;
            cout << "FOX成绩：";
            cin >> tmp->foxscore;
            cout << "C语言成绩：";
            cin >> tmp->cscore;
            cout << "英语成绩：";
            cin >> tmp->englishscore;
            tmp->next = NULL;

            int sum1 = tmp->cscore + tmp->englishscore + tmp->foxscore;
            LinkNode p = Head;

            while (p->next != NULL)
            {
                cout << "Worked" << endl;
                if (sum(p->next) <= sum1)
                {
                    tmp->next = p->next;
                    p->next = tmp;
                    cout << tmp->name << "录入成功" << endl;
                    break;
                }
                p = p->next;
            }
            if (p->next == NULL)
            {
                tmp->next = NULL;
                p->next = tmp;
                cout << tmp->name << "录入成功" << endl;
            }
        }
        forEach();
    }
    void info()
    {
        int number;
        cout << "请输入想要查询的学号：";
        cin >> number;

        LinkNode p = this->Head;
        while (p->next != NULL)
        {
            p = p->next;
            // cout << sum(p) << " ";
            if (p->num == number)
            {
                cout << p->num << endl;
                cout << p->name << endl;
                cout << p->cscore << endl;
                cout << p->englishscore << endl;
                cout << p->foxscore << endl;
                break;
            }
        }
        cout << endl;
    }
    void Welcome()
    {
        ifstream in("welcome");
        string line;

        if (in) // 有该文件
        {
            while (getline(in, line)) // line中不包括每行的换行符
            {
                cout << line << endl;
            }
        }
        else // 没有该文件
        {
            cout << "ERR" << endl;
        }
    }
};