/*
ʱ�䣺2018/6/24 08��26��
���ߣ�¥��Ȼ
��Ŀ��
1020 �±� (25)��25 �֣�
�±����й���������ѽ�ʱ�Ե�һ�ִ�ͳʳƷ����ͬ��������಻ͬ��ζ���±����ָ������������±��Ŀ���������ۼۡ��Լ��г�����������������������Ի�õ���������Ƕ��١�

ע�⣺����ʱ����ȡ��һ���ֿ�档���������������������ģ�����������3���±����������ֱ�Ϊ18��15��10��֣����ۼ۷ֱ�Ϊ75��72��45��Ԫ������г������������ֻ��20��֣���ô��������������Ӧ��������ȫ��15��ֵ�2���±����Լ�5��ֵ�3���±������ 72 + 45/2 = 94.5����Ԫ����

�����ʽ��

ÿ���������1������������ÿ�����������ȸ���һ��������1000��������N��ʾ�±������������Լ�������500�������Ϊ��λ����������D��ʾ�г���������������һ�и���N��������ʾÿ���±��Ŀ�����������Ϊ��λ�������һ�и���N��������ʾÿ���±������ۼۣ�����ԪΪ��λ�������ּ��Կո�ָ���

�����ʽ��

��ÿ�������������һ�������������棬����ԪΪ��λ����ȷ��С�����2λ��

����������

3 20
18 15 10
75 72 45
���������

94.50
*/

#include <stdio.h>
//�走��Ϊʲô˼·����һ���ģ�����д�ı��Ҽ򵥣��ܹ�ͨ������Ҫô���г�ʱҪô�𰸴���
int main(void)
{
    int N,P; //N�����±���������P�����г����������
    scanf("%d %d",&N,&P);
    float n[N];//����ÿ���±��Ŀ����
    float p[N];//����ÿ���±������ۼ�
    double dan_jia[N];//�ֱ����ÿ���±��ĵ���
//    int xu_qiu[N];//�ֱ����ÿ���±���������
    int i,j;//ѭ������
    double res=0;//����ۼ�����ֵ
    for(i=0 ; i<N ; i++)
        scanf("%f",&n[i]);
    for(i=0 ; i<N ; i++)
    {
        scanf("%f",&p[i]);
    }

    for(i=0 ; i<N ; i++)
        dan_jia[i] = p[i]*1.0/n[i];
//    int sorting[N];//�洢���۴Ӹߵ��͵��±�ֵ
    float change = 1;
    double t;
    /*  ѡ�����򷨻���̫����
    for(i=0 ; i<N-1 ; i++)
    {
        for(j=i+1; j<N ;j++)
        {
            if(dan_jia[j]>dan_jia[i])
            {
                change = n[i];
                n[i] = n[j];
                n[j] = change;
                t = dan_jia[i];
                dan_jia[i] = dan_jia[j];
                dan_jia[j] = t;
            }
        }
    }
    */
    int flag = 1;
    for(i=N-1;i>=1&&flag==1;i--)
    {
        flag = 0;
        for(j=0 ; j<N-1 ; j++)
        {
            if(dan_jia[j+1]>dan_jia[j]);
            {
                flag = 1;
                change = n[j+1];
                n[j+1] = n[j];
                n[j] = change;
                t = dan_jia[j+1];
                dan_jia[j+1] = dan_jia[j];
                dan_jia[j] = t;
            }
        }
    }

//    for(i=0 ; i<N ; i++)
//        printf("%d %f\n",n[i],dan_jia[i]);
    i = 0;
    while(P!=0)
    {

        if(n[i] < P)
        {
            res += n[i]*dan_jia[i];
 //           printf("%.2f",n[i]*1.0*dan_jia[i]);
            P -= n[i];
            i++;
        }
        else if (P>0)
        {
 //           printf("%d %f\n",n[i],dan_jia[i]);
            res += P*dan_jia[i];
//            printf("%.2f",P*dan_jia[i]);
//            printf("%f",res);
            P = 0;
        }

    }
    printf("%.2lf",res);
    return 0;
}

/*
��ʡ��
1�������Ǿ�������
2������ʹ�������㷨
*/

/*  �ṹ��˼·
#include <stdio.h>
struct cake{
    double kucun;
    double price;
    double danjia;
}cake[1001];
int main()
{
    int n,d,i,j;
    struct cake temp;
    double tprice=0.0;
    scanf("%d %d",&n,&d);
    for(i=0;i<n;i++)
    {
        scanf("%lf",&cake[i].kucun);
    }
    for(i=0;i<n;i++)
    {
        scanf("%lf",&cake[i].price);
        cake[i].danjia=cake[i].price/cake[i].kucun;
    }
    for(i=0;i<n-1;i++)//���ṹ�尴���۴�С����
    {
        for(j=i+1;j<n;j++)
        {
            if(cake[i].danjia<cake[j].danjia)
            {
                temp=cake[i];
                cake[i]=cake[j];
                cake[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(cake[i].kucun<d)
        {
            tprice+=cake[i].price;
            d=d-cake[i].kucun;
        }else if(d>0)
        {
            tprice=tprice+d*cake[i].danjia;
            d=0;
            break;
        }
    }
    printf("%.2lf\n",tprice);
    return 0;
}
*/

/*  Ѱ�����ֵ�������ֵ0
#include <stdio.h>
int main()
{
    int N, max;
    float D, Storage[1000], Total = 0, Price[1000];
    scanf("%d %f", &N, &D);
    for(int i = 0; i < N; i++) scanf("%f", Storage + i);
    for(int i = 0; i < N; i++) scanf("%f", Price + i);

    while(D > 0)
    {
        max = 0;
        for(int i = 0; i < N; i++)
            if(Price[i] / Storage[i] > Price[max] / Storage[max])
                max = i;

        if(Storage[max] < D)
        {
            Total += Price[max];
            D -= Storage[max];
            Price[max] = 0;
        }
        else
        {
            Total += Price[max] * D / Storage[max];
            D = 0;
        }
    }
    printf("%.2f", Total);

    return 0;
}
*/
