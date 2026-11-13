#ifdef KFUNC_PRESENT_STRONG
extern long present(unsigned long);
#else
extern long present(unsigned long) __attribute__((weak));
#endif
extern long absent(unsigned long) __attribute__((weak));
extern long ordinary(unsigned long);

long entry(unsigned long value)
{
    value = ordinary(value);
#ifdef KFUNC_PRESENT_STRONG
    return present(value) + (absent ? absent(value) : 0);
#else
    if (present)
        return present(value);
    if (absent)
        return absent(value);
    return -1;
#endif
}
