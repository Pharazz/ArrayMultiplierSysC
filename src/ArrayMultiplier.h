/*
 * ArrayMuliplier.h
 *
 *  Created on: Jan. 29, 2022
 *      Author: faraz
 */

#ifndef ARRAYMULTIPLIER_H_
#define ARRAYMULTIPLIER_H_

#include <systemc.h>
#include "CSA.h"
#include "CPA.h"
#include "FullAdder.h"
#include "AND1.h"
#include <string>

SC_MODULE(Amul) {
	sc_in<bool > clk{"clk"}, rst{"Reset"};
	sc_vector<sc_in<bool >> Ain{"Input_A"}, Bin{"Input_B"};
	sc_vector<sc_out<bool >> P{"Final_Sum"};
	sc_out<bool> Cout{"CarryOut"};
	sc_signal<bool> CarryCSA{"AdderA"}, clkprop{"clkprop"}, zero{"zero"};
	sc_vector<sc_signal<bool>> Sum{"TempSum"} ,Sum2{"TempSum2"};//, Carry;//, addC{"AdderC"};
	//clk prop on CPA? Last 8 bits need Carry Out Right to Left
	sc_signal<bool > FinalCarry{"Cout"};
	int i, j, k;
	//sc_vector<sc_vector<CSA >> CSArray;
	sc_signal<bool> Sumprop[8][8];
	sc_signal<bool> Carryprop[8][8];
	sc_signal<bool> Clockprop[9][8];
	sc_signal<bool> Finalprop[9];
	sc_signal<bool> Finalprop2[8];
	//sc_signal<bool> Sum[16];
	CSA *CSArray[8][8];
	CPA  *CPArray[8];

		//void CSA_Bind();
		void make_Amul();
		void Amul_method();

	        SC_CTOR(Amul){
	        	//SC_METHOD(Amul_method);
	        	Ain.init(8);
	        	Bin.init(8);
	        	P.init(16);
	        	Sum.init(8);
	        	Sum2.init(8);
	        	//Carry.init(8);
	        	zero.write(0);
	        	i = 0;
	        	j = 0;
	        	k = 0;
	        	for (i = 0; i < 8 ; i++){
	        		CPArray[i] = new CPA((("CPA"+std::to_string(i))).c_str());
	        		for (j = 0; j < 8 ; j++ ){
	        			//Instantiate All CSA
	        			CSArray[i][j] = new CSA((("CSA"+std::to_string(i)+std::to_string(j))).c_str());
	        		}
	        	}
	        	i = 0;
	        	j = 0;
	        	//Input Initialization
	        	for (i = 0 ; i < 8; i ++){
	        		for (j = 0 ; j < 8; j++){
	        			//All get A and B respective
	        			CSArray[i][j]->Ain(Ain[j]);
	        			CSArray[i][j]->Bin(Bin[i]);
	        			//CSArray[i][j]->clk(clk);
	        			//Middle Rows
	        			if ((i !=0 ) & (j != 7)){CSArray[i][j]->Sin(Sumprop[i-1][j+1]);CSArray[i][j]->Cin(Carryprop[i-1][j]);CSArray[i][j]->clk(Clockprop[i-1][j+1]);}
	        			//First Row
	        			if (i == 0){CSArray[i][j]->Sin(zero); CSArray[i][j]->Cin(zero);CSArray[i][j]->clk(clk);}
	        			//Last Column
	        			else if (j == 7){CSArray[i][j]->Sin(zero);CSArray[i][j]->Cin(Carryprop[i-1][j]);CSArray[i][j]->clk(Clockprop[i-1][j+1]);}

	        		}
	        	}
	        	//Output Initialization
	        	for (i = 0 ; i < 8; i ++){
					for (j = 0 ; j < 8; j++){
						CSArray[i][j]->Co(Carryprop[i][j]);
						if(j != 0 ){CSArray[i][j]->Sout(Sumprop[i][j]);}
						else {CSArray[i][j]->Sout(P[i]);}//CSArray[i][j]->Sout(Sum[i]);}
						CSArray[i][j]->clkout(Clockprop[i][j]);
					}
				}
	        	//CPArray inputs
	        	for (i = 0 ; i < 8; i ++){
	        		if((i != 7) & (i != 0)){CPArray[i]->A(Sumprop[7][i+1]);CPArray[i]->B(Carryprop[7][i]);CPArray[i]->C(Finalprop[i-1]);CPArray[i]->clk(Clockprop[8][i-1]);}
	        		if(i == 0){CPArray[i]->A(Sumprop[7][i+1]);CPArray[i]->B(Carryprop[7][i]);CPArray[i]->C(zero);CPArray[i]->clk(Clockprop[7][7]);}
	        		else if(i == 7){CPArray[i]->A(Carryprop[7][i]);CPArray[i]->B(Finalprop[i-1]);CPArray[i]->C(zero);CPArray[i]->clk(Clockprop[8][i-1]);}
	        	}
	        	//CPArray outputs
	        	for (i = 0 ; i < 8; i ++){
	        		CPArray[i]->clkout(Clockprop[8][i]);
	        		//CPArray[i]->S(Finalprop2[i]);
	        		CPArray[i]->S(P[i+8]);
	        		//CPArray[i]->S(Sum2[i]);
	        		CPArray[i]->Cout(Finalprop[i]);
				}
//	        	for (i = 0 ; i < 8; i ++){
//	        		P[i](Sum[i]);
//	        		P[i+8](Sum2[i]);
//	        	}

	        	Cout(FinalCarry);
	            SC_METHOD(Amul_method);
		        //sensitive << clk.pos();// << Ain << Bin << Sin; //edge sensitive
			//dont_initialize();
			}


};
#endif
