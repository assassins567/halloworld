#include <systemc.h>

#ifndef PRODUCER_H_
#define PRODUCER_H_

SC_MODULE(Producer){

	sc_out<int> data;

	sc_in<bool> clock; //gibt den Takt vor

	int generatedNumber;
	int i;

	SC_CTOR(Producer){
		data.initialize(42); //initialisiert den Ausgangsport mit dem angegebenen Wert (ansonsten 0)
		SC_THREAD(produce);
		dont_initialize(); //normalerweise werden alle threads und methoden einmal im Konstruktor ausgeführt, hiermit nicht (nur bei statischer Sensitivitätsliste anwenden)
		sensitive << clock.pos();
	}

	void produce()
	{
		i = 0;
		while(i < 10) {
			generatedNumber = rand();
			cout << "[" << sc_time_stamp() << "](" << name() << "): generated " << generatedNumber << endl;
			data.write(generatedNumber);
			//data = generatedNumber; //geht bei SC_SIGNAL auch

			wait(clock.posedge_event()); //auf positive Taktflanke warten
			//wait(clock.negedge_event()); //auf negative Taktflanke warten
			//wait(clock.value_changed_event()); //auf nächste Taktflanke warten
			i++;
		}
	}

};

#endif

 

