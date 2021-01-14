#include <thread>
#include <chrono>

bool chopping = true;

void vegitable_chopper(const char* name){
    unsigned int vegitable_count = 0;
    while(chopping){
        vegitable_count++;
    }
    printf("%s chopped %u vegitables.\n", name, vegitable_count);


}
int main(){
    std::thread A(vegitable_chopper,"A");
    std::thread B(vegitable_chopper,"B");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    chopping = false;
    A.join();
    B.join();

}