unsigned long verified_dispatch(unsigned long value) {
    if(value>7) __asm__ volatile("call -1");
    return value*3;
}
unsigned long verified_memory(unsigned long value) {
    if(value>7) __asm__ volatile("r0 = 0; *(u64 *)(r0 + 0) = r0; exit;");
    return value+4;
}
unsigned long program_check(unsigned long value) {
    if(value>7)return 99;
    return value*3;
}
