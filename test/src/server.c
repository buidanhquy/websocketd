#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "myproto-server.h"
#include "ansi-utils.h"

void usage(char *app) {
	printf("%s <connection string>\n", app);
	exit(-1);
}

static void on_request(myproto_server_t *userver, myproto_request_t *request, char *peer_host) {
    switch(request->msg_id) {
    case LIST_TABLES:
        SHOW_LOG(3, "List tables request received !\n");
        break;
    case SHOW_TABLE:
        SHOW_LOG(3, "Show tables request received !\n");
        break;
    }
}

int main(int argc, char *argv[]) {
    pj_caching_pool cp;
    pj_pool_t *pool;
	myproto_server_t userver;
	if( argc < 2 ) {
		usage(argv[0]);
	}
    pj_init();
    pj_caching_pool_init(&cp, 0, 4096);
    pool = pj_pool_create(&cp.factory, "pool", 256, 256, NULL);

    userver.on_init_done_f = NULL;

    myproto_server_init(&userver, argv[1], pool, NULL);
	userver.on_request_f = &on_request;
    userver.on_open_socket_f = NULL;

	myproto_server_start(&userver);
	// Main loop goes here
	my_pause();
    myproto_server_join(&userver, "239.0.0.1");
    my_pause();
    myproto_server_leave(&userver, "239.0.0.1");
    my_pause();
	myproto_server_end(&userver);
	return 0;
}
