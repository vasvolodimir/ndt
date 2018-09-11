#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <arpa/inet.h> // for typedefs

typedef struct
{
    unsigned char mac[6];
} mac_t;

mac_t *atomac(unsigned char *mac_str);
unsigned char *mactoa(mac_t *mac);
uint32_t atoip(unsigned char *ip_str);


#endif // TOOLS_H
