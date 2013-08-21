
#ifndef __MRF24JMACLAYER__
#define __MRF24JMACLAYER__

#include "mrf24j.h"
#include "MACLayer.h"
#include "arduino_debug.h"

class MRF24JMACLayer: public MACLayer{
    private:
      Mrf24j mrf;
      
    public:      
      MRF24JMACLayer(int pin_reset, int pin_chip_select, int pin_interrupt);
      bool init();
      MACTransmissionStatus send(const uip_lladdr_t* lladdr_dest, uint8_t* data, uint16_t length, int *number_transmissions);
      virtual bool receive(uip_lladdr_t* lladdr_src, uip_lladdr_t* lladdr_dest, uint8_t* data, uint16_t* length);
      const uip_lladdr_t* getMacAddress();
};

#endif
