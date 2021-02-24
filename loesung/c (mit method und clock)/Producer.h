#include <systemc.h>

#ifndef PRODUCER_H_
#define PRODUCER_H_

SC_MODULE(Producer){

	sc_out<int> data;
	sc_in<bool> clock;
	int i;
	//ports
	//local vars

	int generatedNumber;

	SC_CTOR(Producer){
		//initialize signal (else 0)
		//declare thread
		data.initialize(42);
		SC_THREAD(produce);
		dont_initialize();
		sensitive << clock.pos();
	}

	void produce()
	{
		//produce 10 random values, send each
		i = 0;
		while(i < 10) {
			generatedNumber = rand();
			cout << "[" << sc_time_stamp() << "](" << name() << "): generated " << generatedNumber << endl;
			//print output
			//send data
			data.write(generatedNumber);
			i++;
			wait(clock.posedge_event());
		}
	}

};

#endif

 

