#include "systemc.h"
#include "Producer.h"
#include "Consumer.h"

int sc_main(int argc, char* argv[])
{
	// generating the sc_signal
	sc_signal<int> data_sig;
	//generate clock with a tick (positive value) every 10 ms 
	sc_clock sig_clock("sig_clock", 10, SC_MS);

	// generating the modules
	Producer prod1("Producer1");
	Consumer cons1("Consumer1");

	// connecting modules via signals
	prod1.data(data_sig);
	cons1.data(data_sig);
	//connect clock
	prod1.clock(sig_clock);
	//prod1.clock(sig_clock);
	// Run the simulation till sc_stop is encountered or till 200 ms have passed
	sc_start(200, SC_MS);

	return 0;
}

