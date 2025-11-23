#include <iostream>
#include <vector>
#include <fstream>
#include <string>



class neuralNetwork{
    private:
        std::vector<int> layerSize; //leftmost is number of input values, and rightmost is output.
        std::vector<int> weights;
        std::vector<int> bias;
        int wIndex(int layer, int oIndex, int iIndex){
            int layerOffset = 0;
            for(int i = 0; i < layer;i++){
                layerOffset += layerSize[i]*layerSize[i+1];
            }
            int outputOffset = oIndex * layerSize[layer-1];
            int inputOffset = iIndex;
        }
        int bIndex(int layer, int oIndex){
            int layerOffset = 0;
            for(int i = 0; i < layer; i++){
                layerOffset += layerSize[i+1];
            }
            return layerOffset + oIndex;
        }

    public:
    neuralNetwork(std::string filename){
        layerSize = {784,28,28,10};
        for(int i = 0; i < 23016; i++){ //ToBeAutomated(TBA)
            weights[i] = 0;
        }
        for(int i = 0; i < 66; i++){
            bias[i] = 0;
        }
    }

};
