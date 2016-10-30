
#include <stdio.h> /*for fopen, fclose */
#include <string.h> /*because of string compare*/
#include <unistd.h> /*because we have usleep()*/
#include "morse.h" /*mcodestring and LED_ON and LED_OFF*/


int main(int argc, char *argv[])
{

	if ( argc==3 && (!strcmp(argv[1],"-w")) ){
		int word_length = strlen(argv[2]);
		int i;

		for(i = 0; i <word_length;i++)
		{
			int word_index = argv[2][i];
			char *morse_letter = mcodestring(word_index);

			int count;
			int length_morse = strlen(morse_letter);

			for (count = 0; count <length_morse; count++){

				char dash_or_dot = morse_letter[count];

				FILE *write_to_LED = NULL;
				const char *LEDBrightness="/sys/class/leds/beaglebone:green:usr0/brightness";

				if (dash_or_dot == '-') {
					LED_ON();
					usleep(1000000);
					LED_OFF();
				}
				else if (dash_or_dot == '.'){
					LED_ON();
					usleep(500000);
					LED_OFF();
				}
				usleep(1000000);
			}
		}

	}
	else {
		printf("You had one job.");
	}

	return 0;

}


