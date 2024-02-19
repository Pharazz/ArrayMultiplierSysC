/*
 * FullAdder.h
 *
 *  Created on: Jan. 27, 2022
 *      Author: faraz
 */

#ifndef FULLADDER_H
#define FULLADDER_H

#include <systemc.h>

void make_FA();

SC_MODULE(FA) {
	sc_in<bool > clk{"clk"};
	sc_in<bool > A{"A"}, B{"B"}, C{"C"};
	sc_out<bool > S{"S"}, Cout{"Cout"};

	void FA_method();

        SC_CTOR(FA) {

        SC_METHOD(FA_method);
        dont_initialize();
        sensitive << clk.pos(); //<< A; //edge sensitive
    }

};
#endif
