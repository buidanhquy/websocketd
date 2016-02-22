#include "myproto-client.h"
#include "ansi-utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void usage(char *app) {
	printf("%s <connection string>\n", app);
	exit(-1);
}

int main(int argc, char *argv[]) {
	myproto_client_t uclient;
    myproto_request_t req;
    char option[10], *dummy;

	if( argc < 2 ) {
		usage(argv[0]);
	}
        setbuf(stdout, NULL);

    printf("zzzz\n");
    
    myproto_client_open(&uclient, argv[1], NULL, NULL);
    dummy = fgets(option, sizeof(option), stdin);

    req.msg_id = LIST_TABLES;
    myproto_client_send(&uclient, &req);

    myproto_client_close(&uclient);

    return 0;
}
