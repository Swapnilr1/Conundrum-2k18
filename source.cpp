#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct cities
{
    pair <ll,ll> coordinates;
    bool visited;
    double price; 
};

double distance(cities c1, cities c2)
{
    double dist = sqrt(pow((c1.coordinates.first - c2.coordinates.first), 2) + pow((c1.coordinates.second - c2.coordinates.second), 2));
    return dist;
}

void solve(int sp, vector <cities>& v)
{   
    int i = sp;
    double petrol = 0, ccost, excost, petreq, petuse, petrem, petbuy;
    while(v.size() > 1)
    {   
        int x = 0;
        if(!i)
            x = 1;
        double mindist = distance(v[i], v[x]), cdist;    
        for(int j = 0; j < v.size(); j++)
        {
            cdist = distance(v[i], v[j]);
            if(cdist && (cdist < mindist))
            {
                x = j;
                mindist = cdist;
            }
        }
        petreq = mindist/10;
        if( petreq > 30 )
            petreq = 30;
        if(v[i].price > 6)
        {
            petuse = (petreq < petrol)?petreq:petrol;
            petrol = petrol - petuse;
            cout<<i+1<<","<<v[i].price<<","<<0<<"\n" ;
            v.erase(v.begin()+i) ;
            i = x;
            continue;
        }
        if(v[i].price < v[x].price)
        {
            petbuy = 30 - petrol;
            if(petreq > 30)
                petrol = 0;
            else
                petrol = 30 - petreq;
            v.erase(v.begin()+i) ;    
            cout<<i+1<<","<<v[i].price<<","<<petbuy<<"\n";    
            i = x;
            continue;
        }
        petbuy = (petreq > petrol)?(petreq-petrol):0 ;
        if(petreq > petrol)
            petrol = 0;
        else
            petrol = petrol - petreq; 
        cout<<i+1<<","<<v[i].price<<","<<petbuy<<"\n"; 
        v.erase(v.begin()+i) ;   
        i = x;
        continue;     
    }
    double cdist = distance(v[sp], v[i]) ;
    petreq = cdist/10;
    if(petreq > 30)
        petreq = 30;
    petbuy = (petreq > petrol)?(petreq-petrol):0 ;
    cout<<i+1<<","<<v[i].price<<","<<petbuy<<"\n";
    return ;
}

int main()
{
    vector <cities> v(500);
    int mini = 0; //index for min priced city
    double minprice; //min price for cities
    char c;
    for(int i = 0; i < 500; i++)
    {
        cin>>v[i].coordinates.first>>c>>v[i].coordinates.second;
        v[i].visited = false;
    }
    for(int i = 0; i < 500; i++)
    {
        cin>>v[i].price;
    }
    minprice = v[0].price ;
    //now finding the city with minimum price
    for(int i = 1; i < 500; i++)
    {
        if(v[i].price < minprice)
        {
            minprice = v[i].price ;
            mini = i ;
        }
    }
    solve(mini, v) ;
    return 0 ;
}
