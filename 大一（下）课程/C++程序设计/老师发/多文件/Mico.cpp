#include <iostream>
#include "Average.h"
using namespace std;

//#define _DEBUG_

extern int Number;

int 1main(void)
{
    int Score[STU_NUM];
    //float Average = 0;

    Number = 100;

    cout << "\nInput " << STU_NUM <<" Score";

    for(int i = 0; i < STU_NUM; i ++)
    {
        cin >> Score[i];
    }
#if 1
    cout << "Score[0] = " << Score[0] << "\n";
    cout << "Score[STU_NUM-1] = " << Score[STU_NUM-1] << "\n";
#else
    cout << "Score = " << Score[0] << "\n";
    cout << "Score = " << Score[STU_NUM-1] << "\n";
#endif

    cout << "Average = " << Average(Score, STU_NUM);

    return 0;
}