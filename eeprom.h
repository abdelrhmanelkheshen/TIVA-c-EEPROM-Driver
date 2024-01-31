
   /******************************************************************************
 *
 * [FILE NAME]: <Eeprom.h>
 *
 * [AUTHOR]: <Abdelrhman Hesham Mohamed>
 *
 * [DATE CREATED]: <6/1/2024>
 *
 * [DESCRIPTION]: <Header file for Eeprom>
 *
 *******************************************************************************/
#ifndef EEPROM_H
#define EEPROM_H
#include "std_types.h"


#define Cycles_delay 6

void eeprom_error_recovery(void);
void eeprom_init(void);
void eeprom_write(uint32 data,uint8 address,uint8 count);
uint32 eeprom_read(uint8 address,uint8 count);



#endif