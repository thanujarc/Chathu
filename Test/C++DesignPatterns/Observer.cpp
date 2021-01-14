#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Observes the changing entity
class Observer{
    public:
    virtual void update(int, int )=0;

};

// The changing entity
class Subject{
    public:
        virtual void Attach(Observer * observer)=0; //attach an observer
        virtual void Detach(Observer * observer)=0; //detach an observer
        virtual void Update(int, int)=0; //detach an observer
    protected:    
    virtual void Notify()=0;//Notify an observer;

};

class Timer:public Subject{
    protected:
        vector<Observer *> _observers;
        int _minutes, _hours;
        
        void Notify(){
            for (auto observer: _observers){
                observer->update(_minutes, _hours);
            }

        }
    public:
        Timer(){
            _minutes=0;
            _hours=0;
        }
        void Attach(Observer * observer){
            _observers.push_back(observer);
            observer->update(_minutes, _hours);
        }

        void Detach(Observer * observer){
            auto iterator = find(_observers.begin(), _observers.end(), observer);
            if (iterator != _observers.end())
            {
              _observers.erase(iterator);
            }     
        }

        

        void Update(int minutes,int hours){
            _minutes=minutes;
            _hours=hours;
            Notify();//Notify the observers of the changes

        }
};



//Bell_A observes the changes in the Subject and does something
class Bell_A:public Observer{
    public:
    void update(int _minutes, int _hours){
        checkRingBell(_minutes, _hours);
    };

    protected:
    void checkRingBell(int _minutes, int _hours){
        if (_minutes ==5 && _hours ==3){
            cout<<"Bell-A ringing"<<endl;
        }
    }
};

//Bell_B observes the changes in the Subject and does something
class Bell_B:public Observer{
    public:
    void update(int _minutes, int _hours){
        checkRingBell(_minutes, _hours);
    };

    protected:
    void checkRingBell(int _minutes, int _hours){
        if (_minutes ==7 && _hours ==3){
            cout<<"Bell-B ringing"<<endl;
        }
    }
};

int main(){
    Subject * subject =new Timer();
    
    Observer * observer1 = new Bell_A();
    Observer * observer2=new Bell_B();

    //attaching observers
    subject->Attach(observer1);
    subject->Attach(observer2);

    //making a change in the subject
    subject->Update(7,3);

    delete subject;
    delete observer1;
    delete observer2;

}