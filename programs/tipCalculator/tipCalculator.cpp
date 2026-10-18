#include <iostream> //Built in header that allows for the user to input standard input and output standard output
#include <string>   //Built in header that allows us to use the string type	
#include <iomanip>  //Built in header that lets you manipulate standard input and output

using namespace std;

string greeting = "Welcome to Luca's tip calculator!";
string tipQuestion = "How much did you pay for tonights dinner?";
string tipPerMessage = "How much percentage of tonights dinner are you willing to tip? Enter in terms of a raw value";

double tipCalc(double dCost, double tipP);

int main(){
	
	double dinnerCost;
	double tipPercentage;
	double totalTip; 

	cout << fixed << setprecision(2);

	cout << greeting << endl;
	cout << tipQuestion << endl;
	cin >> dinnerCost; //Get dinner total cost

	if (dinnerCost <= 0){

		cout << "Invalid input, entered negative or zero bill" << endl;
		return 1;
	}

		
	cout << tipPerMessage << endl; //Ask user for tip percentage
	cin >> tipPercentage; //Store the percentage

	if(tipPercentage < 0){
		cout << "Invalid input, entered negative tip" << endl;
		return 1;
	}
	if(tipPercentage >= 50){
		cout << "\nDayum son you got some chedda in da bank!\n" << endl; 
	}

	totalTip = tipCalc(dinnerCost, tipPercentage);

	cout << "Your total tip for tonights dinner is: $" << totalTip << endl;
	cout << "Your dinners total is: $" << totalTip + dinnerCost << endl; 
	return 0;

}

double tipCalc(double dCost, double tipP){
	// take in the total dinner cost
	// multiply that by the decimal percentage of the total tip
	// return the total tip

	return dCost * (tipP/100);
}


