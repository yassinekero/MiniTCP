#include "tun_alloc.h"
#include <errno.h>
#include <stdint.h>
#include "ipv4.h"
#include "formatter.h"

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
    uint16_t eth_protocol = 0x00;
    eth_protocol = (eth_protocol  | buffer[2]) << 8;
    eth_protocol = eth_protocol | buffer[3];
    //Skip Non IPV4 packets
    if(eth_protocol != 0x0800) 
      continue;
    printf("\nRead %d bytes from %s\n", nread, ifname);
    get_ipv4_header(&header, buffer);
    print_ipv4_packet(&header);

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
