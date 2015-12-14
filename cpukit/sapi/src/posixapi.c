/**
 * @file
 *
 * @brief Initialize POSIX API
 *
 * @ingroup ClassicRTEMS
 */

/*
 *  COPYRIGHT (c) 1989-2014.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.org/license/LICENSE.
 */

#if HAVE_CONFIG_H
#include "config.h"
#endif

#define POSIX_API_INIT

#include <rtems/system.h>    /* include this before checking RTEMS_POSIX_API */

#include <rtems/config.h>
#include <rtems/posix/keyimpl.h>
#include <rtems/posix/posixapi.h>

#ifdef RTEMS_POSIX_API
#include <sys/types.h>
#include <mqueue.h>
#include <rtems/config.h>
#include <rtems/posix/barrierimpl.h>
#include <rtems/posix/config.h>
#include <rtems/posix/priorityimpl.h>
#include <rtems/posix/psignalimpl.h>
#include <rtems/posix/rwlockimpl.h>
#include <rtems/posix/spinlockimpl.h>
#endif

void _POSIX_Fatal_error( POSIX_Fatal_domain domain, int eno )
{
  uint32_t code = ( domain << 8 ) | ( ( uint32_t ) eno & 0xffU );

  _Terminate( INTERNAL_ERROR_POSIX_API, false, code );
}

void _POSIX_API_Initialize(void)
{
  /*
   * If there are any type size assumptions in the POSIX API, this is
   * the appropriate place to place them.
   *
   * Currently, there are no none type size assumptions.
   */

  _POSIX_Key_Manager_initialization();

  #ifdef RTEMS_POSIX_API
    _POSIX_Barrier_Manager_initialization();
    _POSIX_RWLock_Manager_initialization();
    _POSIX_Spinlock_Manager_initialization();
  #endif
}
