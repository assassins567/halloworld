#include "systemc.h"

#ifndef CONSUMER_H_
#define CONSUMER_H_

SC_MODULE(Consumer){
	sc_in<int> data;
	sc_in<bool> clock;

	//ports
	//local vars	
	int readNumber;

	SC_CTOR(Consumer){
	//declare method
	//sensitivity	
		SC_METHOD(consume);
		sensitive << clock.pos();
	}

	void consume()
	{
		readNumber = data.read();
		//read number
		//print output
		cout << "[" << sc_time_stamp() << " / " << sc_delta_count() << "](" << name() << "): read " << readNumber << endl;
	}

};

#endif

 

