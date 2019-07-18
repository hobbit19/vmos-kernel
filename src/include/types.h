#ifndef TYPES_H
#define TYPES_H

typedef signed char int8;
typedef unsigned char uint8;

typedef signed short int16;
typedef unsigned short uint16;

typedef signed int int32;
typedef unsigned int uint32;

typedef signed long long int64;
typedef unsigned long long uint64;

typedef char* string;
typedef const char* cststring;

/*typedef struct {
    string path;
    string; 
    uint8 always0;
    uint8 flags; 
    uint16 high_offset;
} __attribute__((packed)) file ;*/

#define low_16(address) (uint16)((address) & 0xFFFF)            
#define high_16(address) (uint16)(((address) >> 16) & 0xFFFF)

#endif
