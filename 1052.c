/*
ʱ�䣺2018/6/30
���ߣ�¥��Ȼ
��Ŀ��
1052 ������ (20)��20 �֣�
�����ձ������ͨ���ɡ��֡������ۡ������ڡ�������Ҫ������ɡ�����������Ǽ���һ����������ǰ����и�ʽ����ģ�

[����]([����][��][����])[����]
�ָ�����ѡ�õķ��ż��ϣ����㰴�û���Ҫ��������顣

�����ʽ��

����������ǰ����˳���Ӧ�����֡��ۡ��ڵĿ�ѡ���ż���ÿ����������һ�Է�����[]�ڡ���Ŀ��֤ÿ�����϶�������һ�����ţ���������10�����ţ�ÿ�����Ű���1��4���ǿ��ַ���

֮��һ�и���һ��������K��Ϊ�û�����ĸ��������K�У�ÿ�и���һ���û��ķ���ѡ��˳��Ϊ���֡����ۡ��ڡ����ۡ����֡�������ֻ������������Ӧ�����е���ţ���1��ʼ�������ּ��Կո�ָ���

�����ʽ��

��ÿ���û�������һ����������ɵı��顣���û�ѡ�����Ų����ڣ��������Are you kidding me? @\/@����

����������

[�r][�q][o][~\][/~]  [<][>]
 [�s][�t][^][-][=][>][<][@][��]
[��][��][_][��][^]  ...
4
1 1 2 2 2
6 8 1 5 5
3 3 4 3 3
2 10 3 9 3
���������

�r(�s���t)�q
<(@��=)/~
o(^��^)o
Are you kidding me? @\/@
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char symbol[3][10][5]={0};
    int i,j;
    char ch;
    int length[3]={0};
 //   int z=0;
    for(i=0 ; i<3 ; i++)
    {
        for(j=0 ; (ch=getchar())!='\n';)
        {
            if(ch=='[')
                scanf("%[^]]",symbol[i][j++]);
        }
    }
    int N;
    int m[5];
    scanf("%d",&N);
    for(i=0 ; i<N ; i++){
        int j;
        for(j=0 ; j<5 ; j++)
            scanf("%d",&m[j]);
        if(m[0]>0&&m[0]<=10&&*symbol[0][--m[0]]&&m[1]>0&&m[1]<=10&&*symbol[1][--m[1]]&&m[2]>0&&m[2]<=10&&*symbol[2][--m[2]]&&m[3]>0&&m[3]<=10&&*symbol[1][--m[3]]&&m[4]>0&&m[4]<=10&&*symbol[0][--m[4]])
            printf("%s(%s%s%s)%s\n",symbol[0][m[0]],symbol[1][m[1]],symbol[2][m[2]],symbol[1][m[3]],symbol[0][m[4]]);
        else
            printf("Are you kidding me? @\\/@\n");
    }
    return 0;
}

/*
�ܽ᣺
1.scanf("%[^]]")���뺯����Ӧ�ã���˼�ǵ����뵽']'Ϊֹ
2.�ж�������ʹ�ã�*����Ԫ����ζ��ȡ����Ԫ��
*/



/*
#include <stdio.h>
//https://en.wikipedia.org/wiki/Variable-width_encoding
int main()
{
    char c, symbols[3][10][5] = {0};
    int symbol,index;
    for(symbol = 0; symbol < 3; symbol++)
        for(index = 0; (c = getchar()) != '\n'; )
            if(c == '[') scanf("%[^]]", symbols[symbol][index++]);

    int N, m[5];
    scanf("%d", &N);
    int i,j;
    for(i = 0; i < N; i++)
    {
        for(j = 0;j < 5; j++)  scanf("%d", m + j);
        if(m[0] > 0 && m[0] <= 10 && *symbols[0][--m[0]]
        && m[1] > 0 && m[0] <= 10 && *symbols[1][--m[1]]
        && m[2] > 0 && m[0] <= 10 && *symbols[2][--m[2]]
        && m[3] > 0 && m[0] <= 10 && *symbols[1][--m[3]]
        && m[4] > 0 && m[0] <= 10 && *symbols[0][--m[4]])
            printf("%s(%s%s%s)%s\n", symbols[0][m[0]], symbols[1][m[1]],
                   symbols[2][m[2]], symbols[1][m[3]], symbols[0][m[4]]);
        else
            puts("Are you kidding me? @\\/@");
    }

    return 0;
}

*/
