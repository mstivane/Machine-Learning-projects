#include "jpg.h"
#include "mnist.h"


float distance( int* v1, int*v2);
int main()
{
    float** data = read_mnist("t10k-images.idx3-ubyte"); // readmnist definie dns mnist.h//
    float* labels = read_labels("train-labels.idx1-ubyte"); 
    float** test_images= read_mnist("t10k-images.idx3-ubyte");
         
    for(int i=0; i<10000; i++) 
    {
		float mind  = -1;
		int NN;// +proche voisin //
       for(int j=0; j<60000; j++) // comparaison image i et j//
       {
		   float distance1=  distance(test_images[i], data[j]);
		   
		   if(distance1<mind || mind == -1)
		   {
			   
			   mind = distance1;
			   NN = j;
		   }
		   
	   }
       int inference =  labels[NN];
       save_jpg(test_images[i], 28, 28, "%u/%u.jpg", inference, i);
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
