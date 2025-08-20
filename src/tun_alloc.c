#include "tun_alloc.h"


int tun_alloc(const char* dev)
{
  struct ifreq ifr;
  int fd, err;
  if ((fd = open("/dev/net/tun", O_RDWR)) < 0)
  {
    perror("open /dev/net/tun");
    return -1;
  }

  memset(&ifr, 0, sizeof(ifr));
  ifr.ifr_flags= IFF_TUN;
  if(*dev)
    strcpy(ifr.ifr_name, dev);

  if( (err = ioctl(fd, TUNSETIFF, (void *) &ifr)) < 0 )
  {
    close(fd);
    return err;
  }

  return fd;
}
