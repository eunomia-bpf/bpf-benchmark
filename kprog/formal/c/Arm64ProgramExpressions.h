/* Include after defining KPROG_ARM64_PROGRAM_STATE as a live entry pointer.
 * Reads stay at their original expression sites; these calls reuse C bodies.
 */
#undef ARM64_SIM_L_READ_REG_RAW
#define ARM64_SIM_L_READ_REG_RAW(REG) kprog_arm64_program_raw(KPROG_ARM64_PROGRAM_STATE, (REG))
#undef ARM64_SIM_L_READ_REG_PTR
#define ARM64_SIM_L_READ_REG_PTR(REG) kprog_arm64_program_pointer(KPROG_ARM64_PROGRAM_STATE, (REG))
#undef ARM64_SIM_L_REG_TAG
#define ARM64_SIM_L_REG_TAG(REG) kprog_arm64_program_tag(KPROG_ARM64_PROGRAM_STATE, (REG))
#undef ARM64_SIM_L_READ_REG
#define ARM64_SIM_L_READ_REG(REG) kprog_arm64_program_read(KPROG_ARM64_PROGRAM_STATE, (REG))
#undef ARM64_SIM_L_WRITE_REG_WIDTH
#define ARM64_SIM_L_WRITE_REG_WIDTH(REG, VALUE, WIDTH) kprog_arm64_program_write(KPROG_ARM64_PROGRAM_STATE, (REG), (VALUE), (WIDTH))
#undef ARM64_SIM_L_WRITE_REG_PTR_TAG
#define ARM64_SIM_L_WRITE_REG_PTR_TAG(REG, VALUE, TAG) kprog_arm64_program_write_pointer(KPROG_ARM64_PROGRAM_STATE, (REG), (VALUE), (TAG))
#undef ARM64_SIM_L_MOD_VALUE
#define ARM64_SIM_L_MOD_VALUE(REG, MOD, SHIFT, WIDTH) kprog_arm64_program_modified(KPROG_ARM64_PROGRAM_STATE, (REG), (MOD), (SHIFT), (WIDTH))
#undef ARM64_SIM_L_MEM_READ
#define ARM64_SIM_L_MEM_READ(BASE, INDEX, AUX, IMM, EXTRA, WIDTH) kprog_arm64_program_memory_read(KPROG_ARM64_PROGRAM_STATE, (BASE), (INDEX), (AUX), (IMM), (EXTRA), (WIDTH))
#undef ARM64_SIM_L_HELPER_ARG_PTR
#define ARM64_SIM_L_HELPER_ARG_PTR(REG) kprog_arm64_program_argument(KPROG_ARM64_PROGRAM_STATE, (REG))
#undef ARM64_SIM_L_HELPER_CTX_PTR
#define ARM64_SIM_L_HELPER_CTX_PTR(REG) kprog_arm64_program_context(KPROG_ARM64_PROGRAM_STATE, (REG))
#undef ARM64_SIM_L_HELPER_CLOBBERS
#define ARM64_SIM_L_HELPER_CLOBBERS() kprog_arm64_program_clobbers(KPROG_ARM64_PROGRAM_STATE)
#undef ARM64_SIM_L_MOV_PTR_TAG_PATH
#define ARM64_SIM_L_MOV_PTR_TAG_PATH(OP, WIDTH) kprog_arm64_mov_path((OP), (WIDTH))
#undef ARM64_SIM_L_SHIFT_VALUE
#define ARM64_SIM_L_SHIFT_VALUE(KIND, VALUE, AMOUNT, WIDTH) kprog_arm64_shift((KIND), (VALUE), (AMOUNT), (WIDTH))
#undef KPROG_ARM64_IMM_RHS
#define KPROG_ARM64_IMM_RHS(OP, IMM, REG) kprog_arm64_imm_operand((OP), (IMM), (REG))
#undef KPROG_ARM64_CSEL_PTR_TAG_PATH
#define KPROG_ARM64_CSEL_PTR_TAG_PATH(OP, WIDTH, UNSUPPORTED) kprog_arm64_csel_path((OP), (WIDTH))
#undef KPROG_ARM64_ALU_OPERAND_SELECT
#define KPROG_ARM64_ALU_OPERAND_SELECT(OP) kprog_arm64_alu_source(OP)
#undef KPROG_ARM64_EVAL_COND
#define KPROG_ARM64_EVAL_COND(COND, N, Z, C, V, UNSUPPORTED) kprog_arm64_program_condition((COND), &(N), &(Z), &(C), &(V))
#undef KPROG_ALU64_RESULT
#define KPROG_ALU64_RESULT(OP, LHS, RHS, UNSUPPORTED) kprog_arm64_alu_result((OP), (LHS), (RHS))
#undef ARM64_SIM_L_REDUCTION_VALUE
#define ARM64_SIM_L_REDUCTION_VALUE(OP, VALUE) kprog_arm64_reduction((OP), (VALUE))
#undef KPROG_ARM64_FMOV_DEST_VECTOR
#define KPROG_ARM64_FMOV_DEST_VECTOR(DIR, UNSUPPORTED) kprog_arm64_fmov_dest(DIR)
#undef KPROG_ARM64_FLAG_RHS
#define KPROG_ARM64_FLAG_RHS(OP, IMM, REG) kprog_arm64_flag_rhs((OP), (IMM), (REG))
#undef KPROG_ARM64_BRANCH_TEST
#define KPROG_ARM64_BRANCH_TEST(KIND, VALUE, BIT) kprog_arm64_branch_test((KIND), (VALUE), (BIT))
