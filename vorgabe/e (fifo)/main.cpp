#include "systemc.h"
#include "Producer.h"
#include "Consumer.h"

int sc_main(int argc, char* argv[])
{
	// generating the sc_signal
	sc_fifo<int> data_fifo(1);
	//2nd fifo


	// generating the modules
	Producer prod1("Producer1");
	Consumer cons1("Consumer1");
	//2nd consumer

	// connecting moduleports
	prod1.data(data_fifo);
	cons1.data(data_fifo);
	//connect 2nd consumer to 2nd fifo
	
	// Run the simulation till sc_stop is encountered
	sc_start();

	return 0;
}

