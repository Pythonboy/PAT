/*
时间：2018/6/22 22点28分
作者：楼浩然
题目：
1049 数列的片段和(20)（20 分）
给定一个正数数列，我们可以从中截取任意的连续的几个数，称为片段。例如，给定数列{0.1, 0.2, 0.3, 0.4}，我们有(0.1) (0.1, 0.2) (0.1, 0.2, 0.3) (0.1, 0.2, 0.3, 0.4) (0.2) (0.2, 0.3) (0.2, 0.3, 0.4) (0.3) (0.3, 0.4) (0.4) 这10个片段。

给定正整数数列，求出全部片段包含的所有的数之和。如本例中10个片段总和是0.1

0.3 + 0.6 + 1.0 + 0.2 + 0.5 + 0.9 + 0.3 + 0.7 + 0.4 = 5.0。
输入格式：

输入第一行给出一个不超过10^5^的正整数N，表示数列中数的个数，第二行给出N个不超过1.0的正数，是数列中的数，其间以空格分隔。

输出格式：

在一行中输出该序列所有片段包含的数之和，精确到小数点后2位。

输入样例：

4
0.1 0.2 0.3 0.4
输出样例：

5.00
*/
//思路：总结数学规律
#include <stdio.h>

int main(void)
{
    int N; //数列中元素个数
    scanf("%d",&N);
    double num[N];  //存放数列中的元素
    int i;//循环计数
    for(i=0 ; i<N ; i++)
        scanf("%lf",&num[i]);
    double res = 0; //最后结果
    for(i=0 ; i<N ; i++)
        res += num[i]*(i+1)*(N-i);
    printf("%.2lf",res);

    return 0;

}

//运行超时
/*
#include <stdio.h>

int main(void)
{
    int N; //数列中元素个数
    scanf("%d",&N);
    float num[N];  //存放数列中的元素
    int i;//循环计数
    for(i=0 ; i<N ; i++)
        scanf("%f",&num[i]);
    float res = 0; //最后结果
    int j; //循环计数
    for(i=0 ; i<N ; i++)
    {
        int bs = N - i;  //在一次扫描中每个元素出现的次数
        for(j=i ; j<N ; j++)
        {
            res += num[j]*bs ;
            bs--;
        }
    }
    printf("%.2f",res);
    return 0;

}
*/
