#include "systemc.h"

#ifndef CONSUMER_H_
#define CONSUMER_H_

SC_MODULE(Consumer){
	sc_fifo_in<int> data_fifo;

	//ports
	//local vars	
	int readNumber;

	SC_CTOR(Consumer){
	//declare method
	//sensitivity	
		SC_THREAD(consume);
	}

	void consume()
	{
		while(true)
		{
			readNumber = data_fifo.read();
			//read number
			//print output
			cout << "[" << sc_time_stamp() << " / " << sc_delta_count() << "](" << name() << "): read " << readNumber << endl;
		}
	}

};

#endif

 

