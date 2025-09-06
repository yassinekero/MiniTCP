#include "formatter.h"

void ipv4_addr_notation(char* ip_str, size_t size, uint32_t ip_addr)
{
  snprintf(ip_str, size, "%d.%d.%d.%d", (ip_addr & 0xFF000000) >> 24, (ip_addr & 0xFF0000) >> 16, (ip_addr & 0xFF00) >> 8, ip_addr & 0xFF);
}
void ipv4_print_packet(Ipv4Header* header)
{
  char source_ip_str[128] ;
  char dest_ip_str[128];
  ipv4_addr_notation(source_ip_str, sizeof(source_ip_str), header->source_ip);
  ipv4_addr_notation(dest_ip_str, sizeof(dest_ip_str), header->dest_ip);

  printf("%s ->  %s : total length=%d bytes, protocol=%d,  id=%d, ttl=%d", source_ip_str, dest_ip_str, header->total_length,header->protocol, header->id, header->ttl);
}
void tcp_print_segment(TcpHeader* header)
{
  printf("src port: %d, dst port: %d", header->source_port, header->dest_port);
}

