#include <iostream>
#include <string>
#include <vector>

/*
Little program to count
*/
using namespace std;

int countVal = 0;
int countNum;

vector <string> printCount {"Count Num: ", "10 ", "20 ", "30 "};

void printSplash();
void countPrint();

int main(){

    cout << "Hellow Everyone, pick a number, either, " << printCount[1] << " or " << printCount[2] << " or " << printCount[3] << endl;

    printSplash();

    cin >> countVal;
    cout << "Counting " << countVal << " times" << endl;

    countPrint();

    return 0;
}

void printSplash(){
    for (const string& index : printCount){
        cout << index;
    } 
    cout << endl;
}

void countPrint(){
        for(int i = 0; i < countVal + 1; i++){
            cout << countNum << endl;
            countNum++;
        }
}