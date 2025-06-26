#ifndef AUTOCALCMATH_TYPE_DEFINER_H
#define AUTOCALCMATH_TYPE_DEFINER_H
#endif

#include <stdbool.h>

#ifndef TRUE
#define TRUE true
#endif

#ifndef FALSE
#define FALSE false
#endif


enum RETURN_ID
{
        AUTOCALCMATHS_VALID = 1,
        AUTOCALCMATHS_SUCCESS = 0,
        AUTOCALCMATHS_FAILED = -1,
        AUTOCALCMATHS_INVALID = -2,
        AUTOCALCMATHS_ERROR = -3,
        AUTOCALCMATHS_KILLED = -4
}; 

typedef int AUTOCALCMATH_INT;
typedef float AUTOCALCMATH_FLOAT;
typedef bool AUTOCALCMATH_BOOLEAN;

typedef struct 
{
        AUTOCALCMATH_FLOAT x; 
        AUTOCALCMATH_FLOAT y;
} TwoMathNums;
