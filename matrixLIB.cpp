
#include"simulation.h"

using namespace std;


class Matrix {
	private:
	
	public:
	      int xdim,
	            ydim,
	            n,
	            n1;
	            
	float*  Mmultiply (float A[ ][ 10], float X[ 10]) {
	  float Y[10 ], sum;
		
	  for (n1=0; n1<ydim; n1++) {
	  	sum=0 ;
		 for (n=0; n<xdim; n++) {
			 sum += A[ n1][ n]*X[n ];
			 }
			 Y[n1]=sum;
	     }
	   
	  return Y;
	  } 
    };