/* CPU oracle: every mismatch includes all inputs and both resulting states. */
#include "driver.h"
#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>
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
    fprintf(f, "],\"flags\":\"%016" PRIx64 "\",\"vector\":[\"%016" PRIx64 "\",\"%016" PRIx64 "\"],\"stack\":\"", s->flags, s->vec[0], s->vec[1]);
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
    if (argc != 3) { fprintf(stderr, "usage: %s CASES OUTPUT_DIRECTORY\n", argv[0]); return 1; }
    char *end;
    errno = 0;
    unsigned long cases = strtoul(argv[1], &end, 10);
    if (errno || *end || !cases || cases > 1000000) { fprintf(stderr, "invalid case count\n"); return 1; }
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
            input.vec[0] = random64(); input.vec[1] = random64();
#ifdef __x86_64__
            input.flags = 0x202 | ((c & 1) ? 1 : 0) | ((c & 2) ? 0x40 : 0) | ((c & 4) ? 0x80 : 0) | ((c & 8) ? 0x800 : 0);
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
            /* Boundary inputs precede fixed-seed random inputs; flags cycle all 16 combinations. */
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
                if (count > 1) mask &= ~UINT64_C(0x800); /* OF undefined */
                if (form->mode == 2 && count >= form->width) mask &= ~UINT64_C(1); /* CF undefined */
            }
#endif
            int differs = memcmp(native.r, sim.r, sizeof(input.r)) ||
                memcmp(native.vec, sim.vec, sizeof(input.vec)) ||
                memcmp(native.stack, sim.stack, sizeof(input.stack)) ||
                ((native.flags ^ sim.flags) & mask) ||
                memcmp(native_memory, memory, sizeof(memory));
            if (differs) {
                bad++;
                fprintf(mismatches, "{\"form\":%u,\"assembly\":\"%s\",\"case\":%lu,\"flag_mask\":\"%016" PRIx64 "\",\"input\":", j, form->assembly, c, mask);
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
    if (fclose(summary)) error = 1;
    if (fclose(mismatches)) error = 1;
    if (error) { fprintf(stderr, "writing results failed\n"); return 1; }
    printf("forms=%u cases=%lu mismatches=%lu\n", form_count, total, failures);
    return failures ? 1 : 0;
}
