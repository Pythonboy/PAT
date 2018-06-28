/*
ʱ�䣺2018/6/24 11��47��
���ߣ�¥��Ȼ
��Ŀ��
1050 ��������(25)��25 �֣�
����Ҫ�󽫸�����N�����������ǵ�����˳�����롰�������󡱡���ν���������󡱣���ָ�����Ͻǵ�1�����ӿ�ʼ����˳ʱ������������䡣Ҫ�����Ĺ�ģΪm��n�У�����������m*n����N��m>=n����m-nȡ���п���ֵ�е���Сֵ��

�����ʽ��

�����ڵ�1���и���һ��������N����2�и���N�����������������������ֲ�����10^4^�����������Կո�ָ���

�����ʽ��

�����������ÿ��n�����֣���m�С�����������1���ո�ָ�����ĩ�����ж���ո�

����������

12
37 76 20 98 76 42 53 95 60 81 58 93
���������

98 95 93
42 37 81
53 20 76
58 60 76
*/

//���˵Ĵ���ֱ�Ӹ��ƹ�����

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {return *(int*)b - *(int*)a;}

int main()
{
    int N, m, n;
    scanf("%d", &N);

    int *array = (int*)malloc(N * sizeof(int));
    int *matrix = (int*)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++)
        scanf("%d", array + i);

    qsort(array, N, sizeof(int), cmp);

    /* determine m and n */
    for(m = 1; !(m * m >= N && N % m == 0); m++) ;
    n = N / m;

    int x = -1, y = 0, index = 0;
    int horizontal = n, virtical = m;

    while(horizontal > 0 && virtical > 0)
    {
        for(int i = 0; i < horizontal && virtical > 0; i++)  /* toward right */
            matrix[y * n + ++x] = array[index++];
        virtical--;

        for(int i = 0; i < virtical && horizontal > 0; i++)  /* toward bottom */
            matrix[++y * n + x] = array[index++];
        horizontal--;

        for(int i = 0; i < horizontal && virtical > 0; i++)  /* toward left */
            matrix[y * n + --x] = array[index++];
        virtical--;

        for(int i = 0; i < virtical && horizontal > 0; i++)  /* toward top */
            matrix[--y * n + x] = array[index++];
        horizontal--;
    }

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            printf("%d%c", matrix[i * n + j], j == n - 1 ? '\n' : ' ');

    return 0;
}



/*
void bubble_sort(int * a, int n); //������������
void l_w(int z, int * l, int *w); // �������ĳ��Ϳ�

int main(void)
{
    int N;//�����Ԫ�ظ���
    int length,width;//����ĳ��Ϳ�
    scanf("%d",&N);
    int num[N]; //�洢����Ԫ��
    int i,j;
    int d=0; //ѭ������
    for(i=0 ; i<N ; i++)
        scanf("%d",&num[i]);
    bubble_sort(num,N);
    for(i=0 ; i<N ; i++)          //���������û������
        printf("%d ",num[i]);
    printf("\n");
    l_w(N,&length,&width);
    int screw[width][length];
 //   printf("%d %d\n",length,width); //����ĳ���û������
    memset(screw,0,sizeof(int)*length*width);
    int n=length,m=width;
    int k;
    while(k<N){     //��Ҫ��ֵN��
        while(j+1<n&&!screw[i][j+1])    screw[i][++j]=num[k++];//�����ң����С�ڱ߽�ֵ����û�и�ֵ������ֵ
        while(i+1<m&&!screw[i+1][j])    screw[++i][j]=num[k++];//�����£����С�ڱ߽�ֵ����û�и�ֵ������ֵ
        while(i-1>=0&&!screw[i-1][j])   screw[--i][j]=num[k++];//���������С�ڱ߽�ֵ����û�и�ֵ������ֵ
        while(j-1>=0&&!screw[i][j-1])   screw[i][--j]=num[k++];//�����ϣ����С�ڱ߽�ֵ����û�и�ֵ������ֵ
    }
    /*
    while(d<N)
    {
        for(j;j<length&&jz[i][j]==0;j++)
        {
            jz[i][j] = num[d++];
            printf("%d %d %d\n",i,j,jz[i][j]);
        }

        j--;
        printf("%d %d\n",i,j);
        for(i;i<width&&jz[i][j]==0;i++)
        {
            jz[i][j] = num[d++];
            printf("%d %d %d\n",i,j,jz[i][j]);
        }

        i--;
        for(j;j>=0&&jz[i][j]==0 ; j--)
            jz[i][j] = num[d++];
        j++;
        for(i;i--&&jz[i][j]==0 ; i++)
            jz[i][j] = num[d++];
        i++;
    }*/
  //  for(i=0 ; i<width ; i++)                //����ĳ�ʼ��û������
 //   {
 //       for(j=0 ; j<length ; j++)
 //           printf("%d%c",jz[i][j],j!=length-1?' ':'\n');
   // }
