#include "../inc/libmx.h"

int mx_sqrt(int x){

//algorithm Gerona


    if (x <= 0)
    {
        return 0;
    }
    
	#define DEVIATION 0.000001
	
	float numeric = x;
	
	float hypothesis = numeric / 2;
	
	while( hypothesis - (numeric / hypothesis) > DEVIATION ){
		
		hypothesis = (hypothesis + numeric / hypothesis) / 2;
			
	}

    if (hypothesis - (int)hypothesis == 0)
    {
        return hypothesis;
    }
    
    
    return 0;

}

