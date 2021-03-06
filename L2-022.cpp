/*
给定一个单链表 L
​1
​​ →L
​2
​​ →⋯→L
​n−1
​​ →L
​n
​​ ，请编写程序将链表重新排列为 L
​n
​​ →L
​1
​​ →L
​n−1
​​ →L
​2
​​ →⋯。例如：给定L为1→2→3→4→5→6，则输出应该为6→1→5→2→4→3。

输入格式：
每个输入包含1个测试用例。每个测试用例第1行给出第1个结点的地址和结点总个数，即正整数N (≤10
​5
​​ )。结点的地址是5位非负整数，NULL地址用−1表示。

接下来有N行，每行格式为：

Address Data Next
其中Address是结点地址；Data是该结点保存的数据，为不超过10
​5
​​ 的正整数；Next是下一结点的地址。题目保证给出的链表上至少有两个结点。

输出格式：
对每个测试用例，顺序输出重排后的结果链表，其上每个结点占一行，格式与输入相同。

输入样例：
00100 6
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
输出样例：
68237 6 00100
00100 1 99999
99999 5 12309
12309 2 00000
00000 4 33218
33218 3 -1
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

struct Node
{
    int address;
    int data;
    int next;
};

int main()
{
    vector<struct Node>LinkList(100000);
    int firstaddress,N;
    int tempaddresss,tempdata,tempnext;
    cin>>firstaddress>>N;
    int T=0;
    for(int i=0 ; i<N ; i++)
    {
        scanf("%d %d %d",&tempaddresss,&tempdata,&tempnext);
        LinkList[tempaddresss].address = tempaddresss;
        LinkList[tempaddresss].data = tempdata;
        LinkList[tempaddresss].next = tempnext;
    }
    vector<struct Node>Res_1;
    for(int i = firstaddress ; i!=-1 ; i = LinkList[i].next)
    {
        Res_1.push_back(LinkList[i]);
        T++;
    }
    vector<struct Node>Res_2 = Res_1;
    reverse(Res_2.begin(),Res_2.end());
    vector<struct Node>Res;
    int m = 0, n = 0;
    while(Res.size() < T)
    {
        Res.push_back(Res_2[m]);
        Res.push_back(Res_1[n]);
        m++,n++;
    }
    for(int i=0 ; i<T ; i++)
    {
        if(i!=T-1)
            printf("%05d %d %05d\n",Res[i].address,Res[i].data,Res[i+1].address);
        else
            printf("%05d %d -1\n",Res[i].address,Res[i].data);
    }
    return 0;

}
