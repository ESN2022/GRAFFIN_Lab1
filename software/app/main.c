//---------------------pooling sans vitesse-------------------

/*
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
*/


//---------------------interrupt sans vitesse-------------------

/*
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "alt_types.h"
#include <sys/alt_irq.h>
#include "unistd.h"

static void handle_button_interrupts(void* context)
{
	int i=0;
	for (i=0;i<8;i++){
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,0x01 << i);
		usleep(25000);
	}
	
	for (i=0;i<8;i++){
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,0x70 >> i);
		usleep(25000);
	}	

	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_1_BASE, 0x1);

}

int main()
{
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PIO_1_BASE, 0x1);
	//Reset the edge capture register. 
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_1_BASE, 0x1);
	//Register the ISR. 

	alt_ic_isr_register(PIO_1_IRQ_INTERRUPT_CONTROLLER_ID, PIO_1_IRQ, handle_button_interrupts, NULL, 0x0);
	//init_button_pio();

	while (1){}

	return 0;
}
*/

//---------------------interrupt avec vitesse-------------------


#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "alt_types.h"
#include <sys/alt_irq.h>
#include "unistd.h"
int time=25000;

static void handle_button_interrupts(void)
{
	int i=0;
	for (i=0;i<7;i++){
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,0x01 << i);
		usleep(time);
	}
	
	for (i=7;i>=-1;i--){
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,0x01 << i);
		usleep(time);
	}	

	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_1_BASE, 0x1);

}


static void handle_switch_interrupts(void)
{
	int val=0;
	val=IORD_ALTERA_AVALON_PIO_DATA(PIO_2_BASE);
	
	switch(val){
			case 0:
				time = 160000;
				break;
			case 1:
				time = 150000;
				break;
			case 2:
				time = 140000;
				break;
			case 3:
				time = 130000;
				break;
			case 4:
				time = 120000;
				break;
			case 5:
				time = 110000;
				break;
			case 6:
				time = 100000;
				break;
			case 7:
				time = 90000;
				break;
			case 8:
				time = 80000;
				break;
			case 9:
				time = 70000;
				break;
			case 10:
				time = 60000;
				break;
			case 11:
				time = 50000;
				break;
			case 12:
				time = 40000;
				break;
			case 13:
				time = 30000;
				break;
			case 14:
				time = 20000;
				break;
			case 15:
				time = 10000;
				break;
		}

	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_2_BASE, 0xf);

}


int main()
{
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PIO_1_BASE, 0x1);
	//Reset the edge capture register. 
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_1_BASE, 0x1);
	//Register the ISR. 

	alt_ic_isr_register(PIO_1_IRQ_INTERRUPT_CONTROLLER_ID, PIO_1_IRQ, handle_button_interrupts, NULL, 0x0);

	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PIO_2_BASE, 0xf);
	//Reset the edge capture register. 
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_2_BASE, 0xf);
	//Register the ISR. 

	alt_ic_isr_register(PIO_2_IRQ_INTERRUPT_CONTROLLER_ID, PIO_2_IRQ, handle_switch_interrupts, NULL, 0x0);


	while (1){}

	return 0;
}
