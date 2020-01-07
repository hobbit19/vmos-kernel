//String Operations Script
//Last modified: VMOS 1.0.4
//Made by VMGP

#ifndef STRING_H
#define STRING_H

#include "types.h"
uint16 strlength(string ch)
{
        uint16 i = 1;
        while(ch[i++]);  
        return --i;
}

void strJoin(string str1, string str2, char result1[]) {
	int i;
	i = 0;
	while(*str1 != 0) {
		result1[i] = *str1;
		i++;
		str1++;
	}
	while(*str2 != 0) {
		result1[i] = *str2;
		i++;
		str2++;
	}
	result1[i] = '\0';
}

uint8 strEql(string ch1,string ch2)                     
{
        uint8 result = 1;
        uint8 size = strlength(ch1);
        if(size != strlength(ch2)) result =0;
        else 
        {
        uint8 i = 0;
        for(i;i<=size;i++)
        {
                if(ch1[i] != ch2[i]) result = 0;
        }
        }
        return result;
}


#endif
