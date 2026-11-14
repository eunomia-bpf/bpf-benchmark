// Detect embedding default data instead of reading the selected global binding.
struct config_pair { unsigned enabled; unsigned long selector; };
#ifdef TEST_DRIVER
volatile unsigned long config_word;
volatile unsigned char config_flag;
volatile struct config_pair config_pair;
volatile unsigned data_counter;
extern unsigned long read_word(void);
extern unsigned read_flag(void);
extern unsigned long read_pair(void);
extern unsigned read_counter(void);
int main(void) {
    unsigned long values[] = {0, 1, 0xffffffffUL, 0x100000000UL, 0x8000000000000000UL, ~0UL};
    for (unsigned i = 0; i < sizeof(values) / sizeof(values[0]); ++i) {
        config_word = values[i];config_flag = (unsigned char)(i & 1);
        config_pair.enabled = i + 7;config_pair.selector = values[i] ^ 0x123456789abcdef0UL;
        data_counter = (unsigned)values[i] ^ 0xaabbccddU;
        if (read_word() != config_word) return 1;
        if (read_flag() != config_flag) return 2;
        if (read_pair() != (config_pair.selector ^ config_pair.enabled)) return 3;
        if (read_counter() != data_counter) return 4;
    }
    return 0;
}
#else
volatile const unsigned long config_word __attribute__((section(".rodata.config")));
volatile const unsigned char config_flag __attribute__((section(".rodata.config")));
volatile const struct config_pair config_pair __attribute__((section(".rodata.config")));
volatile unsigned data_counter;
#define CONFIG(name) (*({void *out;asm volatile("%0 = " #name " ll" : "=r"(out)); (typeof(name) *)out;}))
__attribute__((section("test/config"), used))
unsigned long read_word(void) { return CONFIG(config_word); }
__attribute__((section("test/config"), used))
unsigned read_flag(void) { return CONFIG(config_flag); }
__attribute__((section("test/config"), used))
unsigned long read_pair(void) { return CONFIG(config_pair).selector ^ CONFIG(config_pair).enabled; }
__attribute__((section("test/config"), used))
unsigned read_counter(void) { return data_counter; }
#endif
