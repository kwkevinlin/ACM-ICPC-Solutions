#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stack>

using namespace std;

int main () {

	/*
	 * Store all input in stack. Pop until see (, if D, store weight. If B, calculate.
	 */

	stack<char> inputStack;
	stack<char> storageStack;

	ifstream input("input.txt");
	char in;
	while (input >> in) {
		inputStack.push(in);
	}

	char n; //More efficient, or negligible?
	while (inputStack.size() != 0) {
		n = inputStack.top();
		if (n == '(') {
			//Search storageStack until ) found
		}
		else if (n == ')') {
			storageStack.push(n);
			cout << storageStack.top() << endl;
			inputStack.pop();
		}
	}

}
