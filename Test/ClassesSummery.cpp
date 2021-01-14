#include <iostream>
#include <memory>
using namespace std;
//class and inheritance and Builder pattern

struct Entree{
    string* name;
};

class Meal{

    protected:
        shared_ptr<Entree>  _entree;
        string* _name;
    
    public: 
        Meal(const string * name):_name(_name){
            cout<<"New meal"<<endl;
        };
        void set_entree(shared_ptr<Entree> entree){
            cout<<"setting entree"<<endl;
            _entree=entree;
        };
        string*  get_entree() const{
            return _entree->name;
        };
};

class MealBuilder{
    protected:
        shared_ptr<Meal> _meal;
        int cols=5;
        float * _a=new float[cols];
        MealBuilder(){}; //constructor
    public:
        virtual void prepareEntree()=0; 
        virtual ~MealBuilder(){  //destructor
            delete _a;
        };
        MealBuilder(const MealBuilder & rhs) {  //copy constructor
            //call copy constructor of the _meal
            _meal=rhs._meal; 
        };
         
};

class HotdogMealBuilder:public MealBuilder{
    private:
     string _name="Hot dog meal";
     float * _b=new float[cols];
    public:
        HotdogMealBuilder(){
           _meal= make_shared<Meal>(&_name);
        };
        void prepareEntree(){
            _meal->set_entree(make_shared<Entree>());
        }
        void setName(string name){ //setter method
            _name=name;
        }
        string getName() const{ //getter method
            return _name;
        }
        ~HotdogMealBuilder(){
            delete _b;
        };
        HotdogMealBuilder(const HotdogMealBuilder & rhs) {  //copy constructor
            _name=rhs.getName();
        };
};

class Cook{
    shared_ptr<MealBuilder> _mealBuilder;
    public:
        Cook(shared_ptr<MealBuilder> mealBuilder):_mealBuilder(mealBuilder){};
        void PrepareMeal(){
            _mealBuilder->prepareEntree();
            cout<<"Done preparing meal"<<endl;
        };

};

int main(){
    auto hotdogMealBuilder=make_shared<HotdogMealBuilder>();
    auto cook = make_shared<Cook>(hotdogMealBuilder);
    cook->PrepareMeal();
}