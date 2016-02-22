#ifndef __MYPROTO_CLIENT_H__
#define __MYPROTO_CLIENT_H__
#include <stdarg.h>
#include <pjlib.h>
#include "lvcode.h"
#include "myproto.h"

typedef struct myproto_client_s myproto_client_t;

struct myproto_client_s {
	pj_sock_t fd;
	char connect_str[30];
    void *connect_data;
    char *(*id_f)();
    char *(*passphrase_f)();
};

void myproto_client_open(myproto_client_t *uclient, char *conn_str, char *(*id_f)(), char *(*pph_f)());
//void myproto_client_open_ex(myproto_client_t *uclient, char *conn_str, char *(*id_f)(), char *(*pph_f)());
int myproto_client_send(myproto_client_t *uclient, myproto_request_t *req);
//int myproto_client_send_ex(myproto_client_t *uclient, myproto_request_t *req);
//int myproto_client_recv(myproto_client_t *uclient, myproto_response_t *resp);
void myproto_client_close(myproto_client_t *uclient);
void myproto_build_request(char *buffer, int len, myproto_request_t *request);
#endif