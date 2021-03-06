/*
1004 成绩排名 (20)（20 分）
读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

输入格式：每个测试输入包含1个测试用例，格式为\

  第1行：正整数n
  第2行：第1个学生的姓名 学号 成绩
  第3行：第2个学生的姓名 学号 成绩
  ... ... ...
  第n+1行：第n个学生的姓名 学号 成绩
其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。

输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。

输入样例：

3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
输出样例：

Mike CS991301
Joe Math990112
*/

#include <iostream>
using namespace std;

int main()
{
    string max_name,max_id,min_name,min_id;//分别代表最高分和最低分的姓名和学号
    int max_score = 0,min_score = 101;
    string name,id;//分别代表输入姓名和学号
    int score,N; //分别代表分数和学生人数
    cin>>N;
    int i;
    for(i=0 ; i<N ; i++)
    {
        cin>>name>>id>>score;
        if(score > max_score)
        {
            max_name = name;
            max_id = id;
            max_score = score;
        }
        if(score < min_score)
        {
            min_name = name;
            min_id = id;
            min_score = score;
        }
    }
    cout<<max_name<<" "<<max_id<<"\n";
    cout<<min_name<<" "<<min_id<<"\n";
    return 0;
}
