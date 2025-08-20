#include "tun_alloc.h"



int main(void)
{
  int fd;
  const char* ifname = "tun0";  
  if((fd = tun_alloc(ifname)) < 0)
  {
    perror("Error in Tun0");
    return -1;
  }

  char buffer[1500];
  while(1)
  {
    int nread = read(fd, buffer, sizeof(buffer));
    if(nread < 0)
    {
      perror("read");
      break;
    }
    printf("Read %d bytes from %s\n", nread, ifname);
     int nwrite = write(fd, buffer, nread);
     if(nwrite < 0)
     {
       perror("write");
       break;
     }
  }
  close(fd);
  return 0;
}
