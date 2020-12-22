/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-12-22 10:01:29
 * @Description: 
 * @Website: https://grimoire.cn
 * @Copyright (c) Mr.Sen All rights reserved.
 */

#include <bits/stdc++.h>
using namespace std;

// * 通过用户给出的关键字查找
typedef long long ll;
template <typename keyElem, typename dtElem>
class hashMap
{
private:
    typedef struct
    {
        int mod;
        int base;
        int n;
        int size;
    } info;

    typedef struct
    {
        keyElem key;
        dtElem data;
        int next;
    } FLNode;

    info hashMapBasic;
    FLNode *hashKey, *hashStg;
    fstream fpInfo, fpKey, fpStg;

    // * 初始化hash表
    void hashInit(int par)
    {
        if (par == 1)
        {
            fpInfo.open("hashInfo.bin", ios::in | ios::binary);
            fpKey.open("hashKey.bin", ios::in);
            fpStg.open("hashStg.data", ios::in);

            fpInfo.read((char *)&hashMapBasic, sizeof(info));
            hashKey = (FLNode *)calloc(hashMapBasic.mod, sizeof(FLNode));
            for (int i = 0; i < hashMapBasic.mod; i++)
            {
                hashKey[i].next = -1; //置空
            }
            for (int i = 0; i < hashMapBasic.mod; i++)
            {
                fpKey >> hashKey[i].next;
            }
            hashStg = (FLNode *)calloc(hashMapBasic.size + 10, sizeof(FLNode));
            for (int i = 0; i < hashMapBasic.size; i++)
            {
                hashStg[i].next = -1; //置空
            }
            for (int i = 0; i < hashMapBasic.n; i++)
            {
                keyElem tmpa;
                dtElem tmpb;
                int c;
                fpStg >> tmpa >> tmpb >> c;
                hashStg[i].key = tmpa;
                hashStg[i].data = tmpb;
                hashStg[i].next = c;
            }
        }
        else
        {
            hashMapBasic.mod = 2729;
            hashMapBasic.base = 131; //实际个数
            hashMapBasic.n = 0;      //实际个数
            hashMapBasic.size = 1;   //数组大小
            hashKey = (FLNode *)calloc(hashMapBasic.mod, sizeof(FLNode));
            for (int i = 0; i < hashMapBasic.mod; i++)
            {
                hashKey[i].next = -1; //置空
            }
            hashStg = (FLNode *)calloc(hashMapBasic.size, sizeof(FLNode));
            for (int i = 0; i < hashMapBasic.size; i++)
            {
                hashStg[i].next = -1; //置空
            }
        }
    }
    //* 手写了三个hash函数
    int hashFunc(int key)
    {
        int ret = 0;
        while (key)
        {
            // * 偏移取模
            ret = (ret * hashMapBasic.base + key % 10) % hashMapBasic.mod;
            key /= 10;
        }
        return ret % hashMapBasic.mod;
    }
    int hashFunc(string key)
    {
        int ret = 0;
        int len = key.length();
        for (int i = 0; i < len; i++)
        {
            ret = (ret * hashMapBasic.base + key[i]) % hashMapBasic.mod;
        }
        return ret % hashMapBasic.mod;
    }
    int hashFunc(char *key)
    {
        //ret key_hashed
        int ret = 0;
        int len = strlen(key);
        for (int i = 0; i < len; i++)
        {
            ret = (ret * hashMapBasic.base + key[i]) % hashMapBasic.mod;
        }
        return ret % hashMapBasic.mod;
    }

    bool makeHash(keyElem key, dtElem data)
    {
        int ter = hashKey[hashFunc(key)].next;
        while (ter != -1)
        {
            if (hashStg[ter].key == key)
            {
                hashStg[ter].data = data;
                return true;
            }
            ter = hashStg[ter].next;
        }
        return false;
    }

