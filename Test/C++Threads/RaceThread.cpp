#include <thread>
#include <chrono>
#include<mutex>
#include <atomic>

//method one:using mutexes
int garlic_to_buy = 0;
std::mutex pencil;

//method 2 : using atomic variables
std::atomic<unsigned int> carrots_to_buy(0);

//passing mutexes by reference
int sushi_count=5000;


void add_garlic(){
    
    for (int i=0 ;i<50000 ;i++){
        pencil.lock();
        garlic_to_buy++;
        pencil.unlock();
    }
     for (int i=0 ;i<50000 ;i++){
         carrots_to_buy++;
     }
    
}

//passing mutex by reference
void philosopher(std::mutex &chopstick){
    int sushi_eaten=0;
    while (sushi_count>0){
        chopstick.lock();
        sushi_count--;
        sushi_eaten++; 
        chopstick.unlock();
    }
    printf("thread id %d , sushi eaten %d \n", std::this_thread::get_id(),sushi_eaten);
}

int main(){
    std::thread A (add_garlic);
    std::thread B (add_garlic);
    A.join();
    B.join();
    printf("Garlic to buy %i \n",garlic_to_buy);
    printf("Carrots to buy %u \n",carrots_to_buy.load());

    /////
    std::mutex chopstick;
    const int num_threads = 10;
    std::thread Philosophers[num_threads];
    
    for(size_t i =0; i<num_threads; i++){
    Philosophers[i]=std::thread(philosopher, std::ref(chopstick));
    }

    for(size_t i =0; i<num_threads; i++){
    Philosophers[i].join();
    }
    
    
  


}