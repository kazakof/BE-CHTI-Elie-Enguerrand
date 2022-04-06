

#include "DriverJeuLaser.h"


extern int DFTModuleAuCarre ( short int * Signal64ech, char k);

int a[64];

extern short int LeSignal[];

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
CLOCK_Configure();


	
	

//============================================================================	
	
	
while	(1)
	{
		for (int i=0; i<64;i++){
			a[i]=DFTModuleAuCarre(&LeSignal[0],i);
	}
}
}

