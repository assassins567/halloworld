#include <systemc.h>

#ifndef PRODUCER_H_
#define PRODUCER_H_

SC_MODULE(Producer){

	//ports
	//local vars
	sc_out<int> num;
	int generatedNumber;
	
	SC_CTOR(Producer){
		//initialize signal (else 0)
		//declare thread
		num.initialize(520);
		SC_THREAD(produce);
		//sensitive << 
	}

	void produce()
	{
		int i = 0;
		//produce 10 random values, send each
		while(i < 10) {
			generatedNumber = rand();
			//print output
			//send data
			//cout << "producer = " << generatedNumber << endl;
			
			num.write(generatedNumber);
			cout << "[" << sc_time_stamp() << "](" << name() << "): generated " << generatedNumber<< endl;
			wait(SC_ZERO_TIME);
			i++;
		}
	}

};

#endif

 

