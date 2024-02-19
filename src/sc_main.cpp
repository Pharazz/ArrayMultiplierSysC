/*
 * sc_main.cpp
 *
 *  Created on: Jan. 27, 2022
 *      Author: faraz
 */
#include <systemc.h>
#include <iostream>
#include "CSA.h"
#include "FullAdder.h"
#include "ArrayMultiplier.h"

using namespace std;

int sc_main(int, char* []) {
	sc_trace_file *tf;//trace for hardware signals
			int i = 0, j = 0; //for loops for assignining test case values
			sc_uint<8> Multiplier, Multiplicand;//decimal version of inputs
			sc_vector<sc_signal<bool >> A, B, Sumout;//Logic Vector Signals for adders
			sc_signal<bool> Cout, rst;//Logic bits
			sc_uint<16> Result;//Output of mult can be 16 bits
			sc_clock clk("clk",10,SC_NS,0.5);   //Create a clock signal
			
      //Initializaing nputs
      A.init(8);
			B.init(8);
			Sumout.init(16);
			
      Amul Amul("Amul");//Declaration and Label for Debugging
      
      //Port Mapping multiplier
			Amul.clk(clk);
			Amul.rst(rst);
			//CSATest.Adder.clk(clk);
			Amul.Ain(A);
			Amul.Bin(B);
			Amul.P(Sumout);

      //Mapping Trace FILE
			tf = sc_create_vcd_trace_file("trace_file");
				tf->set_time_unit(1, SC_NS);
				sc_trace(tf, clk, "clk");
				sc_trace(tf, Multiplier, "inputA");
				sc_trace(tf, Multiplicand, "inputB");
				//sc_trace(tf, Sumout, "Sumout");
				sc_trace(tf, Cout, "Sumout");
  
  //Test Bench Param Initialization
			cout << "Executing Test Bench\n"<<endl;
			for (i = 0; i <8 ; i++){
				if (i == 7 )A[i].write(0);
				else A[i].write(1);
				//00000011
			}
			Multiplier = 1;
			for (i = 0; i <8 ; i++){
				if (i == 7)B[i].write(0);
				else B[i].write(1);
				//00000010
			}
			Multiplicand = 0;
			sc_start(10, SC_NS); //Test Bench Begins
			cout << "Multiplying " << Multiplicand.to_string() << " with " << Multiplier.to_string() <<"\nSum: ";
			cout << "\n P output:";

			for (i = 15; i >= 0; i--){
				cout << Sumout[i] ;

			}
			cout << "\nCout:"<< Amul.Cout.read()<< endl;
			for (j = 0; j < 1; j++){
			cout << "Pull numbers from arrays\nSum: ";
				for (i = 7; i >= 0; i--){
					cout << Amul.CPArray[i]->S;

				}
				for (i = 7; i>= 0; i--){
					cout << Amul.CSArray[i][0]->Sout;
				}
				cout << "\n\n";
			}
// Additional Testcases provided below uncomment as needed
  
//			cout << "Executing Test Case 2\n"<<endl;
//			for (i = 0; i <8 ; i++){
//				if (i == 1 )A[i].write(0);
//				else A[i].write(0);
//				//00000011
//			}
//			Multiplier = 127;
//			for (i = 0; i <8 ; i++){
//				if (i == 7)B[i].write(1);
//				else B[i].write(0);
//				//00000010
//			}
//			Multiplicand = 127;
//			sc_start(10, SC_NS);
//			cout << "Multiplying" << Multiplicand.to_string() << "with" << Multiplier.to_string() <<"\nSum: ";
//			cout << "\n P output:";
//
//			for (i = 15; i >= 0; i--){
//				cout << Sumout[i] ;
//
//			}
//			cout << "\nCout:"<< Amul.Cout.read()<< endl;
//			for (j = 0; j < 1; j++){
//			cout << "Pull numbers from arrays\nSum: ";
//				for (i = 7; i >= 0; i--){
//					cout << Amul.CPArray[i]->S;
//
//				}
//				for (i = 7; i>= 0; i--){
//					cout << Amul.CSArray[i][0]->Sout;
//				}
//				cout << "\n\n";
//			}
//			sc_start(10, SC_NS);
//			cout << "\n P output:";
//
//			for (i = 15; i >= 0; i--){
//				cout << Sumout[i] ;
//
//			}
//			cout << "\n P output:";
//
//			for (i = 15; i >= 0; i--){
//				cout << Amul.P[i] ;
//
//			}
//			cout << "\n Sum output:";
//
//			for (i = 15; i >= 0; i--){
//				cout << Amul.Sum[i] ;
//
//			}
//			cout << "\n Sumprop output:";
//
//			for (i = 7; i >= 0; i--){
//				cout << Amul.Sumprop[i][0] ;
//
//			}
//			cout << "\n Sum output:";
//
//			for (i = 15; i >= 0; i--){
//				cout << Amul.Sum[i] ;
//
//			}
//make_Amul();
    return 0;
}



