/*
ʱ�䣺2018/6/30
���ߣ�¥��Ȼ
��Ŀ��
1040 �м���PAT��25����25 �֣�
�ַ���APPAPT�а������������ʡ�PAT�������е�һ��PAT�ǵ�2λ(P),��4λ(A),��6λ(T)���ڶ���PAT�ǵ�3λ(P),��4λ(A),��6λ(T)��

�ָ����ַ�������һ�������γɶ��ٸ�PAT��

�����ʽ��

����ֻ��һ�У�����һ���ַ��������Ȳ�����10^5^��ֻ����P��A��T������ĸ��

�����ʽ��

��һ������������ַ����а������ٸ�PAT�����ڽ�����ܱȽϴ�ֻ�����1000000007ȡ�����Ľ����

����������

APPAPT
���������

2
*/

//˼·��ÿ��A��Ӧ��PA���������A֮ǰP��������ÿ��T��Ӧ��PAT���������T֮ǰ����A��Ӧ��PA����������ۼӣ����е�PAT�������������T��Ӧ��PAT����������ۼ�
#include <stdio.h>

#define LIM 1000000007

int main(void)
{
    int P=0,PA=0,PAT=0;
    char ch;
    while((ch=getchar())!='\n')
    {
        if(ch=='P')
        {
            P++;
            P = P % LIM;
        }
        else if(ch == 'A')
        {
            PA = (PA + P)%LIM;
        }
        else
            PAT = (PAT + PA) % LIM;
    }
    printf("%d",PAT);
    return 0;
}




//˼·����ô�����ַ��������ÿһA����ǰ���P�ĸ������������T�ĸ����ĳ˻������ܹ��ɵ�PAT�ĸ���
/*
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.length(), result = 0, countp = 0, countt = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'T')
            countt++;
    }
    for (int i = 0; i < len; i++) {
        if (s[i] == 'P') countp++;
        if (s[i] == 'T') countt--;
        if (s[i] == 'A') result = (result + (countp * countt) % 1000000007) % 1000000007;
    }
    cout << result;
    return 0;
}
*/

