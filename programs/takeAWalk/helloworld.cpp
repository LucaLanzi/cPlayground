#include <iostream>
#include <vector> 
#include <string>

using namespace std;

int main(){

    // Vector Definition
    // vector<type of element in vector index> nameOfVector {"String 1", "String 2,", "etc"}
    vector<string> message {"Hey Luca", "You should probably go for a walk", "Listen to Frank"};

    // for loop, read only (const), reference (& is the reference operator) of string type called phrase, : means "in", message is defined
    for (const string& phrase : message ){
        cout << phrase << endl;
    }
    cout << endl;
}

// To excecute this outside of Vscode using the clang++ compiler 
// clang++ helloworld.cpp -o helloworld