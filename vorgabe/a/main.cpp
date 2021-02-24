#include "systemc.h"
#include "Producer.h"
#include "Consumer.h"

int sc_main(int argc, char* argv[])
{
	// generating the sc_signal
	sc_signal<int> sig_num;
	// generating the modules
	Consumer consumer("Consumer");
	Producer producer("producer");

	// connecting modules via signals
	consumer.num(sig_num);

	producer.num(sig_num);

	// Run the simulation till sc_stop is encountered
	sc_start();

	return 0;
}

