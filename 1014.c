/*
ʱ�䣺2018/6/27 09��35��
���ߣ�¥��Ȼ
��Ŀ��
1014 ����Ħ˹��Լ�� (20)��20 �֣�
����̽����Ħ˹�ӵ�һ����ֵ�������������Լ��ɣ� 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm��������̽�ܿ�������ˣ���������ֵ�����ʵ���Ͼ���Լ���ʱ�䡰������ 14:04������Ϊǰ�����ַ����е�1����ͬ�Ĵ�дӢ����ĸ����Сд�����֣��ǵ�4����ĸ'D'�����������ģ���2����ͬ���ַ���'E'�����ǵ�5��Ӣ����ĸ������һ����ĵ�14����ͷ������һ���0�㵽23��������0��9���Լ���д��ĸA��N��ʾ�����������ַ�����1����ͬ��Ӣ����ĸ's'�����ڵ�4��λ�ã���0��ʼ�������ϣ������4���ӡ��ָ��������ַ��������������Ħ˹����õ�Լ���ʱ�䡣

�����ʽ��

������4���зֱ����4���ǿա��������ո��ҳ��Ȳ�����60���ַ�����

�����ʽ��

��һ�������Լ���ʱ�䣬��ʽΪ��DAY HH:MM�������С�DAY����ĳ���ڵ�3�ַ���д����MON��ʾ����һ��TUE��ʾ���ڶ���WED��ʾ��������THU��ʾ�����ģ�FRI��ʾ�����壬SAT��ʾ��������SUN��ʾ�����ա���Ŀ���뱣֤ÿ�����Դ���Ψһ�⡣

����������

3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
���������

THU 14:04
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char Time[4][61];
    int i;
    for(i=0 ; i<4 ; i++)
        scanf("%s",&Time[i]);
    char week[7][4] = {{"MON"},{"TUE"},{"WED"},{"THU"},{"FRI"},{"SAT"},{"SUN"}};
  //  for(i=0 ; i<7 ; i++)            //��֤week�����Ƿ�����
  //      printf("%s\n",week[i]);
    char ch1,ch2; //�ֱ����ڷ���week��hour���������ĸ��
    int j;
    int dot = -1;
    int lenA = strlen(Time[0]),lenB = strlen(Time[1]),lenC = strlen(Time[2]),lenD = strlen(Time[3]);
    for(i=0 ; i<lenA ; i++)
    {
        if(Time[0][i]>='A' && Time[0][i]<='G')
        {
            if(Time[0][i] == Time[1][i])
            {
                    ch1 = Time[0][i];
                    break;

            }
        }
    }
    for(j=i+1 ; j<lenA ; j++)
    {
        if((Time[0][j]>='A'&&Time[1][j]<='N')||(Time[0][j]>='0'&&Time[0][j]<='9'))
        {

            if(Time[0][j] == Time[1][j] && j!=dot)
            {
                ch2 = Time[0][j];
                break;
            }

        }
    }
    int h;
    if(ch2>='A'&&ch2<='N')
    {
        h = ch2-'A'+10;
    }
    else
    {
        h = ch2-'0';
    }
    int w = ch1-'A';
//    printf("%c %c",ch1,ch2);
    dot = -1;
    for(i=0 ; i<lenC ; i++)
    {
        if((Time[2][i]>='A'&&Time[2][i]<'Z')||(Time[2][i]>='a'&&Time[2][i]<='z'))
        {
            if(Time[2][i] == Time[3][i])
            {
                dot = i;
                break;
            }
        }
    }
    printf("%s %02d:%02d",week[w],h,dot);


    return 0;
}
