/*
ʱ�䣺2018/6/27 12��23��
���ߣ�¥��Ȼ
��Ŀ:
1028 �˿��ղ�(20)��20 �֣�
ĳ��������˿��ղ飬�õ���ȫ���������ա�������д�������ҳ��������곤����������ˡ�

����ȷ��ÿ����������ڶ��ǺϷ��ģ�����һ���Ǻ���ġ���������֪����û�г���200������ˣ���������2014��9��6�գ����Գ���200������պ�δ���������ն��ǲ�����ģ�Ӧ�ñ����˵���

�����ʽ��

�����ڵ�һ�и���������N��ȡֵ��(0, 10^5^]�����N�У�ÿ�и���1���˵��������ɲ�����5��Ӣ����ĸ��ɵ��ַ��������Լ�����yyyy/mm/dd��������/��/�գ���ʽ���������ա���Ŀ��֤���곤�����������û�в��С�

�����ʽ��

��һ����˳�������Ч���յĸ��������곤�˺��������˵�����������Կո�ָ���

����������

5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
���������

3 Tom John
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
struct info
{
    char Name[6];
    int Year;
    int month;
    int day;
    struct info * next;
};

bool IsValid(int Y,int M,int D)
{
    if(Y>2014)
        return false;
    else if(Y==2014&&M>9)
        return false;
    else if(Y==2014&&M==9&&D>6)
        return false;
    else if(Y<1814)
        return false;
    else if(Y==1814&&M<9)
        return false;
    else if(Y==1814 && M==9 &&D<6)
        return false;
    else
        return true;
}

bool IsOld(struct info *a,struct info *b)
{
    if(b->Year>a->Year)
        return true;
    else if(b->Year == a->Year && b->month>a->month)
        return true;
    else if(b->Year == a->Year && b->month == a->month && b->day > a->day)
        return true;
    else
        return false;
}

int main(void){
    int N;//����
    int num = 0;
    scanf("%d",&N);
    struct info *head = NULL, *current, * prev;
    int i; //ѭ������
    char Na[6];
    int Y,M,D;
    for(i=0 ; i<N ; i++)
    {
        scanf("%s %d/%d/%d",Na,&Y,&M,&D);
        if(IsValid(Y,M,D))
        {
            current = (struct info *)malloc(sizeof(struct info));
            strcpy(current->Name,Na);
            current->Year = Y;
            current->month = M;
            current->day = D;
            num+=1;
            if(head==NULL)
                head = current;
            else
                prev->next = current;
            prev = current;
        }
    }
    current = head;
    struct info *min = head,*max = head;
    while(current!=NULL)
    {
        if(IsOld(min,current))
            min = current;
        if(IsOld(current,max))
            max = current;
        current = current->next;
    }
    if(num==0)
        printf("0");
    else
        printf("%d %s %s\n",num,max->Name,min->Name);
    return 0;
}







