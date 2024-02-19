/*
 * CPA.h
 *
 *  Created on: Jan. 27, 2022
 *      Author: faraz
 */

#ifndef CPA_H_
#define CPA_H_

/*
 * FullAdder.h
 *
 *  Created on: Jan. 27, 2022
 *      Author: faraz
 */

#include <systemc.h>

void make_CPA();

SC_MODULE(CPA) {
	sc_in<bool > clk{"clk"};
	sc_in<bool > A{"A"}, B{"B"}, C{"C"};
	sc_out<bool > S{"S"}, Cout{"Cout"}, clkout{"clkout"};

	void CPA_method();

        SC_CTOR(CPA) {

        	SC_METHOD(CPA_method);
        dont_initialize();
        sensitive << clk.pos();// << clk.neg(); //<< clk.pos(); //<< A; //edge sensitive
    }

};
#endif
