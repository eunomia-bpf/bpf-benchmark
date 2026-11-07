extern "C" uint64_t load_0(const void*);
extern "C" uint64_t load_1(const void*);
extern "C" uint64_t load_2(const void*);
extern "C" uint64_t load_4(const void*);
extern "C" uint64_t load_8(const void*);
extern "C" uint64_t fixed_0_0(const void*);
extern "C" uint64_t fixed_0_1(const void*);
extern "C" uint64_t fixed_0_2(const void*);
extern "C" uint64_t fixed_0_4(const void*);
extern "C" uint64_t fixed_0_8(const void*);
extern "C" uint64_t fixed_1_0(const void*);
extern "C" uint64_t fixed_1_1(const void*);
extern "C" uint64_t fixed_1_2(const void*);
extern "C" uint64_t fixed_1_4(const void*);
extern "C" uint64_t fixed_1_8(const void*);
extern "C" uint64_t fixed_2_0(const void*);
extern "C" uint64_t fixed_2_1(const void*);
extern "C" uint64_t fixed_2_2(const void*);
extern "C" uint64_t fixed_2_4(const void*);
extern "C" uint64_t fixed_2_8(const void*);
extern "C" uint64_t fixed_3_0(const void*);
extern "C" uint64_t fixed_3_1(const void*);
extern "C" uint64_t fixed_3_2(const void*);
extern "C" uint64_t fixed_3_4(const void*);
extern "C" uint64_t fixed_3_8(const void*);
extern "C" uint64_t fixed_4_0(const void*);
extern "C" uint64_t fixed_4_1(const void*);
extern "C" uint64_t fixed_4_2(const void*);
extern "C" uint64_t fixed_4_4(const void*);
extern "C" uint64_t fixed_4_8(const void*);
extern "C" uint64_t fixed_5_0(const void*);
extern "C" uint64_t fixed_5_1(const void*);
extern "C" uint64_t fixed_5_2(const void*);
extern "C" uint64_t fixed_5_4(const void*);
extern "C" uint64_t fixed_5_8(const void*);
struct Case {const char *name; unsigned width,bytes; int disp; uint64_t (*host)(const void*);};
static const Case cases[]={
{"load_0",0,8,0,load_0},
{"load_1",1,1,0,load_1},
{"load_2",2,2,0,load_2},
{"load_4",4,4,0,load_4},
{"load_8",8,8,0,load_8},
{"fixed_0_0",0,8,-32768,fixed_0_0},
{"fixed_0_1",1,1,-32768,fixed_0_1},
{"fixed_0_2",2,2,-32768,fixed_0_2},
{"fixed_0_4",4,4,-32768,fixed_0_4},
{"fixed_0_8",8,8,-32768,fixed_0_8},
{"fixed_1_0",0,8,-3,fixed_1_0},
{"fixed_1_1",1,1,-3,fixed_1_1},
{"fixed_1_2",2,2,-3,fixed_1_2},
{"fixed_1_4",4,4,-3,fixed_1_4},
{"fixed_1_8",8,8,-3,fixed_1_8},
{"fixed_2_0",0,8,-1,fixed_2_0},
{"fixed_2_1",1,1,-1,fixed_2_1},
{"fixed_2_2",2,2,-1,fixed_2_2},
{"fixed_2_4",4,4,-1,fixed_2_4},
{"fixed_2_8",8,8,-1,fixed_2_8},
{"fixed_3_0",0,8,0,fixed_3_0},
{"fixed_3_1",1,1,0,fixed_3_1},
{"fixed_3_2",2,2,0,fixed_3_2},
{"fixed_3_4",4,4,0,fixed_3_4},
{"fixed_3_8",8,8,0,fixed_3_8},
{"fixed_4_0",0,8,88,fixed_4_0},
{"fixed_4_1",1,1,88,fixed_4_1},
{"fixed_4_2",2,2,88,fixed_4_2},
{"fixed_4_4",4,4,88,fixed_4_4},
{"fixed_4_8",8,8,88,fixed_4_8},
{"fixed_5_0",0,8,32767,fixed_5_0},
{"fixed_5_1",1,1,32767,fixed_5_1},
{"fixed_5_2",2,2,32767,fixed_5_2},
{"fixed_5_4",4,4,32767,fixed_5_4},
{"fixed_5_8",8,8,32767,fixed_5_8},
};
