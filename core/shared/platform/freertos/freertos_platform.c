/*
 * Copyright (C) 2019 Intel Corporation.  All rights reserved.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 */

#include "platform_api_vmcore.h"
// #include "platform_api_extension.h"
#include "portable.h"

int
bh_platform_init()
{
    return 0;
}

void
bh_platform_destroy()
{}

int
os_printf(const char *format, ...)
{
    int ret = 0;
    va_list ap;

    va_start(ap, format);
    ret += vprintf(format, ap);
    va_end(ap);

    return ret;
}

int
os_vprintf(const char *format, va_list ap)
{
    return vprintf(format, ap);
}

uint8 *
os_thread_get_stack_boundary(void)
{
#if defined(CONFIG_FREERTOS_USE_TRACE_FACILITY)
    TaskStatus_t pxTaskStatus;
    vTaskGetInfo(xTaskGetCurrentTaskHandle(), &pxTaskStatus, pdTRUE, eInvalid);
    return pxTaskStatus.pxStackBase;
#else // !defined(CONFIG_FREERTOS_USE_TRACE_FACILITY)
    return NULL;
#endif
}

void *
os_mmap(void *hint, size_t size, int prot, int flags)
{
    return pvPortMalloc(size);
}

void
os_munmap(void *addr, size_t size)
{
    vPortFree(addr);
}

int
os_mprotect(void *addr, size_t size, int prot)
{
    return 0;
}

void
os_dcache_flush(void)
{}

