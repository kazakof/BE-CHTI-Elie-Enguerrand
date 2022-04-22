#include "GestionSon.h"
#include "Affichage_Valise.h"
#include "DriverJeuLaser.h"
#define SEUIL_AMPLITUDE 0x3c2e1

extern int DFTModuleAuCarre ( short int * Signal64ech, char k);


short int dma_buf[64];
int DFT[4];
int tab_Score[4]={0};
int compteurs[4]={0};


void Callback_Systick(void){
	Start_DMA1(64);
	Wait_On_End_Of_DMA1();
	Stop_DMA1;
	DFT[0]=DFTModuleAuCarre(dma_buf,17);
	DFT[1]=DFTModuleAuCarre(dma_buf,19);
	DFT[2]=DFTModuleAuCarre(dma_buf,22);
	DFT[3]=DFTModuleAuCarre(dma_buf,24);
	for(int i = 0;i<4;i++){
		if(DFT[i]>SEUIL_AMPLITUDE){
			compteurs[i]++;
			if (compteurs[i]==11){
				tab_Score[i]++;
				StartSon();
				compteurs[i]=0;
			}	
		}else{
			compteurs[i]=0;
		}
	}
	
	
}

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================
	
	//Initialisation partie son
	Timer_1234_Init_ff( TIM4, 6552);
	PWM_Init_ff(TIM3,3,720);
	GPIO_Configure(GPIOB, 0, OUTPUT, ALT_PPULL);
	Active_IT_Debordement_Timer( TIM4, 2, CallbackSon );

	//Initialisation partie DFT
	Systick_Period_ff(5*72000);
	Systick_Prio_IT( 10 , Callback_Systick );
	SysTick_On;
	SysTick_Enable_IT ;
	Init_TimingADC_ActiveADC_ff( ADC1, 72 );
	Single_Channel_ADC( ADC1, 2 );
	Init_Conversion_On_Trig_Timer_ff( ADC1, TIM2_CC2, 225 );
	Init_ADC1_DMA1( 0, dma_buf );
	


	// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
	CLOCK_Configure();


		
	
	

//============================================================================	
	

while	(1)
	{
	}

}

