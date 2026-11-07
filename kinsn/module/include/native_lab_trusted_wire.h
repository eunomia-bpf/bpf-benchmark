/* SPDX-License-Identifier: GPL-2.0 */
#ifndef NATIVE_LAB_TRUSTED_WIRE_H
#define NATIVE_LAB_TRUSTED_WIRE_H
#include <linux/types.h>
#include <linux/ioctl.h>

#define NATIVE_LAB_TRUSTED_VERSION 1U

/* SUBMIT accepts native ELF, an entry symbol (without a terminating NUL),
 * and typed specialization metadata. There is no proof input or path field.
 * All three spans are copied into kernel-owned storage before submission
 * returns. request_id is kernel-issued, source_prog_id pins the original
 * kernel program/context. flags/reserved and input request_id must be zero.
 * NEXT uses the sizes as user buffer capacities and returns exact sizes;
 * -EMSGSIZE leaves the request queued and reports required capacities.
 * Pointer fields are user addresses, not data to be retained by the kernel.
 */
struct native_lab_trusted_request {
	__u32 version;
	__u32 arch;
	__u32 source_prog_id;
	__u32 flags;
	__u64 request_id;
	__u32 native_size;
	__u32 entry_size;
	__u32 metadata_size;
	__u32 reserved;
	__u64 native_user;
	__u64 entry_user;
	__u64 metadata_user;
};

/* Only the registered service file description can activate a worker.
 * A child receiving that capability FD may ACTIVATE before the trusted
 * loader uploads its freshly generated proof. An application submit FD
 * never grants proof upload authority. One request/worker is active at once.
 */
struct native_lab_trusted_activate {
	__u64 request_id;
};

/* The service returns an already kernel-verified, request-bound program ID,
 * or a negative errno with prog_id zero. WAIT is available only on the
 * submitting file and retains the result program until that file closes.
 * status is zero only after proof verification and native binding succeed.
 */
struct native_lab_trusted_result {
	__u64 request_id;
	__s32 status;
	__u32 prog_id;
	__u64 reserved;
};

/* Kernel facts for the pinned source, not assertions copied from the app.
 * These queries require the registered service capability and active request.
 */
struct native_lab_trusted_context {
	__u64 request_id;
	__u32 prog_type;
	__u32 expected_attach_type;
	__u32 prog_flags;
	__u32 prog_ifindex;
	__u32 attach_btf_id;
	__u32 attach_btf_obj_id;
	__u32 attach_prog_id;
	__u32 gpl_compatible;
	__u32 source_btf_id;
	__u32 token_present;
};
struct native_lab_trusted_map {
	__u64 request_id;
	__u32 map_id;
	__u32 depth; /* 0=used source map, 1=its actual inner template, ... */
	__u32 map_type;
	__u32 key_size;
	__u32 value_size;
	__u32 max_entries;
	__u32 map_flags;
	__u32 btf_id;
	__u32 btf_key_type_id;
	__u32 btf_value_type_id;
	__u32 has_inner;
	__u32 reserved;
};

#define NATIVE_LAB_TRUSTED_SUBMIT _IOWR('N', 0x70, struct native_lab_trusted_request)
#define NATIVE_LAB_TRUSTED_NEXT _IOWR('N', 0x71, struct native_lab_trusted_request)
#define NATIVE_LAB_TRUSTED_ACTIVATE _IOW('N', 0x72, struct native_lab_trusted_activate)
#define NATIVE_LAB_TRUSTED_COMPLETE _IOW('N', 0x73, struct native_lab_trusted_result)
#define NATIVE_LAB_TRUSTED_WAIT _IOR('N', 0x74, struct native_lab_trusted_result)
#define NATIVE_LAB_TRUSTED_CONTEXT _IOWR('N', 0x75, struct native_lab_trusted_context)
#define NATIVE_LAB_TRUSTED_MAP _IOWR('N', 0x76, struct native_lab_trusted_map)
#endif
