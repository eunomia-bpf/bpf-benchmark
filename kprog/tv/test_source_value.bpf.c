/* No map declaration, fake extent or data initialization: the source FD owns
 * the value; the explicit ELF relocation imports only its base address.
 */
#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
extern unsigned char tv_source_value_base[] __ksym;
SEC("xdp") int tv_proof_source_value(void *ctx)
{
    (void)ctx;
    unsigned long value;
    void *address = tv_source_value_base + 1;
    asm volatile("%0 = *(u8 *)(%1 + 0)" : "=r"(value) : "r"(address) : "memory");
    return value;
}
char LICENSE[] SEC("license") = "GPL";
#ifndef TV_SOURCE_SITE
#define TV_SOURCE_SITE "0"
#endif
static const char metadata[] SEC(".native_lab.source_maps") =
    "{\"version\":1,\"objects\":[{\"native_symbol\":\"tv_source_value\","
    "\"source_insn\":" TV_SOURCE_SITE ",\"proof_symbol\":\"tv_source_value_base\"}]}";
