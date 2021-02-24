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
	Producer prod2("Producer2");
	Consumer cons1("Consumer1");

	// connecting moduleports
	prod1.data(data_fifo);
	cons1.data(data_fifo);
	prod2.data(data2_fifo); //Fifos dürfen maximal 1 Writer haben, also brauchen wir hier 2 fifos und einen zusätzlich port im consumer
	cons1.data2(data2_fifo);

	// Run the simulation till sc_stop is encountered
	sc_start();

	return 0;
}

