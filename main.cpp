
#include"simulation.h"

using namespace std;

Answer Y[5];
Inductor Ind[5];
Capacitor Cap[5];
Resistor Res[5];
Voltagesource VS[5];
Currentsource CS[5];

float  X[5] ,
         C[5][5] ,
         Current[5] ;
	
int main( )
	{
    
    int n, n1; 
    
    Comparrange_input() ;
		
	for (n1=0; n1 < 4; n1++) {	
		for (n=0; n < 4; n++) {
			cout<<C[ n1][n]<<std::endl;
		}
    }
		
	for (n=0; n < 4; n++) {
	        //Y[n].setvalue();
	    	//cout<<Y[n].getvalue<<std::endl;
	} 

}