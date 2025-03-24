#pragma once

#include "pico/stdlib.h"
#include "hardware/spi.h"

#define MAX548X_WRITE_WIPER         0b00000000
#define MAX548X_COPY_WIPER_TO_NV    0b00100000
#define MAX548X_NV_TO_WIPER         0b00010000

class MAX548X
{
    public:
        MAX548X(spi_inst_t *SPI, uint8_t chipSelect);
        
        void begin(void); 
        void setWiper(uint16_t value);
        void readWiper();
        void writeWiper();
    private:
        spi_inst_t * _SPI;
        unsigned int _selectPin;
};

