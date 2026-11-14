/* Root the production nonarena width selection and typed pointer read.
 * CompCert alignment-1 copies use the external library's memcpy semantics. */
#include "../../arm64/arm64_sim_local_bpf.h"
#include "Arm64Access.h"
__u64 kprog_arm64_access_read(const void *base, __s64 offset, __u8 width)
{
	__u64 result;
	KPROG_ARM64_LOAD_BYTES_OFFSET_INTO(result, base, offset, width);
	return result;
}
void kprog_arm64_access_write(void *address, __u8 width, __u64 value)
{
	ARM64_SIM_L_STORE_ADDR(address, width, value);
}
void *kprog_arm64_access_pointer(const void *base, __s64 offset)
{
	void *result;
	ARM64_SIM_L_LOAD_PTR_AT_INTO(result, base, offset);
	return result;
}
