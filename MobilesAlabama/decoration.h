/*
 * decoration.h
 *
 *  Created on: Sep 3, 2015
 *      Author: kevin
 */

#ifndef DECORATION_H_
#define DECORATION_H_

class decoration {

public:

	decoration(int ID, float wt) {
		barID = ID;
		weight = wt;
	}
	float getWeight() {
		return weight;
	}
	int getBarID() {
		return barID;
	}

private:
	int barID;
	float weight;

};


#endif /* DECORATION_H_ */
