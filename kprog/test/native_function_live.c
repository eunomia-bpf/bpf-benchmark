#ifdef FUNCTION_DRIVER
extern unsigned long function_entry(void *);
int main(void) { return function_entry((void *)6) == 13 ? 0 : 1; }
#else
extern unsigned long captured_function(unsigned long, unsigned long);
unsigned long function_entry(void *context)
{
    return captured_function((unsigned long)context, 7);
}
#endif
