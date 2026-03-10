/* SPDX-License-Identifier: MIT */
/*
 * bpf_jit_scanner/policy.h — build a v4 JIT policy blob from scan results
 *
 * The policy blob is passed to the kernel via BPF_PROG_JIT_RECOMPILE.
 * Its format is documented in types.h.  This module only builds the blob;
 * issuing the syscall is the caller's responsibility.
 *
 * Pair this C API with the C++ PolicyEngine in engine.hpp when you want a
 * registry-driven scan/decode/apply flow instead of manual rule assembly.
 */

#ifndef BPF_JIT_SCANNER_POLICY_H
#define BPF_JIT_SCANNER_POLICY_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * bpf_jit_build_policy_blob() - serialize scan rules into a kernel policy blob
 * @rules:        array of scan rules from bpf_jit_scan_*()
 * @rule_cnt:     number of entries in @rules
 * @insn_cnt:     number of xlated BPF instructions (xlated_prog_len / 8)
 * @prog_tag:     8-byte program tag from bpf_prog_info.tag
 * @out_blob:     on success, set to a malloc()ed buffer containing the blob
 * @out_blob_len: on success, set to the number of bytes in *out_blob
 *
 * Allocates memory for the policy blob via malloc().  The caller must free
 * it with bpf_jit_free_policy_blob() when done.
 *
 * Returns 0 on success, or negative errno on failure:
 *   -EINVAL  rule_cnt is non-zero but rules is NULL, or out_blob/out_blob_len
 *            is NULL
 *   -ENOMEM  memory allocation failed
 */
int bpf_jit_build_policy_blob(const struct bpf_jit_scan_rule *rules,
                              uint32_t rule_cnt,
                              uint32_t insn_cnt,
                              const uint8_t prog_tag[8],
                              uint8_t **out_blob,
                              uint32_t *out_blob_len);

/**
 * bpf_jit_free_policy_blob() - free a blob allocated by bpf_jit_build_policy_blob()
 * @blob: pointer returned in *out_blob by bpf_jit_build_policy_blob()
 *        (may be NULL, in which case this is a no-op)
 */
void bpf_jit_free_policy_blob(uint8_t *blob);

/**
 * bpf_jit_patch_policy_blob() - update tag and insn_cnt in an existing blob
 * @blob:     policy blob to update in-place (must be at least 32 bytes)
 * @blob_len: length of @blob
 * @insn_cnt: new xlated instruction count
 * @prog_tag: new 8-byte program tag
 *
 * Useful when re-applying a pre-built blob to a freshly loaded program whose
 * prog_tag differs from what was recorded at build time.
 *
 * Returns 0 on success, -EINVAL if blob is too short.
 */
int bpf_jit_patch_policy_blob(uint8_t *blob, uint32_t blob_len,
                              uint32_t insn_cnt,
                              const uint8_t prog_tag[8]);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* BPF_JIT_SCANNER_POLICY_H */
