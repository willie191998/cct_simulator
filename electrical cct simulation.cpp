/*circuit simulation programmed by WILLIE ARTHUR ANORUE 
20:56:40 2020-08-09 */

#include"simulation.h"

using namespace std;

//time,accuracy variables
/* r is no of sum in integrator per unit of  c
    c is the time of circuit simulation that equal real time
    t is the no of c to simulate the cct
    */
 /*note that the variable criterion here is nis used for loops, a is used for local function variable & b for input variable 
int r=1000, t=20; 
float c=0.1, g;  */
 

void Componentarrange_input()
{
//string saves name user give to comp
	string s;
	int  n,
          n1,
          a,
          a2,
          b1,
          b2,
          nL=0,
	      nC=0,
	      nR=0,
	      nVS=0,
	      nCS=0,
          xendcount,          
	      ycount=0,
	      xcount=0,
	      y1count=0,
	      x1count=0,
	      y2count=0,
	      x2count=0;
	float b;
	
	Comp_pointer A[10][10];
	Stack S;
   
	
  cout<<"select componet input \n put name of component using R1,C1,V1\n";
  cin>>s;
  
 for (n=1 ; ; n++ ) {
 	
 if (n==1){  
                  }
         
 else {
          s= S.pop1();
             }
 
 cout<<"put attributes of "<<s<<"\n";
 
 //n+=1;
  
  
  cout<<"press\n1. INDUCTR\n2. CAPACITOR\n3. RESISTOR\n4. DC VOLTAGE SOURCE\n5. DC CURRENT SOURCE\n6. EXIT\n";
  cin>>b2;
  
  cout<<"check if variables of component have been given before, put 1 for yes and 0 for no";
  cin>>b1;
 
   //test if comp was in former loop before

  if ( b1==0  ){
  	
  	 if (n==1){  
                  }
       else {          
  	xcount+=1; }
    
  switch (b2){
  	
  	
   case 1:
//set attributes of components
    Ind[nL].setname(s);
    cout <<"input inductance of inductor";
    cin>>b;
    Ind[nL].setvalue(b);
    cout <<"input initiatial current of inductor";	
  	cin>>b;
  	Ind[nL].setinitcurrent(b);
    cout <<"input polarity of inductor i.e -1 or 1";
     cin>>b2;
     Ind[nL].setpolarity(b2);
     cout<<"input it's number of connectors" ;
     cin>>b2;
//store next connected component in stack 
      for (n1=1; n1<=b2; n1++){
     	 cout<<"put connector "<<n1<<" use words like R1,L1,C1,VS1,CS1";
     	cin>>s;
     	S.push(s,ycount,xcount);
     	 }
      Ind[nL].addcurrentno(ycount);
      Ind[nL].setxarrayno(xcount);
      Ind[nL].setcomptypeno(nL);
     A.A[ycount][xcount] = &Ind[nL];
     nL+=1;
     break;
     
    case 2:
  //  Capacitor Cap[nC];
    Cap[nC].setname(s);
    cout <<"input capacitance of capacitor";
    cin>>b;
    Cap[nC].setvalue(b);
    cout <<"input initial voltage of capacitor";	
    cin>>b;
    Cap[nC].setinitvoltage(b);
    cout <<"input polarity of capacitor i.e -1 or 1";
     cin>>b2;
     Cap[nC].setpolarity(b2);
     cout<<"input it's number of connector";
     cin>>b2;
     for (n1=1; n1<=b2; n1++){
     	cout<<"put connector "<<n1<<" use words like R1,L1,C1,VS1,CS1";
     	cin>>s;
     	S.push(s,ycount,xcount);
     	  }
      Cap[nC].addcurrentno(ycount);
      Cap[nC].setxarrayno(xcount);
      Cap[nC].setcomptypeno(nC);
      A.A[ycount][xcount] = &Cap[nC];
      nC+=1;
     break;
     
     case 3:
  //  Resistor Res[nR];
    Res[nR].setname(s);
    cout <<"input resistance of resistor";
    cin>>b;
    Res[nR].setvalue(b);
    Res[nR].setpolarity(1);
    cout<<"input it's number of connectors";
     cin>>b2;
     for (n1=1; n1<=b2; n1++){
     	cout<<"put connector "<<n1<<" use words like R1,L1,C1,VS1,CS1";
     	cin>>s;
     	S.push(s,ycount,xcount);
     	}
     Res[nR].addcurrentno(ycount);
     Res[nR].setxarrayno(xcount);
     Res[nR].setcomptypeno(nR);
     A.A[ycount][xcount] = &Res[nR] ;
     nR+=1;
     break;
     
     case 4:
   //  Voltagesource VS[nVS];
     VS[nVS].setname(s);
    cout <<"input voltage of voltage source";
     cin>>b;
     VS[nVS].setvalue(b);
     cout <<"input polarity of inductor i.e -1 or 1";
     cin>>b2;
     VS[nVS].setpolarity(b2);
    cout<<"input it's number of connectors.";
     cin>>b2;
     for (n1=1; n1<=b2; n1++){
     	cout<<"put connectors "<<n1<<"use words like R1,L1,C1,VS1,CS1";
     	cin>>s;
     	S.push(s,ycount,xcount);
        }
     VS[nVS].addcurrentno(ycount);
     VS[nVS].setxarrayno(ycount);
     VS[nVS].setcomptypeno(nVS);
     A.A[ycount][xcount] = &VS[nVS] ;
     nVS+=1;
     break;
     
      case 5:
  // Currentsource CS[nlS];
   cout <"input current of source";	
  	cin>>b;
  	CS[nCS].setvalue(b);
      cout <<"input polarity of current source i.e -1 or 1";
     cin>>b2;
     CS[nCS].setpolarity(b2);
     cout<<"input it's number of connectors.";
     cin>>b2;
     for (n1=1; n1<=b2; n1++){
     	cout<<"put connectors "<<n1<<"use words like R1,L1,C1,VS1,CS1";
     	cin>>s;
     	S.push(s,ycount,xcount);     	
     }
     CS[nCS].addcurrentno(ycount);
     CS[nCS].setxarrayno(xcount);
     CS[nCS].setcomptypeno(nCS);
     A.A[ycount][xcount] = &CS[nCS] ;
     nCS+=1;
     break;
     
     case 6:
    
     default:  
     cout <<"the program would simulate the circuit now";
     exit(1);
  }
  
  S.pop2();
  S.pop3(); 
  
  }
  
  else {
  	
      if (a==1){
		for (n=0; ;n++){
   	if (Ind[n].getname()==s){
   	    x2count=Ind[n].getxarrayno();
   	    break;  }
   	 }  }
   	     
     else  if (a==2){
		  for (n=0; ;n++){
      if (Cap[n].getname()==s){
     	 x2count=Cap[n].getxarrayno();
   	     break;  }
   	    } 
   	 }	 
        
      else if (a==3){
	  for (n=0; ;n++){
      if (Res[n].getname()==s){
   	      x2count=Res[n].getxarrayno();
   	      break;  }
   	 } }
   	
      else if (a==4){
	  for (n=0; ;n++){
      if (VS[n].getname()==s){
   	      x2count=VS[n].getxarrayno();
   	      break;  }
   	 } }
   	 
   	else  if  (a==5){
	   for (n=0; ;n++){
   	if (CS[n].getname()==s){
   	    x2count=CS[n].getxarrayno();
   	    break; }
		}  }
 
      
  if (x1count < x2count){
  	
  	for (n1=0;  ; n1++){
  	if ((x2count+1)==x1count){
             break;  }
  	    xcount++;
  		x2count++;
  	   if (x2count > xendcount){
  		   x2count=0;
  	   }
             
A.A[ycount][xcount]=A.A[ycount-1][x2count];
         
     }
  }
  
 /* if (x1count == x2count){
  	
  	for (n1=0;  ; n1++){
  	if ((x2count-1)==x1count){
             break;  }
  	    xcount++;
  		x2count--;
  	   if (x2count > 0){
  		   x2count=xendcount;
  	   }
             
A.A[ycount][xcount]=A.A[ycount-1][x2count];        
     }
  } */
  
  else {
  	
  	for (n1=0;  ; n1++){
  	if ((x2count-1)==x1count){
             break;  }
  	    xcount++;
  		x2count--;
  	   if (x2count > 0){
  		   x2count=xendcount;
  	   }
             
A.A[ycount][xcount]=A.A[ycount-1][x2count];
         
     }
  }
      
 
  xendcount=xcount;
  y1count=S.pop2();
  x1count=S.pop3();
  A.dimA[ycount]=xcount ;
  ycount+=1;
  xcount=0;
        
  if ((y1count==0)&&(x1count==0)){
  	nocurrent =ycount - 1;
 
        break;
          } 
       }
    }
 
noxvariables = nocurrent + nCS + nL ;
/*
float* X = new float [novariables];
 
 float* C = new float [novariables][novariables] ;
 //use ycount to creat anwser values use Y[]
Answer Y[novariables ]; */

//check through all A array use current no compute Y and C arrays
for (n2=0; n2 < ycount ; n2++){

//xendcount captures the end of each xcount in array A replace with 5 below
 	for (n1=0; n1< 5 ; n1++) {
 		int a, a1, a2, n1, ,b;
 	    a=A.A[ n2][n1]->getcurrentsize();
 	  for (n=0; n < a; n++){
 	   a1=A.A[ n2][n1 ]->getcurrentno(n);
 	   C[n2][a1] += 0.05; //A.A[n2][n1]->getintres();
 	  }
 	  a2=A.A[ n2][n1]->gettypeno();
 	  a1=A.A[ n2][n1]->getcomptypeno();
 	  switch(a2)
 	  
 	  case 1:
 	  break;
 	  
 	  case 2:
Y[n2].putvalue(Cap[a1]);
 	  break;
 	  case 3:
 	  break;
 	  case 4:
Y[n2].putvalue( VS[a1]);
       break;
 	  case 5:
 	  break;
    }
 }
 
 } 
 

      