/* Result-only lifetime control. READ_ONE consumes pointer only for STACK;
 * SAVE_ONE replaces pointer before setting STACK. Raw native bytes unchanged. */
#undef X86_SIM_L_SV_CLEAR_ONE
#define X86_SIM_L_SV_CLEAR_ONE(I) \
    do { X86_SIM_L_SV_TAG(I)=X86_SIM_TAG_SCALAR; } while(0);
