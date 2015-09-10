#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>
#include <iomanip>

#include "bar.h"
#include "decoration.h"

using namespace std;

int main () {

	/*
	 * The program reads in from input.txt, and stores each character as a string in a stack (inputStack).
	 * Starting from the top of inputstack, we push everything onto another stack (storageStack), and pop
	 * them off inputStack accordingly when storageStack is done processing them (explained in next sentence).
	 * We repeat this process until we see a "(" string, which signifies the start of a parenthesis. So we pop
	 * that off from storageStack, and check what the next character is.
	 * If it is:
	 * 		"D" : We pop "D", then use the value on storageStack.top() which is the weight of the decoration,
	 * 			  and create a new decoration class object and push that onto dec<vector>. It will be used when
	 * 			  we process "B". Dec<vector> should only always have 2 elements, so kind of stupid to use a
	 * 			  vector I guess. :(
	 * 		"B" : This is where we really get the solution to the question. We pop "B", then using the next two
	 * 			  elements on the top of the stack (bar ID and length), we create a bar class object and put that
	 * 			  onto another vector. Again, a vector doesn't need to be used here because we're only processing
	 * 			  one at a time. It would probably be more efficient to use a single object, and delete/or modify
	 * 			  it every time we're done with it.
	 *
	 * 			  How the Math was Done:
	 * 			  Every time I am processing "B", there should only be two elements inside the decorations<vector>.
	 * 			  We use those two decoration weights, and solve our equation.
	 * 			  		L1 + L2 = X, where X is given (ex: 2)
	 * 			  		L1W1 = L2W2
	 * 			  So let's take L1, and try to substitute that into the first equation. In equation 2,
	 * 			  		L1 = ( L2W2 ) / W1
	 * 			  		L1 = Tweight * L2, where Tweight = W2 / W1
	 * 			  Then, using the new value of L1,
	 * 			  		L1 + L2 = 2
	 * 			  Substitute in:
	 * 			  		Tweight * L2 + L2 = 2
	 * 			  If Tweight = 3
	 * 			  		3 * L2 + L2 = 2
	 * 			  		4L2 = 2
	 * 			  		L2 = 1/2
	 * 			  With L2 known,
	 * 			  		L1 + L2 = 2
	 * 			  		L1 + 1/2 = 2
	 * 			  		L1 = 3/2
	 * 			  So we output the value of L2 since it is the smaller of the two:
	 * 			  		Bar Y must be tied 0.5 from one end
	 *
	 * 			  Once this is done, we empty decoration<vector> and replace with them new values so that the next
	 * 			  bar, if there is one, can use it for future calculations. We can erase decorations<vector> because
	 * 			  both [0] and [1] values (W1 and W2) have already been used.
	 * 			  We then push_back(W1 + W2) on the vector, since that's the total weight of the bar. Now, when we
	 * 			  read in a new "D", we push_back that onto the decoration<vector>, and the next should be a "B",
	 * 			  so we calculate it using the exact same way, since we already had set it up.
	 *
	 */

	stack<string> inputStack;
	stack<string> storageStack;

	ifstream input("input.txt");
	string in;
	while (input >> in) {
		if (in.length() > 1 && in.find(".") == -1) {
			//Reading in as string will read symbols together, ex: ((( or (B
			//Want to split them up, but don't split numbers, ex: 2.0 or 3.1
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
    //If ever want to print out inputStack for debug/testing
	while (!inputStack.empty()) {
		cout << inputStack.top() << " ";
		inputStack.pop();
	}
	cout << "End of Loop" << endl << endl;
*/
	float weightTempFloat, length2Total, length1, length2;
	int tempID;
	int barIndex = 0;
	string eq1, eq1Num, eq1Den, eq2, eq2Temp, weightTemp1, weightTemp2;
	vector<decoration> dec;
	vector<bar> bars; //Notice bars (vector) vs bar (class)
	while (!inputStack.empty()) {
		in = inputStack.top();
		//At start, put everything to storageStack
		//cout << "Reading in: " << in << endl;
		storageStack.push(in);

		if (in == "(") { //Only parse if "("
			storageStack.pop(); //Pop off "("
			//Default runs this
			if (storageStack.top() != ")") {//If not ). Ignore, since if ( ), then its end of input
				//cout << "Inside with " << storageStack.top() << endl;
				if (storageStack.top() == "D") {
					storageStack.pop(); //Pop off D to access weight
					dec.push_back(decoration(stof(storageStack.top()))); //Creates temporary
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


					/*
					 * To Change:
					 * Instead of deleting all from dec<vector>, delete top 2 instead
					 */

					if (storageStack.size() == 0) { //End of input
						//Then start combining Bars and Decorations
						//And don't pop! Something seems a bit fishy here, but not sure yet
						//This if statement (and the "else") is purely for debugging purposes
						//cout << "\nEnd of input" << endl;
					}
					else if (storageStack.size() != 0) { //Still parsing
						storageStack.pop(); //Pop off )
					}
					else
						cout << "Something is wrong\n\n";

					//Once reach bar, then means decorations are ready, so can start calculating
					//cout << "\nNumber of bars: " << bars.size() << endl;
					barIndex = bars.size() - 1; //Can replace using vector since there's really no need for one

					//Doing calculations
					length2Total = 1 + dec[0].getWeight(); // L1+L2 = 2, but L1 = 2L2 so 3L2 = 2. Hardcoded 1 because L2 will always be by itself
					length2 = bars[barIndex].getLength()/length2Total;
					cout << "Length2 = " << length2 << endl;
					length1 = bars[barIndex].getLength() - length2;
					cout << "Length1 = " << length1 << endl;

					if (length1 < length2 )
						cout << "\tBar " << bars[barIndex].getBarID() << " must be tied " << fixed << setprecision(1) << length1 << " from one end." << endl;
					else
						cout << "\tBar " << bars[barIndex].getBarID() << " must be tied " << fixed << setprecision(1) << length2 << " from one end." << endl;

					//Now, write them back to decoration so next bar can use

					//Position shouldn't matter, so erase both and push new total weight (W1 + W2) onto dec vector
					weightTempFloat = dec[0].getWeight() + dec[1].getWeight();
					dec.clear();
					dec.push_back(decoration(weightTempFloat));

					//So every time, dec<vector> will only have 2 items, setting up for future calculations

				}
			} else {
				//It only goes here if at beginning, reading: ()
				storageStack.pop(); //Pop off ")"
			}
		}
		inputStack.pop();
	}
}
