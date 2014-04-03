#ifndef  __MOVS_H__
#define __MOVS_H__



#define SET_DFC(x) \
        __asm__ __volatile__ (" movec %0,%/dfc" : : "d" (x));


#define GET_DFC(x) \
        __asm__ __volatile__ (" movec %/dfc, %0" : "=d" (x) : );


#define SET_SFC(x) \
        __asm__ __volatile__ (" movec %0,%/sfc" : : "d" (x));


#define GET_SFC(x) \
        __asm__ __volatile__ (" movec %/sfc, %0" : "=d" (x) : );

#define SET_VBR(x) \
        __asm__ __volatile__ (" movec %0,%/vbr" : : "r" (x));

#define GET_VBR(x) \
        __asm__ __volatile__ (" movec %/vbr, %0" : "=g" (x) : );


#define SET_CONTROL_BYTE(addr,value) \
        __asm__ __volatile__ (" movsb %0, %1@" : : "d" (value), "a" (addr));


#define GET_CONTROL_BYTE(addr,value) \
        __asm__ __volatile__ (" movsb %1@, %0" : "=d" (value) : "a" (addr));


#define SET_CONTROL_WORD(addr,value) \
        __asm__ __volatile__ (" movsl %0, %1@" : : "d" (value), "a" (addr));


#define GET_CONTROL_WORD(addr,value) \
        __asm__ __volatile__ (" movsl %1@, %0" : "=d" (value) : "a" (addr));
#endif