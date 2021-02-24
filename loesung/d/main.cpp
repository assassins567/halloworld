#include "systemc.h"
#include "Producer.h"
#include "Consumer.h"

int sc_main(int argc, char* argv[])
{
	// generating the sc_signal
	sc_fifo <int> data_fifo(1);
	
	// generating the modules
	Producer prod1("Producer1");
	Consumer cons1("Consumer1");

	// connecting modules via signals
	prod1.data_fifo(data_fifo);
	cons1.data_fifo(data_fifo);

	// Run the simulation till sc_stop is encountered
	sc_start(200, SC_MS);

	return 0;
}

