#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int a,b,sum,t = 0 ; //�������
    char c;
    cin>>a>>b;
    sum = a + b ;
    string res = "",res_2 = "";
    bool flag = true;
    if(sum < 0) //�ж��Ƿ�Ϊ��
    {
        res_2 = "-";
        sum = -sum;
    }
    do
    {
        c = '0' + sum%10;
        res = c + res;
        sum /= 10;
    }while(sum);      //ʹ��do..while �ܹ���Ч��ֹsumһ��ʼΪ0�����
    int l = res.length();
    int temp = l%3;
    for(int i=0 ; i<temp ; i++)
    {
        res_2 = res_2 + res[i];
    }   //�ʼ������
    for(int i=temp ; i<l ; i++)
    {
        if((i-temp)%3==0 && i!=l-1 && i!= 0)
            res_2 = res_2 + ',';
        res_2 = res_2 + res[i];
    } //֮����Ҫ�ӡ����� �����
    cout<<res_2;
    return 0;
}
