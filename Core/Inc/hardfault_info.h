#ifndef HARDFAULT_INFO_H
#define HARDFAULT_INFO_H

#include "stdint.h"

#define SYSHND_CTRL (*(volatile uint32_t*) (0xE000ED24u))
#define NVIC_MFSR   (*(volatile uint8_t*)  (0xE000ED28u))
#define NVIC_BFSR   (*(volatile uint8_t*)  (0xE000ED29u))
#define NVIC_UFSR   (*(volatile uint16_t*) (0xE000ED2Au))
#define NVIC_HFSR   (*(volatile uint32_t*) (0xE000ED2Cu))
#define NVIC_DFSR   (*(volatile uint32_t*) (0xE000ED30u))
#define NVIC_BFAR   (*(volatile uint32_t*) (0xE000ED38u))
#define NVIC_AFSR   (*(volatile uint32_t*) (0xE000ED3Cu))

typedef struct hardfault_registers_st {
    struct {
        volatile uint32_t r0;
        volatile uint32_t r1;
        volatile uint32_t r2;
        volatile uint32_t r3;
        volatile uint32_t r12;
        volatile uint32_t lr;
        volatile uint32_t pc;
        union {
            volatile uint32_t byte;
            struct {
                uint32_t IPSR : 8;
                uint32_t EPSR : 19;
                uint32_t APSR : 5;
            } bits;
        } psr;
    } SavedRegs;
    union {
        volatile uint32_t byte;
        struct {
            uint32_t MEMFAULTACT    : 1;
            uint32_t BUSFAULTACT    : 1;
            uint32_t UnusedBits1    : 1;
            uint32_t USGFAULTACT    : 1;
            uint32_t UnusedBits2    : 3;
            uint32_t SVCALLACT      : 1;
            uint32_t MONITORACT     : 1;
            uint32_t UnusedBits3    : 1;
            uint32_t PENDSVACT      : 1;
            uint32_t SYSTICKACT     : 1;
            uint32_t USGFAULTPENDED : 1;
            uint32_t MEMFAULTPENDED : 1;
            uint32_t BUSFAULTPENDED : 1;
            uint32_t SVCALLPENDED   : 1;
            uint32_t MEMFAULTENA    : 1;
            uint32_t BUSFAULTENA    : 1;
            uint32_t USGFAULTENA    : 1;
        } bits;
    } syshndctrl;
    union {
        volatile uint8_t byte;
        struct {
            uint8_t IACCVIOL    : 1;
            uint8_t DACCVIOL    : 1;
            uint8_t UnusedBits  : 1;
            uint8_t MUNSTKERR   : 1;
            uint8_t MSTKERR     : 1;
            uint8_t UnusedBits2 : 2;
            uint8_t MMARVALID   : 1;
        } bits;
    } mfsr;
    union {
        volatile uint32_t byte;
        struct {
            uint32_t IBUSERR    : 1;
            uint32_t PRECISERR  : 1;
            uint32_t IMPREISERR : 1;
            uint32_t UNSTKERR   : 1;
            uint32_t STKERR     : 1;
            uint32_t UnusedBits : 2;
            uint32_t BFARVALID  : 1;
        } bits;
    } bfsr;
    volatile uint32_t bfar;
    union {
        volatile uint16_t byte;
        struct {
            uint16_t UNDEFINSTR : 1;
            uint16_t INVSTATE   : 1;
            uint16_t INVPC      : 1;
            uint16_t NOCP       : 1;
            uint16_t UnusedBits : 4;
            uint16_t UNALIGNED  : 1;
            uint16_t DIVBYZERO  : 1;
        } bits;
    } ufsr;
    union {
        volatile uint32_t byte;
        struct {
            uint32_t UnusedBits  : 1;
            uint32_t VECTBL      : 1;
            uint32_t UnusedBits2 : 28;
            uint32_t FORCED      : 1;
            uint32_t DEBUGEVT    : 1;
        } bits;
    } hfsr;
    union {
        volatile uint32_t byte;
        struct {
            uint32_t HALTED   : 1;
            uint32_t BKPT     : 1;
            uint32_t DWTTRAP  : 1;
            uint32_t VCATCH   : 1;
            uint32_t EXTERNAL : 1;
        } bits;
    } dfsr;
    volatile uint32_t afsr;
} hardfault_registers_t;

#endif // HARDFAULT_INFO_H
