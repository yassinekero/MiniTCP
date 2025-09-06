#include "tun_alloc.h"
#include <errno.h>
#include <stdint.h>
#include "ipv4.h"
#include "tcp.h"
#include "formatter.h"


#define ONLY_TCP 1
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
  Ipv4Header  ip_header;
  TcpHeader tcp_header;
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

    ipv4_header_parse(&ip_header, buffer, sizeof buffer);
    //Skip Non TCP segments
    #if ONLY_TCP == 1
    if(ip_header.protocol != 0x06)
      continue;
    #endif
    tcp_header_parse(&tcp_header, buffer, sizeof buffer);
    
    printf("\nRead %d bytes from %s\n", nread, ifname);
    ipv4_print_packet(&ip_header);
    printf("\n");
    tcp_print_segment(&tcp_header);


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
