#include "systemc.h"

#ifndef CONSUMER_H_
#define CONSUMER_H_

SC_MODULE(Consumer){
	//ports
	//local vars	
	sc_in<int> num;
	int output_num;
	SC_CTOR(Consumer){
	//declare method
	//sensitivity
		SC_METHOD(consumer);
		sensitive << num;	
	}

	void consumer()
	{
		//read number
		//print output
		output_num = num.read();
		cout << "[" << sc_time_stamp() << " / " << sc_delta_count() << "](" << name() << "): read " << output_num << endl;
	}

};

#endif

 

