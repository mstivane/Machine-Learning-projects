#include "jpg.h"
#include "mnist.h"
#include "stdio.h"

float distance(float* vect1, float* vect2);/* vect1[i]*/






int main(int argc, char** argv)
{
  
   
    float** data = read_mnist("t10k-images.idx3-ubyte"); // readmnist definie dns mnist.h//
    float* labels = read_labels("train-labels.idx1-ubyte"); 
    float** test_images= read_mnist("t10k-images.idx3-ubyte")
   

    return 0;
}


float distance(float* vect1, float* vect2)
{
	
	float distance = 0;

	for (int i=0; i<784 ; i++)
	{
		
		distance = distance + (vect1[i]-vect2[i])*(vect1[i]-vect2[i]);
	
	return distance;
		
     }
	
}

