#ifndef TCP_H
#define TCP_H
#include <stdint.h>
#include <stddef.h>
typedef struct
{
  uint32_t seq;
  uint32_t ack;
  uint16_t src_port;
  uint16_t dest_port;
  uint16_t data_offset : 4;
  uint16_t flags: 6;
  uint16_t window_size;
  uint16_t chucksum;
  uint16_t urgent_pointer;
} TcpHeader;

#define URG_BIT 0x20
#define ACK_BIT 0x10
#define PSH_BIT 0x08
#define RST_BIT 0x04
#define SYN_BIT 0x02
#define FIN_BIT 0x01
int tcp_header_parse(TcpHeader* header, uint8_t* buffer, size_t size);
#endif // TCP_H
