// SPDX-License-Identifier: GPL-2.0
#define _GNU_SOURCE

#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <bpf/bpf.h>
#include <bpf/libbpf.h>

#include "rejit_hotswap_common.h"

#define HOTSWAP_ROUNDS 10
#define EXT_RETVAL_A 1111
#define EXT_RETVAL_B 2222
#define RETVAL_TIMEOUT_MS 1200
#define ROUND_DWELL_US 200000

static const char *g_progs_dir = "tests/unittest/build/progs";
static int g_pass;
static int g_fail;

struct ext_instance {
	struct bpf_object *obj;
	struct bpf_link *link;
	int fd;
};

#define TEST_PASS(name) do { \
	printf("  PASS  %s\n", name); \
	g_pass++; \
} while (0)

#define TEST_FAIL(name, reason) do { \
	fprintf(stderr, "  FAIL  %s: %s\n", name, reason); \
	g_fail++; \
} while (0)

static void destroy_ext_instance(struct ext_instance *ext)
{
	if (ext->link)
		bpf_link__destroy(ext->link);
	if (ext->obj)
		bpf_object__close(ext->obj);

	ext->link = NULL;
	ext->obj = NULL;
	ext->fd = -1;
}

static int test_run_target(int target_fd, __u32 *retval)
{
	unsigned char data[256] = {};
	DECLARE_LIBBPF_OPTS(bpf_test_run_opts, opts,
		.data_in = data,
		.data_size_in = sizeof(data),
	);
	int err;

	err = bpf_prog_test_run_opts(target_fd, &opts);
	if (err < 0)
		return -1;

	*retval = opts.retval;
	return 0;
}

static int wait_for_retval(int target_fd, __u32 expected,
			   char *reason, size_t reason_sz)
{
	__u32 last_retval = 0;
	bool have_retval = false;
	int elapsed_ms = 0;

	while (elapsed_ms < RETVAL_TIMEOUT_MS) {
		if (test_run_target(target_fd, &last_retval) < 0) {
			snprintf(reason, reason_sz,
				 "BPF_PROG_TEST_RUN failed: %s", strerror(errno));
			return -1;
		}

		have_retval = true;
		if (last_retval == expected)
			return 0;

		usleep(10000);
		elapsed_ms += 10;
	}

	if (have_retval)
		snprintf(reason, reason_sz,
			 "timed out waiting for retval %u (last saw %u)",
			 expected, last_retval);
	else
		snprintf(reason, reason_sz, "timed out waiting for retval %u",
			 expected);
	errno = ETIMEDOUT;
	return -1;
}

static int load_rejit_attach_ext(const char *ext_path, int target_fd,
				 __u32 expected, struct ext_instance *ext,
				 char *reason, size_t reason_sz)
{
	char log_buf[65536] = {};
	struct bpf_program *ext_prog;
	struct bpf_insn *orig_insns = NULL;
	struct bpf_insn *patched_insns = NULL;
	int orig_cnt;
	int ret = -1;

	ext->fd = -1;
	ext->obj = bpf_object__open_file(ext_path, NULL);
	if (!ext->obj || libbpf_get_error(ext->obj)) {
		snprintf(reason, reason_sz, "cannot open test_hotswap_ext.bpf.o");
		ext->obj = NULL;
		goto out;
	}

	ext_prog = bpf_object__find_program_by_name(ext->obj, "rejit_hotswap_ext");
	if (!ext_prog) {
		snprintf(reason, reason_sz, "EXT program not found");
		goto out;
	}

	if (bpf_program__set_attach_target(ext_prog, target_fd,
					   "rejit_hotswap_ext_target_func") < 0) {
		snprintf(reason, reason_sz, "bpf_program__set_attach_target failed");
		goto out;
	}

	if (bpf_object__load(ext->obj) < 0) {
		snprintf(reason, reason_sz, "failed to load EXT object");
		goto out;
	}

	ext->fd = bpf_program__fd(ext_prog);
	if (ext->fd < 0) {
		snprintf(reason, reason_sz, "invalid EXT program fd");
		goto out;
	}

	orig_cnt = hotswap_get_original_insns(ext->fd, &orig_insns);
	if (orig_cnt < 0) {
		snprintf(reason, reason_sz, "get_original_insns failed");
		goto out;
	}

	patched_insns = calloc(orig_cnt, sizeof(*patched_insns));
	if (!patched_insns) {
		snprintf(reason, reason_sz, "calloc patched_insns failed");
		goto out;
	}

	memcpy(patched_insns, orig_insns, orig_cnt * sizeof(*patched_insns));
	if (hotswap_patch_return_imm(patched_insns, orig_cnt,
				     (__s32)expected) < 0) {
		snprintf(reason, reason_sz, "failed to patch EXT return value");
		goto out;
	}

	/*
	 * Attached EXT programs clear aux->dst_prog in tracing link setup, so
	 * REJIT them before attach while the verifier can still resolve the
	 * freplace target.
	 */
	if (hotswap_rejit_prog(ext->fd, patched_insns, orig_cnt,
			       log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "    verifier log:\n%s\n", log_buf);
		snprintf(reason, reason_sz, "BPF_PROG_REJIT failed");
		goto out;
	}

	ext->link = bpf_program__attach_trace(ext_prog);
	if (!ext->link || libbpf_get_error(ext->link)) {
		snprintf(reason, reason_sz, "attach_trace failed for EXT program");
		ext->link = NULL;
		goto out;
	}

	ret = 0;

out:
	free(patched_insns);
	free(orig_insns);
	if (ret)
		destroy_ext_instance(ext);
	return ret;
}

