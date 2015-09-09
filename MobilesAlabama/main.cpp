#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <stack>
#include <vector>

#include "bar.h"
#include "decoration.h"

using namespace std;

int main () {

	/*
	 * Store all input in stack. Pop until see (, if D, store weight. If B, calculate.
	 */

	stack<string> inputStack;
	stack<string> storageStack;
	vector<string> storageVector;

	ifstream input("input.txt");
	string in; string temp;
	while (input >> in) {
		if (in.length() > 1 && in.find(".") == -1) {
			for (int i = 0; i < in.length(); i++) {
				cout << in[i] << " ";
				inputStack.push(string(1, in[i]));
			}
		} else {
			cout << in << " ";
			inputStack.push(in);
		}
	}
	cout << endl << endl;
/*
	while (!inputStack.empty()) {
		cout << inputStack.top() << " ";
		inputStack.pop();
	}
	cout << "End of Loop" << endl << endl;
*/
	float dWeight;
	while (!inputStack.empty()) {
		in = inputStack.top();
		//At start, put everything to storageStack
		storageStack.push(in);

		if (in == "(") {
			//Default runs this
			if (storageStack.top() != ")") {//If not ). Ignore, since if ( ), then its end of input
				storageStack.pop(); //Pop off "("
				if (storageStack.top() == "D") {
					//Read next
					storageStack.pop(); //Pop off D to access weight
					decoration dec1(stof(storageStack.top()));
					cout << endl << stof(storageStack.top()) << endl << endl;

				}
				else if (storageStack.top() == "B") {
					cout << endl;
				}
			} else {
				//It only goes here if at beginning, reading: ()
				storageStack.pop();
				storageStack.pop();
			}
		}
	}

	/*
	string n;
	//Processing the inputStack
	while (inputStack.size() != 0) {
		n = inputStack.top();
		if (n.length() > 1 && n.find(".") == -1) {
			string *nArray = new string[n.length()];
			for (int i = 0; i < n.length(); i++) {
				nArray[i] = n[i];
				storageVector.push_back(nArray[i]);
				cout << "\t" <<nArray[i] << endl;
			}
			delete [] nArray;
		} else {
			cout << n << endl;
			storageVector.push_back(n);
		}
		inputStack.pop();
	}

	for (int i = 0; i < storageVector.size(); i++) {
		cout << storageVector[i] << " ";
	}
	*/




/*
		if (n == "(") {
			//Search storageStack until ) found
		}
		else if (n == ")") {
			storageVector.push_back(n);
			cout << "To Storage: " << storageVector.back() << endl;
			inputStack.pop();
		}
		else {
			storageVector.push_back(n);
			cout << "To Storage: " << storageVector.back() << endl;
			inputStack.pop();
		}
		*/

}
