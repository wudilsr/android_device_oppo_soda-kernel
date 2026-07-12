/* SPDX-License-Identifier: GPL-2.0-only */


#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/netdevice.h>
#include <linux/sched.h>
#include <linux/string.h>
#include <linux/skbuff.h>
#include <linux/types.h>
#include <linux/netlink.h>
#include <net/net_namespace.h>
#include <net/sock.h>
#include <linux/version.h>

#ifdef CONFIG_OPLUS_KEVENT_UPLOAD

#define NETLINK_OPLUS_KEVENT 34

struct kernel_packet_info
{
	int type;    
	char log_tag[32];   
	char event_id[20];    
	size_t payload_length;    
	unsigned char payload[0];   
}__attribute__((packed));

int kevent_send_to_user(struct kernel_packet_info *userinfo);
void kernel_kevent_receive(struct sk_buff *__skbbr);
#endif 

#ifdef CONFIG_OPLUS_KEVENT_TEST
ssize_t demo_kevent_write(struct file *filp, const char __user *buffer, size_t count, loff_t *f_pos);
#endif 

