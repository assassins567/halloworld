#include <systemc.h>

#ifndef CONSUMER_H_
#define CONSUMER_H_

SC_MODULE(Consumer){

	sc_fifo_in<int> data;

	int readNumber;

	SC_CTOR(Consumer){
		SC_THREAD(consume);
	}

	void consume()
	{
		while(true) {
			readNumber = data.read();
			cout << "[" << sc_time_stamp() << "](" << name() << "): read " << readNumber << endl;
		}
	}

};

#endif

 

