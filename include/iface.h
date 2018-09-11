#ifndef IFACE_H
#define IFACE_H

#include <arpa/inet.h> // htons, uint8_t, IPPROTO*
#include <sys/ioctl.h> // ioctl feature
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "../include/params.h"

#define BSIZE 1518 // MTU + ethernet header length

typedef struct
{
  struct ifreq handler;
  unsigned char if_name[IFNAMSIZ];
  int if_idx;
  struct sockaddr if_hwdaddr;
  struct sockaddr saddr;

} iface_data_t;

/* XXX: This struct should be relocated to corresponding header */
typedef struct
{
   unsigned char packet[BSIZE];
   size_t pos;

} packet_t;

int open_socket(int domain, int type, int protocol);
void get_iface_data(int fd, iface_data_t *iface, param_t *params);

#endif // IFACE_H
