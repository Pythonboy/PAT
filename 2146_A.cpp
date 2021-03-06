/*
1146 Topological Order（25 分）
This is a problem given in the Graduate Entrance Exam in 2018: Which of the following is NOT a topological order obtained from the given directed graph? Now you are supposed to write a program to test each of the options.
Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers N (≤ 1,000), the number of vertices in the graph, and M (≤ 10,000), the number of directed edges. Then M lines follow, each gives the start and the end vertices of an edge. The vertices are numbered from 1 to N. After the graph, there is another positive integer K (≤ 100). Then K lines of query follow, each gives a permutation of all the vertices. All the numbers in a line are separated by a space.

Output Specification:
Print in a line all the indices of queries which correspond to "NOT a topological order". The indices start from zero. All the numbers are separated by a space, and there must no extra space at the beginning or the end of the line. It is graranteed that there is at least one answer.

Sample Input:
6 8
1 2
1 3
5 2
5 4
2 3
2 6
3 4
6 4
5
1 5 2 3 6 4
5 1 2 6 3 4
5 1 2 3 6 4
5 2 1 6 3 4
1 2 3 4 5 6
Sample Output:
3 4
*/

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
    int vertexnum,edgenum;//分别代表定点数量和边的数量
    scanf("%d %d",&vertexnum,&edgenum);
    int InDegree[vertexnum+1];//代表每个定点的入度
    memset(InDegree,0,sizeof(InDegree));
    int Edge[vertexnum+1][vertexnum+1];
    memset(Edge,0,sizeof(Edge));
    int i,j,k,temp;
    for(i=0 ; i<edgenum ; i++)
    {
        scanf("%d %d",&j,&k);
        Edge[j][k] = 1;
        InDegree[k]++;
    }
    int K;//需要判断的排序数量
    scanf("%d",&K);
    vector<int>Not_Topo;
    for(i=0 ; i<K ; i++)
    {
        queue<int>Sorting; //存放输入的排序数字
        int BZ[vertexnum+1];
        memcpy(BZ,InDegree,sizeof(InDegree));  //将数组InDegree全部复制给BZ数组，头文件cstring
        for(j=0 ; j<vertexnum ; j++)
        {
            scanf("%d",&temp);
            Sorting.push(temp);
        }
        int flag = 0;
        while(!Sorting.empty())
        {
            temp = Sorting.front();
            Sorting.pop();
            if(BZ[temp] == 0)
            {
                for(j = 1; j<=vertexnum ; j++)
                {
                    if(Edge[temp][j]==1)
                    {
                        BZ[j]--;
                    }
                }
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            Not_Topo.push_back(i);
    }
    int len = Not_Topo.size();
    for(i=0 ; i<len ; i++)
    {
        if(i==0)
            cout<<Not_Topo[i];
        else
            cout<<" "<<Not_Topo[i];
    }
    return 0;
}







//他山之玉
//柳婼
/*
题目大意：给一个有向图，判断给定序列是否是拓扑序列～
分析：用邻接表v存储这个有向图，并将每个节点的入度保存在in数组中。对每一个要判断是否是拓扑序列的结点遍历，如果当前结点的入度不为0则表示不是拓扑序列，每
次选中某个点后要将它所指向的所有结点的入度-1，最后根据是否出现过入度不为0的点决定是否要输出当前的编号i～flag是用来判断之前是否输出过现在是否要输出
空格的～judge是用来判断是否是拓扑序列的～
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, a, b, k, flag = 0, in[1010];
    vector<int> v[1010];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        in[b]++;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int judge = 1;
        vector<int> tin(in, in+n+1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &a);
            if (tin[a] != 0) judge = 0;
            for (int it : v[a]) tin[it]--;
        }
        if (judge == 1) continue;
        printf("%s%d", flag == 1 ? " ": "", i);
        flag = 1;
    }
    return 0;
}
