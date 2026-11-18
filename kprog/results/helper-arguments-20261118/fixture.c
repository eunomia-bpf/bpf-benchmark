#include <linux/bpf.h>
#include <stdint.h>
#include <stdio.h>
#define MICRO_NATIVE_HELPER_MACROS
#define __KPROG_HELPERS_ARE_POINTERS
#define __KPROG_SCAN_ONLY__
#include "vendor/bpf/core-compat.h"

#ifdef TEST_ID_ONLY
/* Kept so the draft patch's shape still builds; the header is id-only now. */
#endif

static uint32_t keys[8];
volatile unsigned key_evaluations;
__attribute__((noinline)) const void *next_key(void) {
    unsigned index=key_evaluations++;
    return &keys[index];
}

#ifndef ACTUAL_IR
static unsigned callback_calls,selector_calls;
static void *expected_map;
static void *lookup_callback(void *map,const void *key) {
    if(map!=expected_map) return NULL;
    callback_calls++;
    return (void *)key;
}
static unsigned long observed_selector0(unsigned long id) {
    asm volatile("" : "+r"(id) : : "memory");
    selector_calls++;
    return (unsigned long)lookup_callback;
}
static unsigned long observed_selector2(unsigned long id,unsigned long a0,unsigned long a1) {
    asm volatile("" : "+r"(id) : "r"(a0),"r"(a1) : "memory");
    selector_calls++;
    return (unsigned long)lookup_callback;
}
/* The header selects on the helper id alone, so its id selector is the one to
 * alias: the macro's own call then evaluates the arguments, once. observed_
 * selector2 covers the older arity-2 selector, so the same fixture also runs
 * (and fails on the evaluation count) against a header that still ties the
 * arguments into the selector. */
#define native_helper_id0 observed_selector0
#define native_helper_id2 observed_selector2
#endif

__attribute__((noinline)) void *actual_header_lookup(void *map) {
    return bpf_map_lookup_elem(map,next_key());
}

#ifdef ACTUAL_IR
/* tracemgmt.h:312 passes the same mutable state->fp source expression. */
struct sample_state { unsigned long fp; };
long actual_header_probe(void *destination,struct sample_state *state) {
    return bpf_probe_read_user(destination,8,(void *)state->fp);
}
long actual_header_trace(void) {
    return __kprog_trace_printk("x",1,0,0,0);
}
#endif

#ifndef ACTUAL_IR
int main(void) {
    int map=0;expected_map=&map;
    void *control=lookup_callback(&map,next_key());
    printf("control key_evaluations=%u callback_calls=%u key_index=%ld\n",
           key_evaluations,callback_calls,(long)((uint32_t *)control-keys));
    if(key_evaluations!=1 || callback_calls!=1 || control!=keys) return 2;
    key_evaluations=callback_calls=selector_calls=0;
    void *actual=actual_header_lookup(&map);
    printf("header key_evaluations=%u callback_calls=%u selector_calls=%u key_index=%ld\n",
           key_evaluations,callback_calls,selector_calls,(long)((uint32_t *)actual-keys));
    return key_evaluations!=1 || callback_calls!=1 || selector_calls!=1;
}
#endif
