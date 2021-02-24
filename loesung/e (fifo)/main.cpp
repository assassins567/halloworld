#include "systemc.h"
#include "Producer.h"
#include "Consumer.h"

int sc_main(int argc, char* argv[])
{
	// generating the sc_signal
	sc_fifo<int> data_fifo(1);
	sc_fifo<int> data2_fifo(1);

	// generating the modules
	Producer prod1("Producer1");
	Consumer cons1("Consumer1");
	Consumer cons2("Consumer2");

	// connecting moduleports
	prod1.data(data_fifo);
	cons1.data(data_fifo);

	prod1.data2(data2_fifo);
	cons2.data(data2_fifo); //braucht einen eigenen fifo (fifos dürfen nur von einem Prozess gelesen werden)

	// Run the simulation till sc_stop is encountered
	sc_start();

	return 0;
}

