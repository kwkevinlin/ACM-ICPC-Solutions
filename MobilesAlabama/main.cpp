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
	int tempID, length1, length2;
	vector<decoration> dec;
	vector<bar> bars; //Capitalized
	while (!inputStack.empty()) {
		in = inputStack.top();
		//At start, put everything to storageStack
		cout << "Reading in: " << in << endl;
		storageStack.push(in);

		if (in == "(") {
			storageStack.pop(); //Pop off "("
			//Default runs this
			if (storageStack.top() != ")") {//If not ). Ignore, since if ( ), then its end of input
				cout << "Inside with " << storageStack.top() << endl;
				if (storageStack.top() == "D") {
					//Read next
					storageStack.pop(); //Pop off D to access weight
					dec.push_back(decoration(stof(storageStack.top()))); //Creates temporary
					//cout << "Vector: " << dec[0].getWeight() << endl;
					storageStack.pop(); //Pop off 2.0
					storageStack.pop(); //Pop off )
				}
				else if (storageStack.top() == "B") {
					storageStack.pop(); //Pop off B
					tempID = stoi(storageStack.top());
					storageStack.pop(); //Pop off bar ID
					bars.push_back(bar(tempID, stof(storageStack.top())));
					storageStack.pop(); //Pop off weight
					//cout << "Size check: " << storageStack.size() << " " << storageStack.top() << endl;
					//storageStack.pop(); //Pop off )
					//cout << "Size check: " << storageStack.size() << endl;

					if (storageStack.size() == 0) { //End of input
						//Then start combining Bars and Decorations
						cout << "Size = 1 here" << endl;
					}
					else if (storageStack.size() != 0) { //Still parsing
						storageStack.pop(); //Pop off )
					}
					else
						cout << "Something is wrong\n\n";

					//Once reach bar, then means decorations are ready, so can start calculating
					cout << "\nNumber of bars: " << bars.size() << endl << endl;
					//0 = L1*W1 - L2*W2
					cout << dec[0].getWeight() << " " << dec[1].getWeight() << endl;
					//length1 =

					//then erase [1] and store data to [0]. so everytime, dec<vector> will only have 2 items

;				}
			} else {
				//It only goes here if at beginning, reading: ()
				storageStack.pop(); //Pop off ")"
			}
		}
		inputStack.pop();
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
