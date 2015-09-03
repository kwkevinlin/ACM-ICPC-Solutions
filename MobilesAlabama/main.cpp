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

	while (inputStack.size() != 0) {

	}

}
