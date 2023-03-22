/*
 * Copyright (c) 2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 */

#ifndef FREERTOS_PLATFORM_INTERNAL_H
#define FREERTOS_PLATFORM_INTERNAL_H

#include <FreeRTOS.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <ctype.h>
#include "task.h"
#include "FreeRTOS_POSIX/pthread.h"
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

#define LONG_MAX +2147483647


typedef pthread_t korp_tid;
typedef pthread_mutex_t korp_mutex;
typedef pthread_cond_t korp_cond;
typedef pthread_t korp_thread;
typedef unsigned int korp_sem;


typedef struct os_thread_wait_node *os_thread_wait_list;

#define OS_THREAD_MUTEX_INITIALIZER PTHREAD_MUTEX_INITIALIZER

#define BH_APPLET_PRESERVED_STACK_SIZE (2 * BH_KB)

/* Default thread priority */
#define BH_THREAD_DEFAULT_PRIORITY 5

/* Special value for tv_nsec field of timespec */

#define UTIME_NOW ((1l << 30) - 1l)
#ifndef __cplusplus
#define UTIME_OMIT ((1l << 30) - 2l)
#endif

#ifdef DT_UNKNOWN
#undef DT_UNKNOWN
#endif

#ifdef DT_REG
#undef DT_REG
#endif

#ifdef DT_DIR
#undef DT_DIR
#endif
// typedef TaskHandle_t korp_tid;
// typedef struct SemaphoreHandle_t korp_mutex;
// typedef struct SemaphoreHandle_t korp_cond;
// typedef struct tskTaskControlBlock korp_thread;
// typedef unsigned int korp_sem;

// typedef rt_uint8_t uint8_t;
// typedef rt_int8_t int8_t;
// typedef rt_uint16_t uint16_t;
// typedef rt_int16_t int16_t;
// typedef rt_uint64_t uint64_t;
// typedef rt_int64_t int64_t;

// typedef unsigned char	        uint8_t;
// typedef unsigned short int      uint16_t;
// typedef unsigned int	        uint32_t;
// typedef unsigned long long int  uint64_t;
// typedef char            int8_t;
// typedef short int       int16_t;
// typedef int             int32_t;
// typedef long long int   int64_t;

#ifdef __cplusplus
}
#endif

#endif /* FREERTOS_PLATFORM_INTERNAL_H */
