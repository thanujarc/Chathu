#include<iostream>
#include <array>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
class Record{
    public:
    array<int,5> vals;
    string details;
    
};

class Records{
    public:
    vector<Record*> records;
    string file;
    //Records(string _file):file(_file){};
    void readRecords(Reader* reader){
        vector<string> data= reader->ReadLines();

        
        
    };

    private:
    void addRecord(vector<string> row){

        
    };
};
    

class Reader{
    protected:
        // File pointer 
        fstream fin; 
    public:
        Reader(string * filename){
             // Open an existing file 
            fin.open(*filename, ios::in);
        }
   
    vector<string> ReadLines(){

        vector<string> row; 
        string line, word, temp; 
    
        while (fin >> temp) { 
    
            row.clear(); 
    
            // read an entire row and 
            // store it in a string variable 'line' 
            getline(fin, line); 
    
            // used for breaking words 
            stringstream s(line); 

                    // read every column data of a row and 
            // store it in a string variable, 'word' 
            while (getline(s, word, ', ')) { 
    
                // add all the column data 
                // of a row to a vector 
                row.push_back(word); 
            } 
        }
    };
}

int main(){
    
}



