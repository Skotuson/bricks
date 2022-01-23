#include <stdio.h>
#include <assert.h>

typedef struct {
    int sides[5];
    int sideCnt;
    int count;
    int isUnique;
} TBrick;

void printBrick ( TBrick brick ) {
    printf( "[" );
    for ( int i = 0; i < brick.sideCnt; i++ ) {
        if ( i ) printf(",");
        printf( "%d", brick.sides[i] );
    }
    printf( "]\n" );
}

void printBricks ( TBrick * bricks, int size ) {
    for ( int i = 0; i < size; i++ ) 
        printBrick ( bricks[i] );
}

int compareTwo ( TBrick a, TBrick b ) {
    if ( a.count != b.count || a.sideCnt != b.sideCnt )
        return 0;
    int j = 0;
    int isMatching = 0;
    for ( int i = 0; i < b.sideCnt; i++ ) {
        if ( b.sides[i] == a.sides[j] ) {
            j++;
            isMatching = 1;
        } else {
            j = 0;
            isMatching = 0;
        }
        if ( j + 1 == a.sideCnt ) {
            printBrick( a );
            printBrick( b );
            printf("----------\n");
            return 1;
        }
        if ( i + 1 == b.sideCnt ) {
            if ( isMatching ) {
                i = -1;
            }
            else return 0;
        }
    }
    return 1;
}

void compareAll ( TBrick a, TBrick * bricks, int size ) {
    for ( int i = 1; i < size; i++ ) {
        if ( ! bricks[i].isUnique )
            continue;
        if ( compareTwo ( a, bricks[i] ) )
            bricks[i].isUnique = 0;
    }
}

int findUnique ( TBrick * bricks, int size ) {
    for ( int i = 0; i < size; i++ ) 
        compareAll ( bricks[i], bricks + i, size - i );
    int uniq = 0;
    for ( int i = 0; i < size; i++ ) 
        if ( bricks[i].isUnique )
            uniq++;
    return uniq;
}

int main ( void ) {
    
    int size;
    TBrick bricks [5000];

size = 50;
bricks[0] = { { 4, 2, 4, 9, 4 }, 5, 23, 1 };
bricks[1] = { { 2, 4, 9, 4, 4 }, 5, 23, 1 };
bricks[2] = { { 8, 8, 4 }, 3, 20, 1 };
bricks[3] = { { 8, 4, 8 }, 3, 20, 1 };
bricks[4] = { { 8, 7, 7, 3, 8 }, 5, 33, 1 };
bricks[5] = { { 7, 7, 3, 8, 8 }, 5, 33, 1 };
bricks[6] = { { 2, 3, 8, 1, 4 }, 5, 18, 1 };
bricks[7] = { { 3, 8, 1, 4, 2 }, 5, 18, 1 };
bricks[8] = { { 8, 1, 4, 2, 3 }, 5, 18, 1 };
bricks[9] = { { 3, 0, 6, 3, 7 }, 5, 19, 1 };
bricks[10] = { { 4, 7, 2, 3 }, 4, 16, 1 };
bricks[11] = { { 8, 0, 2, 3, 2 }, 5, 15, 1 };
bricks[12] = { { 0, 2, 3, 2, 8 }, 5, 15, 1 };
bricks[13] = { { 9, 4, 5, 0, 4 }, 5, 22, 1 };
bricks[14] = { { 4, 5, 0, 4, 9 }, 5, 22, 1 };
bricks[15] = { { 5, 0, 4, 9, 4 }, 5, 22, 1 };
bricks[16] = { { 2, 7, 5, 7 }, 4, 21, 1 };
bricks[17] = { { 5, 1, 1, 3, 5 }, 5, 15, 1 };
bricks[18] = { { 1, 1, 3, 5, 5 }, 5, 15, 1 };

int res = findUnique ( bricks, size );
printf("%d\n", res);
assert ( res == 10 );



    return 0;
}