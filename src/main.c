#include "tun_alloc.h"
#include <errno.h>
#include <stdint.h>
#include "ipv4.h"


int main(void)
{
  int fd;
  const char* ifname = "tun0";  
  if((fd = tun_alloc(ifname)) < 0)
  {
    perror("Error in Tun0");
    return -1;
  }

  uint8_t buffer[1500];
  ipv4_header header;
  while(1)
  {
    int nread = read(fd, buffer, sizeof(buffer));
    if(nread < 0)
    {
      perror("read");
      break;
    }
    uint16_t proto = 0x00;
    proto = (proto  | buffer[2]) << 8;
    proto = proto | buffer[3];
    //Skip Non IPV4 packets
    if(proto != 0x0800) 
      continue;
    printf("Read %d bytes from %s\n", nread, ifname);
    get_ipv4_header(&header, buffer);
    printf("%x", header.source_ip);
    
    /* printf("["); */
    /* for(int i = 0; i < nread; i++) */
    /* { */
    /*   printf("%x, ", buffer[i]); */
    /* } */
    printf("]");
    printf("\n");
     /* int nwrite = write(fd, buffer, nread); */
     /* if(nwrite < 0) */
     /* { */
     /*   strerror(errno); */
     /*   break; */
     /* } */
  }
  close(fd);
  return 0;
}
