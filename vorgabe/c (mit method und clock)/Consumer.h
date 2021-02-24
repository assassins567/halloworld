#include <systemc.h>

#ifndef CONSUMER_H_
#define CONSUMER_H_

SC_MODULE(Consumer){

	sc_in<int> data;
	sc_in<bool> clock;

	int readNumber;

	SC_CTOR(Consumer){
		SC_METHOD(consume);
		//sensitivity to positive clock edge
		sensitive << data;
	}

	void consume()
	{	
		
		readNumber = data.read();
		//readNumber = data; //geht bei SC_SIGNAL auch
		cout << "[" << sc_time_stamp() << "](" << name() << "): read " << readNumber << endl;
		next_trigger(10, SC_MS);
	}

};

#endif

 

