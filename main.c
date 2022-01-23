#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int sides[5];
    int sideCnt;
    int count;
    int isUnique;
} TBrick;

void addBrick ( TBrick ** bricks, int * size, int * max, TBrick brick ) {
    if ( *size == *max ) {
        *max *= 2;
        *bricks = ( TBrick* ) realloc ( *bricks, sizeof ( TBrick ) * *max );
    }
    (*bricks)[(*size)++] = brick;
}

int readBrick ( TBrick ** bricks, int * size, int * max ) {
    char c;
    int n;
    TBrick brick;
    brick.sideCnt = 0;
    brick.count = 0;
    brick.isUnique = 1;
    int res;
    scanf(" [ ");
    while ( ( res = scanf( " %d %c ", &n, &c ) ) ) {
        brick.sides[brick.sideCnt++] = n;
        brick.count += n;
        if ( res == -1 )
            return res;
        if ( c == ']' ) break;
    }
    addBrick ( bricks, size, max, brick );
    return 1;
}

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
        if ( j + 1 == a.sideCnt )
            return 1;
        if ( i + 1 == b.sideCnt ) {
            if ( isMatching )
                i = -1;
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
    int size = 0, max = 5;
    TBrick * bricks = ( TBrick* ) malloc ( sizeof ( TBrick ) * max );
    while ( readBrick ( &bricks, &size, &max ) != -1 );
    printf( "Unikatní: %d\n", findUnique ( bricks, size ) );
    free ( bricks );
    return 0;
}