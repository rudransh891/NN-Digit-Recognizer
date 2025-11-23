#include <iostream>
#include <vector>
#include <fstream>
#include <string>



class neuralNetwork{
    private:
        std::vector<int> layerSize = {784, 28, 28, 10}; //leftmost is number of input values, and rightmost is output.
        std::vector<int> weights;
        std::vector<int> bias;
    public:
    neuralNetwork(std::string filename){

    }

}
