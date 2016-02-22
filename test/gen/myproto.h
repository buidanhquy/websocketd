#ifndef __MYPROTO_H__
#define __MYPROTO_H__

typedef struct myproto_request_s myproto_request_t;
struct myproto_request_s {
    int msg_id;
    union {
        struct {
            char request[50];
        } list_tables;

        struct {
            char table_name[10];
        } show_table;

        struct {
            char table_name[10];
        } edit_table;

    };
};

#define SHOW_TABLE 101
#define EDIT_TABLE 102
#define LIST_TABLES 100
#endif
