/*
ʱ�䣺2018/6/15 10��29��
���ߣ�¥��Ȼ
��Ŀ��
1022 D���Ƶ�A+B (20)��20 �֣�
���������Ǹ�10��������A��B(<=2^30^-1)�����A+B��D (1 < D <= 10)��������
�����ʽ��
������һ�������θ���3������A��B��D��
�����ʽ��
���A+B��D��������
����������
123 456 8
���������
1103
*/

#include <stdio.h>
void jin_zhi_zhuan_huan(int num, int d); //������num����D�������
int main(void)
{
    int a,b,d;
    scanf("%d %d %d",&a,&b,&d);
    int num = a+b ;
    jin_zhi_zhuan_huan(num , d);
    return 0;

}
void jin_zhi_zhuan_huan(int num, int d)  //�ݹ鷨
{
    if (num>=d)
        jin_zhi_zhuan_huan(num/d,d);
    printf("%d",num%d);
}
