/* Backend-only context operand probe; no runtime load or workload. */
typedef unsigned int u32;
typedef u32 unaligned_u32 __attribute__((aligned(1), may_alias));
unsigned int register_operand(void *ctx, volatile unsigned long *choice)
{
    void *address = (char *)ctx + 20;
    if ((unsigned long)address < 4096 || *choice) return 0;
    unsigned long value;
    asm volatile("%0 = *(u32 *)(%1 + 0)" : "=r"(value) : "r"(address) : "memory");
    return value;
}
unsigned int memory_operand(void *ctx, volatile unsigned long *choice)
{
    void *address = (char *)ctx + 20;
    if ((unsigned long)address < 4096 || *choice) return 0;
    unsigned long value;
    asm volatile("%0 = *(u32 *)%1" : "=r"(value) : "m"(*(volatile const unaligned_u32 *)address) : "memory");
    return value;
}