//    i=0, j=0;
/* ����
    for(d=0 ; d<N ;d++)
    {
        jz[i][j] = num[d];
        printf("%d %d %d\n",i,j,jz[i][j]);
        if(j<length-1 && j>=0 && jz[i][j+1]==0)
            j++;
        else if(i<width-1 && i>=0 &&jz[i+1][j]==0)
            i++;
        else if(j<=length-1 && j>0 &&jz[i][j-1]==0)
            j--;
        else if(i<=width-1 && i>0 &&jz[i-1][j]==0)
            i--;
    }
*/
    /*  ������ѭ��*
    while(d<N)
    {
        while(j<length&&jz[i][j+1]!=0)
        {
            jz[i][j] = num[d];
            printf("%d %d %d",i,j,jz[i][j]);
            j++;
            d++;
        }
        j--;
        while(i<width && jz[i][j]!=0)
        {
            jz[i][j] = num[d];
            printf("%d %d %d",i,j,jz[i][j]);
            i++;
            d++;
        }
        i--;
        while(j>=0 && jz[i][j]!=0)
        {
            jz[i][j] = num[d];
            printf("%d %d %d",i,j,jz[i][j]);
            d++;
            j--;
        }
        j++;
        while(i>0 && jz[i][j] != 0)
        {
            jz[i][j] = num[d];
            printf("%d %d %d",i,j,jz[i][j]);
            d++;
            i--;
        }
        i++;
    }
    */
/*
    for(i=0 ; i<width ; i++)
    {
        for(j=0 ; j<length ; j++)
            printf("%d%c",screw[i][j],j!=length-1?' ':'\n');
    }
    return 0;

}


void bubble_sort(int * a, int n)
{
    int i,j; //����ѭ������
    int change; //y�����жϵڶ���ѭ�����Ƿ����Ԫ�ػ�������
    int k; //����Ԫ�ػ���
    for(i = n-1 , change = 1 ; i>=1 && change ; i--)
    {
        change = 0;
        for (j=0 ; j<n-1 ; j++)
        {
            if(a[j]<a[j+1])
            {
                k = a[j];
                a[j] = a[j+1];
                a[j+1] = k;
                change = 1;
            }
        }
    }
}

void l_w(int z, int * l, int *w)
{

    int m = sqrt(z);
    int i = m;
    while(z % i)
        i--;
    *l = i;
    *w = z/i ;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {return *(int*)b - *(int*)a;}

int main()
{
    int N, m, n;
    scanf("%d", &N);

    int *array = (int*)malloc(N * sizeof(int));
    int *matrix = (int*)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++)
        scanf("%d", array + i);

    qsort(array, N, sizeof(int), cmp);

    // determine m and n
    for(m = 1; !(m * m >= N && N % m == 0); m++) ;
    n = N / m;

    int x = -1, y = 0, index = 0;
    int horizontal = n, virtical = m;

    while(horizontal > 0 && virtical > 0)
    {
        for(int i = 0; i < horizontal && virtical > 0; i++)  // toward right
            matrix[y * n + ++x] = array[index++];
        virtical--;

        for(int i = 0; i < virtical && horizontal > 0; i++)  //toward bottom
            matrix[++y * n + x] = array[index++];
        horizontal--;

        for(int i = 0; i < horizontal && virtical > 0; i++)  //toward left
            matrix[y * n + --x] = array[index++];
        virtical--;

        for(int i = 0; i < virtical && horizontal > 0; i++)  // toward top
            matrix[--y * n + x] = array[index++];
        horizontal--;
    }

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            printf("%d%c", matrix[i * n + j], j == n - 1 ? '\n' : ' ');

    return 0;
}

*/
