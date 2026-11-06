/* ELF interface probe only: explicit extern identity, no allocated fake map. */
#include <linux/bpf.h>
#include <bpf_helpers.h>
extern __u8 __source_value_base_0[] __ksym;
SEC("socket") int source_map_elf_probe(void *ctx)
{
    __u64 value=42;
    void *address=(void *)(__source_value_base_0+16);
    asm volatile("*(u64 *)(%0 + 0) = %1" : : "r"(address), "r"(value) : "memory");
    return 0;
}
char LICENSE[] SEC("license")="GPL";
static const char metadata[] SEC(".native_lab.source_maps") =
    "{\"version\":1,\"objects\":[{\"native_symbol\":\"__native_source_map_value_0\",\"source_insn\":0,\"proof_symbol\":\"__source_value_base_0\"}]}";
