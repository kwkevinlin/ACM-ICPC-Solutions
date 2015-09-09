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

	decoration(float wt) {
		barID = -1;
		weight = wt;
	}

	void setID(int id) {
		barID = id;
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
