/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef _UAPI_LINUX_COMPILER_H
#define _UAPI_LINUX_COMPILER_H

#define __user
#define __force
#define __iomem
#define __chk_user_ptr(x)	(void)0
#define __chk_io_ptr(x)		(void)0
#define __cond_lock(x,c)	(c)

#endif /* _UAPI_LINUX_COMPILER_H */
