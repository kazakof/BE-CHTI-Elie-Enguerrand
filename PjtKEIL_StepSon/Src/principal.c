

#include "DriverJeuLaser.h"
#include "GestionSon.h"


int i=0;

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
CLOCK_Configure();

Timer_1234_Init_ff( TIM4, 6552);

PWM_Init_ff(TIM3,3,720);
GPIO_Configure(GPIOB, 0, OUTPUT, ALT_PPULL);
	
Active_IT_Debordement_Timer( TIM4, 2, CallbackSon );
//============================================================================	
	
	
while	(1)
	{
		if (i==1)StartSon();
	}
}

