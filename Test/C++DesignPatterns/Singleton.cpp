#include <iostream>
using namespace std;
class Leader{
    private:
        static Leader * _leader;
        Leader(){};
    
    public:
        static Leader* getInstance(){
            if (_leader == NULL){
                _leader=new Leader();
            }
            return _leader;

        }
        void giveSpeech(){
            cout<<"HII"<<endl;
        }
     
};

//this is still from inside the class
Leader* Leader::_leader=NULL;


int main(){
    Leader * myLeader= Leader::getInstance();
    myLeader->giveSpeech();
}