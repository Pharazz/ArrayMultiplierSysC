/*
 * FullAdder.cpp
 *
 *  Created on: Jan. 27, 2022
 *      Author: faraz
 */
#include <systemc.h>
#include <iostream>
#include "FullAdder.h"

void FA :: FA_method(){
	bool Sum, Carry;
	int i, k;
	//printf("Adder Invoked\n");

	Sum = A.read() ^ B.read();
	Carry = A.read() & B.read();
	Carry = Carry | (Sum & C.read());
	Sum = Sum ^ C.read();

	printf("A:%d,B %d,C %d\n", A.read(), B.read(), C.read());
	printf("Sum:%d , Carry %d %s %s\n ", Sum, Carry, sc_get_current_process_b()->get_parent()->basename(), sc_get_current_process_b()->get_parent()->get_parent()->basename());
	cout << "Sum: "<< Sum <<" Cout:" << Carry <<"\n"<< endl;

	S.write(Sum);
	Cout.write(Carry);
}

//void make_FA(){
	//sc_trace_file *tf;
	//sc_signal<bool > clk;
	//sc_signal<sc_bit > A, B, S, Cout, Cin;
//	sc_clock clk("clk",10,SC_NS,0.5);   //Create a clock signal
//}

