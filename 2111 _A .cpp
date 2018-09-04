/*
1111 Online Map（30 分）
Input our current position and a destination, an online map can recommend several paths. Now your job is to recommend two
paths to your user: one is the shortest, and the other is the fastest. It is guaranteed that a path exists for any request
.

Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers N (2≤N≤500), and M, 
being the total number of streets intersections on a map, and the number of streets, respectively. Then M lines follow, 
each describes a street in the format:

V1 V2 one-way length time
where V1 and V2 are the indices (from 0 to N−1) of the two ends of the street; one-way is 1 if the street is one-way from
V1 to V2, or 0 if not; length is the length of the street; and time is the time taken to pass the street.

Finally a pair of source and destination is given.

Output Specification:
For each case, first print the shortest path from the source to the destination with distance D in the format:

Distance = D: source -> v1 -> ... -> destination
Then in the next line print the fastest path with total time T:

Time = T: source -> w1 -> ... -> destination
In case the shortest path is not unique, output the fastest one among the shortest paths, which is guaranteed to be unique
. In case the fastest path is not unique, output the one that passes through the fewest intersections, which is guaranteed
to be unique.

In case the shortest and the fastest paths are identical, print them in one line in the format:

Distance = D; Time = T: source -> u1 -> ... -> destination
Sample Input 1:
10 15
0 1 0 1 1
8 0 0 1 1
4 8 1 1 1
3 4 0 3 2
3 9 1 4 1
0 6 0 1 1
7 5 1 2 1
8 5 1 2 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 1
1 4 0 1 1
9 7 1 3 1
5 1 0 5 2
6 5 1 1 2
3 5
Sample Output 1:
Distance = 6: 3 -> 4 -> 8 -> 5
Time = 3: 3 -> 1 -> 5
Sample Input 2:
7 9
0 4 1 1 1
1 6 1 1 3
2 6 1 1 1
2 5 1 2 2
3 0 0 1 1
3 1 1 1 3
3 2 1 1 2
4 5 0 2 2
6 5 1 1 2
3 5
Sample Output 2:
Distance = 3; Time = 4: 3 -> 2 -> 5
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define MAXN 520
#define INF 999999999
using namespace std;

int Graph[MAXN][MAXN] = {0}; //权值路程
int Graph_1[MAXN][MAXN] = {0};  //权值时间

int main()
{
    int N,M; //城市，边
    cin>>N>>M;
    int v1,v2,one_way,length,time;
    int i,j;
    for(i=0 ; i<M ; i++) //建图
    {
        cin>>v1>>v2>>one_way>>length>>time;
        Graph[v1][v2] = length;
        Graph_1[v1][v2] = time;
        if(!one_way)
        {
            Graph[v2][v1] = length;
            Graph_1[v2][v1] = time;
        }
    }
    int Book[N] = {0}; //用于判断结点是否已经访问过，防止出现重复访问
    int Parent[N]; //记录每个结点的上个结点位置，用于回溯路径
    int st,ed;
    cin>>st>>ed;
    int Dist[N]; //记录从起点开始到该位置的最短路径
    int Tist[N]; //记录从起点开始到该位置的时间，当路程相同时，取最短时间
    fill(Dist,Dist+N,INF);  //初始化
    fill(Parent,Parent+N,-1);//初始化
    fill(Tist,Tist+N,INF);//初始化
    Dist[st] = 0;//初始化
    Tist[st] = 0;//初始化
    for(i=0 ; i<N ; i++)
    {
        if(Graph[st][i])
        {
            Dist[i] = Dist[st] + Graph[st][i];
            Tist[i] = Tist[st] + Graph_1[st][i];
            Parent[i] = st;
        }
    }
    for(i=1 ; i<N ; i++) //迪杰斯特拉算法
    {
        int minindex = -1,minweight = INF;
        for(j=0 ; j<N ; j++)
        {
            if(!Book[j] && Dist[j] < minweight)
            {
                minindex = j;
                minweight = Dist[j];
            }
        }
        if(minindex == -1)
            break;
        Book[minindex] = 1;
        for(j=0 ; j<N ; j++)
        {
            if(!Book[j] && Graph[minindex][j] && Dist[j] > Dist[minindex] + Graph[minindex][j])
            {
                Dist[j] = Dist[minindex] + Graph[minindex][j];
                Tist[j] = Tist[minindex] + Graph_1[minindex][j];
                Parent[j] = minindex;
            }
            else if(!Book[j] && Graph[minindex][j] && Dist[j] == Dist[minindex] + Graph[minindex][j])
            {
                if(Tist[j] >Tist[minindex] + Graph_1[minindex][j])
                {
                    Tist[j]  = Tist[minindex] + Graph_1[minindex][j];
                    Parent[j] = minindex;
                }
            }
        }
    }
    vector<int>Res; //记录最短距离的结果
    int z = ed , D = Dist[ed];
    while(z!=-1)
    {
        Res.push_back(z);
        z = Parent[z];
    }
    reverse(Res.begin(),Res.end());
    int view[N]; //记录当该位置时经过的结点数
    fill(view,view+N,1);
    fill(Parent,Parent+N,-1);
    fill(Tist,Tist+N,INF);
    fill(Book,Book+N,0);
    Tist[st] = 0;
    for(i=0 ; i<N ; i++)
    {
        if(Graph_1[st][i])
        {
            Tist[i] = Tist[st] + Graph_1[st][i];
            Parent[i] = st;
        }
    }
    for(i=1 ; i<N ; i++)
    {
        int minindex = -1,minweight = INF;
        for(j=0 ; j<N ; j++)
        {
            if(!Book[j] && Tist[j] < minweight)
            {
                minindex = j;
                minweight = Tist[j];
            }
        }
        if(minindex == -1)
            break;
        Book[minindex] = 1;
        for(j=0 ; j<N ; j++)
        {
            if(!Book[j] && Graph_1[minindex][j] && Tist[j] > Tist[minindex] + Graph_1[minindex][j])
            {
                Tist[j] = Tist[minindex] + Graph_1[minindex][j];
                view[j] = view[minindex] + 1;
                Parent[j] = minindex;
            }
            else if(!Book[j] && Graph_1[minindex][j] && Tist[j] == Tist[minindex] + Graph_1[minindex][j])
            {
                if(view[j] > view[minindex] + 1)
                {
                    view[j] = view[minindex] + 1;
                    Parent[j] = minindex;
                }
            }
        }
    }
    vector<int>res; //记录最少时间的结果
    int t = ed , T = Tist[ed];
    while(t!=-1)
    {
        res.push_back(t);
        t = Parent[t];
    }
    reverse(res.begin(),res.end());
    if(res==Res)
    {
        printf("Distance = %d; Time = %d: %d",D,T,res[0]);
        for(i=1 ; i<res.size() ; i++)
        {
            printf(" -> %d",res[i]);
        }
        cout<<"\n";
    }
    else
    {
        printf("Distance = %d: %d",D,Res[0]);
        for(i=1 ; i<Res.size() ; i++)
        {
            printf(" -> %d",Res[i]);
        }
        cout<<"\n";
        printf("Time = %d: %d",T,res[0]);
        for(i=1 ; i<res.size() ; i++)
        {
            printf(" -> %d",res[i]);
        }
        cout<<"\n";
    }
    return 0;
}


//他山之玉
//柳婼
/*
分析：
1.用两个Dijkstra。一个求最短路径（如果相同求时间最短的那条），一个求最快路径（如果相同求结点数最小的那条）~~~
2.求最短路径,和最快路径都可以在Dijkstra里面求前驱结点dispre和，Timepre数组~~
3.dispre数组更新的条件是路径更短，或者路径相等的同时时间更短。
4.求最快路径时候要多维护一个NodeNum数组，记录在时间最短的情况下，到达此节点所需的节点数量。
Time数组更新的条件是，时间更短，时间相同的时候，如果此节点能让到达次节点是数目也变小，则更新Timepre，heNodeNum数组
5.最后根据dispre 和Timepre数组递归出两条路径，比较判断，输出最终答案～
注意：如果直接使用DFS的话，会导致最后一个测试用例“运行超时”~~~
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 999999999;
int dis[510], Time[510], e[510][510], w[510][510], dispre[510],Timepre[510], weight[510],NodeNum[510];
bool visit[510];
vector<int> dispath, Timepath, temppath;
int st, fin, minnode = inf;
void dfsdispath(int v) {
    dispath.push_back(v);
    if(v == st) return ;
    dfsdispath(dispre[v]);
}
void dfsTimepath(int v) {
    Timepath.push_back(v);
    if(v == st) return ;
    dfsTimepath(Timepre[v]);
}
int main() {
    fill(dis, dis + 510, inf);
    fill(Time, Time + 510, inf);
    fill(weight, weight + 510, inf);
    fill(e[0], e[0] + 510 * 510, inf);
    fill(w[0], w[0] + 510 * 510, inf);
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b, flag, len, t;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d %d %d", &a, &b, &flag, &len, &t);
        e[a][b] = len;
        w[a][b] = t;
        if(flag != 1) {
            e[b][a] = len;
            w[b][a] = t;
        }
    }
    scanf("%d %d", &st, &fin);
    dis[st] = 0;
    for(int i = 0; i < n; i++)
        dispre[i] = i;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                if(e[u][v] + dis[u] < dis[v]) {
                    dis[v] = e[u][v] + dis[u];
                    dispre[v] = u;
                    weight[v] = weight[u] + w[u][v];
                } else if(e[u][v] + dis[u] == dis[v] && weight[v] > weight[u] + w[u][v]) {
                    weight[v] = weight[u] + w[u][v];
                    dispre[v] = u;
                }
            }
        }
    }
    dfsdispath(fin);
    Time[st] = 0;
    fill(visit, visit + 510, false);
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && minn > Time[j]) {
                u = j;
                minn = Time[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && w[u][v] != inf) {
                if(w[u][v] + Time[u] < Time[v]) {
                    Time[v] = w[u][v] + Time[u];
                    Timepre[v]=(u);
                    NodeNum[v]=NodeNum[u]+1;
                } else if(w[u][v] + Time[u] == Time[v]&&NodeNum[u]+1<NodeNum[v]) {
                    Timepre[v]=(u);
                    NodeNum[v]=NodeNum[u]+1;
                }
            }
        }
    }
    dfsTimepath(fin);
    printf("Distance = %d", dis[fin]);
    if(dispath == Timepath) {
        printf("; Time = %d: ", Time[fin]);
    } else {
        printf(": ");
        for(int i = dispath.size() - 1; i >= 0; i--) {
            printf("%d", dispath[i]);
            if(i != 0) printf(" -> ");
        }
        printf("\nTime = %d: ", Time[fin]);
    }
    for(int i = Timepath.size() - 1; i >= 0; i--) {
        printf("%d", Timepath[i]);
        if(i != 0) printf(" -> ");
    }
    return 0;
}
