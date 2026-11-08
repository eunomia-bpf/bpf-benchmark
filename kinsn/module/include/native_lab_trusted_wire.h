/* SPDX-License-Identifier: GPL-2.0 */
#ifndef NATIVE_LAB_TRUSTED_WIRE_H
#define NATIVE_LAB_TRUSTED_WIRE_H
#include <linux/types.h>
#include <linux/ioctl.h>

#define NATIVE_LAB_TRUSTED_VERSION 1U

/* SUBMIT accepts native ELF, an entry symbol (without a terminating NUL),
 * and specialization metadata. B is generated through the service.
 * All three spans are copied into kernel-owned storage before submission
 * returns. request_id is kernel-issued. A supplied source_prog_id pins its
 * program/context; zero selects the load_context in copied P metadata.
 * Resource map descriptors are retained by SUBMIT_RESOURCES in either form.
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

/* Native-referenced map capabilities accompany the immutable P snapshot.
 * Each signed32 descriptor is resolved in the submitting task and retained
 * by the capsule with the same map-reference lifetime as an ordinary program.
 * The service obtains actual identities/shapes through TRUSTED_MAP. The
 * descriptor array is copied during SUBMIT_RESOURCES; reserved stays zero.
 * The existing request and NEXT layouts keep their original ABI.
 */
struct native_lab_trusted_submission {
	struct native_lab_trusted_request request;
	__u32 map_count;
	__u32 reserved;
	__u64 map_fds_user;
};

/* Only the registered service file description can activate a worker.
 * A child receiving that capability FD may ACTIVATE before the trusted
 * loader uploads its freshly generated proof. An application submit FD
 * never grants proof upload authority. One request/worker is active at once.
 */
struct native_lab_trusted_activate {
	__u64 request_id;
};

/* The service returns an already kernel-verified program ID,
 * or a negative errno with prog_id zero. WAIT is available only on the
 * submitting file and retains the result program until that file closes.
 * status is zero only after verifier acceptance and JIT emission.
 */
struct native_lab_trusted_result {
	__u64 request_id;
	__s32 status;
	__u32 prog_id;
	__u64 reserved;
};

/* Kernel facts for a pinned source and resource maps. Raw native requests
 * carry their program load_context in the kernel-copied P metadata.
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
	__u32 depth; /* 0=pinned source/native map, 1=actual inner template, ... */
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
#define NATIVE_LAB_TRUSTED_SUBMIT_RESOURCES _IOWR('N', 0x77, struct native_lab_trusted_submission)
/* Service-created immutable linked chunk. Counts describe copied spans.
 * chunk_id is allocated by the kernel and names that allocation for its life.
 */
struct native_lab_trusted_chunk {
    __u64 request_id;
    __u64 native_user;
    __u64 relocs_user;
    __u64 proof_user;
    __u32 native_size;
    __u32 reloc_count;
    __u32 proof_insns;
    __u32 chunk_id;
};
#define NATIVE_LAB_TRUSTED_CHUNK _IOWR('N', 0x78, struct native_lab_trusted_chunk)
#endif
