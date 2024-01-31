
 /******************************************************************************
 *
 * [FILE NAME]: <Eeprom.c>
 *
 * [AUTHOR]: <Abdelrhman Hesham>
 *
 * [DATE CREATED]: <6/1/2024>
 *
 * [DESCRIPTION]: <Source file for Eeprom>
 *
 *******************************************************************************/
#include "std_types.h"
#include "eeprom.h"
#include "tm4c123gh6pm.h"
#include "Common_Macros.h"


void eeprom_init(void)
{
  SET_BIT(SYSCTL_RCGCEEPROM_R,0);
 
  for (volatile int n=0; n<Cycles_delay;n++){
  // do nothing
  }
  while(GET_BIT(EEPROM_EEDONE_R,0) == LOGIC_HIGH);

    if((GET_BIT(EEPROM_EESUPP_R,2) == LOGIC_HIGH) | (GET_BIT(EEPROM_EESUPP_R,3) == LOGIC_HIGH))
    {
      
    }
    SET_BIT(SYSCTL_SREEPROM_R,0);
    CLEAR_BIT(SYSCTL_SREEPROM_R,0);
      for (volatile int n; n<6;n++);
      //do nothing
  
    
    while ((GET_BIT(EEPROM_EEDONE_R,0)== LOGIC_HIGH)); 

        if((GET_BIT(EEPROM_EESUPP_R,2) == LOGIC_HIGH) | (GET_BIT(EEPROM_EESUPP_R,3) == LOGIC_HIGH))
        {
         
        }
    else
    {
    //do nothing 
    }
    
}

void eeprom_error_recovery(void)
{
        SET_BIT(EEPROM_EESUPP_R,0);
	while(GET_BIT(EEPROM_EEDONE_R,0) == LOGIC_HIGH);
}

void eeprom_write(uint32 data,uint8 address,uint8 count)
{
	EEPROM_EEBLOCK_R = count;//Block number
	EEPROM_EEOFFSET_R =  address; //offset within the block
	EEPROM_EERDWR_R = data; //data written 
  while ((GET_BIT(EEPROM_EEDONE_R,0)== LOGIC_HIGH)); 
}

uint32 eeprom_read(uint8 address,uint8 count)
{
	uint32 data;
	EEPROM_EEBLOCK_R = count;//Block number
	EEPROM_EEOFFSET_R =  address;
	data = EEPROM_EERDWR_R;
        while ((GET_BIT(EEPROM_EEDONE_R,0)== LOGIC_HIGH)); 
	return data;
}