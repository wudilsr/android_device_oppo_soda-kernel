

#ifndef _HANS_H
#define _HANS_H

#include <linux/freezer.h>
#include <linux/cgroup.h>
#include "../../kernel/sched/sched.h"

#define HANS_NOERROR             (0)
#define HANS_ERROR               (-1)
#define MIN_USERAPP_UID (10000)
#define HANS_SYSTEM_UID (1000)
#define INTERFACETOKEN_BUFF_SIZE (140)
#define PARCEL_OFFSET (16) 
#define CPUCTL_VERSION (2)


struct hans_message {
	int type;
	int port;  

	int caller_uid;  
	int caller_pid;  
	int target_pid;  
	int target_uid;  

        int pkg_cmd;     

	int code;
	char rpc_name[INTERFACETOKEN_BUFF_SIZE];
};


enum message_type {
	
	ASYNC_BINDER,
	SYNC_BINDER,
	FROZEN_TRANS,
	SIGNAL,
	PKG,

	
	SYNC_BINDER_CPUCTL,
	SIGNAL_CPUCTL,
	CPUCTL_TRANS,

	
	LOOP_BACK,
	TYPE_MAX
};


enum pkg_cmd {
	ADD_ONE_UID,
	DEL_ONE_UID,
	DEL_ALL_UID,

	PKG_CMD_MAX
};


static inline bool is_frozen_tg(struct task_struct *task)
{
	return (freezing(task->group_leader) || frozen(task->group_leader));
}

int hans_report(enum message_type type, int caller_pid, int caller_uid, int target_pid, int target_uid, const char *rpc_name, int code);
void hans_network_cmd_parse(uid_t uid, enum pkg_cmd cmd);
void hans_check_frozen_transcation(uid_t uid, enum message_type type);
int hans_netfilter_init(void);
void hans_netfilter_deinit(void);
void hans_check_async_binder_buffer(bool is_async, int free_async_space, int size, int binder_buffer_size, int alloc_buffer_size, int pid);
void hans_check_signal(struct task_struct *p, int sig);

#if defined(CONFIG_CFS_BANDWIDTH)
static inline bool is_belong_cpugrp(struct task_struct *task)
{
	if (task->sched_task_group != NULL) {
		struct cfs_bandwidth cfs_b = task->sched_task_group->cfs_bandwidth;
		if (cfs_b.quota != -1) {
			return true;
		} else if (cfs_b.quota == -1) {
			return false;
		}
	}

	return false;
}
#else
static inline bool is_belong_cpugrp(struct task_struct *task)
{
	return false;
}
#endif  
#endif  
