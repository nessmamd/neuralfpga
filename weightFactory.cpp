#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std; 


class Layer; 
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
    friend class Layer;

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


double sigmoid(double x){
    return 1.0 / (1.0 + exp(-x));
}

class Layer{
    private: 
        int layerNumber;
        LayerData ours;
        vector<double> input; 
        vector<double> output;
    public: 
        static vector<LayerData> webia; 

        Layer(){layerNumber = 1;}

        Layer(Information& instance, int layerNum, vector<double> before){
            vector<LayerData> place = instance.theNumbers;

            if(webia.empty()){
                webia = place;
            }
            layerNumber = layerNum;
            input = before; 
            ours = place[layerNum]; 
        }

        vector<double> processor(){

            vector<double> result;

          
            for (double value : ours.biases) {
                if (value != 0.0) {
                    result.push_back(value);
 
                }
            }

            vector<double> wei; 
            for (double value : ours.weights) {
                if (value != 0.0) {
                    wei.push_back(value);
 
                }
            }            
        
            int ourNode = result.size(); 
            int prevNode = input.size(); 

            int next = 0;
            for (int y = 0; y < ourNode; y++){
                double currentBias = result[y];
                int counter = 0; 
                double sum = 0;
                for(int x = next; x < wei.size(); x++){
                    double weight = wei[x]; 
                    counter++;
                    sum += ((weight*input[counter]) + currentBias);

                    if(counter == 5){
                        double final = sigmoid(sum);
                        output.push_back(final); 
                        next += 5;
                        counter = 0;
                        sum = 0; 
                        break;
                    }

                }

                }
            return output; 
        }

    }; 

 

 string theOutCome(vector<string> results, vector<double> outcome){
    double largest = outcome[0]; 
    int indexo = 0; 
    for(int x = 1; x < outcome.size(); x++){
        if(outcome[x] > largest){
            largest = outcome[x]; 
            indexo = x; 
        }
    }
    return results[indexo]; 
 }


int main(){
    string in = "smaller.csv"; 
    Information instance(in); 
    vector<string> names = {"apple", "strawberry", "cherry"}; 
    instance.readCSV(); 
    vector<double> outcome = {1.0,0.3,0.1}; 

    vector<double> input = {5.0,2.0,3.0,1.0,3.0}; 
    // the first hidden layer
    Layer first(instance, 0, input); 
    input = first.processor(); 
    //the second hidden layer
    Layer second(instance, 1, input); 
    input = second.processor(); 

    //the output 
    Layer output(instance, 2, input); 
    vector<double> sdfsdfsdf = output.processor(); 
    cout << theOutCome(names, sdfsdfsdf) << endl; 

    return 0;
}