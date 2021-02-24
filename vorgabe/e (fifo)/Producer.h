#include <systemc.h>

#ifndef PRODUCER_H_
#define PRODUCER_H_

SC_MODULE(Producer){

	sc_fifo_out<int> data;
	//second port
	

	int generatedNumber;
	int i;

	SC_CTOR(Producer){
		SC_THREAD(produce);
	}

	void produce()
	{
		i = 0;
		while(i < 10) {
			generatedNumber = rand();
			cout << "[" << sc_time_stamp() << "](" << name() << "): generated " << generatedNumber << endl;
			data.write(generatedNumber);
			//write second port 
			
			wait(SC_ZERO_TIME); //sonst kommt der Consumer nie dran
			i++;
		}
	}

};

#endif

 

