#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void saveToPPM(const std::vector<int> & pixels, int width, int height, const std::string& filename){
    std::ofstream file(filename);
    if(!file.is_open()){
        std::cout << filename << " opening failed." << std::endl;
        return;
    }
    file << "P2\n" << width << " " << height << "\n255\n";

    for(int i = 0; i < pixels.size(); i++){
        file << pixels[i] << " ";
        if( (i+1) % width == 0){
            file << "\n";
        }
    }
    file.close();
}

std::vector<int> parseCSVLine(std::string line){
    std::vector<int> pixels;
    std::stringstream ss(line);
    std::string value;

    std::getline(ss, value, ','); // skip first element

    while (std::getline(ss, value, ',')){
        try{
            pixels.push_back(std::stoi(value));
        }
        catch(...){
            pixels.push_back(0);
        }
    }
    return pixels;
}

int main(){
    const std::string filename = "mnist.csv";
    std::ifstream fdata(filename);
    std::string row_data;
    const int H = 28;
    const int W = 28;
    int i = 1;
    std::getline(fdata, row_data);
    while(std::getline(fdata, row_data)){
        // std::cout << "Success Read" << std::endl;
        std::vector<int> pixel = parseCSVLine(row_data);
        std::string opname = "output/" + std::to_string(i) +".ppm";
        saveToPPM(pixel, W, H, opname);
        i++;
    }
    fdata.close();

}