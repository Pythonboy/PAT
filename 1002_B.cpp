/*
1002 д������� (20)��20 �֣�
����һ����Ȼ��n���������λ����֮�ͣ��ú���ƴ��д���͵�ÿһλ���֡�

�����ʽ��ÿ�������������1��������������������Ȼ��n��ֵ�����ﱣ֤nС��10^100^��

�����ʽ����һ�������n�ĸ�λ����֮�͵�ÿһλ��ƴ�����ּ���1 �ո񣬵�һ�������һ��ƴ�����ֺ�û�пո�

����������

1234567890987654321123456789
���������

yi san wu
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    string res[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    cin>>a;
    int i,sum=0;
    for(i=0 ; i<a.size() ; i++)
        sum += (a[i] - '0');
    a = to_string(sum);
    for(i=0 ; i<a.size() ; i++)
        i == a.size()-1 ? cout<<res[a[i]-'0'] : cout<<res[a[i]-'0']+" ";
    return 0;
}