static int test_rejit_hotswap_ext(void)
{
	const char *name = "rejit_hotswap_ext";
	char target_path[512];
	char ext_path[512];
	char reason[256];
	struct bpf_object *target_obj = NULL;
	struct ext_instance ext = {
		.fd = -1,
	};
	struct bpf_program *target_prog;
	int target_fd;
	int i;
	int ret = 1;

	snprintf(target_path, sizeof(target_path), "%s/test_hotswap_ext_target.bpf.o",
		 g_progs_dir);
	snprintf(ext_path, sizeof(ext_path), "%s/test_hotswap_ext.bpf.o",
		 g_progs_dir);

	target_obj = bpf_object__open_file(target_path, NULL);
	if (!target_obj || libbpf_get_error(target_obj)) {
		TEST_FAIL(name, "cannot open test_hotswap_ext_target.bpf.o");
		target_obj = NULL;
		goto out;
	}

	if (bpf_object__load(target_obj) < 0) {
		TEST_FAIL(name, "failed to load EXT target object");
		goto out;
	}

	target_prog = bpf_object__find_program_by_name(target_obj,
						       "rejit_hotswap_ext_target");
	if (!target_prog) {
		TEST_FAIL(name, "target program not found");
		goto out;
	}

	target_fd = bpf_program__fd(target_prog);
	if (target_fd < 0) {
		TEST_FAIL(name, "invalid target program fd");
		goto out;
	}

	if (load_rejit_attach_ext(ext_path, target_fd, EXT_RETVAL_A, &ext,
				  reason, sizeof(reason)) < 0) {
		TEST_FAIL(name, reason);
		goto out;
	}

	if (wait_for_retval(target_fd, EXT_RETVAL_A, reason, sizeof(reason)) < 0) {
		TEST_FAIL(name, reason);
		goto out;
	}

	for (i = 0; i < HOTSWAP_ROUNDS; i++) {
		__u32 expected = (i % 2) == 0 ? EXT_RETVAL_B : EXT_RETVAL_A;

		destroy_ext_instance(&ext);
		if (load_rejit_attach_ext(ext_path, target_fd, expected, &ext,
					  reason, sizeof(reason)) < 0) {
			TEST_FAIL(name, reason);
			goto out;
		}

		if (wait_for_retval(target_fd, expected, reason, sizeof(reason)) < 0) {
			TEST_FAIL(name, reason);
			goto out;
		}

		usleep(ROUND_DWELL_US);
	}

	TEST_PASS(name);
	ret = 0;

out:
	destroy_ext_instance(&ext);
	if (target_obj)
		bpf_object__close(target_obj);
	return ret;
}

int main(int argc, char **argv)
{
	if (argc > 1)
		g_progs_dir = argv[1];

	if (test_rejit_hotswap_ext())
		return 1;

	printf("\nSummary: pass=%d fail=%d\n", g_pass, g_fail);
	return g_fail ? 1 : 0;
}
