#ifndef __PROTO_H__
#define __PROTO_H__
typedef struct uproto_request_s uproto_request_t;
typedef struct uproto_response_s uproto_response_t;
struct uproto_request_s {
	char name[50];
	int age;
};

struct uproto_response_s {
	int code;
	char msg[20];
};
#endif
