/*
ʱ�䣺2018/6/24 22��34��
���ߣ�¥��Ȼ
��Ŀ��
1067 �����루20 �֣�
������ͼ��¼ĳ��ϵͳȴ��������ʱ��ϵͳһ��ֻ�������㳢�����޶�Σ��������������ʱ���˺žͻᱻ���������������ʵ�����С���ܡ�

�����ʽ��
�����ڵ�һ�и���һ�����루���Ȳ����� 20 �ġ��������ո�Tab���س��ķǿ��ַ�������һ�������� N���� 10�����ֱ�����ȷ�������ϵͳ�����ԵĴ��������ÿ�и���һ���Իس������ķǿ��ַ��������û�������������롣���뱣֤������һ�γ��ԡ�������һ��ֻ�е��� # �ַ�ʱ�����������������һ�в����û������롣

�����ʽ��
���û���ÿ�����룬�������ȷ�������ҳ��Դ��������� N������һ������� Welcome in����������������Ǵ���ģ�����һ���а���ʽ��� Wrong password: �û�����Ĵ������룻�������Դﵽ N ��ʱ�������һ�� Account locked������������

�������� 1��
Correct%pw 3
correct%pw
Correct@PW
whatisthepassword!
Correct%pw
#
������� 1��
Wrong password: correct%pw
Wrong password: Correct@PW
Wrong password: whatisthepassword!
Account locked
�������� 2��
cool@gplt 3
coolman@gplt
coollady@gplt
cool@gplt
try again
#
������� 2��
Wrong password: coolman@gplt
Wrong password: coollady@gplt
Welcome in
*/

//���һ�����Ե����ȥ
#include <stdio.h>
#include <string.h>

int main(void)
{
    char password[21];  //��ȷ������
    int N; //�ܹ����ԵĴ���
    scanf("%s %d",password,&N);
    while(getchar()!='\n')
        continue;
    char try[N+1][1000];// �������������
    int i = 0; // ѭ������
    char t[1000];
    while(gets(t)&&t[0]!='#')
    {
        if(i<N+1)
        {
            strcpy(try[i],t);
            i++;
        }
    }
 //   int r = i; //r����try�������ж����ַ���
    for(i=0 ; i<N ; i++)
    {
        if(strcmp(password,try[i])==0)
        {
            printf("Welcome in\n");
            break;
        }
        else
        {
            printf("Wrong password: %s\n",try[i]);
//            puts(try[i]);
            if(i==N-1)
            {
                printf("Account locked\n");
                break;
            }

        }
    }

    return 0;

}


/*
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int main()
{
    int N;
    char c, correct[21], user[21];

    scanf("%s %d", correct, &N);
    while(getchar() != '\n');
    while(N--)
    {
        scanf("%20[^\n]", user);
        c = ungetc(getchar(), stdin);
        if(!strcmp(user, "#") && c == '\n')
        {
            break;
        }
        else if(!strcmp(correct, user) && c == '\n')
        {
            puts("Welcome in");
            break;
        }
        else
        {
            printf("Wrong password: %s", user);
            while(putchar(getchar()) != '\n') ;
            if(!N)  puts("Account locked");
        }
    }

    return 0;
}

*/
