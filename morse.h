/*
 * morse.h
 *
 *  Created on: Oct 24, 2016
 *      Author: luanna
 */
 
#ifndef MORSE_H
#define MORSE_H

char * mcodestring(char);

#define LED_ON()  	if ((write_to_LED = fopen(LEDBrightness, "r+")) != NULL) \
		{fwrite("1", sizeof(char), 1, write_to_LED); \
		fclose(write_to_LED);}

#define LED_OFF() if ((write_to_LED = fopen(LEDBrightness, "r+")) != NULL) \
		{fwrite("0", sizeof(char), 1, write_to_LED); \
		fclose(write_to_LED);}

#endif




