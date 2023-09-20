#include <stdio.h>
#include <pthread.h>

void input_matrix() {

    int m, n, p, q;
    int firstMatrix[][n],secondMatrix[][q], result[][q];
    
    printf("Enter the row and column of first matrix:\n");
    scanf("%d %d", &m, &n);

    printf("Enter the row and column of second matrix:\n");
    scanf("%d %d", &p, &q);

    if (n != p) {
        printf("Matrix Multiplication is not possible\n");
        return 1;
    }
    printf("Enter the elements of the first matrix:\n");

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &firstMatrix[i][j]);
        }
    }
 //}

 //void mult_matrix(int m, int n, int p, int q, int firstMatrix[][n], int secondMatrix[][q], int result[][q]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            result[i][j] = 0; 
            for (int k = 0; k < n; k++) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
    
    printf("Matrix multiplication done !!!!!!!!!!!!!!!!\n");
}

//void print_matrix() {
//    printf("Multiplication of matrix is:\n");
//
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < q; j++) {
//            printf("%d ", result[i][j]);
//        }
//        printf("\n");
//    }
//}

int main() {

    int i=0,not;
    
    printf("Enter the no. of threads\n");
    scanf("%d", &not);
    pthread_t tid[not];
    
   
    pthread_create(&tid[0], NULL, input_matrix, NULL);
     // matrix multiplication thread reamaining
    
    for ( i=0;i<not;i++){
        pthread_join(tid[i], NULL);
    }
    
    pthread_exit(0);

    return 0;
}

