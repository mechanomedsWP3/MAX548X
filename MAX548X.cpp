/*****
 * MAX548X.cpp
 *
 * Created on: 11-16-2016
 *     Author: Robert F. Chapman <Robert.F.Chapman@gmail.com>
 *             Copyright (c) 2016-Current Robert F. Chapman
 *  
 *  This file is part of MAX548X Library for Arduino Micro(s).
 *
 *  This Library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.

 *  This Library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Foobar.  If not, see <https://www.gnu.org/licenses/>.
 */
 
#include "MAX548X.h"

MAX548X::MAX548X(spi_inst_t *SPI, uint8_t chipSelect)
{
     _selectPin = chipSelect;
     _SPI = SPI;
}


void MAX548X::begin(void)
{
     gpio_put(_selectPin, 1); 
}


void MAX548X::setWiper(uint16_t value)
{
     uint8_t command = MAX548X_WRITE_WIPER;
     uint16_t shifted_value = (value << 6);

     gpio_put(_selectPin, 0); 
     spi_write_blocking(_SPI, &command, 1); 
     spi_write16_blocking(_SPI, &shifted_value, 1);
     gpio_put(_selectPin, 1);
}


void MAX548X::writeWiper()
{
    uint8_t command = MAX548X_COPY_WIPER_TO_NV;
       
    gpio_put(_selectPin, 0); 
    spi_write_blocking(_SPI, &command, 1); 
    gpio_put(_selectPin, 1); 
}


void MAX548X::readWiper()
{
    uint8_t command = MAX548X_COPY_WIPER_TO_NV;
       
    gpio_put(_selectPin, 0); 
    spi_write_blocking(_SPI, &command, 1); 
    gpio_put(_selectPin, 1); 
}

