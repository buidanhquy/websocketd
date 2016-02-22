#ifndef __MYPROTO_SERVER_H__
#define __MYPROTO_SERVER_H__
#include <pjlib.h>
#include "myproto.h"

typedef struct myproto_server_s myproto_server_t;

struct myproto_server_s {
    pj_sock_t fd;
    pj_pool_t *pool;
    pj_thread_t *master_thread;
    pj_mutex_t *mutex;
    char connect_str[30];
    volatile int is_end;
    int (*recv_f)(int fd, char *buff, int len, void *data, unsigned int *data_len);
    int (*send_f)(int fd, char *buff, int len, void *data, unsigned int data_len);
    void (*on_request_f)(myproto_server_t *userver, myproto_request_t *request, char *caddr_str);
    void (*on_init_done_f)(myproto_server_t *userver);
    void (*on_open_socket_f)(myproto_server_t *userver);
    char *(*get_pph_f)(pj_str_t *id);
    void *user_data;

    int is_online;
};

void myproto_server_init(myproto_server_t *userver, char *conn_str, pj_pool_t *pool, char *(*get_pph_f)(pj_str_t *id));
//void myproto_server_init_ex(myproto_server_t *userver, char *conn_str, pj_pool_t *pool, char *(*get_pph_f)(pj_str_t *id));
void myproto_server_start(myproto_server_t *userver);
//void myproto_server_start_ex(myproto_server_t *userver);
void myproto_server_join(myproto_server_t *userver, char *multicast_ip);
void myproto_server_leave(myproto_server_t *userver, char *multicast_ip);
void myproto_server_end(myproto_server_t *userver);
void myproto_parse_request(char *buffer, int len, myproto_request_t *request);
#endif