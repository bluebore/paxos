
include config.mk

CXX=g++
INCPATH=-I$(PROTOBUF_PATH)/include -I$(SOFA_PATH)/include
CXXFLAGS=-W -Wall -Wno-unused-parameter -fPIC -D_GNU_SOURCE -D__STDC_LIMIT_MACROS -g $(INCPATH)
LIBRARY=$(SOFA_PATH)/lib/libsofa-pbrpc.a $(PROTOBUF_PATH)/lib/libprotobuf.a \
	$(SNAPPY_PATH)/lib/libsnappy.a $(LZ_PATH)/lib/libz.a
LDFLAGS=-lpthread -lrt

all: dict_server

install:
	mkdir -p ./output/bin
	cp -rf dict_server ./output/bin/

clean: 
	rm -rf dict_server
	rm -f src/*.o
	rm -f src/*.pb.cc
	rm -f src/*.pb.h
	rm -rf output

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

SERVER_OBJS = $(SERVER_SRC:.cc=.o)

dict_server: $(SERVER_OBJS) $(SERVER_HEADER)
	$(CXX) $(LDFLAGS) $(SERVER_OBJS) $(LIBRARY) -o dict_server

