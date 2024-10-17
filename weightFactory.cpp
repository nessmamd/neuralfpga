#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std; 

struct LayerData{
    vector<double> weights; 
    vector<double> biases; 
}; 

class Information{
private: 
    string location; 
    vector<LayerData> theNumbers; 
    vector<int> arrayOfNodeValues;
    int sizeofTwo; 

public: 
    Information() {
        location = ""; 
        sizeofTwo = 0; 
    }
    Information(string& filename){
        location = filename; 
    }  

    int sizeFinder(string line){
        vector<string> temp; 
        stringstream ss(line);
        string token;

        while(getline(ss,token, ',')){
            temp.push_back(token); 
        }
        int header = temp.size(); 
        
        return header / 2; //the number should always be even
    }

    vector<double> splitter(string line){
        vector<double> temp; 
        stringstream ss(line);
        string token;

        while(getline(ss,token, ',')){
            if (!token.empty()){
                try {
                    temp.push_back(std::stod(token));
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Invalid argument: " << token << std::endl;
                }
            }
            else{
                temp.push_back(0);
            }
        }
        return temp; 
    }

    void readCSV(){
        ifstream file(location); 
        vector<LayerData> layerData; 
        string line; 
        getline(file,line); 
        sizeofTwo = sizeFinder(line); 

        for(int x = 0; x < sizeofTwo; x++){
            LayerData temp; 
            theNumbers.push_back(temp);
        }


        // cout << "this is the start" << sizeofTwo << endl; 
        vector<vector<double>> arr; 
        //populating the array
        while(getline(file,line)){

            stringstream ss(line); 
            string item; 
            string token; 

            LayerData data;
            getline(ss,item); 
            vector<double> temp = splitter(item); 
            arr.push_back(temp); 
        }

        for (const auto& row : arr) {
            for (int i = 0; i < 3; ++i) {
                theNumbers[i].weights.push_back(row[i]);  
                theNumbers[i].biases.push_back(row[i + 3]); 
            }
        }
    }
}; 



int main(){
    string in = "smaller.csv"; 
    Information instance(in); 
    instance.readCSV(); 
    return 0;
}