    void hashInsert(keyElem key, dtElem data)
    {
        if (makeHash(key, data))
        {
            cout << "Already existed!(Auto modified)"
                 << "\n";
            return;
        }
        if (hashKey[hashFunc(key)].next == -1) //无后
        {
            hashKey[hashFunc(key)].next = hashMapBasic.n;
            if (hashMapBasic.n >= hashMapBasic.size) //扩容
            {
                hashMapBasic.size *= 2;
                FLNode *hash_stg_new = (FLNode *)calloc(hashMapBasic.size, sizeof(FLNode));
                for (int i = 0; i < hashMapBasic.size / 2; i++)
                {
                    *(hash_stg_new + i) = *(hashStg + i);
                }
                for (int i = hashMapBasic.size / 2; i < hashMapBasic.size; i++)
                {
                    hash_stg_new[i].next = -1; //置空
                }
                free(hashStg);
                hashStg = hash_stg_new;
            }
            hashStg[hashMapBasic.n].key = key;
            hashStg[hashMapBasic.n].data = data;
            hashMapBasic.n++;
        }
        else
        {
            int ter = hashKey[hashFunc(key)].next;
            while (hashStg[ter].next != -1)
            {
                ter = hashStg[ter].next;
            }
            hashStg[ter].next = hashMapBasic.n;
            if (hashMapBasic.n >= hashMapBasic.size) //扩容
            {
                hashMapBasic.size *= 2;
                FLNode *hash_stg_new = (FLNode *)calloc(hashMapBasic.size, sizeof(FLNode));
                for (int i = 0; i < hashMapBasic.size / 2; i++)
                {
                    *(hash_stg_new + i) = *(hashStg + i);
                }
                for (int i = hashMapBasic.size / 2; i < hashMapBasic.size; i++)
                {
                    hash_stg_new[i].next = -1; //置空
                }
                free(hashStg);
                hashStg = hash_stg_new;
            }
            hashStg[hashMapBasic.n].key = key;
            hashStg[hashMapBasic.n].data = data;
            hashMapBasic.n++;
        }
    }

    dtElem hashSearch(keyElem key)
    {
        int ter = hashKey[hashFunc(key)].next;
        while (ter != -1)
        {
            if (hashStg[ter].key == key)
            {
                return hashStg[ter].data;
            }
            ter = hashStg[ter].next;
        }
        dtElem fault;
        cout << "Value Not Found !!!";
        return fault;
    }

    void hashErase(keyElem key)
    {
        int ter = hashKey[hashFunc(key)].next;
        if (ter == -1)
        {
            return;
        }
        else
        {
            if (hashStg[ter].key == key) //第一个就是
            {
                hashKey[hashFunc(key)].next = hashStg[ter].next;
            }
            else
            {
                while (hashStg[ter].next != -1 && hashStg[hashStg[ter].next].key != key)
                {
                    ter = hashStg[ter].next;
                }
                if (hashStg[ter].next != -1 && hashStg[hashStg[ter].next].key == key)
                {
                    hashStg[ter].next = hashStg[hashStg[ter].next].next;
                }
            }
        }
        // hashMapBasic.n--;
    }

public:
    hashMap()
    {

        hashInit(0);
    }
    ~hashMap()
    {
        //清空缓冲区
        fpInfo.close();
        fpKey.close();
        fpStg.close();

        fpInfo.open("hashInfo.bin", ios::out | ios::binary);
        fpInfo.write((char *)&hashMapBasic, sizeof(info));
        fpKey.open("hashKey.bin", ios::out);
        fpStg.open("hashStg.data", ios::out);
        for (int i = 0; i < hashMapBasic.mod; i++)
        {
            fpKey << hashKey[i].next << "\n";
        }
        free(hashKey);

        for (int i = 0; i < hashMapBasic.n; i++)
        {
            fpStg << hashStg[i].key << " " << hashStg[i].data << " " << hashStg[i].next << "\n";
        }
        free(hashStg);
        fpInfo.close();
        fpKey.close();
        fpStg.close();
    }

    void insert(keyElem key, dtElem data)
    {
        hashInsert(key, data);
    }

    dtElem find(keyElem key)
    {
        return hashSearch(key);
    }

    void erase(keyElem key)
    {
        hashErase(key);
    }
};
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
        cout << "[WARNING] File: Welcome NOT FOUND!!!" << endl;
    }
    return;
}