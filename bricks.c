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
    int iter = 0;
    for ( int i = 0; i < b.sideCnt; i++ ) {

        if ( b.sides[i] != a.sides[j] ) {
            j = 0;
            isMatching = 0;
        }
        
        if ( b.sides[i] == a.sides[j] ) {
            j++;
            isMatching = 1;
        } 

        if ( j + 1 == a.sideCnt )
            return 1;

        if ( i + 1 == b.sideCnt ) {
            if ( isMatching && !iter ) {
                i = -1;
                iter = 1;
            }
            else {
                return 0;
            }
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
    
    size = 750;
    bricks[0] = { { 7, 9, 1, 3, 7 }, 5, 27, 1 };
    bricks[1] = { { 9, 1, 3, 7, 7 }, 5, 27, 1 };
    bricks[2] = { { 1, 3, 7, 7, 9 }, 5, 27, 1 };
    bricks[3] = { { 7, 9, 2, 3, 4 }, 5, 25, 1 };
    bricks[4] = { { 9, 2, 3, 4, 7 }, 5, 25, 1 };
    bricks[5] = { { 6, 6, 5, 1 }, 4, 18, 1 };
    bricks[6] = { { 6, 5, 1, 6 }, 4, 18, 1 };
    bricks[7] = { { 5, 1, 6, 6 }, 4, 18, 1 };
    bricks[8] = { { 4, 0, 3, 4 }, 4, 11, 1 };
    bricks[9] = { { 0, 3, 4, 4 }, 4, 11, 1 };
    bricks[10] = { { 3, 4, 4, 0 }, 4, 11, 1 };
    bricks[11] = { { 4, 5, 8, 7, 9 }, 5, 33, 1 };
    bricks[12] = { { 5, 8, 7, 9, 4 }, 5, 33, 1 };
    bricks[13] = { { 8, 7, 9, 4, 5 }, 5, 33, 1 };
    bricks[14] = { { 7, 9, 4, 5, 8 }, 5, 33, 1 };
    bricks[15] = { { 5, 5, 6, 2 }, 4, 18, 1 };
    bricks[16] = { { 5, 6, 2, 5 }, 4, 18, 1 };
    bricks[17] = { { 6, 2, 5, 5 }, 4, 18, 1 };
    bricks[18] = { { 2, 4, 7, 4, 4 }, 5, 21, 1 };
    bricks[19] = { { 7, 1, 9, 4, 9 }, 5, 30, 1 };
    bricks[20] = { { 1, 9, 4, 9, 7 }, 5, 30, 1 };
    bricks[21] = { { 1, 0, 5, 3, 6 }, 5, 15, 1 };
    bricks[22] = { { 0, 5, 3, 6, 1 }, 5, 15, 1 };
    bricks[23] = { { 1, 2, 6, 7, 5 }, 5, 21, 1 };
    bricks[24] = { { 1, 5, 4, 9, 1 }, 5, 20, 1 };
    bricks[25] = { { 5, 4, 9, 1, 1 }, 5, 20, 1 };
    bricks[26] = { { 9, 6, 7, 3, 7 }, 5, 32, 1 };
    bricks[27] = { { 6, 7, 3, 7, 9 }, 5, 32, 1 };
    bricks[28] = { { 7, 3, 7, 9, 6 }, 5, 32, 1 };
    bricks[29] = { { 0, 5, 2, 9, 7 }, 5, 23, 1 };
    bricks[30] = { { 5, 0, 8, 1, 8 }, 5, 22, 1 };
    bricks[31] = { { 0, 8, 1, 8, 5 }, 5, 22, 1 };
    bricks[32] = { { 5, 9, 7, 6, 2 }, 5, 29, 1 };
    bricks[33] = { { 0, 5, 3, 2, 2 }, 5, 12, 1 };
    bricks[34] = { { 5, 3, 2, 2, 0 }, 5, 12, 1 };
    bricks[35] = { { 6, 4, 3, 8, 2 }, 5, 23, 1 };
    bricks[36] = { { 2, 7, 4, 6 }, 4, 19, 1 };
    bricks[37] = { { 7, 4, 6, 2 }, 4, 19, 1 };
    bricks[38] = { { 4, 6, 2, 7 }, 4, 19, 1 };
    bricks[39] = { { 6, 2, 7, 4 }, 4, 19, 1 };
    bricks[40] = { { 0, 3, 9, 8, 2 }, 5, 22, 1 };
    bricks[41] = { { 3, 9, 8, 2, 0 }, 5, 22, 1 };
    bricks[42] = { { 9, 8, 2, 0, 3 }, 5, 22, 1 };
    bricks[43] = { { 8, 2, 0, 3, 9 }, 5, 22, 1 };
    bricks[44] = { { 7, 0, 8, 4, 1 }, 5, 20, 1 };
    bricks[45] = { { 0, 8, 4, 1, 7 }, 5, 20, 1 };
    bricks[46] = { { 9, 5, 5, 9, 3 }, 5, 31, 1 };
    bricks[47] = { { 5, 5, 9, 3, 9 }, 5, 31, 1 };
    bricks[48] = { { 9, 8, 3, 2, 4 }, 5, 26, 1 };
    bricks[49] = { { 4, 2, 6, 4, 6 }, 5, 22, 1 };
    bricks[50] = { { 2, 6, 4, 6, 4 }, 5, 22, 1 };
    bricks[51] = { { 6, 4, 6, 4, 2 }, 5, 22, 1 };
    bricks[52] = { { 4, 6, 4, 2, 6 }, 5, 22, 1 };
    bricks[53] = { { 6, 4, 2, 6, 4 }, 5, 22, 1 };
    bricks[54] = { { 1, 5, 4, 4, 3 }, 5, 17, 1 };
    bricks[55] = { { 5, 4, 4, 3, 1 }, 5, 17, 1 };
    bricks[56] = { { 4, 4, 3, 1, 5 }, 5, 17, 1 };
    bricks[57] = { { 9, 1, 2, 7, 4 }, 5, 23, 1 };
    bricks[58] = { { 1, 2, 7, 4, 9 }, 5, 23, 1 };
    bricks[59] = { { 2, 7, 4, 9, 1 }, 5, 23, 1 };
    bricks[60] = { { 7, 4, 9, 1, 2 }, 5, 23, 1 };
    bricks[61] = { { 4, 8, 7, 9, 7 }, 5, 35, 1 };
    bricks[62] = { { 8, 7, 9, 7, 4 }, 5, 35, 1 };
    bricks[63] = { { 0, 6, 9, 3, 4 }, 5, 22, 1 };
    bricks[64] = { { 6, 9, 3, 4, 0 }, 5, 22, 1 };
    bricks[65] = { { 9, 3, 4, 0, 6 }, 5, 22, 1 };
    bricks[66] = { { 0, 7, 5, 7, 5 }, 5, 24, 1 };
    bricks[67] = { { 7, 5, 7, 5, 0 }, 5, 24, 1 };
    bricks[68] = { { 0, 3, 7, 0, 9 }, 5, 19, 1 };
    bricks[69] = { { 0, 9, 0, 6, 7 }, 5, 22, 1 };
    bricks[70] = { { 9, 0, 6, 7, 0 }, 5, 22, 1 };
    bricks[71] = { { 0, 6, 7, 0, 9 }, 5, 22, 1 };
    bricks[72] = { { 6, 7, 0, 9, 0 }, 5, 22, 1 };
    bricks[73] = { { 9, 9, 7, 4, 5 }, 5, 34, 1 };
    bricks[74] = { { 9, 7, 4, 5, 9 }, 5, 34, 1 };
    bricks[75] = { { 7, 4, 5, 9, 9 }, 5, 34, 1 };
    bricks[76] = { { 6, 7, 0, 0, 5 }, 5, 18, 1 };
    bricks[77] = { { 7, 0, 0, 5, 6 }, 5, 18, 1 };
    bricks[78] = { { 4, 7, 3, 0, 8 }, 5, 22, 1 };
    bricks[79] = { { 7, 3, 0, 8, 4 }, 5, 22, 1 };
    bricks[80] = { { 3, 0, 8, 4, 7 }, 5, 22, 1 };
    bricks[81] = { { 7, 2, 5, 4, 3 }, 5, 21, 1 };
    bricks[82] = { { 2, 5, 4, 3, 7 }, 5, 21, 1 };
    bricks[83] = { { 5, 3, 0, 9, 6 }, 5, 23, 1 };
    bricks[84] = { { 3, 0, 9, 6, 5 }, 5, 23, 1 };
    bricks[85] = { { 4, 4, 8, 3, 2 }, 5, 21, 1 };
    bricks[86] = { { 4, 8, 3, 2, 4 }, 5, 21, 1 };
    bricks[87] = { { 8, 3, 2, 4, 4 }, 5, 21, 1 };
    bricks[88] = { { 3, 2, 4, 4, 8 }, 5, 21, 1 };
    bricks[89] = { { 8, 7, 6, 0, 9 }, 5, 30, 1 };
    bricks[90] = { { 7, 6, 0, 9, 8 }, 5, 30, 1 };
    bricks[91] = { { 6, 0, 9, 8, 7 }, 5, 30, 1 };
    bricks[92] = { { 0, 9, 8, 7, 6 }, 5, 30, 1 };
    bricks[93] = { { 0, 1, 8, 7, 3 }, 5, 19, 1 };
    bricks[94] = { { 1, 8, 7, 3, 0 }, 5, 19, 1 };
    bricks[95] = { { 8, 7, 3, 0, 1 }, 5, 19, 1 };
    bricks[96] = { { 7, 3, 0, 1, 8 }, 5, 19, 1 };
    bricks[97] = { { 5, 7, 7, 8, 1 }, 5, 28, 1 };
    bricks[98] = { { 7, 7, 8, 1, 5 }, 5, 28, 1 };
    bricks[99] = { { 3, 4, 6, 4 }, 4, 17, 1 };
    bricks[100] = { { 4, 6, 4, 3 }, 4, 17, 1 };
    bricks[101] = { { 6, 4, 3, 4 }, 4, 17, 1 };
    bricks[102] = { { 3, 4, 9, 7, 9 }, 5, 32, 1 };
    bricks[103] = { { 4, 9, 7, 9, 3 }, 5, 32, 1 };
    bricks[104] = { { 9, 7, 9, 3, 4 }, 5, 32, 1 };
    bricks[105] = { { 7, 9, 3, 4, 9 }, 5, 32, 1 };
    bricks[106] = { { 1, 1, 8, 8, 5 }, 5, 23, 1 };
    bricks[107] = { { 1, 8, 8, 5, 1 }, 5, 23, 1 };
    bricks[108] = { { 9, 8, 3, 4, 9 }, 5, 33, 1 };
    bricks[109] = { { 8, 3, 4, 9, 9 }, 5, 33, 1 };
    bricks[110] = { { 9, 5, 1, 1, 3 }, 5, 19, 1 };
    bricks[111] = { { 5, 1, 1, 3, 9 }, 5, 19, 1 };
    bricks[112] = { { 9, 6, 1, 6 }, 4, 22, 1 };
    bricks[113] = { { 6, 1, 6, 9 }, 4, 22, 1 };
    bricks[114] = { { 1, 6, 9, 6 }, 4, 22, 1 };
    bricks[115] = { { 2, 9, 5, 1, 7 }, 5, 24, 1 };
    bricks[116] = { { 9, 5, 1, 7, 2 }, 5, 24, 1 };
    bricks[117] = { { 4, 5, 4, 0, 4 }, 5, 17, 1 };
    bricks[118] = { { 5, 4, 0, 4, 4 }, 5, 17, 1 };
    bricks[119] = { { 4, 0, 4, 4, 5 }, 5, 17, 1 };
    bricks[120] = { { 1, 6, 5, 2, 2 }, 5, 16, 1 };
    bricks[121] = { { 6, 5, 2, 2, 1 }, 5, 16, 1 };
    bricks[122] = { { 5, 2, 2, 1, 6 }, 5, 16, 1 };
    bricks[123] = { { 3, 2, 0, 3, 8 }, 5, 16, 1 };
    bricks[124] = { { 2, 0, 3, 8, 3 }, 5, 16, 1 };
    bricks[125] = { { 0, 3, 8, 3, 2 }, 5, 16, 1 };
    bricks[126] = { { 3, 8, 3, 2, 0 }, 5, 16, 1 };
    bricks[127] = { { 8, 3, 2, 0, 3 }, 5, 16, 1 };
    bricks[128] = { { 5, 0, 3, 4, 6 }, 5, 18, 1 };
    bricks[129] = { { 0, 3, 4, 6, 5 }, 5, 18, 1 };
    bricks[130] = { { 3, 4, 6, 5, 0 }, 5, 18, 1 };
    bricks[131] = { { 7, 0, 7, 6 }, 4, 20, 1 };
    bricks[132] = { { 9, 4, 5, 1, 5 }, 5, 24, 1 };
    bricks[133] = { { 4, 5, 1, 5, 9 }, 5, 24, 1 };
    bricks[134] = { { 5, 1, 5, 9, 4 }, 5, 24, 1 };
    bricks[135] = { { 2, 5, 2, 3, 1 }, 5, 13, 1 };
    bricks[136] = { { 5, 2, 3, 1, 2 }, 5, 13, 1 };
    bricks[137] = { { 2, 3, 1, 2, 5 }, 5, 13, 1 };
    bricks[138] = { { 3, 3, 1, 3, 6 }, 5, 16, 1 };
    bricks[139] = { { 3, 1, 3, 6, 3 }, 5, 16, 1 };
    bricks[140] = { { 6, 4, 0, 0, 4 }, 5, 14, 1 };
    bricks[141] = { { 4, 0, 0, 4, 6 }, 5, 14, 1 };
    bricks[142] = { { 0, 0, 4, 6, 4 }, 5, 14, 1 };
    bricks[143] = { { 7, 6, 3, 7, 4 }, 5, 27, 1 };
    bricks[144] = { { 6, 3, 7, 4, 7 }, 5, 27, 1 };
    bricks[145] = { { 3, 7, 4, 7, 6 }, 5, 27, 1 };
    bricks[146] = { { 7, 4, 7, 6, 3 }, 5, 27, 1 };
    bricks[147] = { { 0, 2, 1, 8, 9 }, 5, 20, 1 };
    bricks[148] = { { 2, 1, 8, 9, 0 }, 5, 20, 1 };
    bricks[149] = { { 1, 8, 9, 0, 2 }, 5, 20, 1 };
    bricks[150] = { { 8, 9, 0, 2, 1 }, 5, 20, 1 };
    bricks[151] = { { 8, 7, 2, 6, 5 }, 5, 28, 1 };
    bricks[152] = { { 7, 2, 6, 5, 8 }, 5, 28, 1 };
    bricks[153] = { { 2, 0, 5, 1, 4 }, 5, 12, 1 };
    bricks[154] = { { 0, 5, 1, 4, 2 }, 5, 12, 1 };
    bricks[155] = { { 2, 1, 8, 1, 9 }, 5, 21, 1 };
    bricks[156] = { { 9, 7, 6, 0, 5 }, 5, 27, 1 };
    bricks[157] = { { 7, 6, 0, 5, 9 }, 5, 27, 1 };
    bricks[158] = { { 6, 0, 5, 9, 7 }, 5, 27, 1 };
    bricks[159] = { { 0, 9, 5, 1, 9 }, 5, 24, 1 };
    bricks[160] = { { 9, 5, 1, 9, 0 }, 5, 24, 1 };
    bricks[161] = { { 5, 1, 9, 0, 9 }, 5, 24, 1 };
    bricks[162] = { { 9, 2, 5, 9, 6 }, 5, 31, 1 };
    bricks[163] = { { 5, 7, 3, 4, 2 }, 5, 21, 1 };
    bricks[164] = { { 8, 3, 9, 8, 1 }, 5, 29, 1 };
    bricks[165] = { { 3, 9, 8, 1, 8 }, 5, 29, 1 };
    bricks[166] = { { 7, 3, 2, 1, 3 }, 5, 16, 1 };
    bricks[167] = { { 3, 3, 1, 2, 8 }, 5, 17, 1 };
    bricks[168] = { { 3, 1, 2, 8, 3 }, 5, 17, 1 };
    bricks[169] = { { 1, 2, 8, 3, 3 }, 5, 17, 1 };
    bricks[170] = { { 6, 5, 7, 3, 1 }, 5, 22, 1 };
    bricks[171] = { { 5, 7, 3, 1, 6 }, 5, 22, 1 };
    bricks[172] = { { 7, 3, 1, 6, 5 }, 5, 22, 1 };
    bricks[173] = { { 6, 4, 0, 5, 9 }, 5, 24, 1 };
    bricks[174] = { { 4, 0, 5, 9, 6 }, 5, 24, 1 };
    bricks[175] = { { 0, 5, 9, 6, 4 }, 5, 24, 1 };
    bricks[176] = { { 9, 4, 1, 4, 5 }, 5, 23, 1 };
    bricks[177] = { { 4, 1, 4, 5, 9 }, 5, 23, 1 };
    bricks[178] = { { 1, 4, 5, 9, 4 }, 5, 23, 1 };
    bricks[179] = { { 1, 5, 2, 9, 4 }, 5, 21, 1 };
    bricks[180] = { { 5, 2, 9, 4, 1 }, 5, 21, 1 };
    bricks[181] = { { 2, 9, 4, 1, 5 }, 5, 21, 1 };
    bricks[182] = { { 9, 4, 1, 5, 2 }, 5, 21, 1 };
    bricks[183] = { { 1, 0, 8, 8, 8 }, 5, 25, 1 };
    bricks[184] = { { 0, 8, 8, 8, 1 }, 5, 25, 1 };
    bricks[185] = { { 8, 0, 3, 7, 5 }, 5, 23, 1 };
    bricks[186] = { { 0, 3, 7, 5, 8 }, 5, 23, 1 };
    bricks[187] = { { 3, 7, 5, 8, 0 }, 5, 23, 1 };
    bricks[188] = { { 5, 2, 2, 4, 8 }, 5, 21, 1 };
    bricks[189] = { { 2, 2, 4, 8, 5 }, 5, 21, 1 };
    bricks[190] = { { 2, 4, 8, 5, 2 }, 5, 21, 1 };
    bricks[191] = { { 3, 8, 8, 2, 2 }, 5, 23, 1 };
    bricks[192] = { { 8, 8, 2, 2, 3 }, 5, 23, 1 };
    bricks[193] = { { 4, 0, 3, 5, 7 }, 5, 19, 1 };
    bricks[194] = { { 0, 3, 5, 7, 4 }, 5, 19, 1 };
    bricks[195] = { { 6, 4, 2, 9, 7 }, 5, 28, 1 };
    bricks[196] = { { 4, 2, 9, 7, 6 }, 5, 28, 1 };
    bricks[197] = { { 2, 9, 7, 6, 4 }, 5, 28, 1 };
    bricks[198] = { { 1, 0, 5, 1, 1 }, 5, 8, 1 };
    bricks[199] = { { 0, 5, 1, 1, 1 }, 5, 8, 1 };
    bricks[200] = { { 5, 1, 1, 1, 0 }, 5, 8, 1 };
    bricks[201] = { { 4, 6, 0, 6, 3 }, 5, 19, 1 };
    bricks[202] = { { 6, 0, 6, 3, 4 }, 5, 19, 1 };
    bricks[203] = { { 0, 6, 3, 4, 6 }, 5, 19, 1 };
    bricks[204] = { { 6, 3, 4, 6, 0 }, 5, 19, 1 };
    bricks[205] = { { 5, 3, 8, 2, 6 }, 5, 24, 1 };
    bricks[206] = { { 4, 5, 0, 6, 4 }, 5, 19, 1 };
    bricks[207] = { { 5, 0, 6, 4, 4 }, 5, 19, 1 };
    bricks[208] = { { 0, 6, 4, 4, 5 }, 5, 19, 1 };
    bricks[209] = { { 6, 4, 4, 5, 0 }, 5, 19, 1 };
    bricks[210] = { { 5, 8, 1, 1, 4 }, 5, 19, 1 };
    bricks[211] = { { 8, 1, 1, 4, 5 }, 5, 19, 1 };
    bricks[212] = { { 1, 1, 4, 5, 8 }, 5, 19, 1 };
    bricks[213] = { { 8, 5, 1, 1, 9 }, 5, 24, 1 };
    bricks[214] = { { 5, 1, 1, 9, 8 }, 5, 24, 1 };
    bricks[215] = { { 1, 1, 9, 8, 5 }, 5, 24, 1 };
    bricks[216] = { { 8, 7, 1, 5, 8 }, 5, 29, 1 };
    bricks[217] = { { 7, 1, 5, 8, 8 }, 5, 29, 1 };
    bricks[218] = { { 1, 5, 8, 8, 7 }, 5, 29, 1 };
    bricks[219] = { { 3, 1, 5, 2, 8 }, 5, 19, 1 };
    bricks[220] = { { 1, 5, 2, 8, 3 }, 5, 19, 1 };
    bricks[221] = { { 5, 2, 8, 3, 1 }, 5, 19, 1 };
    bricks[222] = { { 6, 4, 5, 2, 1 }, 5, 18, 1 };
    bricks[223] = { { 4, 5, 2, 1, 6 }, 5, 18, 1 };
    bricks[224] = { { 5, 2, 1, 6, 4 }, 5, 18, 1 };
    bricks[225] = { { 3, 5, 6, 3, 1 }, 5, 18, 1 };
    bricks[226] = { { 9, 1, 3, 2, 5 }, 5, 20, 1 };
    bricks[227] = { { 1, 3, 2, 5, 9 }, 5, 20, 1 };
    bricks[228] = { { 9, 1, 8, 0, 6 }, 5, 24, 1 };
    bricks[229] = { { 1, 8, 0, 6, 9 }, 5, 24, 1 };
    bricks[230] = { { 8, 0, 6, 9, 1 }, 5, 24, 1 };
    bricks[231] = { { 9, 2, 7, 7, 9 }, 5, 34, 1 };
    bricks[232] = { { 2, 7, 7, 9, 9 }, 5, 34, 1 };
    bricks[233] = { { 7, 7, 9, 9, 2 }, 5, 34, 1 };
    bricks[234] = { { 4, 3, 9, 6, 2 }, 5, 24, 1 };
    bricks[235] = { { 1, 2, 8, 2, 6 }, 5, 19, 1 };
    bricks[236] = { { 2, 8, 2, 6, 1 }, 5, 19, 1 };
    bricks[237] = { { 9, 5, 8, 6, 9 }, 5, 37, 1 };
    bricks[238] = { { 5, 8, 6, 9, 9 }, 5, 37, 1 };
    bricks[239] = { { 5, 6, 8, 0, 3 }, 5, 22, 1 };
    bricks[240] = { { 6, 8, 0, 3, 5 }, 5, 22, 1 };
    bricks[241] = { { 8, 0, 3, 5, 6 }, 5, 22, 1 };
    bricks[242] = { { 6, 4, 9, 4, 9 }, 5, 32, 1 };
    bricks[243] = { { 2, 5, 8, 3, 2 }, 5, 20, 1 };
    bricks[244] = { { 5, 8, 3, 2, 2 }, 5, 20, 1 };
    bricks[245] = { { 8, 3, 2, 2, 5 }, 5, 20, 1 };
    bricks[246] = { { 3, 2, 2, 5, 8 }, 5, 20, 1 };
    bricks[247] = { { 2, 1, 5, 2, 7 }, 5, 17, 1 };
    bricks[248] = { { 1, 5, 2, 7, 2 }, 5, 17, 1 };
    bricks[249] = { { 5, 2, 7, 2, 1 }, 5, 17, 1 };
    bricks[250] = { { 1, 8, 9, 3, 6 }, 5, 27, 1 };
    bricks[251] = { { 8, 9, 3, 6, 1 }, 5, 27, 1 };
    bricks[252] = { { 9, 3, 6, 1, 8 }, 5, 27, 1 };
    bricks[253] = { { 4, 3, 5, 4, 9 }, 5, 25, 1 };
    bricks[254] = { { 3, 5, 4, 9, 4 }, 5, 25, 1 };
    bricks[255] = { { 6, 5, 2, 2, 4 }, 5, 19, 1 };
    bricks[256] = { { 5, 2, 2, 4, 6 }, 5, 19, 1 };
    bricks[257] = { { 3, 9, 3, 8, 7 }, 5, 30, 1 };
    bricks[258] = { { 9, 3, 8, 7, 3 }, 5, 30, 1 };
    bricks[259] = { { 3, 8, 7, 3, 9 }, 5, 30, 1 };
    bricks[260] = { { 8, 7, 3, 9, 3 }, 5, 30, 1 };
    bricks[261] = { { 0, 3, 5, 2, 3 }, 5, 13, 1 };
    bricks[262] = { { 3, 5, 2, 3, 0 }, 5, 13, 1 };
    bricks[263] = { { 1, 4, 7, 1, 1 }, 5, 14, 1 };
    bricks[264] = { { 4, 7, 1, 1, 1 }, 5, 14, 1 };
    bricks[265] = { { 7, 1, 1, 1, 4 }, 5, 14, 1 };
    bricks[266] = { { 8, 7, 2, 8, 4 }, 5, 29, 1 };
    bricks[267] = { { 7, 2, 8, 4, 8 }, 5, 29, 1 };
    bricks[268] = { { 2, 8, 4, 8, 7 }, 5, 29, 1 };
    bricks[269] = { { 5, 1, 9, 9, 1 }, 5, 25, 1 };
    bricks[270] = { { 1, 9, 9, 1, 5 }, 5, 25, 1 };
    bricks[271] = { { 9, 9, 1, 5, 1 }, 5, 25, 1 };
    bricks[272] = { { 1, 9, 9, 4, 7 }, 5, 30, 1 };
    bricks[273] = { { 9, 9, 4, 7, 1 }, 5, 30, 1 };
    bricks[274] = { { 9, 4, 7, 1, 9 }, 5, 30, 1 };
    bricks[275] = { { 6, 3, 7, 7 }, 4, 23, 1 };
    bricks[276] = { { 3, 7, 7, 6 }, 4, 23, 1 };
    bricks[277] = { { 5, 2, 5, 3, 8 }, 5, 23, 1 };
    bricks[278] = { { 2, 5, 3, 8, 5 }, 5, 23, 1 };
    bricks[279] = { { 5, 3, 8, 5, 2 }, 5, 23, 1 };
    bricks[280] = { { 3, 8, 5, 2, 5 }, 5, 23, 1 };
    bricks[281] = { { 6, 6, 9, 5, 5 }, 5, 31, 1 };
    bricks[282] = { { 6, 9, 5, 5, 6 }, 5, 31, 1 };
    bricks[283] = { { 0, 8, 7, 6, 6 }, 5, 27, 1 };
    bricks[284] = { { 8, 7, 6, 6, 0 }, 5, 27, 1 };
    bricks[285] = { { 7, 6, 6, 0, 8 }, 5, 27, 1 };
    bricks[286] = { { 2, 0, 5, 2, 6 }, 5, 15, 1 };
    bricks[287] = { { 0, 5, 2, 6, 2 }, 5, 15, 1 };
    bricks[288] = { { 5, 2, 6, 2, 0 }, 5, 15, 1 };
    bricks[289] = { { 2, 4, 4, 1, 5 }, 5, 16, 1 };
    bricks[290] = { { 4, 4, 1, 5, 2 }, 5, 16, 1 };
    bricks[291] = { { 4, 1, 5, 2, 4 }, 5, 16, 1 };
    bricks[292] = { { 1, 5, 2, 4, 4 }, 5, 16, 1 };
    bricks[293] = { { 2, 2, 7, 3, 8 }, 5, 22, 1 };
    bricks[294] = { { 2, 7, 3, 8, 2 }, 5, 22, 1 };
    bricks[295] = { { 7, 3, 8, 2, 2 }, 5, 22, 1 };
    bricks[296] = { { 3, 8, 2, 2, 7 }, 5, 22, 1 };
    bricks[297] = { { 2, 5, 1, 6, 4 }, 5, 18, 1 };
    bricks[298] = { { 5, 1, 6, 4, 2 }, 5, 18, 1 };
    bricks[299] = { { 1, 6, 4, 2, 5 }, 5, 18, 1 };
    bricks[300] = { { 6, 4, 2, 5, 1 }, 5, 18, 1 };
    bricks[301] = { { 0, 4, 9, 8, 1 }, 5, 22, 1 };
    bricks[302] = { { 0, 2, 6, 5, 8 }, 5, 21, 1 };
    bricks[303] = { { 5, 3, 9, 4, 3 }, 5, 24, 1 };
    bricks[304] = { { 3, 9, 4, 3, 5 }, 5, 24, 1 };
    bricks[305] = { { 2, 0, 1, 3, 1 }, 5, 7, 1 };
    bricks[306] = { { 1, 0, 7, 9 }, 4, 17, 1 };
    bricks[307] = { { 6, 5, 4, 2 }, 4, 17, 1 };
    bricks[308] = { { 5, 4, 2, 6 }, 4, 17, 1 };
    bricks[309] = { { 4, 2, 6, 5 }, 4, 17, 1 };
    bricks[310] = { { 9, 3, 1, 4, 4 }, 5, 21, 1 };
    bricks[311] = { { 3, 1, 4, 4, 9 }, 5, 21, 1 };
    bricks[312] = { { 4, 0, 1, 2 }, 4, 7, 1 };
    bricks[313] = { { 0, 3, 7, 8, 2 }, 5, 20, 1 };
    bricks[314] = { { 3, 7, 8, 2, 0 }, 5, 20, 1 };
    bricks[315] = { { 7, 8, 2, 0, 3 }, 5, 20, 1 };
    bricks[316] = { { 8, 2, 0, 3, 7 }, 5, 20, 1 };
    bricks[317] = { { 2, 0, 3, 7, 8 }, 5, 20, 1 };
    bricks[318] = { { 5, 9, 1, 9, 1 }, 5, 25, 1 };
    bricks[319] = { { 9, 1, 9, 1, 5 }, 5, 25, 1 };
    bricks[320] = { { 1, 5, 7, 9, 6 }, 5, 28, 1 };
    bricks[321] = { { 3, 0, 6, 9, 8 }, 5, 26, 1 };
    bricks[322] = { { 4, 8, 8, 7, 7 }, 5, 34, 1 };
    bricks[323] = { { 8, 8, 7, 7, 4 }, 5, 34, 1 };
    bricks[324] = { { 8, 7, 7, 4, 8 }, 5, 34, 1 };
    bricks[325] = { { 7, 7, 4, 8, 8 }, 5, 34, 1 };
    bricks[326] = { { 9, 0, 2, 1, 7 }, 5, 19, 1 };
    bricks[327] = { { 0, 2, 1, 7, 9 }, 5, 19, 1 };
    bricks[328] = { { 2, 1, 7, 9, 0 }, 5, 19, 1 };
    bricks[329] = { { 1, 7, 9, 0, 2 }, 5, 19, 1 };
    bricks[330] = { { 0, 4, 9, 4, 3 }, 5, 20, 1 };
    bricks[331] = { { 4, 9, 4, 3, 0 }, 5, 20, 1 };
    bricks[332] = { { 9, 4, 3, 0, 4 }, 5, 20, 1 };
    bricks[333] = { { 4, 3, 0, 4, 9 }, 5, 20, 1 };
    bricks[334] = { { 7, 0, 0, 7, 1 }, 5, 15, 1 };
    bricks[335] = { { 0, 0, 7, 1, 7 }, 5, 15, 1 };
    bricks[336] = { { 0, 7, 1, 7, 0 }, 5, 15, 1 };
    bricks[337] = { { 7, 7, 3, 3, 9 }, 5, 29, 1 };
    bricks[338] = { { 9, 4, 1, 8 }, 4, 22, 1 };
    bricks[339] = { { 4, 1, 8, 9 }, 4, 22, 1 };
    bricks[340] = { { 0, 7, 6, 8, 1 }, 5, 22, 1 };
    bricks[341] = { { 8, 5, 5, 9, 1 }, 5, 28, 1 };
    bricks[342] = { { 5, 5, 9, 1, 8 }, 5, 28, 1 };
    bricks[343] = { { 5, 9, 1, 8, 5 }, 5, 28, 1 };
    bricks[344] = { { 9, 1, 8, 5, 5 }, 5, 28, 1 };
    bricks[345] = { { 1, 8, 5, 5, 9 }, 5, 28, 1 };
    bricks[346] = { { 8, 1, 4, 9, 4 }, 5, 26, 1 };
    bricks[347] = { { 1, 4, 9, 4, 8 }, 5, 26, 1 };
    bricks[348] = { { 7, 1, 0, 3, 3 }, 5, 14, 1 };
    bricks[349] = { { 1, 0, 3, 3, 7 }, 5, 14, 1 };
    bricks[350] = { { 0, 3, 3, 7, 1 }, 5, 14, 1 };
    bricks[351] = { { 3, 3, 7, 1, 0 }, 5, 14, 1 };
    bricks[352] = { { 7, 7, 7, 9, 3 }, 5, 33, 1 };
    bricks[353] = { { 7, 7, 9, 3, 7 }, 5, 33, 1 };
    bricks[354] = { { 7, 9, 3, 7, 7 }, 5, 33, 1 };
    bricks[355] = { { 1, 2, 8, 1, 3 }, 5, 15, 1 };
    bricks[356] = { { 2, 8, 1, 3, 1 }, 5, 15, 1 };
    bricks[357] = { { 8, 1, 3, 1, 2 }, 5, 15, 1 };
    bricks[358] = { { 0, 0, 4, 3, 7 }, 5, 14, 1 };
    bricks[359] = { { 0, 4, 3, 7, 0 }, 5, 14, 1 };
    bricks[360] = { { 4, 3, 7, 0, 0 }, 5, 14, 1 };
    bricks[361] = { { 9, 9, 4, 5, 3 }, 5, 30, 1 };
    bricks[362] = { { 2, 7, 9, 9, 4 }, 5, 31, 1 };
    bricks[363] = { { 7, 9, 9, 4, 2 }, 5, 31, 1 };
    bricks[364] = { { 9, 9, 4, 2, 7 }, 5, 31, 1 };
    bricks[365] = { { 4, 8, 7, 1, 9 }, 5, 29, 1 };
    bricks[366] = { { 8, 7, 1, 9, 4 }, 5, 29, 1 };
    bricks[367] = { { 7, 1, 9, 4, 8 }, 5, 29, 1 };
    bricks[368] = { { 1, 9, 4, 8, 7 }, 5, 29, 1 };
    bricks[369] = { { 3, 3, 0, 1, 8 }, 5, 15, 1 };
    bricks[370] = { { 3, 0, 1, 8, 3 }, 5, 15, 1 };
    bricks[371] = { { 8, 0, 0, 4, 5 }, 5, 17, 1 };
    bricks[372] = { { 0, 0, 4, 5, 8 }, 5, 17, 1 };
    bricks[373] = { { 0, 4, 5, 8, 0 }, 5, 17, 1 };
    bricks[374] = { { 3, 2, 2, 8, 4 }, 5, 19, 1 };
    bricks[375] = { { 2, 2, 8, 4, 3 }, 5, 19, 1 };
    bricks[376] = { { 4, 5, 1, 9, 7 }, 5, 26, 1 };
    bricks[377] = { { 5, 1, 9, 7, 4 }, 5, 26, 1 };
    bricks[378] = { { 5, 0, 5, 3, 9 }, 5, 22, 1 };
    bricks[379] = { { 0, 5, 3, 9, 5 }, 5, 22, 1 };
    bricks[380] = { { 5, 2, 6, 1, 8 }, 5, 22, 1 };
    bricks[381] = { { 2, 6, 1, 8, 5 }, 5, 22, 1 };
    bricks[382] = { { 6, 1, 8, 5, 2 }, 5, 22, 1 };
    bricks[383] = { { 5, 8, 8, 1, 6 }, 5, 28, 1 };
    bricks[384] = { { 8, 8, 1, 6, 5 }, 5, 28, 1 };
    bricks[385] = { { 0, 7, 3, 1, 8 }, 5, 19, 1 };
    bricks[386] = { { 7, 3, 1, 8, 0 }, 5, 19, 1 };
    bricks[387] = { { 3, 1, 8, 0, 7 }, 5, 19, 1 };
    assert ( findUnique ( bricks, size ) == 150 );

    return 0;
}