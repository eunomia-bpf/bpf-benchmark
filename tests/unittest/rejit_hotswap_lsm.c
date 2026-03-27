// SPDX-License-Identifier: GPL-2.0
#define _GNU_SOURCE

#include <errno.h>
#include <fcntl.h>
#include <linux/bpf.h>
#include <linux/unistd.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>

#include <bpf/bpf.h>
#include <bpf/libbpf.h>

#include "rejit_hotswap_common.h"

#define HOTSWAP_ROUNDS 10
#define SAMPLE_INTERVAL_US 50000
#define ROUND_DWELL_US 500000
#define RATIO_TIMEOUT_MS 2500
#define MIN_WINDOW_EVENTS 16
#define LSM_TRIGGER_BATCH 32

static const char *g_progs_dir = "tests/unittest/build/progs";
static int g_pass;
static int g_fail;
static int g_skip;

struct hotswap_stats {
	__u64 total;
	__u64 events;
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
	printf("  SKIP  %s: %s\n", name, reason); \
	g_skip++; \
} while (0)

static int read_stats(int map_fd, struct hotswap_stats *stats)
{
	__u32 key = 0;

	return bpf_map_lookup_elem(map_fd, &key, stats);
}

static bool lsm_list_has_name(const char *lsm_list, const char *name)
{
	size_t name_len = strlen(name);
	const char *cur = lsm_list;

	while (*cur) {
		const char *end = strchr(cur, ',');
		size_t token_len;

		if (!end)
			end = cur + strlen(cur);

		token_len = end - cur;
		if (token_len == name_len && !strncmp(cur, name, name_len))
			return true;

		if (!*end)
			break;
		cur = end + 1;
	}

	return false;
}

static bool bpf_lsm_is_active(char *reason, size_t reason_sz)
{
	char lsm_list[256];
	FILE *fp;
	size_t len;

	fp = fopen("/sys/kernel/security/lsm", "re");
	if (!fp) {
		snprintf(reason, reason_sz,
			 "cannot inspect /sys/kernel/security/lsm: %s",
			 strerror(errno));
		return false;
	}

	if (!fgets(lsm_list, sizeof(lsm_list), fp)) {
		snprintf(reason, reason_sz,
			 "failed to read /sys/kernel/security/lsm: %s",
			 ferror(fp) ? strerror(errno) : "empty file");
		fclose(fp);
		return false;
	}
	fclose(fp);

	len = strlen(lsm_list);
	if (len && lsm_list[len - 1] == '\n')
		lsm_list[len - 1] = '\0';

	if (lsm_list_has_name(lsm_list, "bpf"))
		return true;

	snprintf(reason, reason_sz,
		 "BPF LSM not active (/sys/kernel/security/lsm=%s)", lsm_list);
	return false;
}

static bool ratio_matches(__u64 total_delta, __u64 event_delta, __u64 expected)
{
	__u64 target;
	__u64 diff;
	__u64 tolerance;

	if (!event_delta)
		return false;

	target = event_delta * expected;
	diff = total_delta > target ? total_delta - target : target - total_delta;
	tolerance = event_delta / 20 + 2;
	return diff <= tolerance;
}

static int wait_for_expected_delta(int map_fd, const char *path,
				   __u64 expected, char *reason,
				   size_t reason_sz)
{
	struct hotswap_stats prev;
	struct hotswap_stats cur;
	__u64 total_delta = 0;
	__u64 event_delta = 0;
	int elapsed_ms = 0;

	if (read_stats(map_fd, &prev) < 0) {
		snprintf(reason, reason_sz, "initial map lookup failed: %s",
			 strerror(errno));
		return -1;
	}

	while (elapsed_ms < RATIO_TIMEOUT_MS) {
		int i;

		for (i = 0; i < LSM_TRIGGER_BATCH; i++) {
			int fd = open(path, O_RDONLY | O_CLOEXEC);

			if (fd < 0) {
				snprintf(reason, reason_sz,
					 "open trigger failed: %s",
					 strerror(errno));
				return -1;
			}

			close(fd);
		}

		usleep(SAMPLE_INTERVAL_US);

		if (read_stats(map_fd, &cur) < 0) {
			snprintf(reason, reason_sz, "map lookup failed: %s",
				 strerror(errno));
			return -1;
		}

		total_delta = cur.total - prev.total;
		event_delta = cur.events - prev.events;
		if (event_delta >= MIN_WINDOW_EVENTS) {
			if (ratio_matches(total_delta, event_delta, expected))
				return 0;
			prev = cur;
		}

		elapsed_ms += SAMPLE_INTERVAL_US / 1000;
	}

	snprintf(reason, reason_sz,
		 "timed out waiting for delta=%llu (total_delta=%llu event_delta=%llu)",
		 (unsigned long long)expected,
		 (unsigned long long)total_delta,
		 (unsigned long long)event_delta);
	errno = ETIMEDOUT;
	return -1;
}

