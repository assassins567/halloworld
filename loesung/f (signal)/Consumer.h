#include <systemc.h>

#ifndef CONSUMER_H_
#define CONSUMER_H_

SC_MODULE(Consumer)
{

	sc_in<int> data;
	sc_in<int> data2;

	SC_CTOR(Consumer)
	{
		SC_METHOD(consume);
		sensitive << data;

		SC_METHOD(consume2);
		sensitive << data2;
	}

	void consume()
	{
		int readNumber = data.read();
		cout << "[" << sc_time_stamp() << "](" << name() << "): read " << readNumber << " from port data." << endl;
	}

	void consume2()
	{
		int readNumber = data2.read();
		cout << "[" << sc_time_stamp() << "](" << name() << "): read " << readNumber << " from port data." << endl;
	}
};

#endif
