#ifndef TUN_ALLOC_H
#define TUN_ALLOC_H

#include <linux/if.h>
#include <linux/if_tun.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>


int tun_alloc(const char *dev);
int read_tun(int fd, char* buf);
int write_tun(int fd, char* buf, size_t size);

#endif // TUN_ALLOC_H
