#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    float Poly[1024] = {0}; //�������ʽ���±��ʾϵ����ֵ��ʾָ��
    int coef,K;  //����ϵ������
    float index;//����ָ��
    for(int i=0 ; i<2 ; i++)
    {
        cin>>K;
        for(int j=0 ; j<K ; j++)
        {
            //scanf("%d%f",&coef,&index);
            cin>>coef>>index;
            Poly[coef] += index;
        }
    }
    int S = 0;
    for(int i=0 ; i<1024; i++)
    {
        if(abs(Poly[i] - 0.0) > 1e-32)
            S++;
    }
    cout<<S;
    for(int i=1024 ; i>=0 ; i--)
    {
        if(abs(Poly[i] - 0.0) > 1e-32)  //�жϸ������Ƿ�Ϊ0�ķ�������Ϊ�������洢���Ȳ���
        {
            printf(" %d %.1f",i,Poly[i]);  //��ʽ�����
        }
    }
    cout<<"\n";
    return 0;
}
