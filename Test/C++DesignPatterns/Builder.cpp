#include <iostream>
using namespace std;

//Creating a combo meal

class Entree{
    protected:
        string _name;
        Entree(){};
    public:
        string gerEntree(){
            return _name;
        }


};

class Burger:public Entree{
    public:
        Burger(){
            _name="Burger";
            //other steps for making it
        };
};

class HotDog:public Entree{
    public:
        HotDog(){
            _name="Hotdog";
            //other steps for making it
        }


};
class Side{
    protected:
        string _name;
        Side(){};
    
    public:
        string getName(){
            return _name;
        }

};

class Salad:public Side{
    public:
        Salad(){
            _name="Salad";
            //do other steps for makeing the salad
        }
};

class Fries:public Side{
    public:
        Fries(){
            _name="Fries";
            //do other steps for makeing the salad
        }
      
};

class Drink{
    private:
        string _name="water";
    public:
        Drink(){};
        string getName(){
            return _name;
        }

};

//Product
class Meal{
    protected:
        Entree* entree;
        Side* side;
        Drink* drink;
        string name;
    public:
        Meal(string n):name(n){};
        void setEntree(Entree * E){
            entree=E;
        };
        
        void setSide(Side * S){
            side=S;
        };
        void setDrink(Drink * d){
            drink=d;
        };

        void printMeal(){
            cout<<"Meal name : "<<name.c_str()<<endl;
            cout<<"Entree : "<<entree->gerEntree().c_str()<<endl;
            cout<<"Side : "<<side->getName().c_str()<<endl;
            cout<<"Drink : "<<drink->getName().c_str()<<endl;
        }
};

//Builder   - Abstract

class MealBuilder{
    protected:
    Meal * meal;
    public :
    virtual void buildEntree()=0;
    virtual void buildSide()=0;
    virtual void buildDrink()=0;

    Meal * getMeal(){
        return meal;
    }
};

//Builder   - Concrete
class HoltdogMealBuilder:public MealBuilder{
    public: 
        HoltdogMealBuilder(){
            meal=new Meal("HotDog meal");
        };
        void buildEntree(){
            meal->setEntree(new HotDog());
        };

        void buildSide(){
            meal->setSide(new Fries());
        };

        void buildDrink(){
            meal->setDrink(new Drink());
        };
};

//Builder   - Concrete
class BurgerMealBuilder:public MealBuilder{
    public: 
        BurgerMealBuilder(){
            meal=new Meal("Burger meal");
        };
        void buildEntree(){
            meal->setEntree(new Burger());
        };

        void buildSide(){
            meal->setSide(new Salad());
        };

        void buildDrink(){
            meal->setDrink(new Drink());
        };
};

//Director - calls the abstract methods in the Builder class
class Cook{
    public:
        Cook(){};
        Meal* ConstructMeal(MealBuilder * mealBuilder){
            mealBuilder->buildDrink();
            mealBuilder->buildEntree();
            mealBuilder->buildSide();
            return mealBuilder->getMeal();
        };
    

};
int main(){
    MealBuilder * mealBuilder= new BurgerMealBuilder();
    Cook * cook=new Cook();
    Meal* meal= cook->ConstructMeal(mealBuilder);
    meal->printMeal();
    
    

}