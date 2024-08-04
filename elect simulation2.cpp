
#include"simulation.h"

//component class definition
class Components{
protected: 
        string m_name;
          float m_current,
                   m_Ri,
                   m_voltage,                  
                   m_value;
              int m_pole,
                   m_currentsize,
                   m_xarrayno,
                   m_comptypeno,
                   m_currentno[5] ;
   
public:
            void setname(string a){   
            m_name=a; 
            m_Ri=0.05; m_currentsize=0; }
            void setvalue(float a){ m_value=a; }
            void setpolarity(int a){ m_pole=a; }  
            void setxarrayno(int a){ m_xarrayno=a;}
             void setcomptypeno(int a){ m_comptypeno=a; }
                
             string getname(){
                	return m_name; }
             float getintres(){
             	   return m_Ri; }
             int getpolarity(){
                	return m_pole; }  
             float getvalue(){
                	return m_value; }
             int getxarrayno(){
                  return m_xarrayno; }
             int getcurrentsize(){
                   return m_currentsize; }
             int  getcurrentno (int a1) {
                   return m_currentno[a1];
                   }
             int getxcomptypeno(){
                  return m_comptypeno; }
         float getvoltage ( ) {
         	return m_voltage; }
         void getcurrentvalue( ) {
         	     m_current = 0;
         	for (n=0; n < m_currentsize; n++) {
         		int a;
         		a=m_currentno[n];
          	   m_current += Current[a];
         	   }
         }	
//  float evaluatevoltage ( ) {
         	
             	
             void addcurrentno( int a1 ){
//  store number of current through it
//  float *currentno = new float[1];
 m_currentno[m_currentsize] = a1;
 m_currentsize += 1;
            }
     };

//A class pointer to components
class Comp_pointer{
	public:
        Components *  A[10][10] ;
        int dimA[10] ;
   } ;

//inductor class definition    
class Inductor : public Components { 
private:
             float m_I0;
public: 
           void setinitcurrent(float a){
           	m_I0=a ;  }
             int gettypeno ( ) {
             	return 1; }
                 } ;

//capacitor class definition           
class Capacitor : public Components { 
private:
             float m_V0 ;
public:
           void setinitvoltage(float a){
           	m_V0=a ;  }
             int gettypeno ( ) {
             	return 2; }
     };

//resistor class definition 
 class Resistor : public Components{  
 public:
              int gettypeno ( ) {
             	return 3; }      
    } ;
 
//voltagesource class definition   
 class Voltagesource : public Components{ 
 public:
              int gettypeno ( ) {
             	return 4; }      
      } ;

//currentsource class definition     
class Currentsource : public Components{  
public:
             int gettypeno ( ) {
             	return 5; }
       } ;      

//stack implementation 
 class Stack {
 	private:
 	      int stkno=0,
 	            element2[10],
                 element3[10] ;
    
      string element1[10];
 	
 	public:
 	
     Stack () {
         element1[0]="empty";
         element2[0]=0;
         element3[0]=0;  }	
 
 void push(string s, int n1, int n2){
	stkno++;
	element1[stkno]=s;
	element2[stkno]=n1;
	element3[stkno]=n2;
    
}

string pop1(){
	stkno--;
	return element1[stkno+1];
}

int pop2(){
	return element2[stkno+1];
}

int pop3(){
	return element3[stkno+1];
    }    
               
 };

//class definition for y values used in matrix evaluation 
 class Answer {
    private:
           int m_no;
        float *m_comp[5],
                   m_value;
                 
	public: 
	  void putvalue(Components a1) {
	       m_comp[m_no]=&a1; 
	       m_no+=1; }
	  
	   void setvalue() {
	   for (int n=0; n<m_no; n++) {
	      m_value += m_comp[n]->getvoltage; }
	  }
	   float getvalue() {
	   	return m_value; }   
	
   } ;

