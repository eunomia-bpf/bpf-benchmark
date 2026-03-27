// SPDX-License-Identifier: GPL-2.0
#define _GNU_SOURCE

#include <errno.h>
#include <linux/bpf.h>
#ifndef __bitwise
#define __bitwise
#endif
#ifndef __force
#define __force
#endif
#include <linux/perf_event.h>
#include <linux/unistd.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <time.h>
#include <unistd.h>

#include <bpf/bpf.h>
#include <bpf/libbpf.h>

#include "rejit_hotswap_common.h"

#define HOTSWAP_ROUNDS 10
#define SAMPLE_INTERVAL_US 50000
#define ROUND_DWELL_US 500000
#define RATIO_TIMEOUT_MS 2500
#define MIN_WINDOW_EVENTS 8

static const char *g_progs_dir = "tests/unittest/build/progs";
static int g_pass;
static int g_fail;

struct hotswap_stats {
	__u64 total;
	__u64 events;
};

enum perf_workload_mode {
	PERF_WORKLOAD_BUSY_LOOP,
	PERF_WORKLOAD_PAGE_FAULTS,
};

struct perf_event_candidate {
	__u64 config;
	__u64 sample_period;
	enum perf_workload_mode workload_mode;
	const char *name;
};

#define TEST_PASS(name) do { \
	printf("  PASS  %s\n", name); \
	g_pass++; \
} while (0)

#define TEST_FAIL(name, reason) do { \
	fprintf(stderr, "  FAIL  %s: %s\n", name, reason); \
	g_fail++; \
} while (0)

static int sys_perf_event_open(const struct perf_event_attr *attr, pid_t pid,
			       int cpu, int group_fd, unsigned long flags)
{
	return syscall(__NR_perf_event_open, attr, pid, cpu, group_fd, flags);
}

