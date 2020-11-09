//--------------------------------------------
// Time Unit Definitions
//--------------------------------------------
#define TIME_UNIT               (200000)
#define DOT_TIME                (TIME_UNIT)
#define DASH_TIME               (DOT_TIME * 3)

#define TIME_BETWEEN_LETTER     (TIME_UNIT * 3)
#define TIME_BETWEEN_WORDS      (TIME_UNIT * 7)

//--------------------------------------------
// Memory Value Representations
//--------------------------------------------
#define BYTE            4
#define DOT             0x1
#define DASH            0x2


/*
Morse Code Letters are built from LEFT-to-RIGHT. 
For example: 
                Morse Code D = - * *
    The #define D is built as: * * -
This is built in reverse so we can byte shift right
in the program to catch/read the first DOT/DASH. 
*/

//--------------------------------------------
// Tier 1 Branch
//--------------------------------------------
#define E (DOT)
#define T (DASH)

//--------------------------------------------
// Tier 2 Branch
//--------------------------------------------

// 'E' Derived Children
#define I ((DOT  << BYTE) | E)
#define A ((DASH << BYTE) | E)

// 'T' Derived Children
#define N ((DOT  << BYTE) | T)
#define M ((DASH << BYTE) | T)

//--------------------------------------------
// Tier 3 Branch
//--------------------------------------------

// 'I' Derived Children
#define S ((DOT  << (2*BYTE)) | I)
#define U ((DASH << (2*BYTE)) | I)

// 'A' Derived Children
#define R ((DOT  << (2*BYTE)) | A)
#define W ((DASH << (2*BYTE)) | A)

// 'N' Derived Children
#define D ((DOT  << (2*BYTE)) | N)
#define K ((DASH << (2*BYTE)) | N)

// 'M' Derived Children
#define G ((DOT  << (2*BYTE)) | M)
#define O ((DASH << (2*BYTE)) | M)

//--------------------------------------------
// Tier 4 Branch
//--------------------------------------------

// 'S' Derived Children
#define H ((DOT  << (3*BYTE)) | S)
#define V ((DASH << (3*BYTE)) | S)

// 'U' Derived Children
#define F ((DOT  << (3*BYTE)) | U)

// 'R' Derived Children
#define L ((DOT  << (3*BYTE)) | R)

// 'W' Derived Children
#define P ((DOT  << (3*BYTE)) | W)
#define J ((DASH << (3*BYTE)) | W)

// 'D' Derived Children
#define B ((DOT  << (3*BYTE)) | D)
#define X ((DASH << (3*BYTE)) | D)

// 'K' Derived Children
#define C ((DOT  << (3*BYTE)) | K)
#define Y ((DASH << (3*BYTE)) | K)

// 'G' Derived Children
#define Z ((DOT  << (3*BYTE)) | G)
#define Q ((DASH << (3*BYTE)) | G)
