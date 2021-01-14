#include <stdio.h>
using namespace std;


class MultBy{
    int mult=0;
    MultBy();

    public:
        MultBy(int n):mult(n){};
        int operator() (int n) const {return mult*n;};
};

int main(){
    const MultBy times(4);
    printf(" 4*5 = %i \n", times(5));
}