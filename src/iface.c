#include "../include/iface.h"

int open_socket(int domain, int type, int protocol)
{
    int fd;

    /* default: protocol values is 0 (IPPROTO_IP)
    IPPROTO means that we operates with 3d OSI layer */

    if ((fd = socket(domain, type, protocol)) == -1)
    {
        perror("Socket ");
        return -1;
    }

    return fd;
}

void get_iface_data(int fd, iface_data_t *iface, param_t *params)
{
    /* Store iface name */
    memcpy(iface->if_name, params->if_name, IFNAMSIZ - 1);
    memcpy(iface->handler.ifr_name, iface->if_name, IFNAMSIZ - 1);

    /* Get the index of the interface to send on */
    if (ioctl(fd, SIOCGIFINDEX, &iface->handler) < 0)
        perror("SIOCGIFINDEX");

    iface->if_idx = iface->handler.ifr_ifindex;

    /* Get the MAC address of the interface to send on */
    if (ioctl(fd, SIOCGIFHWADDR, &iface->handler) < 0)
        perror("SIOCGIFHWADDR");

    memcpy(&iface->if_hwdaddr, &iface->handler.ifr_hwaddr, sizeof(struct sockaddr));
}
