/*
ʱ�䣺2018/6/19 22��04��
���ߣ�¥��Ȼ
��Ŀ��
�����ʽ��
�����һ�и���һ�������� N���� 100������� N �У�ÿ�а��� ���-�� �ĸ�ʽ����һ����� 4 ��ѡ�T ��ʾ��ȷѡ�F ��ʾ����ѡ�ѡ����ÿո�ָ���

�����ʽ��
��һ������� wifi ���롣

����������
8
A-T B-F C-F D-F
C-T B-F A-F D-F
A-F D-F C-F B-T
B-T A-F C-F D-F
B-F D-T A-F C-F
A-T C-F B-F D-F
D-T B-F C-F A-F
C-T A-F B-F D-F
���������
13224143
*/
#include <stdio.h>
int pan_duan(char n){
    if (n == 'A')
        return 1;
    else if (n == 'B')
        return 2;
    else if (n == 'C')
        return 3;
    else if (n == 'D')
        return 4;
}
int main(void)
{
    int N;
    scanf("%d",&N);
    int i,j;
    char ans[8];
    int res[N];
    for(i=0 ; i<N ; i++)
    {
        scanf(" %c-%c %c-%c %c-%c %c-%c",&ans[0],&ans[1],&ans[2],&ans[3],&ans[4],&ans[5],&ans[6],&ans[7]);
        //��һ��%cǰ��Ҫ�пո�
        for(j=1 ; j<8 ; j+=2)
        {
            if(ans[j] == 'T')
                res[i] = pan_duan(ans[j-1]);
        }
    }
    for (j=0 ; j<N; j++)
        printf("%d",res[j]);
    printf("\n");
    return 0;
}
