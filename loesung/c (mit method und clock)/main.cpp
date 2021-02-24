#include "systemc.h"
#include "Producer.h"
#include "Consumer.h"

int sc_main(int argc, char* argv[])
{
	// generating the sc_signal
	sc_signal <int> data_sig;
	sc_clock clock_sig ("clock_sig", 10, SC_MS);
	
	// generating the modules
	Producer prod1("Producer1");
	Consumer cons1("Consumer1");

	// connecting modules via signals
	prod1.data(data_sig);
	prod1.clock(clock_sig);
	cons1.data(data_sig);
	cons1.clock(clock_sig);

	// Run the simulation till sc_stop is encountered
	sc_start(200, SC_MS);

	return 0;
}

