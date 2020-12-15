/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-12-15 10:05:01
 * @Description: 成绩管理系统的头文件
 * @Website: https://grimoire.cn
 * @Copyright (c) Mr.Sen All rights reserved.
 */

#include <bits/stdc++.h>
using namespace std;
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
    // * 构造函数
    System()
    {
        Head = new student;
        Head->next = NULL;
    }
    // *析构函数
    ~System()
    {
        LinkNode p = this->Head, q = p;
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
            delete q;
        }
        delete p;
    }

    // * 遍历链表
    void forEach(int config)
    {
        cout << "==========================" << endl;
        LinkNode p = this->Head;
        while (p->next != NULL)
        {
            p = p->next;
            if (config == 1)
            {
                cout << "学号：" << p->num << endl;
                cout << "名字：" << p->name << endl;
                cout << "C语言成绩：" << p->cscore << endl;
                cout << "英语成绩：" << p->englishscore << endl;
                cout << "FOX成绩：" << p->foxscore << endl;
            }
            if (config == 0)
            {
                cout << "名字：" << p->name << endl;
                cout << "总分：" << sum(p) << endl;
            }
            cout << "==========================" << endl;
        }
        // cout << endl;
    }

    // * 计算当前节点总成绩
    int sum(LinkNode s)
    {
        if (s == NULL)
            return 0;
        return s->cscore + s->englishscore + s->foxscore;
    }

    // * 录入学生信息，同时进行逆序排序
    // * 保证当前一定是逆序的，避免额外的排序操作
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
        // forEach();
    }

    // * 查询单个学生信息
    void info()
    {
        int number;
        cout << "请输入想要查询的学号：";
        cin >> number;

        LinkNode p = this->Head;
        while (p->next != NULL)
        {
            p = p->next;
            if (p->num == number)
            {
                cout << "学号：" << p->num << endl;
                cout << "名字：" << p->name << endl;
                cout << "C语言成绩：" << p->cscore << endl;
                cout << "英语成绩：" << p->englishscore << endl;
                cout << "FOX成绩：" << p->foxscore << endl;
                break;
            }
        }
        // cout << endl;
    }

    // * 用于输出欢迎信息
    void Welcome(string filename)
    {
        ifstream in(filename);
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
            cout << "File: Welcome NOT FOUND!!!" << endl;
        }
        return;
    }
};