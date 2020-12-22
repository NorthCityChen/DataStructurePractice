#include <bits/stdc++.h>
using namespace std;
typedef char ElemType;
typedef struct BiTree
{
    ElemType data;
    struct BiTree *lchild, *rchild;
} BiNode, *Bitree;
void preorder(Bitree T)
{
    if (T)
    {
        cout << T->data;
        preorder(T->lchild);
        preorder(T->rchild);
    }
}
void inorder(Bitree T)
{
    if (T)
    {
        inorder(T->lchild);
        cout << T->data;
        inorder(T->rchild);
    }
}
void postorder(Bitree T)
{
    if (T)
    {
        postorder(T->lchild);
        postorder(T->rchild);
        cout << T->data;
    }
}
Bitree level_create(ElemType level[], ElemType in[], int left1, int right1, int left2, int right2)
{
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
void menu()
{
    cout << "1.Creating a binary tree by pre order and middle order" << endl;
    cout << "2.Creating a binary tree by level order and middle order" << endl;
}
void pre()
{
    cout << "please input preorder and inorder:" << endl;
    ElemType in[100], t[100];
    cin >> t >> in;
    Bitree T;
    int now = 0;
    pre_create(T, t, in, 0, strlen(t) - 1, strlen(t), now);
    if (T)
    {
        cout << "successfully create!" << endl;
        cout << "The tree's preorder is : ";
        preorder(T);
        cout << endl;
        cout << "The tree's inorder is : ";
        inorder(T);
        cout << endl;
        cout << "The tree's postorder is : ";
        postorder(T);
        cout << endl;
    }
    else
    {
        cout << "Creation failed!" << endl;
        return;
    }
}
void level()
{
    cout << "please input levelorder and inorder:" << endl;
    ElemType in[100], t[100];
    cin >> t >> in;
    Bitree T;
    T = level_create(t, in, 0, strlen(t) - 1, 0, strlen(in) - 1);
    if (T)
    {
        cout << "successfully create!" << endl;
        cout << "The tree's preorder is : ";
        preorder(T);
        cout << endl;
        cout << "The tree's inorder is : ";
        inorder(T);
        cout << endl;
        cout << "The tree's postorder is : ";
        postorder(T);
        cout << endl;
    }
    else
    {
        cout << "Creation failed!" << endl;
        return;
    }
}
int main()
{
    cout << endl;
    cout << "\t\t\tWelcome to use the create binary tree algorithm!" << endl;
    cout << "\t\t\t";
    system("PAUSE");
    while (1)
    {
        system("cls");
        menu();
        int x, flag = 0;
        cout << "please input 1 or 2 to use the corresponding function or 0 exit:";
        cin >> x;
        switch (x)
        {
        case 1:
            pre();
            system("PAUSE");
            break;
        case 2:
            level();
            system("PAUSE");
            break;
        case 0:
            flag = 1;
            break;
        default:
            cout << "Illegal input!!!" << endl;
            break;
        }
        if (flag == 1)
        {
            cout << "Thanks to use the create binary tree algorithm!" << endl;
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