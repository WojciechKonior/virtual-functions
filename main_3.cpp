#include<bits/stdc++.h>

using namespace std;
#include <algorithm>
struct Workshop
{
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops
{
    int n;
    Workshop *a;
};

Available_Workshops* initialize(int start_time[], int duration[], int n)
{
    Available_Workshops *obj = new Available_Workshops;
    obj->n = n;
    obj->a = new Workshop[n]();
    for(int i = 0; i<n; i++)
    {
        obj->a[i].start_time = start_time[i];
        obj->a[i].duration = duration[i];
        obj->a[i].end_time = start_time[i] + duration[i];
    }
    return obj;
}

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    vector<int> count;
    for(int i = 0; i<ptr->n; i++){
        count.push_back(0);
        for(int j = 0; j<ptr->n; j++){
            if(i!=j){
                if(ptr->a[i].end_time >= ptr->a[j].start_time) count[i]++;
            }
        }
    }
    int max = 0;
    for(auto & c : count)
        if(c>max) max = c;
    return max;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
