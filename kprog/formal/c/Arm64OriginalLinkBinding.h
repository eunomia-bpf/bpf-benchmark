/* Original pointer-writer statement body, retained inline only for LINK.
 * Other operations keep the existing extraction bindings. */
#define KPROG_ARM64_ORIGINAL_LINK_WRITE(REG, VALUE, TAG) \
	do { __s64 __a64_write_old_sp=__a64_sp;  __u64 __a64_l_reg = (REG); \
	     void *__a64_l_next_ptr = (void *)(VALUE); \
	     __u8 __a64_l_next_tag = (TAG); \
	     if (__a64_l_reg == ARM64_SP) { \
	       if (__a64_l_next_tag == ARM64_SIM_TAG_STACK) \
	           __a64_sp = (__s64)(long)__a64_l_next_ptr; \
	       else { \
	           __u64 __a64_write_value, __a64_write_base; \
	           ARM64_SIM_L_MATERIALIZE_INTO(__a64_write_value, (__u64)(long)__a64_l_next_ptr, __a64_l_next_tag); \
	           ARM64_SIM_L_STACK_BASE_INTO(__a64_write_base); \
	           __a64_sp = (__s64)(__a64_write_value - __a64_write_base); \
	       } \
	     } else if (__a64_l_reg < KPROG_ARM64_GPR_COUNT && KPROG_ARM64_REG_WRITABLE(__a64_l_reg)) { \
	       __a64_cells[KPROG_ARM64_GPR_CELL(__a64_l_reg)]->ptr = __a64_l_next_ptr; \
	       *__a64_tag_cells[KPROG_ARM64_GPR_CELL(__a64_l_reg)] = __a64_l_next_tag; \
	     } \
	if ((REG)==ARM64_SP) ARM64_SIM_L_STACK_RELEASE(__a64_write_old_sp); \
	} while (0)

#undef ARM64_SIM_A64_LINK
#define ARM64_SIM_A64_LINK(RETURN_ADDR) \
 do { __a64_lr = (RETURN_ADDR); \
      KPROG_ARM64_ORIGINAL_LINK_WRITE((ARM64_X30), (void *)(long)(__a64_lr), ARM64_SIM_TAG_CODE); \
 } while (0)
