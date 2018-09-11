#ifndef PARAMS_H
#define PARAMS_H

#include <net/if.h> // iface configuration
#include "../include/tools.h"

typedef struct
{
  unsigned char if_name[IFNAMSIZ];
  mac_t *mac_dest;
  uint32_t ip_dest;

} param_t;


#endif // PARAMS_H
