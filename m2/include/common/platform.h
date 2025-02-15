/******************************************************************************
* Copyright (C) 2025 by Sezer Kılıç - Coursera
*
* Redistribution, modification, or use of this software in source or binary
* forms is permitted as long as this copyright notice is retained. Users are 
* permitted to modify and use this project to learn about embedded software. 
* Sezer Kılıç is not liable for any misuse of this material. 
******************************************************************************/

#ifndef __PLATFORM_H__
#define __PLATFORM_H__

/******************************************************************************
 Platform - MSP432
******************************************************************************/
#if defined (MSP432)
#include "msp432p401r.h"
#define PRINTF(...)
/******************************************************************************
 Platform - HOST
******************************************************************************/
#elif defined (HOST)
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
/******************************************************************************
 Platform - Unsupported
******************************************************************************/
#else
#error "Platform provided is not supported in this Build System"
#endif

#endif /* __PLATFORM_H__ */

