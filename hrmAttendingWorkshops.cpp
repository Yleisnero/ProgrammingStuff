#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
struct Workshop{
    int start_time, duration, end_time;
};

struct Available_Workshops{
    int n;
    vector<Workshop> Av_Ws_Vector;
};

//Implement the functions initialize and CalculateMaxWorkshops
Available_Workshops* initialize (int start_time[], int duration[], int n){
    Available_Workshops *avWorkshops = new Available_Workshops();
    avWorkshops->n = n;
    Workshop ws;
    for(int i = 0; i < n; i++){
        ws.start_time = start_time[i];
        ws.duration = duration[i];
        ws.end_time = start_time[i] + duration[i]; 
        avWorkshops->Av_Ws_Vector.push_back(ws);
    }
    return avWorkshops;
}

bool compare(Workshop w1, Workshop w2){ //source: https://www.hackerrank.com/challenges/attending-workshops/forum
    return (w1.end_time < w2.end_time); 
}

int CalculateMaxWorkshops(Available_Workshops* ptr){
    
    sort(ptr->Av_Ws_Vector.begin(), ptr->Av_Ws_Vector.end(), compare); 
    
    int cur_end_time = 0;
    int maxWorkshops = 0;
    for(int i = 0; i < ptr->n; i++){
        if(ptr->Av_Ws_Vector[i].start_time >= cur_end_time){
            cur_end_time = ptr->Av_Ws_Vector[i].end_time;
            maxWorkshops++;
        }
    }
    return maxWorkshops;
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
