#ifndef TCP_H
#define TCP_H
#include <stdint.h>
#include <stddef.h>
typedef struct
{
  uint32_t seq;
  uint32_t ack;
  uint16_t source_port;
  uint16_t dest_port;
  uint16_t data_offset : 4;
  uint16_t flags: 6;
  uint16_t window_size;
  uint16_t chucksum;
  uint16_t urgent_pointer;
} TcpHeader;

int tcp_header_parse(TcpHeader* header, uint8_t* buffer, size_t size);
#endif // TCP_H
