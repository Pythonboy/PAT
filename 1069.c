/*
ʱ�䣺2018/7/1
���ߣ�¥��Ȼ
��Ŀ��
1069 ΢��ת���齱��20 �֣�
С�� PAT �������֣�����֮���������΢��ת���齱�����ת���������а�˳��ÿ�� N ���˾ͷ���һ������������д���������ȷ���н�������

�����ʽ��
�����һ�и������������� M���� 1000����N �� S���ֱ���ת����������С���������н�������Լ���һλ�н��ߵ���ţ���Ŵ� 1 ��ʼ������� M �У�˳�����ת��΢�������ѵ��ǳƣ������� 20 ���ַ����������ո�س��ķǿ��ַ�������

�����ʽ��
���������˳������н�������ÿ���ǳ�ռһ�С����û�����н�������� Keep going...��

�������� 1��
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain
������� 1��
PickMe
Imgonnawin!
TryAgainAgain
�������� 2��
2 3 5
Imgonnawin!
PickMe
������� 2��
Keep going...
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    int M,N,S; //�ֱ����ת����������С���������н�������Լ���һλ�н��ߵ����
    scanf("%d %d %d",&M,&N,&S);
    char ID[M][21];
    char id[M*22];  //���ڼ�¼��ID
    id[0] = '\0';
    int i;
    for(i=0 ; i<M ; i++)
        scanf("%s",ID[i]);
    if(S>M)
        printf("Keep going...\n");
    else
    {
        while(S<=M)
        {
            if(strstr(id,ID[S-1])==0)
            {
                strcat(id,ID[S-1]);
                strcat(id," ");
                printf("%s\n",ID[S-1]);
                S = S + N;
            }
            else
            {
                S = S + 1;
            }
        }
    }
    return 0;

}

/*
�ܽ᣺
1.�ڶ��λ񽱻ᱻ���ԣ�ѡ����������
2.��strcat()��������ID�ϲ�Ϊһ�����ַ�����Ȼ����strstr()�������ж��µ�ID�Ƿ�����ڻ�ID�ַ�����
*/
