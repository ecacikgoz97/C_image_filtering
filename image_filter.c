/*
 * ELEC230 - PE7
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define A(I,J) (*(a+(I)*numCols+(J)))
#define MAX_GRAYVAL 255
#define BUFFER_SIZE 50
void readFileToMat(char filename[],int *a, int numRows, int numCols){
    // Write a C function to read file content into a double array,
    /* YOUR CODE GOES HERE */
    int data;
    FILE *fp = fopen(filename, "r");
    if(fp!=NULL){
	for(int i=0; i < numRows; i++){
	    for(int j=0; j < numCols; j++){ 
	        if(fscanf(fp, "%d,", &data)==1)
		    *(a+i*numCols+j) = data;
	    }
	}
        fclose(fp);
    }
}
void printMatToFile(char filename[],int *m, int numRows, int numCols){
    // Write a C function to print a double array to an output file
    /* YOUR CODE GOES HERE */
    int data;
    FILE *fp = fopen(filename, "w");
    for(int i=0; i < numRows; i++){
        for(int j=0; j < numCols; j++){
            fprintf(fp, "%d ", *(m+i*numCols+j));
        }
        fprintf(fp, "\n");
    }
        fclose(fp);
}

void imNegate(int *n,int *m,int numRows, int numCols){
    // Write a C function to return the image negative of the original image
    /* YOUR CODE GOES HERE */
     for(int i=0; i < numRows; i++){
        for(int j=0; j < numCols; j++){
                *(n+i*numCols+j) = 255 - *(m+i*numCols+j);
            }
        }
}

void imChange(int *n,int *m,int numRows, int numCols, int changeVal){
    // Write a C function that updates pixel values as follows: output pixel = input pixel + changeVal
    /* YOUR CODE GOES HERE */
    for(int i=0; i < numRows; i++){
        for(int j=0; j < numCols; j++){
	    if (changeVal + *(m+i*numCols+j) > 255)
	        *(n+i*numCols+j) = 255;
	    
	    else if (changeVal + *(m+i*numCols+j) < 0)
	         *(n+i*numCols+j) = 0;
	    
	    else
                *(n+i*numCols+j) = changeVal + *(m+i*numCols+j);
        }
    }
}

int main(int argc, char* argv[]) {
    
    // Get your inputs that are passed using command line arguments.
     /* YOUR CODE GOES HERE */
    char *filename;
    int numRows,numCols, change;
    filename = argv[1];
    char *a = argv[2];
    char *b = argv[3];
    char *c = argv[4];

    numRows = atoi(a); 
    numCols = atoi(b);
    change =  atoi(c);

    int orgMat[numRows][numCols];
    readFileToMat(filename,&orgMat[0][0],numRows,numCols);
    
    // Get an image negative of your input image and write an output file name as \textit{input\_file\_name\_neg.txt}.
    /* YOUR CODE GOES HERE */
    char out_filename[] = "input_file_name_neg.txt"; 
    int negMat[numRows][numCols];
    imNegate(&negMat[0][0], &orgMat[0][0], numRows, numCols);
    printMatToFile(out_filename, &negMat[0][0], numRows, numCols);
    // Update your input image with the given changeVal, and write an output file name as \textit{input\_file\_name\_changeVal.txt}
    /* YOUR CODE GOES HERE */
    char out_filename2[] = "input_file_name_changeVal.txt";
    int chgMat[numRows][numCols];
    imChange(&chgMat[0][0], &orgMat[0][0],numRows, numCols, change);
    printMatToFile(out_filename2, &chgMat[0][0], numRows, numCols);
    return 0;
}
