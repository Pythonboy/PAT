/*
ʱ�䣺2018/6/23 18��00��
���ߣ�¥��Ȼ
��Ŀ��
1010 һԪ����ʽ�� (25)��25 �֣�
��ƺ�����һԪ����ʽ�ĵ�������ע��x^n^��nΪ��������һ�׵���Ϊn*x^n-1^����

�����ʽ����ָ���ݽ���ʽ�������ʽ������ϵ����ָ��������ֵ��Ϊ������1000�������������ּ��Կո�ָ���

�����ʽ������������ͬ�ĸ�ʽ�����������ʽ�������ϵ����ָ�������ּ��Կո�ָ�������β�����ж���ո�ע�⡰�����ʽ����ָ����ϵ������0�����Ǳ�ʾΪ��0 0����

����������

3 4 -5 2 6 1 -2 0
���������

12 3 -10 1 6 0
*/
#include <stdio.h>

int main(void)
{
    int index,coef,count = 0;
    int res[1000];
    int i=0;
    while(scanf("%d %d",&index,&coef)!=EOF && coef!=0)   //��ס�������뷽ʽ
    {
        if(coef)
        {
            res[i] = coef*index;
            res[i+1] = coef - 1;
            i+=2;
            //printf("%d %d%c",index*coef,coef-1,coef?' ':'\n');   //��������ִ��
            count++;
        }
    }
    int j;
    if(count==0)
        printf("0 0\n");
    else
    {
        for(j=0 ; j<i ; j++)
            printf("%d%c",res[j],j!=i-1?' ':'\n');
    }

    return 0;
}


/*  ����д�ģ�˼·�ر�ã�������PAT�и�ʽͨ����
#include <stdio.h>
int main()
{
    int coef, index, count = 0;

    while(scanf("%d %d", &coef, &index) != EOF) if(index)
    {   //constant terms results in zero term, so no output for index = 0
        printf("%c%d %d", count++ ? ' ' : '\0', coef * index, index - 1);
    }
    // zero polynomial or constant, the result is zero polynomial
    if(count == 0) puts("0 0");

    return 0;
}
*/
