#include <stdio.h>
#include <time.h>
#include <math.h>

#define TEST_COUNT 10000

void printArray ( int * arr, int l, int shift ) {
    printf("{ ");
    for ( int i = shift; i < l; i++ ) {
        printf("%d", arr[i]);
        if ( i != l - 1 ) printf(", ");
    }
    for ( int i = 0; i < shift; i++ ) {
        printf(", %d", arr[i]);
    }
    printf(" }");
}

void generateArr ( int * index ) {
    int n = rand ( ) % 99899 + 100;
    int len = log10( n ) + 1;
    int arr[5];
    int sum = 0;
    for ( int i = 0; i < len; i++ ) {
        arr[i] = n % 10;
        sum += n % 10;
        n /= 10;
    }
    for ( int i = 0; i < rand() % len + 1; i++ ) {
        printf( "bricks[%d] = { ", (*index)++ );
        printArray ( arr, len, i );
        printf( ", %d, %d, 1 };\n", len, sum );
    }
}

int main ( void ) {
    srand( time( NULL ) );
    printf( "size = %d;\n", TEST_COUNT * 5 );
    int index = 0;
    for ( int i = 0; i < TEST_COUNT; i++ )
        generateArr ( &index );
    printf ( "assert ( findUnique ( bricks, size ) == %d );\n", TEST_COUNT );
    return 0;
}