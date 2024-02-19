/*
 * AND1.h
 *
 *  Created on: Jan. 28, 2022
 *      Author: faraz
 */

#ifndef AND1_H_
#define AND1_H_


#include <systemc.h>

SC_MODULE(AND1) {
	sc_in<bool > A{"A"}, B{"B"}, clk{"AdderClk"};
	sc_out<bool > Y{"Y"}, clk2{"Adderclkout"};

	void AND1_method();

        SC_CTOR(AND1) {

        SC_METHOD(AND1_method);
	dont_initialize();
        sensitive << clk << A << B; //edge sensitive
    }

};
#endif

