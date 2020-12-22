/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-12-22 10:04:46
 * @Description: 
 * @Website: https://grimoire.cn
 * @Copyright (c) Mr.Sen All rights reserved.
 */
#include <bits/stdc++.h>
using namespace std;

/*
* 我们默认输入的树是合法的
*/

typedef char ElemType;
typedef struct BiTree
{
    ElemType data;
    struct BiTree *lchild, *rchild;
} BiNode, *Bitree;

void preOrder(Bitree T)
{
    // * 先序遍历输出
    if (T)
    {
        cout << T->data;
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

void midOrder(Bitree T)
{
    // * 中序输出
    if (T)
    {
        midOrder(T->lchild);
        cout << T->data;
        midOrder(T->rchild);
    }
}

void beOrder(Bitree T)
{
    // * 后序输出
    if (T)
    {
        beOrder(T->lchild);
        beOrder(T->rchild);
        cout << T->data;
    }
}

Bitree level_create(ElemType level[], ElemType in[], int left1, int right1, int left2, int right2)
{
    // * 层次建树
    if (left2 > right2)
    {
        return NULL;
    }
    else
    {
        int i, j;
        int flag = 0;
        for (i = left1; i <= right1; i++)
        {
            for (j = left2; j <= right2; j++)
            {
                if (level[i] == in[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                break;
            }
        }
        Bitree T = new BiNode;
        T->data = level[i];
        T->lchild = level_create(level, in, left1 + 1, right1, left2, j - 1);
        T->rchild = level_create(level, in, left1 + 1, right1, j + 1, right2);
        return T;
    }
}
void pre_create(Bitree &T, ElemType pre[], ElemType in[], int left, int right, int len, int &now)
{
    // * 先序建树
    T = new BiNode;
    T->lchild = T->rchild = NULL;
    T->data = *(pre + now);
    int pos = (int)(strchr(in, *(pre + now)) - in);
    now++;
    if (now >= len)
        return;
    if (pos - 1 >= left)
    {
        pre_create(T->lchild, pre, in, left, pos - 1, len, now);
    }
    if (pos + 1 <= right)
    {
        pre_create(T->rchild, pre, in, pos + 1, right, len, now);
    }
}

void pre()
{
    cout << "[INFO] 请输入先序遍历以及后序遍历:" << endl;
    ElemType in[100], t[100];
    cin >> t >> in;
    Bitree T;
    int now = 0;
    pre_create(T, t, in, 0, strlen(t) - 1, strlen(t), now);
    if (T)
    {

        cout << "[INFO] 树建立成功" << endl;
        cout << "[INFO] 先序输出： ";
        preOrder(T);
        cout << endl;
        cout << "[INFO] 中序输出：";
        midOrder(T);
        cout << endl;
        cout << "[INFO] 后序输出：";
        beOrder(T);
        cout << endl;
    }
    else
    {
        cout << "[WARN] FAILED!!!" << endl;
        return;
    }
}
void level()
{
    cout << "[INFO] 请出入层次遍历和中序遍历：" << endl;
    ElemType in[100], t[100];
    cin >> t >> in;
    Bitree T;
    T = level_create(t, in, 0, strlen(t) - 1, 0, strlen(in) - 1);
    if (T)
    {
        cout << "[INFO] 树建立成功" << endl;

        cout << "[INFO] 先序输出：";
        preOrder(T);
        cout << endl;

        cout << "[INFO] 中序输出：";
        midOrder(T);
        cout << endl;

        cout << "[INFO] 后序输出：";
        beOrder(T);
        cout << endl;
    }
    else
    {
        cout << "[WARN] FAILED!!!" << endl;
        return;
    }
}
void welcome(string filename)
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
int main()
{
    welcome("welcome");
    while (1)
    {
        int x, flag = 0;

        cout << "\033[32m"
             << "admin@coolQuery: # "
             << "\033[0m";
        cin >> x;
        switch (x)
        {
        case 1:
            pre();
            break;
        case 2:
            level();
            break;
        case 0:
            flag = 1;
            break;
        default:
            cout << "[WARN] 非法输入!!!" << endl;
            break;
        }
        if (flag == 1)
        {
            cout << "Bye ~ " << endl;
            break;
        }
    }
    return 0;
}
/*
level: ABCDEFGR
in   : DBERAFCG
*/

/*
level : ABCDEF
in    : DFBAEC
*/

/*
pre : ABDECFG
in  : DBEAFCG
*/
/*
level : ABCDEFGHI
in    : DBEAHFICG
pre   : ABDECFHIG
post  : DEBHIFGCA
*/