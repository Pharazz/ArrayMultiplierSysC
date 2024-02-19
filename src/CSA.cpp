/*
 * CSA.cpp
 *
 *  Created on: Jan. 27, 2022
 *      Author: faraz
 */
#include <systemc.h>
#include <iostream>
#include "CSA.h"
#include "FullAdder.h"
#include "AND1.h"

//void CSA :: CSA_Bind(){
//	sc_signal<bool> tmp;
//	tmp = Ain.read() & Bin.read();
//	Adder.A(tmp);
//	Adder.FA_method();
//}

void CSA :: CSA_method(){
	//sc_signal<bool> tmp;
	//tmp = Ain.read() & Bin.read();
	//printf("CSA invoked\n");
	clkout.write(clk.read());
	//ANDGate->AND1_method();
	//Adder->FA_method();
	//addA = Ain.read() & Bin.read();
	//addA = tmp;
	//addB = Sin.read();
   //Adder.A(Ain.read() & Bin.read());
   // Adder.B(Sin);

   // Adder.C(Cin);

    //Adder.S(Sout);
    //Adder.Cout(Co);
	//Adder.FA_method();
}

void make_CSA(){
	sc_trace_file *tf;
	//sc_signal<bool > clk;
	sc_signal<bool > A, B, Sumin, Sumout, Cout, Cin, AB;

	sc_clock clk("clk",10,SC_NS,0.5);   //Create a clock signal

	CSA CSATest("CSA");

	CSATest.clk(clk);
	//CSATest.Adder.clk(clk);
	CSATest.Ain(A);
	CSATest.Bin(B);
	//CSATest.addA(AB);
	CSATest.Cin(Cin);
	CSATest.Sin(Sumin);
	CSATest.Co(Cout);
	CSATest.Sout(Sumout);
	//CSATest.Adder.A()
	//CSATest.Adder.B(CSATest.Sin);
	//CSATest.Adder.C(Cin);
	//CSATest.Adder.S(Sumout);
	//CSATest.Adder.Cout(Cout);

	tf = sc_create_vcd_trace_file("trace_file");
		tf->set_time_unit(1, SC_NS);
		sc_trace(tf, clk, "clk");
		sc_trace(tf, A, "A");
		sc_trace(tf, B, "B");
		sc_trace(tf, Cin, "Cin");
		sc_trace(tf, Sumin, "Sin");
		sc_trace(tf, Sumout, "Sout");
		sc_trace(tf, Cout, "Cout");

	cout << "Executing CSA Test Bench\n"<<endl;

	A.write(0); B.write(0); Cin.write(0); Sumin.write(0);
	sc_start(10, SC_NS);
	cout << "Sum: "<< Sumout.read() <<" Cout:" << Cout.read() << " AND Result:" << CSATest.addA.read()<<"\n"<< endl;

	A.write(1); B.write(0); Cin.write(0); Sumin.write(0);
	sc_start(10, SC_NS);
	cout << "Sum: "<< Sumout.read() <<" Cout:" << Cout.read() << " AND Result:" << CSATest.addA.read()<<"\n"<< endl;

	A.write(1); B.write(1); Cin.write(0); Sumin.write(0);
	sc_start(10, SC_NS);
	cout << "Sum: "<< Sumout.read() <<" Cout:" << Cout.read() << " AND Result:" << CSATest.addA.read()<<"\n"<< endl;

	A.write(1); B.write(0); Cin.write(1); Sumin.write(0);
	sc_start(10, SC_NS);
	cout << "Sum: "<< Sumout.read() <<" Cout:" << Cout.read() << " AND Result:" << CSATest.addA.read()<<"\n"<< endl;

	A.write(1); B.write(1); Cin.write(1); Sumin.write(0);
	sc_start(10, SC_NS);
	cout << "Sum: "<< Sumout.read() <<" Cout:" << Cout.read() << " AND Result:" << CSATest.addA.read()<<"\n"<< endl;

	A.write(1); B.write(1); Cin.write(0); Sumin.write(1);
	sc_start(10, SC_NS);
	cout << "Sum: "<< Sumout.read() <<" Cout:" << Cout.read() << " AND Result:" << CSATest.addA.read()<<"\n"<< endl;

	A.write(1); B.write(1); Cin.write(1); Sumin.write(1);
	sc_start(10, SC_NS);
	cout << "Sum: "<< Sumout.read() <<" Cout:" << Cout.read() << " AND Result:" << CSATest.addA.read()<<"\n"<< endl;
	//A = '1';
	//B = 0; Cin = 0; Sumin = 0;
	//sc_start(10, SC_NS);

}