static int test_rejit_hotswap_lsm(void)
{
	const char *name = "rejit_hotswap_lsm";
	char obj_path[512];
	char tmp_path[256];
	char log_buf[65536];
	char reason[256];
	struct bpf_object *obj = NULL;
	struct bpf_program *prog;
	struct bpf_map *map;
	struct bpf_link *link = NULL;
	struct bpf_insn *orig_insns = NULL;
	struct bpf_insn *patched_insns = NULL;
	int map_fd;
	int prog_fd;
	int orig_cnt;
	int fd = -1;
	int i;
	int ret = 1;

	snprintf(obj_path, sizeof(obj_path), "%s/test_hotswap_lsm.bpf.o",
		 g_progs_dir);
	snprintf(tmp_path, sizeof(tmp_path), "/tmp/test_lsm_rejit_%d", getpid());

	fd = open(tmp_path, O_CREAT | O_RDWR | O_TRUNC | O_CLOEXEC, 0600);
	if (fd < 0) {
		TEST_FAIL(name, "failed to create test file");
		return 1;
	}
	close(fd);
	fd = -1;

	if (!bpf_lsm_is_active(reason, sizeof(reason))) {
		TEST_SKIP(name, reason);
		return 0;
	}

	obj = bpf_object__open_file(obj_path, NULL);
	if (!obj || libbpf_get_error(obj)) {
		TEST_FAIL(name, "cannot open test_hotswap_lsm.bpf.o");
		obj = NULL;
		goto out;
	}

	if (bpf_object__load(obj) < 0) {
		TEST_FAIL(name, "failed to load BPF object");
		goto out;
	}

	prog = bpf_object__find_program_by_name(obj, "rejit_hotswap_lsm");
	if (!prog) {
		TEST_FAIL(name, "program rejit_hotswap_lsm not found");
		goto out;
	}

	map = bpf_object__find_map_by_name(obj, "stats_map");
	if (!map) {
		TEST_FAIL(name, "stats_map not found");
		goto out;
	}

	prog_fd = bpf_program__fd(prog);
	map_fd = bpf_map__fd(map);
	if (prog_fd < 0 || map_fd < 0) {
		TEST_FAIL(name, "invalid prog/map fd");
		goto out;
	}

	link = bpf_program__attach_lsm(prog);
	if (!link || libbpf_get_error(link)) {
		TEST_FAIL(name, "failed to attach LSM program");
		link = NULL;
		goto out;
	}

	orig_cnt = hotswap_get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		goto out;
	}

	patched_insns = calloc(orig_cnt, sizeof(*patched_insns));
	if (!patched_insns) {
		TEST_FAIL(name, "calloc patched_insns failed");
		goto out;
	}

	if (wait_for_expected_delta(map_fd, tmp_path, 1,
				    reason, sizeof(reason)) < 0) {
		TEST_FAIL(name, reason);
		goto out;
	}

	for (i = 0; i < HOTSWAP_ROUNDS; i++) {
		int expected = (i % 2 == 0) ? 2 : 1;

		memcpy(patched_insns, orig_insns, orig_cnt * sizeof(*patched_insns));
		if (hotswap_patch_atomic_add_imm(patched_insns, orig_cnt,
						 offsetof(struct hotswap_stats, total),
						 expected) < 0) {
			TEST_FAIL(name, "failed to patch total delta immediate");
			goto out;
		}

		memset(log_buf, 0, sizeof(log_buf));
		if (hotswap_rejit_prog(prog_fd, patched_insns, orig_cnt,
				       log_buf, sizeof(log_buf)) < 0) {
			fprintf(stderr, "    verifier log:\n%s\n", log_buf);
			TEST_FAIL(name, "BPF_PROG_REJIT failed");
			goto out;
		}

		if (wait_for_expected_delta(map_fd, tmp_path, expected,
					    reason, sizeof(reason)) < 0) {
			TEST_FAIL(name, reason);
			goto out;
		}

		usleep(ROUND_DWELL_US);
	}

	TEST_PASS(name);
	ret = 0;

out:
	free(patched_insns);
	free(orig_insns);
	if (link)
		bpf_link__destroy(link);
	if (obj)
		bpf_object__close(obj);
	unlink(tmp_path);
	return ret;
}

int main(int argc, char **argv)
{
	if (argc > 1)
		g_progs_dir = argv[1];

	if (test_rejit_hotswap_lsm())
		return 1;

	printf("\nSummary: pass=%d fail=%d skip=%d\n", g_pass, g_fail, g_skip);
	return g_fail ? 1 : 0;
}
