#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

vector< vector<int> > merge(vector< vector<int> > &intervals)
{
    vector< vector<int> > result;
    for (int i = 0; i < intervals.size(); i++)
    {
        vector<int> left = intervals[i];
        int lleft = left[0];
        int rleft = left[1];
        for (int i = i + 1; i < intervals.size(); i++)
        {
            vector<int> right = intervals[i];
            int lright = right[0];
            int rright = right[1];
            if (rleft < lright)
            {
                result.push_back(left);
                --i;
                break;
            }
            else if (rleft < rright)
            {
                vector<int> tempvec;
                tempvec.push_back(lleft);
                tempvec.push_back(rright);
                result.push_back(tempvec);
                break;
            }
        }
    }
    return result;
}


int main()
{
    
    vector< vector<int> > interval;
    int n;
    cout <<"input:" << endl;
    while (cin >> n)
    {
        for (size_t i = 0; i < n; i++)
        {
            vector<int> v;
            int v1,v2;
            cin >> v1 >> v2;
            v.push_back(v1);
            v.push_back(v2);
            interval.push_back(v);
        }
        vector< vector<int> > result = merge(interval);
        cout<< "output:"<<endl;
        for (int i = 0; i < result.size(); i++){
            vector<int> vec = result[i];
            printf("[%d, %d] ",vec[0],vec[1]);
        }
    }
}