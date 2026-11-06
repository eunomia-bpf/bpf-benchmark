/* CPU oracle: every mismatch includes all inputs and both resulting states. */
#include "driver.h"
#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>
#include <unistd.h>
#ifdef __x86_64__
#include <asm/prctl.h>
#include <sys/syscall.h>
#endif
uint64_t native_stack_base;
static uint64_t seed = UINT64_C(0x6b70726f67460001);
static uint64_t random64(void)
{
    seed ^= seed << 13; seed ^= seed >> 7; seed ^= seed << 17;
    return seed;
}
static FILE *open_output(const char *dir, const char *name)
{
    char path[4096];
    int n = snprintf(path, sizeof(path), "%s/%s", dir, name);
    if (n < 0 || (size_t)n >= sizeof(path)) { fprintf(stderr, "output path too long\n"); exit(1); }
    FILE *f = fopen(path, "w");
    if (!f) { perror(path); exit(1); }
    return f;
}
static void state_json(FILE *f, const struct state *s)
{
    fputs("{\"registers\":[", f);
    for (unsigned i = 0; i < 32; i++) fprintf(f, "%s\"%016" PRIx64 "\"", i ? "," : "", s->r[i]);
    fprintf(f, "],\"flags\":\"%016" PRIx64 "\",\"vector\":[", s->flags);
    for (unsigned i = 0; i < sizeof(s->vec) / sizeof(s->vec[0]); i++)
        fprintf(f, "%s\"%016" PRIx64 "\"", i ? "," : "", s->vec[i]);
    fputs("],\"stack\":\"", f);
    for (unsigned i = 0; i < 64; i++) fprintf(f, "%02x", s->stack[i]);
    fputs("\"}", f);
}
static void memory_json(FILE *f, const unsigned char *p, size_t n)
{
    fputc('"', f);
    for (size_t i = 0; i < n; i++) fprintf(f, "%02x", p[i]);
    fputc('"', f);
}
int main(int argc, char **argv)
{
    if (argc != 3 && argc != 4) { fprintf(stderr, "usage: %s CASES OUTPUT_DIRECTORY [TRACE_BINARY]\n", argv[0]); return 1; }
    char *end;
    errno = 0;
    unsigned long cases = strtoul(argv[1], &end, 10);
    if (errno || *end || !cases || cases > 1000000) { fprintf(stderr, "invalid case count\n"); return 1; }
    FILE *trace = argc == 4 ? fopen(argv[3], "wb") : NULL;
    if (argc == 4 && !trace) { perror(argv[3]); return 1; }
    if (trace) {
        const uint32_t layout[] = {sizeof(struct state),256,form_count,(uint32_t)cases};
        if (fwrite("KPFID002",1,8,trace)!=8 || fwrite(layout,sizeof(layout),1,trace)!=1) { perror("trace header"); return 1; }
    }
    if (trace) {
        uint64_t fs_base=0,gs_base=0;
#ifdef __x86_64__
        if (syscall(SYS_arch_prctl,ARCH_GET_FS,&fs_base) || syscall(SYS_arch_prctl,ARCH_GET_GS,&gs_base)) { perror("read segment bases"); return 1; }
#endif
        FILE *metadata=open_output(argv[2],"native-code.json");
        fprintf(metadata,"{\"fs_base\":%" PRIu64 ",\"gs_base\":%" PRIu64 ",\"forms\":[",fs_base,gs_base);
        for (unsigned i=0;i<form_count;i++) {
            fprintf(metadata,"%s{\"pc\":%" PRIuPTR ",\"next_pc\":%" PRIuPTR ",\"native_bytes\":[",i?",":"",(uintptr_t)forms[i].pc,(uintptr_t)forms[i].next_pc);
            size_t bytes=(uintptr_t)forms[i].next_pc-(uintptr_t)forms[i].pc;
            for (size_t b=0;b<bytes;b++) fprintf(metadata,"%s%u",b?",":"",forms[i].pc[b]);
            fputs("]}",metadata);
        }
        fputs("]}\n",metadata);
        int metadata_error=ferror(metadata);
        if (fclose(metadata)) metadata_error=1;
        if (metadata_error) { perror("native-code metadata"); return 1; }
    }
    FILE *summary = open_output(argv[2], "forms.tsv");
    FILE *mismatches = open_output(argv[2], "mismatches.jsonl");
    FILE *meta = open_output(argv[2], "host.txt");
    struct utsname u;
    if (uname(&u)) { perror("uname"); return 1; }
    fprintf(meta, "%s %s %s\nseed=0x%016" PRIx64 "\ncases_per_form=%lu\n", u.sysname, u.release, u.machine, seed, cases);
    if (fclose(meta)) { perror("host.txt"); return 1; }
    fputs("assembly\topcode\tcases\tmismatches\n", summary);
    unsigned long total = 0, failures = 0;
    _Alignas(16) unsigned char memory[256], before[256], native_memory[256];
    for (unsigned j = 0; j < form_count; j++) {
        const struct form *form = &forms[j];
        unsigned long bad = 0;
        for (unsigned long c = 0; c < cases; c++) {
            struct state input, native, sim;
            for (unsigned i = 0; i < 32; i++) input.r[i] = random64();
            for (unsigned i = 0; i < sizeof(memory); i++) memory[i] = random64();
            for (unsigned i = 0; i < sizeof(input.stack); i++) input.stack[i] = random64();
            for (unsigned i = 0; i < sizeof(input.vec) / sizeof(input.vec[0]); i++)
                input.vec[i] = random64();
#ifdef __x86_64__
            input.flags = 0x202 | ((c & 1) ? 1 : 0) | ((c & 2) ? 0x40 : 0) | ((c & 4) ? 0x80 : 0) | ((c & 8) ? 0x800 : 0) | ((c & 16) ? 4 : 0) | ((c & 32) ? 0x10 : 0);
            input.r[4] = form->mode == 5 ? (int64_t)(int32_t)form->count : 0; /* abstract RSP */
            input.r[7] = (uintptr_t)(memory + 32);
            input.r[6] = (uintptr_t)(memory + 160);
            if (form->mode == 4) input.r[1] = 8; /* fixed-count REP MOVS */
            if (form->mode == 1) { input.r[2] = 0; input.r[3] |= 1; } /* non-faulting DIV */
#else
            input.flags = (uint64_t)(c & 15) << 28;
            input.r[31] = 0; /* SP is the wrapper's private stack. */
            input.r[4] = (uintptr_t)(memory + 32);
            input.r[5] = 8; /* bounded address index */
#endif
            /* Boundary inputs precede random inputs; all status-flag combinations cycle. */
            if (c < 128) {
                static const uint64_t edge[] = {0, 1, 0x7f, 0x80, 0xff, 0x7fff, 0x8000, 0xffff, 0x7fffffff, 0x80000000, 0xffffffff, UINT64_C(0x7fffffffffffffff), UINT64_C(0x8000000000000000), UINT64_MAX, 0x5555555555555555, 0xaaaaaaaaaaaaaaaa};
                input.r[0] = edge[c % 16];
#ifdef __x86_64__
                if (form->mode != 1) input.r[3] = edge[(c / 8) % 16];
#else
                input.r[1] = edge[(c / 8) % 16];
                input.r[2] = edge[(c / 4) % 16];
#endif
            }
            memcpy(before, memory, sizeof(memory));
            native = sim = input;
            form->native(&native);
            memcpy(native_memory, memory, sizeof(memory));
            memcpy(memory, before, sizeof(memory));
            form->sim(&sim);
            uint64_t mask = form->flag_mask;
#ifdef __x86_64__
            if (form->mode == 2 || form->mode == 3) {
                unsigned count = form->count == 256 ? input.r[1] : form->count;
                count &= form->width == 64 ? 63 : 31;
                if (form->mode == 2 && count) mask &= ~UINT64_C(0x10); /* AF undefined */
                if (count > 1) mask &= ~UINT64_C(0x800); /* OF undefined */
                if (form->mode == 2 && count >= form->width) mask &= ~UINT64_C(1); /* CF undefined */
            }
#endif
            if (trace) {
                const uint32_t record[] = {j,(uint32_t)c};
                if (fwrite(record,sizeof(record),1,trace)!=1 || fwrite(&native_stack_base,sizeof(native_stack_base),1,trace)!=1 ||
                    fwrite(&input,sizeof(input),1,trace)!=1 || fwrite(&native,sizeof(native),1,trace)!=1 || fwrite(&sim,sizeof(sim),1,trace)!=1 ||
                    fwrite(before,sizeof(before),1,trace)!=1 || fwrite(native_memory,sizeof(native_memory),1,trace)!=1 || fwrite(memory,sizeof(memory),1,trace)!=1) {
                    perror("trace record"); return 1;
                }
            }
            int differs = memcmp(native.r, sim.r, sizeof(input.r)) ||
                memcmp(native.vec, sim.vec, sizeof(input.vec)) ||
                memcmp(native.stack, sim.stack, sizeof(input.stack)) ||
                ((native.flags ^ sim.flags) & mask) ||
                memcmp(native_memory, memory, sizeof(memory));
            if (differs) {
                bad++;
                fprintf(mismatches, "{\"form\":%u,\"assembly\":\"%s\",\"case\":%lu,\"flag_mask\":\"%016" PRIx64 "\",\"native_stack_base\":\"%016" PRIx64 "\",\"input\":", j, form->assembly, c, mask, native_stack_base);
                state_json(mismatches, &input);
                fputs(",\"native\":", mismatches); state_json(mismatches, &native);
                fputs(",\"simulator\":", mismatches); state_json(mismatches, &sim);
                fputs(",\"memory_input\":", mismatches); memory_json(mismatches, before, sizeof(before));
                fputs(",\"memory_native\":", mismatches); memory_json(mismatches, native_memory, sizeof(memory));
                fputs(",\"memory_simulator\":", mismatches); memory_json(mismatches, memory, sizeof(memory));
                fputs("}\n", mismatches);
            }
        }
        fprintf(summary, "%s\t%s\t%lu\t%lu\n", form->assembly, form->opcode, cases, bad);
        total += cases; failures += bad;
    }
    int error = ferror(summary) || ferror(mismatches);
    if (trace && fclose(trace)) error = 1;
    if (fclose(summary)) error = 1;
    if (fclose(mismatches)) error = 1;
    if (error) { fprintf(stderr, "writing results failed\n"); return 1; }
    printf("forms=%u cases=%lu mismatches=%lu\n", form_count, total, failures);
    return failures ? 1 : 0;
}
