/*
ʱ�䣺2018/7/1
���ߣ�¥��Ȼ
��Ŀ��
1059 C���Ծ�����20 �֣�

�����ʽ��
�����һ�и���һ��������,�ǲ�������������� N �и�������������ÿ�а�����˳�����һλ�����ߵ� ID��4 λ������ɣ�������������һ�������� K �Լ� K ����Ҫ��ѯ�� ID��

�����ʽ��
��ÿ��Ҫ��ѯ�� ID����һ������� ID: ��Ʒ�����н�Ʒ������ Mystery Award�����ش󽱣��������� Minion��С���ˣ��������� Chocolate���ɿ�������������� ID ���������������ӡ Are you kidding?��ˣ���أ���������� ID �Ѿ�����ˣ�����Ʒ�Ѿ�����ˣ�����ӡ ID: Checked�����ܶ�Զ�ռ����

����������
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222
���������
8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?
*/
#include <stdio.h>
#include <math.h>

//˼·����һ����������±�洢��ţ���1~N������������-1�����Ѿ���ѯ����
int Is_prime(int z)
{
    int item = (int)sqrt(z)+1;
    int j;
    if (z<2)
        return 0;
    else if (z == 2 || z == 3)
        return 1;
    else if (z%6!=1 && z%6!=5)
        return 0;
    for (j = 5; j < item; j+=6)
    {
        if (z%j==0 || z%(j+2)==0)
            return 0;
    }
    return 1;
}

int main(void)
{
    int ID[10000] = {0};
    int N;//����ѧ������
    scanf("%d",&N);
    int i;
    int id;
    for(i=1 ; i<=N ; i++)
    {
        scanf("%d",&id);
        ID[id] = i;
    }
    int K; //��Ҫ��ѯ��ID����
    scanf("%d",&K);
    for(i=0 ; i<K ; i++)
    {
        scanf("%d",&id);
        if(ID[id] == 0)
            printf("%04d: Are you kidding?\n",id);
        else if(ID[id] == -1)
            printf("%04d: Checked\n",id);
        else if(ID[id] == 1)
        {
            printf("%04d: Mystery Award\n",id);
            ID[id] = -1;
        }
        else if(Is_prime(ID[id]))
        {
            printf("%04d: Minion\n",id);
            ID[id] = -1;
        }
        else
        {
            printf("%04d: Chocolate\n",id);
            ID[id] = -1;
        }
    }
    return 0;
}
/*
�ܽ᣺
1.�ô�������±�����¼ID������ֵ�Ĳ�ͬ��ȷ���Ƿ���ڡ��Ƿ��ѯ����������
*/




/*
���µ���������¼��ѯ����ID�������Ͳ����ƻ�ID��������

#include <iostream>
#include <set>
#include <cmath>
using namespace std;
int ran[10000];
bool isprime(int a) {
    if(a <= 1) return false;
    int Sqrt = sqrt((double)a);
    for(int i = 2; i <= Sqrt; i++) {
        if(a % i == 0)
            return false;
    }
    return true;
}
int main() {
    int n, k;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int id;
        scanf("%d", &id);
        ran[id] = i + 1;
    }
    scanf("%d", &k);
    set<int> ss;
    for(int i = 0; i < k; i++) {
        int id;
        scanf("%d", &id);
        printf("%04d: ", id);
        if(ran[id] == 0) {
            printf("Are you kidding?\n");
            continue;
        }
        if(ss.find(id) == ss.end()) {
            ss.insert(id);
        } else {
            printf("Checked\n");
            continue;
        }
        if(ran[id] == 1) {
            printf("Mystery Award\n");
        }else if(isprime(ran[id])) {
            printf("Minion\n");
        }else {
            printf("Chocolate\n");
        }
    }
    return 0;
}
*/

/*
������Ԫ�ظ�ֵʱ�����ò�ͬ�����������ֽ��з��࣬Ȼ��ʹ��switch�����ж����
#include <stdio.h>

int isPrime(int n)
{
    if(n == 1) return 0;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
            return 0;
    return 1;
}

int main()
{
    int award[10000] = {0}, N, K, ID;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &ID);
        if(i == 0)              award[ID] = 1;
        else if(isPrime(i + 1)) award[ID] = 2;
        else                    award[ID] = 3;
    }
    scanf("%d", &K);
    for(int i = 0; i < K; i++)
    {
        scanf("%d", &ID);
        switch(award[ID])
        {
            case 0: printf("%04d: Are you kidding?\n", ID);               break;
            case 1: printf("%04d: Mystery Award\n", ID);  award[ID] = 4;  break;
            case 2: printf("%04d: Minion\n", ID);         award[ID] = 4;  break;
            case 3: printf("%04d: Chocolate\n", ID);      award[ID] = 4;  break;
            case 4: printf("%04d: Checked\n", ID);                        break;
        }
    }

    return 0;
}

*/
