// Frozen configs must use the supplied bytes while mutable data stays live.
extern unsigned long read_word(void);
extern unsigned read_flag(void);
extern unsigned long read_pair(void);
extern unsigned read_counter(void);
volatile unsigned data_counter;
int main(void) {
    for (unsigned i = 0; i < 6; ++i) {
        data_counter = i ^ 0xaabbccddU;
        if (read_word() != 0x8877665544332211UL || read_flag() != 1 ||
            read_pair() != (0xfedcba9876543210UL ^ 0x12345678U)) return 1;
        if (read_counter() != data_counter) return 2;
    }
    return 0;
}
