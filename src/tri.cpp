#include "jpg.h"
#include "mnist.h"



int main(int argc, char** argv)
{
    if(argc < 3) {fprintf(stderr, "Please provide two mnist file\n"); exit(1); } // demande mise en boite de 2 fichiers
    string path = argv[1];
    string path_labels = argv[2]; //  2 arguments necessaires
    float** data = read_mnist(path); // readmnist definie dns mnist.h//
    float* triage = read_labels(path_labels); 
    
  
    for(int i=0; i<60000; i++) {
        printf("%u\n, label=%u\n", i, (int)labels[i]); // affichage i//
        save_jpg(data[i], 28, 28, "%u/%04u.jpg", i/10000, i%10000, (int)labels[i],i); // savejpg definie dns jpg.h et %u ( ubytes)//
       
    }
    
    
    return 0;
}
