#include<iostream>
#include<fstream>
#include<string>
#include<bitset>    

using namespace std;    

int main() {    
    string filename = "binary.txt";    
    ifstream file(filename);    
    if (!file) {    
        cerr << "Error opening file: " << filename << endl;    
        return 1;    
    }    

    string line;    
    while (getline(file, line)) {    
        // Convert binary string to decimal
        unsigned long long decimal = bitset<64>(line).to_ullong();    
        cout << decimal << endl;    
    }    

    file.close();    
    return 0;    
}