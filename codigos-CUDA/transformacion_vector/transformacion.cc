#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;


//**************************************************************************
int main(int argc, char *argv[])
//**************************************************************************
{
int N;
if (argc != 2)
  { cout << "Uso: transformacion Num_elementos  "<<endl;
    return(0);
  }
else
  {N = atoi(argv[1]);  
  }


//* pointers to host memory */
float *A, *B;

//* Allocate arrays a, b and c on host*/
A = new float[N+4];
B = new float[N];
float mx; // maximum of B

//* Initialize array A */
for (int i=2; i<N+2;i++)
  A[i]= (float) (1  -(i%100)*0.001);
A[0]=0.0;
A[1]=0.0;
A[N+2]=0.0;
A[N+3]=0.0;
   
float Ai, Aim1, Aim2, Aip1, Aip2;    

// Time measurement  
double t1=clock();
  

// Compute B[i] and mx
for (int i=2; i<N+2;i++)
  { const int iB=i-2;
    Aim2= A[i-2];
    Aim1= A[i-1];  
    Ai=A[i];
    Aip1= A[i+1];  
    Aip2= A[i+2];
    float stencil=fabs((2*Aim1*Aim1-3*Aip1*Aip1)/4*Ai+(5*Aim2+Ai*Ai-3*Aip1)/24*Ai); 
    B[iB]=sqrt(stencil);
    mx=(iB==0)?B[0]:max(B[iB],mx);
  }

  double t2=clock();
  t2=(t2-t1)/CLOCKS_PER_SEC;
  


cout<<"................................."<<endl;
//for (int i=0; i<N;i++)    cout<<"B["<<i<<"]="<<B[i]<<endl;
cout<<"................................."<<endl<<"El valor máximo en B es:  "<<mx<<endl;

cout<<endl<<"N="<<N<<"  ........  Tiempo gastado CPU= "<<t2<<endl<<endl;


//* Free the memory */
delete(A); 
delete(B);

}
