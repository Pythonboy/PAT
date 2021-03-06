/*
1094 The Largest Generation (25)（25 分）提问
A family hierarchy is usually presented by a pedigree tree where all the nodes on the same level belong to the same generation. Your task is to find the generation with the largest population.

Input Specification:

Each input file contains one test case. Each case starts with two positive integers N (&lt100) which is the total number of family members in the tree (and hence assume that all the members are numbered from 01 to N), and M (&ltN) which is the number of family members who have children. Then M lines follow, each contains the information of a family member in the following format:

ID K ID[1] ID[2] ... ID[K]

where ID is a two-digit number representing a family member, K (&gt0) is the number of his/her children, followed by a sequence of two-digit ID's of his/her children. For the sake of simplicity, let us fix the root ID to be 01. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the largest population number and the level of the corresponding generation. It is assumed that such a generation is unique, and the root level is defined to be 1.

Sample Input:

23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18
Sample Output:

9 4
*/

#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;
struct parent
{
    vector<int>child;
    int cd = 0;
};

int main()
{
    int M,N;
    cin>>M>>N;
    vector<parent>Family(M+1);
    vector<int>Book(M+1,0);
    int i,j;
    int temp,mth,cld;
    for(i=0 ; i<N ; i++)
    {
        cin>>temp>>mth;
        for(j=0 ; j<mth ; j++)
        {
            cin>>cld;
            Book[cld] = 1;
            Family[temp].child.push_back(cld);
        }
        Family[temp].cd = 1;
    }
    int root;
    for(i=1 ; i<=M ; i++)
    {
        if(Book[i]==0)
        {
            root = i;
            break;
        }
    }
    queue<int>res;
    int cnt=0,Max = 0;
    int cg = 0;
    res.push(root);
    map<int,int>generation;
    while(!res.empty())
    {
        cnt = res.size();
        cg++;
        generation[cg] = cnt;
        int z;
        for(z=0 ; z<cnt ; z++)
        {
            int Node = res.front();
            res.pop();
            if(Family[Node].cd==1)
            {
                for(auto c : Family[Node].child)
                    res.push(c);
            }
        }
    }
    int Max_level = 0,Max_mouth = 0;
    auto k = generation.begin();
    for( ; k!=generation.end() ; k++)
    {
        if(k->second > Max_mouth)
        {
            Max_level = k->first;
            Max_mouth = k->second;
        }
    }
    cout<<Max_mouth<<" "<<Max_level<<"\n";
    return 0;

}

//DFS
//注：用图的方式来记录家族成员之间的关系更加巧妙，可以很好的取代结构体数组

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
vector<vector<int>>Graph;
map<int,int>Depth;
int maxdepth,maxpopulation = 0;
void DFS(int root,int depth)
{
    Depth[depth]++;
    if(Depth[depth] > maxpopulation)
    {
        maxpopulation = Depth[depth];
        maxdepth = depth;
    }
    int i,len = Graph[root].size();
    for(i=0 ; i<len ; i++)
        DFS(Graph[root][i],depth+1);
}
int main()
{
    int N,M,K,i,j,temp,father;
    cin>>N>>M;
    Graph.resize(N+1);
    for(i=0 ; i<M ; i++)
    {
        cin>>father>>K;
        for(j=0 ; j<K ; j++)
        {
            cin>>temp;
            Graph[father].push_back(temp);
        }
    }
    DFS(1,1);
    cout<<maxpopulation<<" "<<maxdepth<<"\n";
    return 0;
}


//他山之玉
//柳婼
/*
题目大意：输入树的结点个数N，结点编号为1~N，非叶子结点个数M，然后输出M个非叶子结点格子的孩子结点的编号，求结点个数最多的一层，根结点的层号为1，输出该层的结点个数以及层号<(▰˘◡˘▰)>
分析：用DFS或者BFS，用DFS就用参数index和level标记当前遍历的结点的编号和层数，一个数组book标记当前层数level所含结点数，最后遍历一遍数组找出最大值。注意 ：book[level]++;这句话是发生在return语句判断之前的外面，即每遇到一个结点都要进行处理，而不是放在return语句的条件判断里面~~~~~
如果是BFS，就用一个数组level[i]标记i结点所处的层数，它等于它的父亲结点的level的值+1，用一个数组book，book[i]标记i层所拥有的结点数，在遍历的时候每弹出一个结点就将当前结点的层数所对应的book值+1，最后遍历一遍book数组找出最大拥有的结点数和层数~~~
*/

//深度优先dfs方法：
#include <cstdio>
#include <vector>
using namespace std;
vector<int> v[100];
int book[100];
void dfs(int index, int level) {
    book[level]++;
    for(int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], level+1);
}
int main() {
    int n, m, a, k, c;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d",&a, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[a].push_back(c);
        }
    }
    dfs(1, 1);
    int maxnum = 0, maxlevel = 1;
    for(int i = 1; i < 100; i++) {
        if(book[i] > maxnum) {
            maxnum = book[i];
            maxlevel = i;
        }
    }
    printf("%d %d", maxnum, maxlevel);
    return 0;
}


//广度优先方法
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[100];
int level[100];
int book[100];
int main() {
    int n, m, a, k, c;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d",&a, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[a].push_back(c);
        }
    }
    queue<int> q;
    q.push(1);
    level[1] = 1;
    while(!q.empty()) {
        int index = q.front();
        q.pop();
        book[level[index]]++;
        for(int i = 0; i < v[index].size(); i++) {
            level[v[index][i]] = level[index] + 1;
            q.push(v[index][i]);
        }
        
    }
    int maxnum = 0, maxlevel = 1;
    for(int i = 1; i < 100; i++) {
        if(book[i] > maxnum) {
            maxnum = book[i];
            maxlevel = i;
        }
    }
    printf("%d %d", maxnum, maxlevel);
    return 0;
}
