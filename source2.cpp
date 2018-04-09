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
    double price[500];
    double petrol = 0, petbuy, petreq;
    int order[500];
    for(int i = 0; i < 500; i++)
    {
        cin>>order[i];
    }
    for(int i = 0; i < 500; i++)
    {
        cin>>price[i];
        /* */
        if (2*price[i]<=6)
        {
            price[i]*=1.25;
        }
    }
    for(int i = 0; i < 499; i++)
    {
        petreq = (citigraph[order[i]][order[i+1]])/10.0;
        if(price[order[i]] > 6)
        {
            petbuy = 0;
            petrol = (petrol < petreq)?0:(petrol - petreq);
        }
        else if(price[order[i]] <= price[order[i+1]])
        {
            petbuy = min(1.3*petreq - petrol, 30-petrol) ;
            if(petbuy < 0 )
            {
                petbuy = 0;
                petrol = petrol - petreq;
            }
            else
            {
                petrol += petbuy;
                petrol = (petrol < petreq)?0:(petrol-petreq);
            }
        }
        else
        {
            if(petrol >= petreq)
            {
                petbuy = 0;
                petrol = petrol - petreq;
            }

            else 
            {
                petbuy = (petreq < 30)?(petreq - petrol):(30 - petrol);
                petrol = 0;
            }
        }
        cout<<order[i]+1<<","<<price[order[i]]<<","<<petbuy<<"\n";
    }
    petreq = (citigraph[order[499]][order[0]])/10.0;
    
    if(price[order[499]] > 6)
    {
        petbuy = 0;
        petrol = (petrol < petreq)?0:(petrol - petreq);
    }
    
    else if( petrol > petreq )
    {
        petbuy = 0;
    }

    else
    {
        petbuy = (petreq < 30)?(petreq - petrol):(30 - petrol);
    }

    cout<<order[499]+1<<","<<price[order[499]]<<","<<petbuy<<"\n";
}