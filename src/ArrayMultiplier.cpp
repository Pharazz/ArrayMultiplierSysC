/*
 * ArrayMultiplier.cpp
 *
 *  Created on: Jan. 29, 2022
 *      Author: faraz
 */


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
#include "ArrayMultiplier.h"

void amulReset(){

}

void Amul :: Amul_method(){
	zero.write(0);
	//if (rst == 1){
		//free(Sumprop);
		//free(Carryprop);
		//free(Clockprop);
		//free(Finalprop);
		//free(Finalprop2);
	//}
	//sc_signal<bool> tmp;
	//tmp = Ain.read() & Bin.read();
	//Ain(num.read().to_bool());
	//int i;
//	printf("Amul invoked\n");
//	for (i = 0 ; i < 16; i++){
//		if(i < 8){P[i].write(Sumprop[i][0].read());}
//		else{P[i].write(CPArray[i-8]->S.read());}
//	}
//	printf("P[0] should be:%d\n", P[0]);
//	for (i = 0 ; i < 8; i ++){
//		Sum[i].write((Sumprop[i][0].read()));
//		CPArray[i]->S(Finalprop2[i]);
//		Sum[i+8].write((Finalprop2[i]));
//		//CPArray[i]->S(Sum[i+8]);
//		CPArray[i]->Cout(Finalprop[i]);
//
//	}
//	FinalCarry.write(Finalprop[7]);

}

//sc_vector<bool> bitConversion(uint<8> num){
//	sc_vector<bool> temp;
//	int t = 0;
//	temp.init(8);
//	temp = num.toBoolean();
//	for(t = 0; t < 8; t++){
//		temp[t]();
//	}
//	temp = num.to_bv();
//	temp.init(8);
//
//}

void make_Amul(){
	//sc_trace_file *tf;
		//sc_signal<bool > clk;
		int i = 0;
		sc_uint<8> Multiplier, Multiplicand;
		sc_vector<sc_signal<bool >> A, B, Sumout;
		sc_signal<bool> Cout;

		sc_clock clk("clk",10,SC_NS,0.5);   //Create a clock signal
		A.init(8);
		B.init(8);
		Sumout.init(8);
		Amul Amul("Amul");

		Amul.clk(clk);
		//CSATest.Adder.clk(clk);
		Amul.Ain(A);
		Amul.Bin(B);
		//CSATest.addA(AB);
		Amul.P(Sumout);
		Amul.Cout(Cout);
		//CSATest.Adder.A()
		//CSATest.Adder.B(CSATest.Sin);
		//CSATest.Adder.C(Cin);
		//CSATest.Adder.S(Sumout);
		//CSATest.Adder.Cout(Cout);

		//tf = sc_create_vcd_trace_file("trace_file");
			//tf->set_time_unit(1, SC_NS);
			//sc_trace(tf, clk, "clk");
			//sc_trace(tf, A, "A");
			//sc_trace(tf, B, "B");
			//sc_trace(tf, Cin, "Cin");
			//sc_trace(tf, Sumin, "Sin");
			//sc_trace(tf, Sumout, "Sout");
			//sc_trace(tf, Cout, "Cout");

		cout << "Executing Test Bench\n"<<endl;
		for (i = 0; i <8 ; i++){
			if (i < 2)A[i].write(1);
			else A[i].write(0);
			//00000011
		}
		for (i = 0; i <8 ; i++){
			if (i == 1)B[i].write(1);
			else A[i].write(0);
			//00000010
		}

		sc_start(10, SC_NS);
		cout << "Sum: "
		<< Sumout[7].read()
		<< Sumout[6].read()
		<< Sumout[5].read()
		<< Sumout[4].read()
		<< Sumout[3].read()
		<< Sumout[2].read()
		<< Sumout[1].read()
		<< Sumout[0].read()
		<<" Cout:"
		<< Cout.read()
		<< endl;

}




