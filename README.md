#include <stdio.h>
int main(){
	int n,i,j;
	
	//The size of squar matrix (n*n)
	printf("add the dimension of the squar matrix (n*n):");
	scanf("%d",&n);
	
	//Add the elements of the squar matrix (n*n)
	int A[n][n];
	
	printf("add the values of elements of matrix \n");
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("A[%d][%d] =   ",i,j);
			scanf("%d",&A[i][j]);
		}
	}
	
	//The matrix befor the swap
    printf("Matrix befor swapping : \n");
    for (i=0;i<n;i++){
    	for(j=0;j<n;j++){
    		printf("%d",A[i][j]);
    	}
    	printf("\n");
    }
	
	//Swap upper and lower triangles
	for(i=0;i<n;i++){ 
		for(j=i+1;j<n;j++){
		int temp = A[i][j];
		A[i][j] = A[j][i];
		A[j][i] = temp;
		}
	}
    //The new matrix after the swap
    printf("\nMatrix after swapping upper and lower triangles : \n");
    for (i=0;i<n;i++){
    	for(j=0;j<n;j++){
    		printf("%d",A[i][j]);
    	}
    	printf("\n");
		}
		return 0;
}
