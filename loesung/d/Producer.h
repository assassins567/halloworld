#include <systemc.h>

#ifndef PRODUCER_H_
#define PRODUCER_H_

SC_MODULE(Producer){

	sc_fifo_out<int> data_fifo;
	int i;
	//ports
	//local vars

	int generatedNumber;

	SC_CTOR(Producer){
		SC_THREAD(produce);
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
			data_fifo.write(generatedNumber);
			i++;
			wait(SC_ZERO_TIME);
		}
	}

};

#endif

 

