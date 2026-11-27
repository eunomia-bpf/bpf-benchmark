/* Original captured profile and complete captured caller;LINK stays inline. */
#define ARM64_SIM_RET_CASES_11c 
#define ARM64_SIM_RET_CASES_15c 
#define ARM64_SIM_RET_CASES_254 
#define ARM64_SIM_ENABLE_STACK 1
#define ARM64_SIM_STACK_BIAS 32LL
#define ARM64_SIM_STACK_BYTES 32U
#define ARM64_SIM_STACK_PAYLOAD_WORDS 1U
#define ARM64_SIM_L_STACK_PAYLOAD_LOAD(INDEX) (__a64_stack_payload[(((__u64)(INDEX) > 0ULL))])
#define ARM64_SIM_L_STACK_PAYLOAD_STORE(INDEX, VALUE) do { __a64_stack_payload[(((__u64)(INDEX) > 0ULL))] = (VALUE); } while (0)
#define ARM64_SIM_RETURN_CASES \
	case 0x58ULL: goto arm64_l_58; \
	case 0x90ULL: goto arm64_l_90; \
	case 0xacULL: goto arm64_l_ac; \
	case 0xf8ULL: goto arm64_l_f8; \
	case 0x10cULL: goto arm64_l_10c; \
	case 0x134ULL: goto arm64_l_134; \
	case 0x14cULL: goto arm64_l_14c; \
	case 0x188ULL: goto arm64_l_188;
#include "../../arm64/arm64_sim_local_bpf.h"
#include "Arm64OriginalLinkBinding.h"
#include "Arm64CiliumCaller.c"
