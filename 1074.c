/*
ʱ�䣺2018/6/23 13��52��
���ߣ�¥��Ȼ
��Ŀ��
1074 �����޵мӷ�����20 �֣�
������ϰ��ʹ��ʮ������������Ĭ��һ�����ֵ�ÿһλ����ʮ���Ƶġ����� PAT ���˿��ҵ������ÿ�����ֵ�ÿһλ���ǲ�ͬ���Ƶģ�������������ֳ�Ϊ��PAT������ÿ�� PAT ���˶�������Ǹ�λ���ֵĽ��Ʊ����硰����0527���ͱ�ʾ���λ�� 7 ���������� 2 λ�� 2 ���������� 3 λ�� 5 ���������� 4 λ�� 10 ���������ȵȡ�ÿһλ�Ľ��� d ������ 0����ʾʮ���ƣ��������� [2��9] �����ڵ�������������������Ʊ�Ӧ�ð��������λ���֣�����ʵ��Ӧ�ó�����PAT ����ͨ��ֻ��Ҫ��סǰ 20 λ�͹����ˣ��Ժ��λĬ��Ϊ 10 ���ơ�

������������ϵͳ�У���ʹ�Ǽ򵥵ļӷ�����Ҳ��ò��򵥡������Ӧ���Ʊ�0527��������μ��㡰6203 + 415���أ����ǵ����ȼ������λ��3 + 5 = 8����Ϊ���λ�� 7 ���Ƶģ��������ǵõ� 1 �� 1 ����λ���� 2 λ�ǣ�0 + 1 + 1����λ��= 2����Ϊ��λ�� 2 ���Ƶģ��������ǵõ� 0 �� 1 ����λ���� 3 λ�ǣ�2 + 4 + 1����λ��= 7����Ϊ��λ�� 5 ���Ƶģ��������ǵõ� 2 �� 1 ����λ���� 4 λ�ǣ�6 + 1����λ��= 7����Ϊ��λ�� 10 ���Ƶģ��������Ǿ͵õ� 7��������ǵõ���6203 + 415 = 7201��

�����ʽ��
���������ڵ�һ�и���һ�� N λ�Ľ��Ʊ�0 < N �� 20�����Իس������� ������У�ÿ�и���һ�������� N λ�ķǸ��� PAT ����

�����ʽ��
��һ����������� PAT ��֮�͡�

����������
30527
06203
415
���������
7201
*/

#include <stdio.h>
#include <string.h>

#define  SIZE 21

int main(void)
{
    char jinzhi[SIZE];
    char num_1[SIZE];
    char num_2[SIZE];
    int i;
    scanf("%s",jinzhi);
    scanf("%s",num_1);
    scanf("%s",num_2);
    int N = strlen(jinzhi); //���Ƶ�λ��
    int n1 = strlen(num_1);
    int n2 = strlen(num_2); //�ֱ��ʾ�������ֵ�λ��
    int n = n1>n2?n1:n2;
    char res[n+2];
    int mid = 0; //�������
    int sum;//������λ�����������ֵĺ�
    res[n+1] = '\0';
    for(i=1 ; i<=n ; i++)
    {
        int a = n1-i>=0?num_1[n1-i]-'0':0;
        int b = n2-i>=0?num_2[n2-i]-'0':0;

        sum = a + b + mid;
 //       printf("s %d\n",sum);
        if(sum < (jinzhi[N-i]-'0'))
        {
            res[n+1-i] = sum + '0';
            mid = 0;
    //        printf("1 %c\n",res[n+1-i]);
        }

        else
        {
            int c = sum;
            int d = jinzhi[N-i] - '0';
            if(d==0)
                d = 10;
            sum = c%d;
            res[n+1-i] = sum + '0';
            mid = c/d;
   //         printf(" 2 %c\n",res[n+1-i]);
        }
    }
    if(mid==0)
    {
        res[0] = '0';
    }
    else
        res[0] = mid+'0';
    i = 0;
    int j;
 //   printf("%s",res);
    for(i=0 ; i<n+1 ; i++)
    {
        if(res[i] == '0')
        {
            j=i;
        }
        else
        {
            j = i;
            break;
        }
    }
    for(;j<n+1;j++)
        printf("%c",res[j]);
    return 0;

}

/*
int main(void)
{
    char a[3][SIZE];
    int i;
    char ch;
    for(i=0 ; i<3 ; i++)
    {
        int j=0;
        while((ch=getchar())&&ch!='\n')
        {
            a[i][j] = ch;
            j++;
        }
        a[i][j] = '\0';
    }
    int leng_0,leng_1,leng_2,l1,l2;
    leng_0 = strlen(a[0]),l1 = leng_1 = strlen(a[1]),l2 = leng_2 = strlen(a[2]);
    int leg = leng_1>leng_2?leng_1:leng_2;
    int a_,b_,d_;
    int mid_4 = 0;
    int res[SIZE];
    int j=0;
    for(i=1 ; i<=leg ;i++)
    {
        if(i<=l1)
            a_ = (a[1][leng_1-i])-'0';
        else
            a_ = 0;
        if(i<=l2)
            b_ = a[2][leng_2-i]-'0';
        else
            b_ = 0;
        d_ = a[0][leng_0-i]-'0';
        res[j] = (a_ + b_ + mid_4)%d_;
        mid_4 = (a_ + b_ + mid_4)/d_;
        j++;
    }
    int z;
    for(z=j-1 ; z>=0 ; z--)
        scanf("%d",res[i]);
    return 0;
}

*/

/* �������
#include <stdio.h>
#define SIZE 20

int main(void)
{
    long int d;
    long int a;
    long int b;
    int mid_1,mid_2,mid_3,mid_4=0;  //�ֱ����ڴ��d,a,b,res������
    scanf("%ld",&d);
    scanf("%ld",&a);
    scanf("%ld",&b);
    int res[SIZE];
    int i=0;
    while(a!=0 || b!=0)
    {
        mid_1 = d%10;
        d = d/10;
        mid_2 = a/10;
        a = a/10;
        mid_3 = b/10;
        b = b/10;
        res[i] = (mid_2 + mid_3 + mid_4)%mid_1;
        mid_4 = (mid_2 + mid_3 + mid_4)/mid_1;
        i++;
    }
    int j;
    long int Re=0;//����������
    for(i=0 ; i<j ; i++)
        Re = Re*10+res[i];
    printf("%d",Re);
    return 0;
}
*/
