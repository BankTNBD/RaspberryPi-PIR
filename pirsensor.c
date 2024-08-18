#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

#define PIRPin       7

int main(void)
{
	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !");
		exit(1);
	}
	
	pinMode(PIRPin,INPUT);

	printf("\n");
	printf("========================================\n");
	printf("|              Alarm                   |\n");
	printf("|    ------------------------------    |\n");
	printf("|        PIR connect to GPIO7          |\n");
	printf("|                                      |\n");
	printf("|                                      |\n");
	printf("|                                      |\n");
	printf("========================================\n");
	printf("\n");
	delay(30000);
	system("amixer -D pulse sset Master 50%");
	system("mpg123 /home/banky/beep.mp3");
	delay(1000);
	system("amixer -D pulse sset Master 100%");
	while(1){
		if(!(digitalRead(PIRPin))){
		printf("\n");
		printf("-------------------|\n");
		printf("|    no alarm...   |\n");
		printf("-------------------|\n");
		delay(500);
		}
		else{
		printf("\n");
		printf("===================|\n");
		printf("|      alarm...    |\n");
		printf("===================|\n");
		system("mpg123 /home/banky/eagle-scream-112940.mp3  >/dev/null 2>&1");
		delay(2000);
		}
	}

	return 0;
}