static int read_stats(int map_fd, struct hotswap_stats *stats)
{
	__u32 key = 0;

	return bpf_map_lookup_elem(map_fd, &key, stats);
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

static int induce_page_fault_batch(char *reason, size_t reason_sz)
{
	enum { PAGE_FAULT_BATCH_PAGES = 32 };
	static long page_sz;
	char *buf;
	int i;

	if (!page_sz) {
		page_sz = sysconf(_SC_PAGESIZE);
		if (page_sz <= 0) {
			snprintf(reason, reason_sz,
				 "sysconf(_SC_PAGESIZE) failed: %s",
				 strerror(errno));
			return -1;
		}
	}

	buf = mmap(NULL, page_sz * PAGE_FAULT_BATCH_PAGES,
		   PROT_READ | PROT_WRITE,
		   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (buf == MAP_FAILED) {
		snprintf(reason, reason_sz, "mmap failed: %s", strerror(errno));
		return -1;
	}

	for (i = 0; i < PAGE_FAULT_BATCH_PAGES; i++)
		buf[i * page_sz] = (char)i;

	if (munmap(buf, page_sz * PAGE_FAULT_BATCH_PAGES) < 0) {
		snprintf(reason, reason_sz, "munmap failed: %s",
			 strerror(errno));
		return -1;
	}

	return 0;
}

static int drive_perf_event_window(enum perf_workload_mode workload_mode,
				   char *reason, size_t reason_sz)
{
	struct timespec start;
	volatile __u64 sink = 0;

	if (clock_gettime(CLOCK_MONOTONIC, &start) < 0) {
		snprintf(reason, reason_sz, "clock_gettime failed: %s",
			 strerror(errno));
		return -1;
	}

	do {
		struct timespec now;
		long long sec_diff;
		long long nsec_diff;
		__u64 elapsed_ns;

		if (workload_mode == PERF_WORKLOAD_PAGE_FAULTS) {
			if (induce_page_fault_batch(reason, reason_sz) < 0)
				return -1;
		} else {
			int i;

			for (i = 0; i < 10000; i++)
				sink += i;
		}

		if (clock_gettime(CLOCK_MONOTONIC, &now) < 0) {
			snprintf(reason, reason_sz,
				 "clock_gettime failed: %s",
				 strerror(errno));
			return -1;
		}

		sec_diff = now.tv_sec - start.tv_sec;
		nsec_diff = now.tv_nsec - start.tv_nsec;
		if (nsec_diff < 0) {
			sec_diff--;
			nsec_diff += 1000000000LL;
		}

		elapsed_ns = (__u64)sec_diff * 1000000000ULL;
		elapsed_ns += (__u64)nsec_diff;
		if (elapsed_ns >= (__u64)SAMPLE_INTERVAL_US * 1000)
			break;
	} while (1);

	(void)sink;
	return 0;
}

static int wait_for_expected_delta(int map_fd,
				   const struct perf_event_candidate *candidate,
				   __u64 expected,
				   char *reason, size_t reason_sz)
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
		if (drive_perf_event_window(candidate->workload_mode,
					    reason, reason_sz) < 0)
			return -1;

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

static int open_software_event(const struct perf_event_candidate *candidate)
{
	struct perf_event_attr attr = {};

	attr.type = PERF_TYPE_SOFTWARE;
	attr.config = candidate->config;
	attr.size = sizeof(attr);
	attr.sample_period = candidate->sample_period;
	attr.wakeup_events = 1;
	return sys_perf_event_open(&attr, 0, -1, -1, PERF_FLAG_FD_CLOEXEC);
}

static int open_software_perf_event(struct perf_event_candidate *selected,
				    char *reason, size_t reason_sz)
{
	static const struct perf_event_candidate candidates[] = {
		{
			.config = PERF_COUNT_SW_PAGE_FAULTS,
			.sample_period = 1,
			.workload_mode = PERF_WORKLOAD_PAGE_FAULTS,
			.name = "PERF_COUNT_SW_PAGE_FAULTS",
		},
		{
			.config = PERF_COUNT_SW_TASK_CLOCK,
			.sample_period = 100000,
			.workload_mode = PERF_WORKLOAD_BUSY_LOOP,
			.name = "PERF_COUNT_SW_TASK_CLOCK",
		},
		{
			.config = PERF_COUNT_SW_CPU_CLOCK,
			.sample_period = 100000,
			.workload_mode = PERF_WORKLOAD_BUSY_LOOP,
			.name = "PERF_COUNT_SW_CPU_CLOCK",
		},
	};
	const char *last_name = NULL;
	int last_errno = ENODEV;
	int i;

	for (i = 0; i < ARRAY_SIZE(candidates); i++) {
		int fd = open_software_event(&candidates[i]);

		if (fd >= 0) {
			*selected = candidates[i];
			return fd;
		}

		last_name = candidates[i].name;
		last_errno = errno;
	}

	snprintf(reason, reason_sz,
		 "perf_event_open failed for all software events (last %s errno=%d: %s)",
		 last_name ? last_name : "unknown", last_errno,
		 strerror(last_errno));
	errno = last_errno;
	return -1;
}

static int test_rejit_hotswap_perf_event(void)
{
	const char *name = "rejit_hotswap_perf_event";
	char obj_path[512];
	char log_buf[65536];
	char reason[256];
	struct perf_event_candidate perf_event = {};
	struct bpf_object *obj = NULL;
	struct bpf_program *prog;
	struct bpf_map *map;
	struct bpf_link *link = NULL;
	struct bpf_insn *orig_insns = NULL;
	struct bpf_insn *patched_insns = NULL;
	int map_fd;
	int perf_fd = -1;
	int prog_fd;
	int orig_cnt;
	int i;
	int ret = 1;

	snprintf(obj_path, sizeof(obj_path), "%s/test_hotswap_perf_event.bpf.o",
		 g_progs_dir);
	obj = bpf_object__open_file(obj_path, NULL);
	if (!obj || libbpf_get_error(obj)) {
		TEST_FAIL(name, "cannot open test_hotswap_perf_event.bpf.o");
		obj = NULL;
		goto out;
	}

	if (bpf_object__load(obj) < 0) {
		TEST_FAIL(name, "failed to load BPF object");
		goto out;
	}

	prog = bpf_object__find_program_by_name(obj, "rejit_hotswap_perf_event");
	if (!prog) {
		TEST_FAIL(name, "program rejit_hotswap_perf_event not found");
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

	perf_fd = open_software_perf_event(&perf_event, reason, sizeof(reason));
	if (perf_fd < 0) {
		TEST_FAIL(name, reason);
		goto out;
	}

	link = bpf_program__attach_perf_event(prog, perf_fd);
	if (!link || libbpf_get_error(link)) {
		TEST_FAIL(name, "failed to attach perf_event program");
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

	if (wait_for_expected_delta(map_fd, &perf_event, 1,
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

		if (wait_for_expected_delta(map_fd, &perf_event, expected,
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
	if (perf_fd >= 0)
		close(perf_fd);
	if (obj)
		bpf_object__close(obj);
	return ret;
}

int main(int argc, char **argv)
{
	if (argc > 1)
		g_progs_dir = argv[1];

	if (test_rejit_hotswap_perf_event())
		return 1;

	printf("\nSummary: pass=%d fail=%d\n", g_pass, g_fail);
	return g_fail ? 1 : 0;
}
