/*
时间：2018/6/24 10点50分
作者：楼浩然
题目：
1053 住房空置率 (20)（20 分）
在不打扰居民的前提下，统计住房空置率的一种方法是根据每户用电量的连续变化规律进行判断。判断方法如下：

在观察期内，若存在超过一半的日子用电量低于某给定的阈值e，则该住房为“可能空置”；
若观察期超过某给定阈值D天，且满足上一个条件，则该住房为“空置”。
现给定某居民区的住户用电量数据，请你统计“可能空置”的比率和“空置”比率，即以上两种状态的住房占居民区住房总套数的百分比。

输入格式：

输入第一行给出正整数N（<=1000），为居民区住房总套数；正实数e，即低电量阈值；正整数D，即观察期阈值。随后N行，每行按以下格式给出一套住房的用电量数据：

K E~1~ E~2~ ... E~K~

其中K为观察的天数，E~i~为第i天的用电量。

输出格式：

在一行中输出“可能空置”的比率和“空置”比率的百分比值，其间以一个空格分隔，保留小数点后1位。

输入样例：

5 0.5 10
6 0.3 0.4 0.5 0.2 0.8 0.6
10 0.0 0.1 0.2 0.3 0.0 0.8 0.6 0.7 0.0 0.5
5 0.4 0.3 0.5 0.1 0.7
11 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1
11 2 2 2 1 1 0.1 1 0.1 0.1 0.1 0.1
输出样例：

40.0% 20.0%
*/

#include <stdio.h>

int main(void)
{
    int N,D;//分别代表房屋数量以及观察时长
    float E;//代表电量阈值
    scanf("%d %f %d",&N,&E,&D);
    int i;
    int x=0 ,y = 0; //分别代表可能空置以及空置的房屋数
    for(i=0 ; i<N ; i++)
    {
        int d_ = 0; //用电量不足阈值的天数
        int d; //代表观察天数
        scanf("%d",&d);
        int j; //循环计数
        float e;//用电量
        for(j=0 ; j<d ; j++)
        {
            scanf("%f",&e);
            if(e<E)
                d_+=1;
        }
        if(d>D && d_>d/2)
            y++;
        else if (d_ > d/2)
            x++;
        else
            continue;
    }
    printf("%.1f",x*100*1.0/N);
    printf("%% ");
    printf("%.1f",y*100*1.0/N);
    printf("%%\n");
    return 0;
}
