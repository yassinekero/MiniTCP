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


#endif // TUN_ALLOC_H
