#include <systemc.h>

#ifndef CONSUMER_H_
#define CONSUMER_H_

SC_MODULE(Consumer){

	sc_fifo_in<int> data;
	sc_fifo_in<int> data2;

	int readNumber;

	SC_CTOR(Consumer){
		SC_THREAD(consume);
		SC_THREAD(consume2);
	}

	void consume()
	{
		while(true) {
			readNumber = data.read();
			cout << "[" << sc_time_stamp() << "](" << name() << "): read " << readNumber << endl;
		}
	}

	void consume2()
	{
		while(true) {
			readNumber = data2.read();
			cout << "[" << sc_time_stamp() << "](" << name() << "): read " << readNumber << endl;
		}
	}

};

#endif

 

