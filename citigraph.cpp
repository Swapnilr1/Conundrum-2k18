#include <bits/stdc++.h>
using namespace std;

struct point
{
    double x;
    double y;
};

double distance(point p1, point p2)
{
    double dist = sqrt((double)pow((p1.x - p2.x), 2) + (double)pow((p1.y - p2.y), 2));
    return dist;
}

int main()
{
    point p[500] ;
    char c;
    for(int i = 0; i < 500; i++)
    {
        cin>>p[i].x>>c>>p[i].y;
    }
    double citigraph[500][500];
    for(int i = 0; i < 500; i++)
    {
        for(int j = 0; j < 500; j++)
        {
            citigraph[i][j] = distance(p[i], p[j]);
        }
    }
    
}