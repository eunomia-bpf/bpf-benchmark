#ifndef F_REGISTER_READ_FRAME_H
#define F_REGISTER_READ_FRAME_H
struct Frame { unsigned long long value; unsigned int table[16]; unsigned long long canary[4]; };
#endif
