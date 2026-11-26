/* Result-only range lifetime control. Keep the existing full clear/release;
 * range invalidation only changes the tag. READ_ONE consumes pointer only for
 * STACK, and SAVE_ONE replaces pointer before setting STACK. */
#undef X86_SIM_L_SV_ERASE_ONE
#define X86_SIM_L_SV_ERASE_ONE(I) \
    do { __u64 __x86_sv_start=(__u64)(I)*8U; \
         if (__x86_sv_index-__x86_sv_start<8U || __x86_sv_start-__x86_sv_index<__x86_sv_width) \
             X86_SIM_L_SV_TAG(I)=X86_SIM_TAG_SCALAR; } while(0);
