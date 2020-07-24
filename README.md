# ARM-hardfault-analyzer
Neat trick to read the hardfault cause and stack pointer from the ARM HardFault_Handler

See hardfault_info.h and stm32g4xx_it.c for the nuts and bolts of this :) the only purpose of main.c is to cause a hardfault.
