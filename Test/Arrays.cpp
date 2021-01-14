#include <iostream>
#include <array>
using namespace std;

void initiatize(float* mat, int length, int width){
    for (int i =0; i<length;i++){ 
        for (int j =0; j<width;j++){
            mat[i*width+j]=rand()%6;
        }
    }
}

void printMat(float* mat, size_t length, size_t width){
    for (int i =0; i<length;i++){ 
        for (int j =0; j<width;j++){
            cout <<mat[i*width+j]<< " ";
        }
        cout << "\n";
    }
     cout << "\n";
}

float** dynamicArray(size_t rows, size_t cols){
    float** p=new float*[rows];
    for(int i=0; i<rows; i++ ){
        p[i]=new float[cols];
    }
    return p;
}

void deleteDynamicArray(float** p, size_t rows, size_t cols){
    for (int i=0;i<rows;i++){
        delete[] p[i];
    }
    delete p;
}

void printDynamicArray(float** p, size_t rows, size_t cols ){
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
             cout<<p[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void initializeDynamicArray(float** p, size_t rows, size_t cols ){
    for (int i=0;i<rows;i++){
            float* col=p[i];
        for (int j=0;j<cols;j++){
             col[j]=rand()%6;
        }
    }
}

void dynamicArray_smartPointers(size_t rows, size_t cols){
     //size_t is an unsigned integer data type which can assign only 0 and greater than 0 integer values
     //auto array2d=unique_ptr<float*[]> (new float*[rows]);
}

void staticArray(){
 const int length = 3;
    const int width = 3; 
    float mat1[length][width];
    float mat2[length][width];
    float mat3[length][width]={0};
    array<float,5> test;
    //memset(mat3, 0, sizeof(mat3[0][0]) * length * width)

    initiatize(&mat1[0][0],length,width);
    initiatize(&mat2[0][0],length,width);
     
    printMat(&mat1[0][0],length,width);
    printMat(&mat2[0][0],length,width);
 
    for (int i =0; i<length;i++){   
        for (int k =0; k<width;k++){
            for (int j =0; j<width;j++){
                mat3[i][k] = mat3[i][k]+mat1[i][j]*mat2[j][k];
            }
         }
    }
    
     printMat(&mat3[0][0],length,width);

}

void findMatch(){
    int arr[]={2, 3, 5,7};
    int sum =5;
    int arrSize=sizeof(arr)/sizeof(arr[0]);
    for (int i=0; i<arrSize;i++){
        for (int j=i+1;j<arrSize;j++){
            if (arr[i]+arr[j]==sum){
                printf("%i + %i = %i",arr[i],arr[j],sum);
                break;
            }
        }

    }
}

int main(){
    size_t rows =3;
    size_t cols =4;
    float** p =dynamicArray(rows,cols);
    initializeDynamicArray(p, rows,cols);
    printDynamicArray(p,rows,cols);
    deleteDynamicArray(p,rows,cols);
    findMatch();

    return 0;
}
