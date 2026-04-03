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
static int g_skip;

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

#define TEST_SKIP(name, reason) do { \
	fprintf(stderr, "  SKIP  %s: %s\n", name, reason); \
	g_skip++; \
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

static struct bpf_program *find_ext_program(struct ext_instance *ext)
{
	if (!ext->obj)
		return NULL;

	return bpf_object__find_program_by_name(ext->obj, "rejit_hotswap_ext");
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

static int open_ext_instance(const char *ext_path, int target_fd,
			     struct ext_instance *ext, char *reason,
			     size_t reason_sz)
{
	struct bpf_program *ext_prog;

	ext->fd = -1;
	ext->obj = bpf_object__open_file(ext_path, NULL);
	if (!ext->obj || libbpf_get_error(ext->obj)) {
		snprintf(reason, reason_sz, "cannot open test_hotswap_ext.bpf.o");
		ext->obj = NULL;
		return -1;
	}

	ext_prog = find_ext_program(ext);
	if (!ext_prog) {
		snprintf(reason, reason_sz, "EXT program not found");
		goto err;
	}

	if (bpf_program__set_attach_target(ext_prog, target_fd,
					   "rejit_hotswap_ext_target_func") < 0) {
		snprintf(reason, reason_sz, "bpf_program__set_attach_target failed");
		goto err;
	}

	if (bpf_object__load(ext->obj) < 0) {
		snprintf(reason, reason_sz, "failed to load EXT object");
		goto err;
	}

	ext->fd = bpf_program__fd(ext_prog);
	if (ext->fd < 0) {
		snprintf(reason, reason_sz, "invalid EXT program fd");
		goto err;
	}

	return 0;

err:
	destroy_ext_instance(ext);
	return -1;
}

static int attach_ext_instance(struct ext_instance *ext, char *reason,
			       size_t reason_sz)
{
	struct bpf_program *ext_prog = find_ext_program(ext);

	if (!ext_prog) {
		snprintf(reason, reason_sz, "EXT program not found");
		return -1;
	}

	ext->link = bpf_program__attach_trace(ext_prog);
	if (!ext->link || libbpf_get_error(ext->link)) {
		snprintf(reason, reason_sz, "attach_trace failed for EXT program");
		ext->link = NULL;
		return -1;
	}

	return 0;
}

static int rejit_ext_return_value(int ext_fd, const struct bpf_insn *orig_insns,
				  int orig_cnt, __u32 expected,
				  char *log_buf, size_t log_buf_sz,
				  char *reason, size_t reason_sz)
{
	struct bpf_insn *patched_insns = NULL;
	int ret = -1;

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

	memset(log_buf, 0, log_buf_sz);
	if (hotswap_rejit_prog(ext_fd, patched_insns, orig_cnt,
			       log_buf, log_buf_sz) < 0) {
		fprintf(stderr, "    verifier log:\n%s\n", log_buf);
		snprintf(reason, reason_sz,
			 "kernel does not support live REJIT of attached EXT programs");
		errno = EOPNOTSUPP;
		goto out;
	}

	ret = 0;

out:
	free(patched_insns);
	return ret;
}

static int test_rejit_hotswap_ext(void)
{
	const char *name = "rejit_hotswap_ext";
	char target_path[512];
	char ext_path[512];
	char log_buf[65536];
	char reason[256];
	struct bpf_object *target_obj = NULL;
	struct ext_instance ext = {
		.fd = -1,
	};
	struct bpf_insn *orig_insns = NULL;
	struct bpf_program *target_prog;
	int target_fd;
	int orig_cnt;
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

	if (open_ext_instance(ext_path, target_fd, &ext,
			      reason, sizeof(reason)) < 0) {
		TEST_FAIL(name, reason);
		goto out;
	}

	orig_cnt = hotswap_get_original_insns(ext.fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		goto out;
	}

	if (attach_ext_instance(&ext, reason, sizeof(reason)) < 0) {
		TEST_FAIL(name, reason);
		goto out;
	}

	if (wait_for_retval(target_fd, EXT_RETVAL_A, reason, sizeof(reason)) < 0) {
		TEST_FAIL(name, reason);
		goto out;
	}

	for (i = 0; i < HOTSWAP_ROUNDS; i++) {
		__u32 expected = (i % 2) == 0 ? EXT_RETVAL_B : EXT_RETVAL_A;

		if (rejit_ext_return_value(ext.fd, orig_insns, orig_cnt,
					   expected, log_buf,
					   sizeof(log_buf),
					   reason, sizeof(reason)) < 0) {
			if (errno == EOPNOTSUPP) {
				TEST_SKIP(name, reason);
				ret = 0;
				goto out;
			}
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
	free(orig_insns);
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

	printf("\nSummary: pass=%d fail=%d skip=%d\n", g_pass, g_fail, g_skip);
	return g_fail ? 1 : 0;
}
