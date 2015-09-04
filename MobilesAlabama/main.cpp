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
	stack<char> storageStack;
	vector<string> storageVector;

	ifstream input("input.txt");
	string in; string temp;
	while (input >> in) {
		inputStack.push(in);
		cout << inputStack.top() << endl;
	}
	cout << endl;

	string n; //More efficient, or negligible?
	//Processing the inputStack
	inputStack.pop(); //Pop )
	inputStack.pop(); //Pop (
	while (inputStack.size() != 0) {
		n = inputStack.top();
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
	}

}
