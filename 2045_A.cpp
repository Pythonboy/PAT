/*
1045 Favorite Color Stripe（30 分）
Eva is trying to make her own color stripe out of a given one. She would like to keep only her favorite colors in her favorite order by cutting off those unwanted pieces and sewing the remaining parts together to form her favorite color stripe.

It is said that a normal human eye can distinguish about less than 200 different colors, so Eva's favorite colors are limited. However the original stripe could be very long, and Eva would like to have the remaining favorite stripe with the maximum length. So she needs your help to find her the best result.

Note that the solution might not be unique, but you only have to tell her the maximum length. For example, given a stripe of colors {2 2 4 1 5 5 6 3 1 1 5 6}. If Eva's favorite colors are given in her favorite order as {2 3 1 5 6}, then she has 4 possible best solutions {2 2 1 1 1 5 6}, {2 2 1 5 5 5 6}, {2 2 1 5 5 6 6}, and {2 2 3 1 1 5 6}.

Sample Input:
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6
Sample Output:
7
*/
//尝试了一下回溯法，运行超时
#include <iostream>
#include <vector>
using namespace std;

vector<int>Favorate;
vector<int>color;
vector<int>path,temppath;
void DFS(int i,int N)
{
    if(i > N)
    {
        if(temppath.size() > path.size())
            path = temppath;
        return ;
    }
    if(temppath.size()+(N-i+1)<=temppath.size())
        return ;
    int j;
    for(j=0 ; j<=1 ; j++)
    {
        if(j==0)
        {
            int flag = 0;
            if(temppath.size()==0)
                flag =1;
            else
            {
                int len = temppath.size()-1;
                int k = temppath[len];
                if(Favorate[color[i]] >= Favorate[k])
                {
                    flag = 1;
                }
            }
            if(flag == 1)
            {
                temppath.push_back(color[i]);
                DFS(i+1,N);
                temppath.pop_back();
            }
        }
        else
            DFS(i+1,N);
    }

}

int main()
{
    int N,M,K;
    cin>>N;
    Favorate.resize(N+1,0);
    int i,temp;
    cin>>M;
    for(i=1 ; i<=M ; i++)
    {
        cin>>temp;
        Favorate[temp] = i;
    }
    cin>>K;
    for(i=1 ; i<=K ; i++)
    {
        cin>>temp;
        if(Favorate[temp] != 0)
            color.push_back(temp);
    }
    K = color.size();
    DFS(0,K);
    cout<<path.size();
    return 0;
}



#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
vector<int>Weight;
int main()
{
    int N,K,M,i,j,temp,root,ed;
    scanf("%d",&N);

    cin>>K;
    vector<int>Favorate(N+1,0); //最喜欢的颜色顺序
    for(i=0 ; i<K ; i++)
    {
        scanf("%d",&temp);
        Favorate[temp] = i+1;
    }
    cin>>M;
    vector<int>Origin; //已有颜色顺序
    for(i=0 ; i<M ; i++)
    {
        cin>>temp;
        if(Favorate[temp]!=0)
            Origin.push_back(temp);
    }
    M = Origin.size();
    Weight.resize(M,1);
    int Max = 1;
    for(i=0 ; i<M ; i++)
    {
        for(j=i+1 ; j<M ; j++)
        {
            if(Favorate[Origin[j]] >= Favorate[Origin[i]])
            {
                Weight[j] = max(Weight[j],Weight[i]+1);
            }
        }
        Max = max(Weight[i],Max);
    }
    cout<<Max;
    return 0;
}



#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N,K,M,i,j,temp;
    cin>>N;
    vector<int>Favorate(N+1,0);
    cin>>M;
    for(i=0 ; i<M ; i++)
    {
        cin>>temp;
        Favorate[temp]=i+1;
    }
    cin>>K;
    vector<int>Color;
    for(i=0 ; i<K ; i++)
    {
        cin>>temp;
        if(Favorate[temp]!=0)
            Color.push_back(temp);
    }
    int Max = 0,num = Color.size();
    vector<int>Weight(num,1);
    for(i=0 ; i<num ; i++)
    {
        for(j=0 ; j<i ; j++)
        {
            if(Favorate[Color[j]]<=Favorate[Color[i]])
            {
                Weight[i] = max(Weight[i],Weight[j]+1);
            }
        }
        Max = max(Max,Weight[i]);
    }
    cout<<Max;
    return 0;
}

//他山之玉
//柳婼
/*
题目大意：给出m中颜色作为喜欢的颜色（同时也给出顺序），然后给出一串长度为L的颜色序列，现在要去掉这个序列中的不喜欢的颜色，然后求剩下序列的一个子序列，使得这个子序列表示的颜色顺序符合自己喜欢的颜色的顺序，不一定要所有喜欢的颜色都出现。
分析：因为喜欢的颜色是不重复的，把喜欢的颜色的序列依次存储到数组中，book[i] = j表示i颜色的下标为j。先在输入的时候剔除不在喜欢的序列中的元素，然后把剩余的保存在数组a中。按照最长不下降子序列的方式做，对于从前到后的每一个i，如果它前面的所有的j，一下子找到了一个j的下标book[j]比book[i]小，此时就更新dp[i]使它 = max(dp[i], dp[j] + 1)；并且同时再每一次遍历完成一次j后更新maxn的值为长度的最大值，最后输出maxn~~~~
/*

#include <iostream>
#include <vector>
using namespace std;
int book[201], a[10001], dp[10001];
int main() {
    int n, m, x, l, num = 0, maxn = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &x);
        book[x] = i;
    }
    scanf("%d", &l);
    for(int i = 0; i < l; i++) {
        scanf("%d", &x);
        if(book[x] >= 1)
            a[num++] = book[x];
    }
    for(int i = 0; i < num; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
            if(a[i] >= a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        maxn = max(dp[i], maxn);
    }
    printf("%d", maxn);
    return 0;
}
