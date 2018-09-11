#include "../include/tools.h"

mac_t *atomac(unsigned char *mac_str)
{
    static mac_t mac = { 0 };
    int tmp[6] = { 0 };

    if (!mac_str)
        return NULL;

    if (sscanf(mac_str, "%02x:%02x:%02x:%02x:%02x:%02x", &tmp[0], &tmp[1], &tmp[2],
            &tmp[3],&tmp[4],&tmp[5]) != 6)
    {
        printf("MAC doesn't valid!\n");
        return NULL;
    }

    for(int i=0; i<6; i++)
        mac.mac[i] = (unsigned char) tmp[i];

    return &mac;
}

unsigned char *mactoa(mac_t *mac)
{
    static unsigned char mac_str[18] = { 0 };

    if (!mac)
        return NULL;

    sprintf(mac_str, "%02x%02x%02x%02x%02x%02x", mac->mac[0], mac->mac[1], mac->mac[2],
            mac->mac[3], mac->mac[4], mac->mac[5]);

    return mac_str;
}

uint32_t atoip(unsigned char *ip_str)
{
    unsigned int tmp[4] = { 0 };

    if (!ip_str)
        return -1;

    if (sscanf(ip_str, "%d.%d.%d.%d", &tmp[0], &tmp[1], &tmp[2], &tmp[3]) != 4)
    {
        printf("%s\n", "IP address not valid!");
        return -1;
    }

    uint32_t ip = 0;

    return (( (( ((ip | (uint8_t) tmp[0]) << 8) | (uint8_t) tmp[1]) << 8)
            | (uint8_t) tmp[2]) << 8) | (uint8_t) tmp[3];
}

