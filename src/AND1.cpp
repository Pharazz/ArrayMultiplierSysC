/*
 * AND1.cpp
 *
 *  Created on: Jan. 28, 2022
 *      Author: faraz
 */

/*
 * FullAdder.cpp
 *
 *  Created on: Jan. 27, 2022
 *      Author: faraz
 */
#include <systemc.h>
#include <iostream>
#include "AND1.h"

void AND1 :: AND1_method(){
	bool Result;
	//printf("AND Result before %d\n",Result);
	Result = A.read() & B.read();
	//printf("AND Result after %d\n",Result);

	clk2.write(clk.read());

	Y.write(Result);
}

//void make_FA(){
	//sc_trace_file *tf;
	//sc_signal<bool > clk;
	//sc_signal<sc_bit > A, B, S, Cout, Cin;
//	sc_clock clk("clk",10,SC_NS,0.5);   //Create a clock signal
//}




