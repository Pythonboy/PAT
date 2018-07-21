/*
1141 PAT Ranking of Institutions（25 分）
After each PAT, the PAT Center will announce the ranking of institutions based on their students' performances. Now you are asked to generate the ranklist.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤10
​5
​​ ), which is the number of testees. Then N lines follow, each gives the information of a testee in the following format:

ID Score School
where ID is a string of 6 characters with the first one representing the test level: B stands for the basic level, A the advanced level and T the top level; Score is an integer in [0, 100]; and School is the institution code which is a string of no more than 6 English letters (case insensitive). Note: it is guaranteed that ID is unique for each testee.

Output Specification:
For each case, first print in a line the total number of institutions. Then output the ranklist of institutions in nondecreasing order of their ranks in the following format:

Rank School TWS Ns
where Rank is the rank (start from 1) of the institution; School is the institution code (all in lower case); ; TWS is the total weighted score which is defined to be the integer part of ScoreB/1.5 + ScoreA + ScoreT*1.5, where ScoreX is the total score of the testees belong to this institution on level X; and Ns is the total number of testees who belong to this institution.

The institutions are ranked according to their TWS. If there is a tie, the institutions are supposed to have the same rank, and they shall be printed in ascending order of Ns. If there is still a tie, they shall be printed in alphabetical order of their codes.

Sample Input:
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu
Sample Output:
5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Collenge
{
    string Name;
    float total_score = 0;
    int total_num = 0;
    int score;
    int rk;
};

bool cmp(struct Collenge a,struct Collenge b)
{
    if(a.score!=b.score)
        return a.score > b.score;
    else if(a.total_num!=b.total_num)
        return a.total_num < b.total_num;
    else
        return a.Name < b.Name;
}

int main()
{
    int N;
    cin>>N;
    vector<struct Collenge>Rank;
    map<string,int>ID;
    int i;
    int j = 0;
    for(i=0 ; i<N ; i++)
    {
        string na,sc;
        int sco;
        cin>>na>>sco>>sc;
        for(auto &k : sc)
            k = tolower(k);
        if(ID.count(sc)!=0)
        {
            int id = ID[sc];
            Rank[id].total_num++;
            switch(na[0])
            {
            case 'T':
                Rank[id].total_score += sco * 1.5;
                break;
            case 'A':
                Rank[id].total_score += sco;
                break;
            case 'B':
                Rank[id].total_score += (sco/1.5);
                break;
            }
        }
        else
        {
            struct Collenge temp;
            temp.Name = sc;
            temp.total_num++;
            switch(na[0])
            {
            case 'T':
                temp.total_score += sco * 1.5;
                break;
            case 'A':
                temp.total_score += sco;
                break;
            case 'B':
                temp.total_score += (sco/1.5);
                break;
            }
            Rank.push_back(temp);
            ID[sc] = j++;
        }
    }
    int len = Rank.size();
    for(i=0 ; i< len ; i++)
        Rank[i].score = (int)(Rank[i].total_score);
    sort(Rank.begin(),Rank.end(),cmp);
    for(i=0 ; i<len ; i++)
    {
        if(i==0)
            Rank[i].rk = i+1;
        else
        {
            if(Rank[i].score==Rank[i-1].score)
                Rank[i].rk = Rank[i-1].rk;
            else
                Rank[i].rk = i+1;
        }
    }
    cout<<len<<"\n";
    for(i=0 ; i<len ; i++)
        cout<<Rank[i].rk<<" "<<Rank[i].Name<<" "<<Rank[i].score<<" "<<Rank[i].total_num<<"\n";
    return 0;
}
