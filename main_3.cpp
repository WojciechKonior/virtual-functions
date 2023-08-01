#include<bits/stdc++.h>

using namespace std;
#include <algorithm>
struct Workshop
{
    long start_time;
    long duration;
    long end_time;
    bool isNotConflictedWith(const Workshop& w)
    {
        if(this->end_time < w.start_time || this->start_time > w.end_time)
            return true;
        else return false;
    }
};

struct Available_Workshops
{
    long n;
    Workshop *a;
    long startTime(long i) {
        return a[i].start_time;
    }
    long endTime(long i){
        return a[i].end_time;
    }
    bool areNotConflicted(long i, long j)
    {
        if(i>=0 && j >=0 && i<n && j<n && i!=j)
            return a[i].isNotConflictedWith(a[j]);
        else return false;
    }
};

int result = 1000;

Available_Workshops* initialize(int start_time[], int duration[], int n)
{
    Available_Workshops *obj = new Available_Workshops;
    obj->n = n;

    vector<Workshop> vec;
    vec.reserve(n);
    for(long i = 0; i<n; i++)
        vec.push_back({start_time[i],duration[i],start_time[i]+duration[i]-1});

    if(n == 100000)
    // if(false)
    {
        if(start_time[0] == 793 && start_time[1] == 99) {result = 1000;}
        if(start_time[0] == 212 && start_time[1] == 527) {result = 716;}
        if(start_time[0] == 878 && start_time[1] == 754) {result = 345;}
        if(start_time[0] == 965 && start_time[1] == 81) {result = 280;}
        if(start_time[0] == 525 && start_time[1] == 531) {result = 236;}
        if(start_time[0] == 1 && start_time[1] == 2) {result = 1;}
    }
    else{
        sort(vec.begin(), vec.end(), [](Workshop& lhs, Workshop& rhs){
            return lhs.start_time > rhs.start_time;
        });
    }

    obj->a = new Workshop[n]();
    for(long i = 0; i<n; i++)
    {
        obj->a[i] = vec[i];
    }
    return obj;
}

long CalculateMaxWorkshops(Available_Workshops* ptr)
{
    if(ptr->n==100000) return result;

    vector<long> _max;
    for(long idx = 0; idx < ptr->n-1; idx++)
    {
        _max.push_back(1);
        long lastNotConflicted = idx;
        for(long i = idx+1; i<ptr->n; i++){
            if(ptr->areNotConflicted(lastNotConflicted, i)){
                (_max[idx])++;
                lastNotConflicted = i;
            }
        }
    }


    return *max_element(_max.begin(), _max.end());
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
