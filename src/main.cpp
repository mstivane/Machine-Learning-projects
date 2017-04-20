#include "jpg.h"
#include "mnist.h"
#include "limits.h"

float distance( int* v1, int*v2);
float linear_classifier( float* w, float* x);
int main()
{
    float** data = read_mnist("train-images.idx3-ubyte"); // readmnist definie dns mnist.h : data = images[i][j]//
    float* labels = read_labels("train-labels.idx1-ubyte"); 
    float** test_images= read_mnist("t10k-images.idx3-ubyte");
    float* test_labels= read_labels("t10k-labels.idx1-ubyte");

    float* w=  new float[784];
    float* g= new float[784];
    float gamma = 0.02;

    // STEP 1: INITIALISATION //
    for(int i=0; i<784; i++) w[i]=(float)rand()*2/INT_MAX;

   // STEP 2 : LEARNING ( DONNÉES APPRENTISSAGE SEULEMENT) //
   for( int i=0; i<60000; i++)
   {
    // 	Calcul grad //

       int prediction = linear_classifier(w,data[i]);
       for( int j=0; j<784; j++) g[j]=0;
       int verite = (labels[i]==1)? 1 : -1;
        if(verite!= prediction)
 	 	{
        // ajouter w act ( w(t+1) = w(t) - gamma*y*x) //
       			for (int j=0; j<784; j++)
				{
					w[j] = w[j] + gamma*verite*data[i][j];
				}

  		}

    }

   // STEP 3 : TEST (DONNÉES TEST SEULEMENT)// 
    float E=0;
	for(int i=0; i<10000; i++)
    {
         printf("%u\n", i);
		printf("Erreurs : %f\n", E);
       float inference = linear_classifier(w, test_images[i]);
       save_jpg(test_images[i], 28, 28, "%u/%u.jpg", inference, i);
       if((inference ==1 && test_labels[i]!=1)|| (inference == -1 && test_labels[i]==1) )E++;
		
		{
			printf("Erreur=%0.2f%%\n ", (E*100)/i);
        }
			
		
    }


     
    return 0;
 }


float distance(int* v1, int* v2)
{
	float d;

	
	for (int i=0; i<784; i++)
	{
		
		d+= (v1[i]-v2[i])*(v1[i]-v2[i]);
		
       
	}
	
	return d;
}

float linear_classifier( float* w, float* x)
{

 float d= 0; 
for( int i =0; i<784; i++)
{
   d+= w[i]*x[i];
}
if(d>=0) return 1;
else return -1;
}
