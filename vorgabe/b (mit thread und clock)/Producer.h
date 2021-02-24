#include <systemc.h>

#ifndef PRODUCER_H_
#define PRODUCER_H_

SC_MODULE(Producer){

	sc_out<int> data;
	//clock input
	sc_in<bool> clock;
	int generatedNumber;
	int i;

	SC_CTOR(Producer){
		data.initialize(42); //initialisiert den Ausgangsport mit dem angegebenen Wert (ansonsten 0)
		SC_THREAD(produce);
		dont_initialize();
		//sensitivity to clock
		sensitive << clock.pos();
	}

	void produce()
	{
		i = 0;
		while(i < 10) {
			generatedNumber = rand();
			cout << "[" << sc_time_stamp() << "](" << name() << "): generated " << generatedNumber << endl;
			data.write(generatedNumber);
			
			//wait for clock edge
			wait(clock.posedge_event());
			i++;
		}
	}

};

#endif

 

