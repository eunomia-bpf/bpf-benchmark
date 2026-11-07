#include "frame.h"
extern "C" uint64_t read_0_0(const Frame*);
extern "C" uint64_t read_0_8(const Frame*);
extern "C" uint64_t read_1_0(const Frame*);
extern "C" uint64_t read_1_8(const Frame*);
extern "C" uint64_t read_2_0(const Frame*);
extern "C" uint64_t read_2_8(const Frame*);
extern "C" uint64_t read_4_0(const Frame*);
extern "C" uint64_t read_4_8(const Frame*);
extern "C" uint64_t read_8_0(const Frame*);
extern "C" uint64_t read_8_8(const Frame*);
extern "C" uint64_t guard_0_0(const Frame*);
extern "C" uint64_t guard_0_8(const Frame*);
extern "C" uint64_t guard_1_0(const Frame*);
extern "C" uint64_t guard_1_8(const Frame*);
extern "C" uint64_t guard_2_0(const Frame*);
extern "C" uint64_t guard_2_8(const Frame*);
extern "C" uint64_t guard_4_0(const Frame*);
extern "C" uint64_t guard_4_8(const Frame*);
extern "C" uint64_t guard_8_0(const Frame*);
extern "C" uint64_t guard_8_8(const Frame*);
struct Case {const char *name; unsigned width,bytes,shift; bool guard; uint64_t (*host)(const Frame*);};
static const Case cases[]={
{"read_0_0",0,8,0,false,read_0_0},
{"read_0_8",0,8,8,false,read_0_8},
{"read_1_0",1,1,0,false,read_1_0},
{"read_1_8",1,1,8,false,read_1_8},
{"read_2_0",2,2,0,false,read_2_0},
{"read_2_8",2,2,8,false,read_2_8},
{"read_4_0",4,4,0,false,read_4_0},
{"read_4_8",4,4,8,false,read_4_8},
{"read_8_0",8,8,0,false,read_8_0},
{"read_8_8",8,8,8,false,read_8_8},
{"guard_0_0",0,8,0,true,guard_0_0},
{"guard_0_8",0,8,8,true,guard_0_8},
{"guard_1_0",1,1,0,true,guard_1_0},
{"guard_1_8",1,1,8,true,guard_1_8},
{"guard_2_0",2,2,0,true,guard_2_0},
{"guard_2_8",2,2,8,true,guard_2_8},
{"guard_4_0",4,4,0,true,guard_4_0},
{"guard_4_8",4,4,8,true,guard_4_8},
{"guard_8_0",8,8,0,true,guard_8_0},
{"guard_8_8",8,8,8,true,guard_8_8},
};
