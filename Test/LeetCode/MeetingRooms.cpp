#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<set>

using namespace std;

int stringToTime(string a, char  seperator){
    const int minsPerHour=60;
    size_t pos=a.find(seperator);
    int hours=0;
    int mins=0;
    if (pos!=string::npos){
        hours=stoi(a.substr(0,pos));
        mins=stoi(a.substr(pos+1,a.size()-pos));
    }
    else{
        hours=stoi(a);
    }
    return hours*minsPerHour+mins;

}

struct Comparator{
 bool operator()(vector <float>& a, vector <float>& b){
 return !(a[1] < b[1]);
 }
};

bool findGreater(vector<float> a, vector<float> b){
    return a[0]<b[0];
}
bool compareF(vector<float> a, vector<float> b){
    return a[1]>b[1];
}
bool checkOverlap(vector<float> a, vector<float> b){
    return (a[0]<=b[0] && a[1]>b[0] ) ;// no need to compare the second boundry because there are sorted
}
int numOfRooms2(vector<vector<float>> & meetings){
    if(meetings.empty()){
        return 0;
    }
    auto cmp=[](vector<float> a, vector<float> b){return a[1]<b[1];};
    //priority_queue<vector<float>, vector<vector<float>>, decltype(cmp)> pq;
    //priority_queue<vector<float>, vector<vector<float> >, Comparator> pq;
    set<int> intset;
    sort(meetings.begin(),meetings.end(),findGreater);
    int meetingRooms=0;

        for(size_t id=0;id<meetings.size();id++){//n
             vector<float> interval=meetings[id];
            //while(!pq.empty() && pq.top()[1]<=interval[0]){
            //    cout<<id<<" "<<pq.top()[0]<<" "<<pq.top()[1]<<endl;
            //    pq.pop();
            //}
            while(!intset.empty() && *(prev(intset.end()))<=interval[0]){
                intset.erase(prev(intset.end()));
            }
            //pq.push(interval); //log(n)
            intset.insert(interval[1]);
            //meetingRooms=max(meetingRooms,(int)pq.size());
            meetingRooms=max(meetingRooms,(int)intset.size());
            
        }

        return meetingRooms;

}

int numOfRooms(vector<vector<float>> & meetings){
    if(meetings.empty()){
        return 0;
    }
    sort(meetings.begin(),meetings.end(),findGreater);
    int meetingRooms=1;
        for(size_t id=0;id<meetings.size();id++){
            vector<float> interval=meetings[id];
            int id_comp=id-1;
            int tempNRooms=1;
            while(id_comp>=0){
                
               cout<<meetings[id_comp][0]<<" "<<meetings[id_comp][1]<<" : "<<interval[0]
               <<" "<<interval[1] << " ovelap "<<checkOverlap(meetings[id_comp],interval)<<endl;
               if(checkOverlap(meetings[id_comp],interval)){ //if there is an overlap
                 tempNRooms=tempNRooms+1;                
               }
               id_comp--;            
               //else{//exit the while loop at the first point of no overlap;
                  // break;
               //}
            }
            meetingRooms=meetingRooms>tempNRooms?meetingRooms:tempNRooms;
        }

        return meetingRooms;

}


int main(){
    char seperator='.';
    vector<vector<float>> input{{10,14},{11,13},{11.3,15},{16,17},{17,18},{17.3,18}};
    cout<<"N rooms "<<numOfRooms2(input)<<endl;
    //cout<<stringToTime("10",seperator);
    
}
