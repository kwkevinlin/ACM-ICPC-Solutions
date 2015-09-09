#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <stack>
#include <vector>

//#include "bar.h"
//#include "decoration.h"

using namespace std;

int main () {

	/*
	 * Store all input in stack. Pop until see (, if D, store weight. If B, calculate.
	 */

	stack<string> inputStack;
	stack<char> storageStack;
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
	cout << "inputStack.size() = " << inputStack.size() << endl;
	for (int i = 0; i < inputStack.size(); i++) {
		cout << i << "  " << inputStack.top() << endl;
		inputStack.pop();
	}
*/
	while (!inputStack.empty()) {
		cout << inputStack.top() << endl;
		inputStack.pop();
	}

	cout << "End of Loop" << inputStack.empty() << endl;

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
