/*
 * CSA.h
 *
 *  Created on: Jan. 27, 2022
 *      Author: faraz
 */

#ifndef CSA_H_
#define CSA_H_

#include <systemc.h>
#include "FullAdder.h"
#include "AND1.h"


void make_CSA();

SC_MODULE(CSA) {
	sc_in<bool > clk{"clk"};
	sc_in<bool > Ain{"Ain"}, Bin{"Bin"}, Cin{"Cin"},Sin{"Sin"};//, Cin{"Cin"};
	sc_signal<bool> addA{"AdderA"}, clkprop{"clkprop"}, clkprop2{"clkprop"}, addC{"AdderC"};//, addC{"AdderC"};
	//sc_signal<bool> tmp;
	sc_out<bool > Sout{"Sout"}, Co{"Cout"}, clkout{"clkout"};
	FA *Adder;
	AND1 *ANDGate;

		//void CSA_Bind();
		void CSA_method();

	        SC_CTOR(CSA){
	        	ANDGate = new AND1 ("ANDGate");
	        	ANDGate->A(Ain);
	        	ANDGate->B(Bin);
	        	ANDGate->clk(clk);
	        	ANDGate->clk2(clkprop);
	        	ANDGate->Y(addA);
	        	Adder = new FA ("Adder");
	        	Adder->clk(clkprop);
	        	Adder->A(addA);
	        	Adder->B(Sin);
	        	Adder->C(Cin);
	        	Adder->S(Sout);
	        	Adder->Cout(Co);
	        	//clkout(clkprop2);
	        	//Adder.C(addC);
//				tmp = Ain.read();
//				tmp = tmp & Bin.read();
//				Adder.A(tmp);
//				//Adder.A(Ain.read() & Bin.read());
//				Adder.B(Sin);
//				Adder.Cout(Co);
//				Adder.C(Cin);
//				Adder.S(Sout);
	        //SC_METHOD(CSA_method);
	        	SC_METHOD(CSA_method);
	        //Adder->FA_method();
		dont_initialize();
	        sensitive << clk.pos();// << Ain << Bin << Sin; //edge sensitive
	    }

};
#endif
