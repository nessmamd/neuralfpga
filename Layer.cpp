#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std; 


class Layer; 
class Information; 
struct LayerData{
    vector<double> weights; 
    vector<double> biases; 
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
