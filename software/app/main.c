#include "system.h"
#include "unistd.h"
#include "altera_avalon_pio_regs.h"



int main(void){
	int i=0;
	while(1){
		if (IORD_ALTERA_AVALON_PIO_DATA(PIO_1_BASE)==0x0){
			for (i=0;i<8;i++){
				IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,0x01 << i);
				usleep(25000);
			}
			
			for (i=0;i<8;i++){
				IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,0x70 >> i);
				usleep(25000);
			}
		}
	}
	return 0;
}
