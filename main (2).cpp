//
//  main.cpp
//  quiz1
//
//  Created by junyeong on 2018. 4. 6..
//  Copyright © 2018년 junyeong. All rights reserved.
//

#include <iostream>

using namespace std;

#define NUM 2

struct Stscore
{
    int classnum;
    int score;
};

void inputScore(Stscore *score, int size);
double calMean(Stscore *score, int size);
void outputScore(Stscore *score, double mean, int size);

int main(void)
{
    
    double mean;
    Stscore score[NUM];
    
    inputScore(score, NUM);
    mean = calMean(score, NUM);
    outputScore(score, mean, NUM);
    
    return 1;
    
}

void inputScore(Stscore *score, int size)
{
    cout << "input student id and score" << endl;
    for(int i=0; i< size; i++)
    {
        cout <<"student ID" << endl;
        cin >> score[i].classnum;
        cout <<endl;
        cout << "score" << endl;
        cin >> score[i].score;
        cout << endl;
    }
}

double  calMean(Stscore *score, int size)
{
    double total = 0;
    for(int i = 0; i < size; i++)
    {
        total += score[i].score;
    }
    return total/size;
}

void outputScore(Stscore *score, double mean, int size)
{
    cout << "output student id and score" << endl;
    for(int i = 0; i < size; i++)
        cout << "student id : " << score[i].classnum << endl
             <<"score" << score[i].score << endl;
        
        cout << endl << "====== average of the class score ====== " << endl;
        cout << "average : " << mean << endl;
    
}
