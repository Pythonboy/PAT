/*
ʱ�䣺2018/6/12 23��33��
���ߣ�¥��Ȼ
��Ŀ��
����һ��Ӣ�Ҫ�����д���򣬽��������е��ʵ�˳��ߵ������

�����ʽ�������������һ��������������һ���ڸ����ܳ��Ȳ�����80���ַ������ַ��������ɵ��ʺ����ɿո���ɣ����е�������Ӣ����ĸ����Сд�����֣���ɵ��ַ���������֮����1���ո�ֿ������뱣֤����ĩβû�ж���Ŀո�
�����ʽ��ÿ���������������ռһ�У���������ľ��ӡ�
����������
Hello World Here I Come
���������
Come I Here World Hello
*/
#include <stdio.h>
#include <string.h>
#define SIZE 80
/* ȫ�����Ե���ȷͨ��
int main(void)
{
    char english[SIZE][SIZE];
    int i=0;
    int j=0;
    while((english[i][j]=getchar())!='\n')
    {
        if (english[i][j]==' ')
        {
            english[i][j] = '\0';
            i++;
            j = 0;
        }
        else
            j++;
    }
    english[i][j]='\0';
    for (;i>=0;i--)
    {
        printf("%s",english[i]);
        if(i>0)
            printf(" ");
    }
    return 0;
}
*/

/*  δ��ͨ�����ĸ����Ե�
int main(void)
{
    char english[SIZE];
    char ans[SIZE][SIZE];
    fgets(english,SIZE,stdin);
    int i=0;
    while(english[i]!='\n' && english[i]!='\0')
       i++;
    if(english[i]=='\n')
        english[i]='\0';
    int length = strlen(english),n,m=0,k=0;
    for(n=0; n<length; n++)
    {
        if(english[n]!=' ')
        {
            ans[m][k++]=english[n];
        }
        else{
            ans[m][k]='\0';
            k = 0;
            m++;
        }
    }
    printf("%s",ans[m]);
    for(n=m-1;n>=0;n--)
    {
        printf(" ");
        printf("%s",ans[n]);
    }
    return 0;
}
*/
