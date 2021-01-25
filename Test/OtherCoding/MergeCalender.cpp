//Merging calender of 2 people and finding common free slots for both
#include <iostream>
#include<vector>
using namespace std;

struct Interval{
    int start;
    int end;
    Interval(int _start, int _end){
        start=_start;
        end=_end;
    };
};

//this is to practice merging . Merging is not needed for this particular problem
vector<Interval *> mergePractice( vector<Interval> C1, vector<Interval>  C2, int daystart, int dayend){
    int pointer1=0;//points to C1
    int pointer2=0;//points to C2
    vector<Interval> sortedCalender;
    vector<Interval *> mergedCalender;
    vector<Interval *> freeTimes;

    //first merge bease of increasing start time
        while(pointer1<C1.size() && pointer2<C2.size()){
            Interval I1=C1[pointer1];
            Interval I2=C2[pointer2];
            if(I1.start>I2.start){
                    sortedCalender.push_back(I2);
                    pointer2=pointer2+1;
            }
            else {
                sortedCalender.push_back(I1);
                pointer1=pointer1+1;
            }
        }
        while(pointer1<C1.size()){
            sortedCalender.push_back(C1[pointer1]);
            pointer1++;
        }

        while(pointer2<C2.size()){
            sortedCalender.push_back(C2[pointer2]);
            pointer2++;
        }


    
    //I1=10-11, I2- 9-13;  mod I1 9-13 
    //I1=12-13, I2- 13-14;
    //edit C1 
        bool merging=true;
        int index=0;
        int start=sortedCalender[0].start;
        int end=sortedCalender[0].end;
        //while(merging){
        for (unsigned int i=1;i<sortedCalender.size();i++){
            Interval I=sortedCalender[i];    
            //check if the inetrvals does not overlap
            if((end<I.start ) ){ //intervals does not overlap.
                
                mergedCalender.push_back(new Interval(start,end));
                start=I.start;
                end=I.end;
            }
            else{ //intervals overlap. keep editing the end until a non overlapping item is found;
                end=end<I.end?I.end:end;
            }


        }
        //push the last item
        mergedCalender.push_back(new Interval(start,end));
        //deal with day start
        if(mergedCalender[0]->start != daystart){
            freeTimes.push_back(new Interval(daystart,mergedCalender[0]->start));
        }

        
        
        for (int i=1;i<mergedCalender.size();i++){
            freeTimes.push_back(new Interval(mergedCalender[i-1]->end,mergedCalender[i]->start));
        }

        //deal with the day end

        if(mergedCalender[mergedCalender.size()-1]->end != dayend){
            freeTimes.push_back(new Interval(mergedCalender[mergedCalender.size()-1]->end,dayend));
        }

return freeTimes;  

};

vector<Interval *> mergeCalaenders( vector<Interval> C1, vector<Interval>  C2, int daystart, int dayend){
    int pointer1=0;//points to C1
    int pointer2=0;//points to C2
    vector<Interval> sortedCalender;
    vector<Interval *> mergedCalender;
    vector<Interval *> freeTimes;

    //first merge based of increasing start time
        while(pointer1<C1.size() && pointer2<C2.size()){
            Interval I1=C1[pointer1];
            Interval I2=C2[pointer2];
            if(I1.start>I2.start){
                    sortedCalender.push_back(I2);
                    pointer2=pointer2+1;
            }
            else {
                sortedCalender.push_back(I1);
                pointer1=pointer1+1;
            }
        }
        while(pointer1<C1.size()){
            sortedCalender.push_back(C1[pointer1]);
            pointer1++;
        }

        while(pointer2<C2.size()){
            sortedCalender.push_back(C2[pointer2]);
            pointer2++;
        }

        //find the non overlaping intervals
        int end =daystart;
        Interval last(dayend,dayend);
        sortedCalender.push_back(last);
        for(size_t i=0; i<sortedCalender.size();i++){
            if(sortedCalender[i].start>end){ //non overlping interval
              freeTimes.push_back(new Interval(end,sortedCalender[i].start));
              end=sortedCalender[i].end;
            }
            else{ //overlaping interval
                end=end<sortedCalender[i].end?sortedCalender[i].end:end;
            }

        }

        return freeTimes;

}



int main(){
    int day_start=9;
    int day_end=21;
    //ans = 
    //9-10, 11-12,14-16
    vector<Interval> Calender_1;
    Interval I1(10,21);
    //Interval I2(12,13);
    //Interval I3(16,21);
    Calender_1.push_back(I1);
    //Calender_1.push_back(I2);
    //Calender_1.push_back(I3);
     
    vector<Interval> Calender_2;
    Interval I4(12,14);
    Interval I5(17,18);
    Interval I6(20,21);
    Calender_2.push_back(I4);
    Calender_2.push_back(I5);
    Calender_2.push_back(I6);
    
    //merge 2 calenders
     vector<Interval *> Calender_3=mergeCalaenders( Calender_1, Calender_2, day_start,day_end);
     for(int i=0;i<Calender_3.size();i++){
         cout<<"start "<<Calender_3[i]->start<<", end"<<Calender_3[i]->end<<endl;
     }
    
    //find the free slots in the merged calender

}
