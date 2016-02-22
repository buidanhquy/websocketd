.PHONY: all clean
include custom.mk
USERVER_DIR:=../../userver

COMMON_DIR:=../../common
COMMON_SRCS:=ansi-utils.c my-pjlib-utils.c my-openssl.c lvcode.c

PROTOCOL:=$(shell ls -1 protocol|head -1)
PROTOCOL_DIR:=./protocol

GEN_DIR:=gen
GEN_S_SRCS:=myproto-server.c
GEN_C_SRCS:=myproto-client.c

MAIN_DIR:=.
MAIN_S_SRCS:=server.c
MAIN_C_SRCS:=client.c

SERVER_APP:=man_itf
CLIENT_APP:=config

CFLAGS:=-DPJ_AUTOCONF=1 -O2 -DPJ_IS_BIG_ENDIAN=0 -DPJ_IS_LITTLE_ENDIAN=1 -fms-extensions
CFLAGS+=-I$(COMMON_DIR)/include
CFLAGS+=-I$(LIBS_DIR)/include
CFLAGS+=-I$(LIBS_DIR)/include/json-c
CFLAGS+=-I$(GEN_DIR)
CFLAGS+=-I$(MAIN_DIR)/include
CFLAGS+=-I$(USERVER_DIR)/include
CFLAGS+=-D__ICS_INTEL__

LIBS+= -lcrypto

all: gen $(SERVER_APP) $(CLIENT_APP)

gen: protocol/$(PROTOCOL)
	mkdir -p gen 
	awk -v base_dir=$(USERVER_DIR) -f $(USERVER_DIR)/gen-tools/gen.awk $<

$(SERVER_APP): $(MAIN_S_SRCS:.c=.o) $(COMMON_SRCS:.c=.o) $(GEN_S_SRCS:.c=.o) 
	$(CROSS_TOOL) -o $@ $^ $(LIBS)

$(CLIENT_APP): $(COMMON_SRCS:.c=.o) $(GEN_C_SRCS:.c=.o) $(MAIN_C_SRCS:.c=.o)
	$(CROSS_TOOL) -o $@ $^ $(LIBS)

$(COMMON_SRCS:.c=.o): %.o: $(COMMON_DIR)/src/%.c
	$(CROSS_TOOL) -o $@ -c $< $(CFLAGS)

$(GEN_S_SRCS:.c=.o): %.o: $(GEN_DIR)/%.c
	$(CROSS_TOOL) -o $@ -c $< $(CFLAGS)

$(GEN_C_SRCS:.c=.o): %.o: $(GEN_DIR)/%.c
	$(CROSS_TOOL) -o $@ -c $< $(CFLAGS)

$(MAIN_C_SRCS:.c=.o): %.o: $(MAIN_DIR)/src/%.c
	$(CROSS_TOOL) -o $@ -c $< $(CFLAGS)

$(MAIN_S_SRCS:.c=.o): %.o: $(MAIN_DIR)/src/%.c
	$(CROSS_TOOL) -o $@ -c $< $(CFLAGS)

clean:
	rm -fr gen $(SERVER_APP) $(CLIENT_APP) *.o
