/*
1108 Finding Average (20)（20 分）
The basic task is simple: given N real numbers, you are supposed to calculate their average. But what makes it complicated is that some of the input numbers might not be legal. A "legal" input is a real number in [-1000, 1000] and is accurate up to no more than 2 decimal places. When you calculate the average, those illegal numbers must not be counted in.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=100). Then N numbers are given in the next line, separated by one space.

Output Specification:

For each illegal input number, print in a line "ERROR: X is not a legal number" where X is the input. Then finally print in a line the result: "The average of K numbers is Y" where K is the number of legal inputs and Y is their average, accurate to 2 decimal places. In case the average cannot be calculated, output "Undefined" instead of Y. In case K is only 1, output "The average of 1 number is Y" instead.

Sample Input 1:

7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
Sample Output 1:

ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
Sample Input 2:

2
aaa -9999
Sample Output 2:

ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdio.h>
using namespace std;

bool IsLegal(string m)
{
    auto i = m.begin();
    int cnt = 0;
    for( ; i<m.end();i++)
    {
        if(isalpha(*i))   //判断是否为字母
            return false;
        if(*i=='.')
        {
            cnt++;
            if(cnt>1)
                return false;
        }
    }
    float j = atof(m.c_str());   //将string转化为float类型
    if(j>1000||j<-1000)
        return false;
    return true;
}

bool xiaoshudian(string temp)    //判断小数点的位数
{
    auto i = temp.begin();
    int cnt = 0;
    for( ; i!=temp.end() ; i++)
    {
        if(*i=='.'||cnt!=0)
            cnt++;
    }
    cnt--;
    if(cnt>2)
        return false;
    else
        return true;
}

int main()
{
    int N;
    cin>>N;
    vector<float>num;
    int i;
    for(i=0 ; i<N ; i++)
    {
        string temp;
        cin>>temp;
        if(IsLegal(temp))
        {
            if(xiaoshudian(temp))
            {
                float j = atof(temp.c_str());
                num.push_back(j);
            }
            else
                cout<<"ERROR: "<<temp<<" is not a legal number\n";
        }
        else
        {
            cout<<"ERROR: "<<temp<<" is not a legal number\n";
        }
    }
    int l = num.size();
    if(l==0)
        cout<<"The average of 0 numbers is Undefined\n";
    else
    {
        float res = 0;
        for(i=0 ; i<l ; i++)
            res += num[i];
        if(l!=1)
            printf("The average of %d numbers is %.2f",l,res/l);
        else
            printf("The average of %d number is %.2f",l,res/l);
    }
    return 0;
}




//他山之玉
//柳婼
/*
sscanf() – 从一个字符串中读进与指定格式相符的数据
sprintf() – 字符串格式化命令，主要功能是把格式化的数据写入某个字符串中。
*/
#include <iostream>
#include <string.h>
using namespace std;
int main() {
    int n, cnt = 0;
    char a[50], b[50];
    double temp, sum = 0.0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%s", a);
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2lf",temp);
        int flag = 0;
        for(int j = 0; j < strlen(a); j++) {
            if(a[j] != b[j]) {
                flag = 1;
            }
        }
        if(flag || temp < -1000 || temp > 1000) {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        } else {
            sum += temp;
            cnt++;
        }
    }
    if(cnt == 1) {
        printf("The average of 1 number is %.2lf", sum);
    } else if(cnt > 1) {
        printf("The average of %d numbers is %.2lf", cnt, sum / cnt);
    } else {
        printf("The average of 0 numbers is Undefined");
    }
    return 0;
}
