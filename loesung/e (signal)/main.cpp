#include "systemc.h"
#include "Producer.h"
#include "Consumer.h"

int sc_main(int argc, char* argv[])
{
	// generating the sc_signal
	sc_signal<int> data_sig;

	// generating the modules
	Producer prod1("Producer1");
	Consumer cons1("Consumer1");
	Consumer cons2("Consumer2"); //zweiter consumer

	// connecting modules via signals
	prod1.data(data_sig);
	cons1.data(data_sig);
	cons2.data(data_sig); //wird an das gleiche Signal gebunden wie der erste consumer

	// Run the simulation till sc_stop is encountered
	sc_start();

	return 0;
}

