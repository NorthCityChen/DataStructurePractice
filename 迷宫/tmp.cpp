/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-12-18 09:13:43
 * @Description: 
 * @Website: https://grimoire.cn
 * @Copyright (c) Mr.Sen All rights reserved.
 */
#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
} node;

int main()
{
    node a[13];
    int i;
    int x;
    int key;
    node *p, *q, *s;
    for (i = 0; i < 13; i++)
    {
        a[i].data = i;
        a[i].next = NULL;
    }
    cin >> x;
    while (x != 0)
    {
        key = x % 13;
        s = new node;
        s->data = x;
        s->next = a[key].next;
        a[key].next = s;

        cin >> x;
    }
    for (i = 0; i < 13; i++)
    {
        cout << a[i].data << ':';
        p = a[i].next;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}
