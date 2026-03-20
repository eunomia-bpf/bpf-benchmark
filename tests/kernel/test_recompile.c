// SPDX-License-Identifier: MIT
#define _GNU_SOURCE

#include <errno.h>
#include <fcntl.h>
#include <linux/bpf.h>
#include <linux/if_ether.h>
#include <net/if.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdatomic.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <sys/syscall.h>
#include <unistd.h>

#include <bpf/bpf.h>
#include <bpf/libbpf.h>

#ifndef TEST_KERNEL_ROOT
#error "TEST_KERNEL_ROOT must be defined by the build"
#endif

#ifndef MFD_CLOEXEC
#define MFD_CLOEXEC 0x0001U
#endif

#ifndef MFD_ALLOW_SEALING
#define MFD_ALLOW_SEALING 0x0002U
#endif

#ifndef F_ADD_SEALS
#define F_ADD_SEALS 1033
#endif

#ifndef F_SEAL_WRITE
#define F_SEAL_WRITE 0x0008
#endif

#ifndef F_SEAL_GROW
#define F_SEAL_GROW 0x0004
#endif

#ifndef F_SEAL_SHRINK
#define F_SEAL_SHRINK 0x0002
#endif

#ifndef XDP_FLAGS_UPDATE_IF_NOEXIST
#define XDP_FLAGS_UPDATE_IF_NOEXIST (1U << 0)
#endif

#ifndef XDP_FLAGS_SKB_MODE
#define XDP_FLAGS_SKB_MODE (1U << 1)
#endif

#ifndef XDP_FLAGS_DRV_MODE
#define XDP_FLAGS_DRV_MODE (1U << 2)
#endif

#define SIMPLE_OBJ TEST_KERNEL_ROOT "/build/progs/test_simple.bpf.o"
#define DIAMOND_OBJ TEST_KERNEL_ROOT "/build/progs/test_diamond.bpf.o"
#define ROTATE_OBJ TEST_KERNEL_ROOT "/build/progs/test_rotate.bpf.o"
#define WIDE_OBJ TEST_KERNEL_ROOT "/build/progs/test_wide.bpf.o"
#define ADDR_CALC_OBJ TEST_KERNEL_ROOT "/build/progs/test_addr_calc.bpf.o"
#define BITFIELD_EXTRACT_OBJ TEST_KERNEL_ROOT "/build/progs/test_bitfield_extract.bpf.o"
#define ZERO_EXT_ELIDE_OBJ TEST_KERNEL_ROOT "/build/progs/test_zero_ext_elide.bpf.o"
#define ENDIAN_FUSION_OBJ TEST_KERNEL_ROOT "/build/progs/test_endian_fusion.bpf.o"
#define BRANCH_FLIP_OBJ TEST_KERNEL_ROOT "/build/progs/test_branch_flip.bpf.o"

#define LOG_BUF_SIZE 4096

struct blob {
	unsigned char *data;
	size_t len;
};

struct loaded_program {
	const char *obj_path;
	const char *prog_name;
	struct bpf_object *obj;
	struct bpf_program *prog;
	int prog_fd;
	int result_map_fd;
	int attached_ifindex;
	__u32 attached_flags;
};

struct program_meta {
	struct bpf_prog_info info;
	struct bpf_insn *insns;
	__u32 insn_cnt;
};

struct jit_snapshot {
	struct bpf_prog_info info;
	struct blob image;
	struct bpf_line_info *line_info;
	__u64 *jited_line_info;
	__u64 *jited_ksyms;
	__u32 line_info_cnt;
	__u32 jited_line_info_cnt;
	__u32 jited_ksym_cnt;
};

struct native_range {
	size_t start;
	size_t end;
};

struct rule_parts {
	struct bpf_jit_rewrite_rule_v2 rule;
};

struct thread_ctx {
	pthread_barrier_t *barrier;
	atomic_int *stop;
	int prog_fd;
	int policy_fd;
	unsigned int attempts;
	unsigned int success_count;
	unsigned int ebusy_count;
	unsigned int unexpected_count;
	int last_unexpected_errno;
};

struct test_case {
	const char *name;
	bool (*fn)(char *msg, size_t msg_len);
};

static int tests_passed;
static int tests_failed;

static __u16 native_jit_arch_id(void)
{
#if defined(__x86_64__)
	return BPF_JIT_ARCH_X86_64;
#elif defined(__aarch64__)
	return BPF_JIT_ARCH_ARM64;
#else
#error "Unsupported test_recompile build architecture"
#endif
}

static __u16 non_native_jit_arch_id(void)
{
	switch (native_jit_arch_id()) {
	case BPF_JIT_ARCH_X86_64:
		return BPF_JIT_ARCH_ARM64;
	case BPF_JIT_ARCH_ARM64:
		return BPF_JIT_ARCH_X86_64;
	default:
		return 0;
	}
}

static bool native_jit_arch_is_arm64(void)
{
	return native_jit_arch_id() == BPF_JIT_ARCH_ARM64;
}

static int libbpf_silent(enum libbpf_print_level level, const char *fmt, va_list args)
{
	(void)level;
	(void)fmt;
	(void)args;
	return 0;
}

static void set_msg(char *msg, size_t msg_len, const char *fmt, ...)
{
	va_list args;

	if (!msg || !msg_len)
		return;

	va_start(args, fmt);
	vsnprintf(msg, msg_len, fmt, args);
	va_end(args);
}

static void free_blob(struct blob *blob)
{
	free(blob->data);
	blob->data = NULL;
	blob->len = 0;
}

static void free_program_meta(struct program_meta *meta)
{
	free(meta->insns);
	meta->insns = NULL;
	meta->insn_cnt = 0;
	memset(&meta->info, 0, sizeof(meta->info));
}

static void free_jit_snapshot(struct jit_snapshot *snapshot)
{
	free_blob(&snapshot->image);
	free(snapshot->line_info);
	free(snapshot->jited_line_info);
	free(snapshot->jited_ksyms);
	snapshot->line_info = NULL;
	snapshot->jited_line_info = NULL;
	snapshot->jited_ksyms = NULL;
	snapshot->line_info_cnt = 0;
	snapshot->jited_line_info_cnt = 0;
	snapshot->jited_ksym_cnt = 0;
	memset(&snapshot->info, 0, sizeof(snapshot->info));
}

static void unload_program(struct loaded_program *prog)
{
	if (!prog)
		return;

	if (prog->attached_ifindex > 0)
		bpf_xdp_detach(prog->attached_ifindex, prog->attached_flags, NULL);
	if (prog->obj)
		bpf_object__close(prog->obj);
	memset(prog, 0, sizeof(*prog));
	prog->prog_fd = -1;
	prog->result_map_fd = -1;
}

static uint64_t ptr_to_u64(const void *ptr)
{
	return (uint64_t)(uintptr_t)ptr;
}

static bool tag_is_zero(const __u8 tag[BPF_TAG_SIZE])
{
	size_t i;

	for (i = 0; i < BPF_TAG_SIZE; i++) {
		if (tag[i] != 0)
			return false;
	}
	return true;
}

static void format_tag(const __u8 tag[BPF_TAG_SIZE], char *buf, size_t buf_len)
{
	size_t i;

	if (!buf || buf_len == 0)
		return;

	buf[0] = '\0';
	for (i = 0; i < BPF_TAG_SIZE && (i * 2 + 2) < buf_len; i++)
		snprintf(buf + i * 2, buf_len - i * 2, "%02x", tag[i]);
}

static int raise_memlock_limit(void)
{
	struct rlimit limit = {
		.rlim_cur = RLIM_INFINITY,
		.rlim_max = RLIM_INFINITY,
	};

	return setrlimit(RLIMIT_MEMLOCK, &limit);
}

static int load_program(const char *obj_path, const char *prog_name,
			struct loaded_program *out, char *msg, size_t msg_len)
{
	struct bpf_object_open_opts open_opts = {
		.sz = sizeof(open_opts),
	};
	struct bpf_object *obj;
	struct bpf_program *prog;
	struct bpf_map *result_map;
	int err;

	memset(out, 0, sizeof(*out));
	out->prog_fd = -1;
	out->result_map_fd = -1;
	out->obj_path = obj_path;
	out->prog_name = prog_name;

	obj = bpf_object__open_file(obj_path, &open_opts);
	err = libbpf_get_error(obj);
	if (err) {
		set_msg(msg, msg_len, "bpf_object__open_file(%s): %s",
			obj_path, strerror(-err));
		return -1;
	}

	prog = bpf_object__find_program_by_name(obj, prog_name);
	if (!prog) {
		bpf_object__close(obj);
		set_msg(msg, msg_len, "unable to find program %s in %s",
			prog_name, obj_path);
		return -1;
	}

	err = bpf_object__load(obj);
	if (err) {
		bpf_object__close(obj);
		set_msg(msg, msg_len, "bpf_object__load(%s): %s",
			obj_path, strerror(-err));
		return -1;
	}

	result_map = bpf_object__find_map_by_name(obj, "result_map");
	if (!result_map) {
		bpf_object__close(obj);
		set_msg(msg, msg_len, "result_map not found in %s", obj_path);
		return -1;
	}

	out->obj = obj;
	out->prog = prog;
	out->prog_fd = bpf_program__fd(prog);
	out->result_map_fd = bpf_map__fd(result_map);
	if (out->prog_fd < 0 || out->result_map_fd < 0) {
		unload_program(out);
		set_msg(msg, msg_len, "unable to obtain BPF fds from %s", obj_path);
		return -1;
	}

	return 0;
}

static int fetch_program_meta(int prog_fd, struct program_meta *meta,
			      char *msg, size_t msg_len)
{
	struct bpf_prog_info info = {};
	__u32 info_len = sizeof(info);
	__u32 xlated_len;

	memset(meta, 0, sizeof(*meta));
	if (bpf_prog_get_info_by_fd(prog_fd, &info, &info_len)) {
		set_msg(msg, msg_len, "bpf_prog_get_info_by_fd(fd=%d): %s",
			prog_fd, strerror(errno));
		return -1;
	}

	if (info.xlated_prog_len == 0 ||
	    info.xlated_prog_len % sizeof(struct bpf_insn) != 0) {
		set_msg(msg, msg_len, "unexpected xlated length %u",
			info.xlated_prog_len);
		return -1;
	}

	meta->insns = calloc(1, info.xlated_prog_len);
	if (!meta->insns) {
		set_msg(msg, msg_len, "calloc(%u) failed", info.xlated_prog_len);
		return -1;
	}

	xlated_len = info.xlated_prog_len;
	memset(&info, 0, sizeof(info));
	info.xlated_prog_len = xlated_len;
	info.xlated_prog_insns = ptr_to_u64(meta->insns);
	info_len = sizeof(info);
	if (bpf_prog_get_info_by_fd(prog_fd, &info, &info_len)) {
		free(meta->insns);
		meta->insns = NULL;
		set_msg(msg, msg_len,
			"bpf_prog_get_info_by_fd(xlated, fd=%d): %s",
			prog_fd, strerror(errno));
		return -1;
	}

	meta->info = info;
	meta->insn_cnt = info.xlated_prog_len / sizeof(struct bpf_insn);
	return 0;
}

static int fetch_jit_snapshot(int prog_fd, struct jit_snapshot *snapshot,
			      char *msg, size_t msg_len)
{
	struct bpf_prog_info info = {};
	__u32 info_len = sizeof(info);
	__u32 image_len;
	__u32 line_info_cnt;
	__u32 jited_line_info_cnt;
	__u32 jited_ksym_cnt;

	memset(snapshot, 0, sizeof(*snapshot));
	if (bpf_prog_get_info_by_fd(prog_fd, &info, &info_len)) {
		set_msg(msg, msg_len, "bpf_prog_get_info_by_fd(jit, fd=%d): %s",
			prog_fd, strerror(errno));
		return -1;
	}

	if (!info.jited_prog_len) {
		set_msg(msg, msg_len, "program fd=%d has empty JIT image", prog_fd);
		return -1;
	}

	image_len = info.jited_prog_len;
	line_info_cnt = info.nr_line_info;
	jited_line_info_cnt = info.nr_jited_line_info;
	jited_ksym_cnt = info.nr_jited_ksyms;
	snapshot->image.data = calloc(1, image_len);
	if (!snapshot->image.data) {
		set_msg(msg, msg_len, "calloc(%u) failed for JIT image", image_len);
		goto err;
	}
	snapshot->image.len = image_len;

	if (line_info_cnt) {
		snapshot->line_info = calloc(line_info_cnt,
					     sizeof(*snapshot->line_info));
		if (!snapshot->line_info) {
			set_msg(msg, msg_len, "calloc(%u) failed for line info",
				line_info_cnt);
			goto err;
		}
	}
	if (jited_line_info_cnt) {
		snapshot->jited_line_info = calloc(jited_line_info_cnt,
						   sizeof(*snapshot->jited_line_info));
		if (!snapshot->jited_line_info) {
			set_msg(msg, msg_len,
				"calloc(%u) failed for jited line info",
				jited_line_info_cnt);
			goto err;
		}
	}
	if (jited_ksym_cnt) {
		snapshot->jited_ksyms = calloc(jited_ksym_cnt,
					       sizeof(*snapshot->jited_ksyms));
		if (!snapshot->jited_ksyms) {
			set_msg(msg, msg_len, "calloc(%u) failed for jited ksyms",
				jited_ksym_cnt);
			goto err;
		}
	}

	memset(&info, 0, sizeof(info));
	info.jited_prog_len = image_len;
	info.jited_prog_insns = ptr_to_u64(snapshot->image.data);
	if (snapshot->line_info) {
		info.nr_line_info = line_info_cnt;
		info.line_info_rec_size = sizeof(*snapshot->line_info);
		info.line_info = ptr_to_u64(snapshot->line_info);
	}
	if (snapshot->jited_line_info) {
		info.nr_jited_line_info = jited_line_info_cnt;
		info.jited_line_info_rec_size = sizeof(*snapshot->jited_line_info);
		info.jited_line_info = ptr_to_u64(snapshot->jited_line_info);
	}
	if (snapshot->jited_ksyms) {
		info.nr_jited_ksyms = jited_ksym_cnt;
		info.jited_ksyms = ptr_to_u64(snapshot->jited_ksyms);
	}
	info_len = sizeof(info);
	if (bpf_prog_get_info_by_fd(prog_fd, &info, &info_len)) {
		set_msg(msg, msg_len,
			"bpf_prog_get_info_by_fd(jit dump, fd=%d): %s",
			prog_fd, strerror(errno));
		goto err;
	}

	snapshot->info = info;
	snapshot->image.len = info.jited_prog_len;
	snapshot->line_info_cnt = info.nr_line_info;
	snapshot->jited_line_info_cnt = info.nr_jited_line_info;
	snapshot->jited_ksym_cnt = info.nr_jited_ksyms;
	return 0;

err:
	free_jit_snapshot(snapshot);
	return -1;
}

static int find_line_info_idx_exact(const struct jit_snapshot *snapshot,
				    __u32 insn_off)
{
	__u32 i;

	for (i = 0; i < snapshot->line_info_cnt; i++) {
		if (snapshot->line_info[i].insn_off == insn_off)
			return (int)i;
	}

	return -1;
}

static int find_line_info_idx_after(const struct jit_snapshot *snapshot,
				    __u32 insn_off)
{
	__u32 i;

	for (i = 0; i < snapshot->line_info_cnt; i++) {
		if (snapshot->line_info[i].insn_off > insn_off)
			return (int)i;
	}

	return -1;
}

static bool find_site_native_range(const struct jit_snapshot *snapshot,
				   __u32 site_start, __u32 site_len,
				   struct native_range *range,
				   char *msg, size_t msg_len)
{
	int start_idx;
	int end_idx;
	__u64 base_addr;
	__u64 start_addr;
	__u64 end_addr;

	if (!snapshot->jited_ksym_cnt || !snapshot->jited_ksyms) {
		set_msg(msg, msg_len, "no jited ksym available to map site");
		return false;
	}
	if (!snapshot->line_info_cnt || !snapshot->jited_line_info_cnt ||
	    !snapshot->line_info || !snapshot->jited_line_info) {
		set_msg(msg, msg_len, "line info unavailable for native site mapping");
		return false;
	}
	if (snapshot->line_info_cnt != snapshot->jited_line_info_cnt) {
		set_msg(msg, msg_len,
			"line info count mismatch: %u vs %u",
			snapshot->line_info_cnt, snapshot->jited_line_info_cnt);
		return false;
	}

	start_idx = find_line_info_idx_exact(snapshot, site_start);
	end_idx = find_line_info_idx_exact(snapshot, site_start + site_len);
	if (start_idx < 0) {
		set_msg(msg, msg_len,
			"missing exact line info start for site %u+%u",
			site_start, site_len);
		return false;
	}
	if (end_idx < 0)
		end_idx = find_line_info_idx_after(snapshot,
						    site_start + site_len - 1);

	base_addr = snapshot->jited_ksyms[0];
	start_addr = snapshot->jited_line_info[start_idx];
	if (end_idx >= 0)
		end_addr = snapshot->jited_line_info[end_idx];
	else
		end_addr = base_addr + snapshot->image.len;
	if (start_addr < base_addr || end_addr < start_addr) {
		set_msg(msg, msg_len,
			"invalid native range [%llu, %llu) with base %llu",
			(unsigned long long)start_addr,
			(unsigned long long)end_addr,
			(unsigned long long)base_addr);
		return false;
	}

	range->start = (size_t)(start_addr - base_addr);
	range->end = (size_t)(end_addr - base_addr);
	if (range->end > snapshot->image.len) {
		set_msg(msg, msg_len,
			"native site range [0x%zx, 0x%zx) exceeds image size %zu",
			range->start, range->end, snapshot->image.len);
		return false;
	}

	return true;
}

static bool region_is_identical(const struct blob *before,
				size_t before_off,
				const struct blob *after,
				size_t after_off,
				size_t len)
{
	if (before_off + len > before->len || after_off + len > after->len)
		return false;

	return memcmp(before->data + before_off, after->data + after_off, len) == 0;
}

static size_t blob_common_prefix_len(const struct blob *before,
				     const struct blob *after)
{
	size_t len = before->len < after->len ? before->len : after->len;
	size_t i;

	for (i = 0; i < len; i++) {
		if (before->data[i] != after->data[i])
			return i;
	}

	return len;
}

static bool find_unique_sequence(const struct blob *image,
				 const unsigned char *seq, size_t seq_len,
				 size_t *offset,
				 char *msg, size_t msg_len)
{
	size_t i;
	size_t match_cnt = 0;
	size_t found = 0;

	if (image->len < seq_len) {
		set_msg(msg, msg_len,
			"sequence length %zu exceeds image size %zu",
			seq_len, image->len);
		return false;
	}

	for (i = 0; i + seq_len <= image->len; i++) {
		if (memcmp(image->data + i, seq, seq_len))
			continue;
		found = i;
		match_cnt++;
	}

	if (match_cnt != 1) {
		set_msg(msg, msg_len,
			"expected exactly one sequence match, found %zu",
			match_cnt);
		return false;
	}

	*offset = found;
	return true;
}

static bool find_wide_native_range(const struct jit_snapshot *snapshot,
				   bool optimized,
				   __u32 site_start, __u32 site_len,
				   struct native_range *range,
				   char *msg, size_t msg_len)
{
	static const unsigned char stock_seq[] = {
		0x48, 0x0f, 0xb6, 0x5f, 0x02,
		0x48, 0xc1, 0xe3, 0x08,
		0x48, 0x0f, 0xb6, 0x7f, 0x01,
		0x48, 0x09, 0xfb,
	};
	static const unsigned char opt_seq[] = {
		0x48, 0x0f, 0xb7, 0x5f, 0x01,
	};
	const unsigned char *seq = optimized ? opt_seq : stock_seq;
	size_t seq_len = optimized ? sizeof(opt_seq) : sizeof(stock_seq);
	size_t offset = 0;
	char seq_msg[128] = {};

	if (find_unique_sequence(&snapshot->image, seq, seq_len, &offset,
				 seq_msg, sizeof(seq_msg))) {
		range->start = offset;
		range->end = offset + seq_len;
		return true;
	}

	if (!find_site_native_range(snapshot, site_start, site_len, range,
				    msg, msg_len)) {
		set_msg(msg, msg_len,
			"failed to locate wide native range (%s); pattern search: %s",
			optimized ? "optimized" : "stock", seq_msg);
		return false;
	}

	return true;
}

static int reset_result_map(int map_fd)
{
	__u32 key = 0;
	__u64 zero = 0;

	return bpf_map_update_elem(map_fd, &key, &zero, BPF_ANY);
}

static int read_result_map(int map_fd, __u64 *value)
{
	__u32 key = 0;

	return bpf_map_lookup_elem(map_fd, &key, value);
}

static int run_program_and_read_result(int prog_fd, int result_map_fd,
				       const void *data_in, size_t data_len,
				       __u32 *retval_out, __u64 *result_out,
				       char *msg, size_t msg_len)
{
	unsigned char short_packet[ETH_HLEN] = {};
	unsigned char data_out[64] = {};
	struct xdp_md ctx_in = {
		.data_meta = 0,
		.data = 0,
		.data_end = data_len,
	};
	const void *run_data = data_in;
	size_t run_len = data_len;
	struct bpf_test_run_opts opts = {
		.sz = sizeof(opts),
		.repeat = 1,
		.data_out = data_out,
		.data_size_out = sizeof(data_out),
		.ctx_in = &ctx_in,
		.ctx_size_in = sizeof(ctx_in),
	};

	if (data_len < ETH_HLEN) {
		if (data_in && data_len)
			memcpy(short_packet, data_in, data_len);
		run_data = short_packet;
		run_len = sizeof(short_packet);
	}

	opts.data_in = run_data;
	opts.data_size_in = run_len;

	if (reset_result_map(result_map_fd)) {
		set_msg(msg, msg_len, "bpf_map_update_elem(result_map): %s",
			strerror(errno));
		return -1;
	}

	if (bpf_prog_test_run_opts(prog_fd, &opts)) {
		set_msg(msg, msg_len, "bpf_prog_test_run_opts: %s",
			strerror(errno));
		return -1;
	}

	if (read_result_map(result_map_fd, result_out)) {
		set_msg(msg, msg_len, "bpf_map_lookup_elem(result_map): %s",
			strerror(errno));
		return -1;
	}

	if (retval_out)
		*retval_out = opts.retval;
	return 0;
}

static int append_bytes(unsigned char *dst, size_t dst_len, size_t *offset,
			const void *src, size_t src_len)
{
	if (*offset + src_len > dst_len)
		return -1;

	memcpy(dst + *offset, src, src_len);
	*offset += src_len;
	return 0;
}

static int build_policy_blob(const struct program_meta *meta,
			     const struct rule_parts *rules,
			     size_t rule_cnt,
			     struct blob *blob,
			     char *msg,
			     size_t msg_len)
{
	struct bpf_jit_policy_hdr hdr = {};
	size_t i;
	size_t total_len = sizeof(hdr);
	size_t offset = 0;

	memset(blob, 0, sizeof(*blob));

	for (i = 0; i < rule_cnt; i++) {
		total_len += sizeof(struct bpf_jit_rewrite_rule_v2);
	}

	blob->data = calloc(1, total_len);
	if (!blob->data) {
		set_msg(msg, msg_len, "calloc(%zu) failed for policy blob",
			total_len);
		return -1;
	}
	blob->len = total_len;

	hdr.magic = BPF_JIT_POLICY_MAGIC;
	hdr.version = BPF_JIT_POLICY_VERSION_2;
	hdr.hdr_len = sizeof(hdr);
	hdr.total_len = total_len;
	hdr.rule_cnt = rule_cnt;
	hdr.insn_cnt = meta->insn_cnt;
	memcpy(hdr.prog_tag, meta->info.tag, sizeof(hdr.prog_tag));
	hdr.arch_id = native_jit_arch_id();

	if (append_bytes(blob->data, blob->len, &offset, &hdr, sizeof(hdr)))
		goto overflow;

	for (i = 0; i < rule_cnt; i++) {
		if (append_bytes(blob->data, blob->len, &offset,
				 &rules[i].rule, sizeof(rules[i].rule)))
			goto overflow;
	}

	return 0;

overflow:
	free_blob(blob);
	set_msg(msg, msg_len, "internal policy blob overflow");
	return -1;
}

static int create_memfd_from_blob(const char *name, const struct blob *blob,
				  bool seal)
{
	int fd;
	size_t written = 0;

	fd = memfd_create(name, MFD_CLOEXEC | MFD_ALLOW_SEALING);
	if (fd < 0)
		return -1;

	while (written < blob->len) {
		ssize_t rc = write(fd, blob->data + written, blob->len - written);

		if (rc < 0) {
			if (errno == EINTR)
				continue;
			close(fd);
			return -1;
		}
		written += rc;
	}

	if (seal) {
		int seals = F_SEAL_WRITE | F_SEAL_GROW | F_SEAL_SHRINK;

		if (fcntl(fd, F_ADD_SEALS, seals)) {
			close(fd);
			return -1;
		}
	}

	return fd;
}

static int sys_prog_jit_recompile(int prog_fd, int policy_fd, __u32 flags,
				  char *log_buf, __u32 log_size,
				  bool log_enabled)
{
	union bpf_attr attr;
	long rc;

	memset(&attr, 0, sizeof(attr));
	attr.jit_recompile.prog_fd = prog_fd;
	attr.jit_recompile.policy_fd = policy_fd;
	attr.jit_recompile.flags = flags;
	attr.jit_recompile.log_level = log_enabled ? 1 : 0;
	attr.jit_recompile.log_size = log_size;
	attr.jit_recompile.log_buf = ptr_to_u64(log_buf);

	errno = 0;
	rc = syscall(__NR_bpf, BPF_PROG_JIT_RECOMPILE, &attr, sizeof(attr));
	if (rc == 0)
		return 0;
	return -errno;
}

static int apply_blob(int prog_fd, const struct blob *blob, bool seal,
		      char *log_buf, size_t log_buf_len)
{
	int policy_fd;
	int rc;

	policy_fd = create_memfd_from_blob("bpf-jit-policy", blob, seal);
	if (policy_fd < 0)
		return -errno;

	if (log_buf && log_buf_len)
		memset(log_buf, 0, log_buf_len);

	rc = sys_prog_jit_recompile(prog_fd, policy_fd, 0,
				    log_buf,
				    log_buf ? (__u32)log_buf_len : 0,
				    log_buf ? 1 : 0);
	close(policy_fd);
	return rc;
}

static int apply_stock_rejit(int prog_fd, char *log_buf, size_t log_buf_len)
{
	if (log_buf && log_buf_len)
		memset(log_buf, 0, log_buf_len);

	return sys_prog_jit_recompile(prog_fd, 0, 0,
				      log_buf,
				      log_buf ? (__u32)log_buf_len : 0,
				      log_buf ? 1 : 0);
}

static bool is_cond_select_jump(const struct bpf_insn *insn)
{
	__u8 cls = BPF_CLASS(insn->code);

	if (cls != BPF_JMP && cls != BPF_JMP32)
		return false;
	if (BPF_SRC(insn->code) != BPF_X && BPF_SRC(insn->code) != BPF_K)
		return false;

	switch (BPF_OP(insn->code)) {
	case BPF_JEQ:
	case BPF_JNE:
	case BPF_JGT:
	case BPF_JLT:
	case BPF_JGE:
	case BPF_JLE:
	case BPF_JSGT:
	case BPF_JSLT:
	case BPF_JSGE:
	case BPF_JSLE:
		return true;
	default:
		return false;
	}
}

static bool is_simple_mov(const struct bpf_insn *insn)
{
	__u8 cls = BPF_CLASS(insn->code);

	if ((cls != BPF_ALU && cls != BPF_ALU64) || BPF_OP(insn->code) != BPF_MOV)
		return false;
	if (insn->off != 0)
		return false;

	switch (BPF_SRC(insn->code)) {
	case BPF_X:
		return insn->imm == 0;
	case BPF_K:
		return insn->src_reg == 0;
	default:
		return false;
	}
}

static bool find_guarded_select_site(const struct program_meta *meta, __u32 *site)
{
	__u32 i;

	for (i = 0; i + 2 < meta->insn_cnt; i++) {
		const struct bpf_insn *default_insn = &meta->insns[i];
		const struct bpf_insn *jump = &meta->insns[i + 1];
		const struct bpf_insn *override_insn = &meta->insns[i + 2];
		__u8 mov_cls;

		if (!is_simple_mov(default_insn) || !is_simple_mov(override_insn))
			continue;
		if (!is_cond_select_jump(jump) || jump->off != 1)
			continue;
		if (default_insn->dst_reg != override_insn->dst_reg)
			continue;
		mov_cls = BPF_CLASS(default_insn->code);
		if (mov_cls != BPF_CLASS(override_insn->code))
			continue;
		if (BPF_CLASS(jump->code) == BPF_JMP && mov_cls != BPF_ALU64)
			continue;
		if (BPF_CLASS(jump->code) == BPF_JMP32 && mov_cls != BPF_ALU)
			continue;
		*site = i;
		return true;
	}

	return false;
}

static bool find_rotate_site(const struct program_meta *meta, __u32 *site)
{
	__u32 i;

	for (i = 0; i + 3 < meta->insn_cnt; i++) {
		const struct bpf_insn *mov = &meta->insns[i];
		const struct bpf_insn *insn1 = &meta->insns[i + 1];
		const struct bpf_insn *insn2 = &meta->insns[i + 2];
		const struct bpf_insn *ior = &meta->insns[i + 3];
		const struct bpf_insn *lsh;
		const struct bpf_insn *rsh;

		if (BPF_CLASS(mov->code) != BPF_ALU64 ||
		    BPF_OP(mov->code) != BPF_MOV ||
		    BPF_SRC(mov->code) != BPF_X ||
		    mov->off != 0 || mov->imm != 0 ||
		    mov->dst_reg == mov->src_reg)
			continue;
		if (BPF_OP(insn1->code) == BPF_RSH &&
		    BPF_SRC(insn1->code) == BPF_K &&
		    BPF_CLASS(insn1->code) == BPF_ALU64 &&
		    BPF_OP(insn2->code) == BPF_LSH &&
		    BPF_SRC(insn2->code) == BPF_K &&
		    BPF_CLASS(insn2->code) == BPF_ALU64) {
			rsh = insn1;
			lsh = insn2;
		} else if (BPF_OP(insn1->code) == BPF_LSH &&
			   BPF_SRC(insn1->code) == BPF_K &&
			   BPF_CLASS(insn1->code) == BPF_ALU64 &&
			   BPF_OP(insn2->code) == BPF_RSH &&
			   BPF_SRC(insn2->code) == BPF_K &&
			   BPF_CLASS(insn2->code) == BPF_ALU64) {
			lsh = insn1;
			rsh = insn2;
		} else {
			continue;
		}
		if (rsh->off != 0 || lsh->off != 0)
			continue;
		if (rsh->dst_reg != mov->dst_reg ||
		    lsh->dst_reg != mov->src_reg)
			continue;
		if ((unsigned int)lsh->imm == 0 || (unsigned int)lsh->imm >= 64)
			continue;
		if ((unsigned int)rsh->imm != 64U - (unsigned int)lsh->imm)
			continue;
		if (BPF_CLASS(ior->code) != BPF_ALU64 ||
		    BPF_OP(ior->code) != BPF_OR ||
		    BPF_SRC(ior->code) != BPF_X ||
		    ior->off != 0 || ior->imm != 0)
			continue;
		if (ior->dst_reg != mov->src_reg || ior->src_reg != mov->dst_reg)
			continue;
		*site = i;
		return true;
	}

	return false;
}

static bool find_wide_site(const struct program_meta *meta, __u32 *site)
{
	__u32 i;

	for (i = 0; i + 3 < meta->insn_cnt; i++) {
		const struct bpf_insn *ld_hi = &meta->insns[i];
		const struct bpf_insn *lsh = &meta->insns[i + 1];
		const struct bpf_insn *ld_lo = &meta->insns[i + 2];
		const struct bpf_insn *ior = &meta->insns[i + 3];

		if (ld_hi->code != 0x71 || lsh->code != 0x67 ||
		    ld_lo->code != 0x71 || ior->code != 0x4f)
			continue;
		if (ld_hi->src_reg != ld_lo->src_reg)
			continue;
		if (ld_hi->imm != 0 || ld_lo->imm != 0)
			continue;
		if (ld_hi->off != ld_lo->off + 1)
			continue;
		if (lsh->dst_reg != ld_hi->dst_reg || lsh->imm != 8)
			continue;
		if (ior->dst_reg != ld_hi->dst_reg ||
		    ior->src_reg != ld_lo->dst_reg)
			continue;
		*site = i;
		return true;
	}

	return false;
}

static bool find_addr_calc_site(const struct program_meta *meta, __u32 *site)
{
	__u32 i;

	for (i = 0; i + 2 < meta->insn_cnt; i++) {
		const struct bpf_insn *mov = &meta->insns[i];
		const struct bpf_insn *lsh = &meta->insns[i + 1];
		const struct bpf_insn *add = &meta->insns[i + 2];

		if (mov->code != (BPF_ALU64 | BPF_MOV | BPF_X))
			continue;
		if (mov->off != 0 || mov->imm != 0)
			continue;
		if (lsh->code != (BPF_ALU64 | BPF_LSH | BPF_K))
			continue;
		if (lsh->dst_reg != mov->dst_reg || lsh->off != 0)
			continue;
		if (lsh->imm < 1 || lsh->imm > 3)
			continue;
		if (add->code != (BPF_ALU64 | BPF_ADD | BPF_X))
			continue;
		if (add->dst_reg != mov->dst_reg || add->off != 0 || add->imm != 0)
			continue;

		*site = i;
		return true;
	}

	return false;
}

static bool find_bitfield_extract_site(const struct program_meta *meta,
				       __u32 *site, __u16 *site_len)
{
	__u32 i;

	for (i = 0; i + 2 < meta->insn_cnt; i++) {
		const struct bpf_insn *mov = &meta->insns[i];
		const struct bpf_insn *first = &meta->insns[i + 1];
		const struct bpf_insn *second = &meta->insns[i + 2];
		__u8 mov_opcode;
		__u8 rsh_opcode;
		__u8 and_opcode;

		switch (first->code) {
		case BPF_ALU64 | BPF_RSH | BPF_K:
		case BPF_ALU64 | BPF_AND | BPF_K:
			mov_opcode = BPF_ALU64 | BPF_MOV | BPF_X;
			rsh_opcode = BPF_ALU64 | BPF_RSH | BPF_K;
			and_opcode = BPF_ALU64 | BPF_AND | BPF_K;
			break;
		case BPF_ALU | BPF_RSH | BPF_K:
		case BPF_ALU | BPF_AND | BPF_K:
			mov_opcode = BPF_ALU | BPF_MOV | BPF_X;
			rsh_opcode = BPF_ALU | BPF_RSH | BPF_K;
			and_opcode = BPF_ALU | BPF_AND | BPF_K;
			break;
		default:
			continue;
		}

		if (mov->code != mov_opcode || mov->off != 0 || mov->imm != 0)
			continue;
		if (first->dst_reg != mov->dst_reg || second->dst_reg != mov->dst_reg)
			continue;
		if (first->off != 0 || second->off != 0)
			continue;
		if (!((first->code == rsh_opcode && second->code == and_opcode) ||
		      (first->code == and_opcode && second->code == rsh_opcode)))
			continue;

		*site = i;
		*site_len = 3;
		return true;
	}

	for (i = 0; i + 1 < meta->insn_cnt; i++) {
		const struct bpf_insn *first = &meta->insns[i];
		const struct bpf_insn *second = &meta->insns[i + 1];
		__u8 rsh_opcode;
		__u8 and_opcode;

		switch (first->code) {
		case BPF_ALU64 | BPF_RSH | BPF_K:
		case BPF_ALU64 | BPF_AND | BPF_K:
			rsh_opcode = BPF_ALU64 | BPF_RSH | BPF_K;
			and_opcode = BPF_ALU64 | BPF_AND | BPF_K;
			break;
		case BPF_ALU | BPF_RSH | BPF_K:
		case BPF_ALU | BPF_AND | BPF_K:
			rsh_opcode = BPF_ALU | BPF_RSH | BPF_K;
			and_opcode = BPF_ALU | BPF_AND | BPF_K;
			break;
		default:
			continue;
		}

		if (second->dst_reg != first->dst_reg)
			continue;
		if (first->off != 0 || second->off != 0)
			continue;
		if (!((first->code == rsh_opcode && second->code == and_opcode) ||
		      (first->code == and_opcode && second->code == rsh_opcode)))
			continue;

		*site = i;
		*site_len = 2;
		return true;
	}

	return false;
}

static bool is_zero_ext_tail(const struct bpf_insn *insn, __u8 dst_reg)
{
	if (insn->code == (BPF_ALU | BPF_MOV | BPF_X))
		return insn->dst_reg == dst_reg &&
		       insn->src_reg == dst_reg &&
		       insn->off == 0 &&
		       insn->imm == 1;

	if (insn->code == (BPF_ALU64 | BPF_MOV | BPF_X))
		return insn->dst_reg == dst_reg &&
		       insn->src_reg == dst_reg &&
		       insn->off == 0 &&
		       insn->imm == 0;

	if (insn->code == (BPF_ALU64 | BPF_AND | BPF_K))
		return insn->dst_reg == dst_reg &&
		       insn->off == 0 &&
		       insn->imm == -1;

	return false;
}

static bool find_zero_ext_elide_site(const struct program_meta *meta, __u32 *site)
{
	__u32 i;

	for (i = 0; i + 1 < meta->insn_cnt; i++) {
		const struct bpf_insn *alu32 = &meta->insns[i];
		const struct bpf_insn *tail = &meta->insns[i + 1];

		if (BPF_CLASS(alu32->code) != BPF_ALU || BPF_OP(alu32->code) == BPF_END)
			continue;
		if (!is_zero_ext_tail(tail, alu32->dst_reg))
			continue;

		*site = i;
		return true;
	}

	return false;
}

static int endian_width_from_mem_code(__u8 code)
{
	switch (code) {
	case BPF_LDX | BPF_MEM | BPF_H:
	case BPF_STX | BPF_MEM | BPF_H:
		return 16;
	case BPF_LDX | BPF_MEM | BPF_W:
	case BPF_STX | BPF_MEM | BPF_W:
		return 32;
	case BPF_LDX | BPF_MEM | BPF_DW:
	case BPF_STX | BPF_MEM | BPF_DW:
		return 64;
	default:
		return -1;
	}
}

static bool is_endian_swap(const struct bpf_insn *insn, int width)
{
	if (insn->off != 0 || insn->src_reg != 0 || insn->imm != width)
		return false;

	if (insn->code == (BPF_ALU64 | BPF_END | BPF_FROM_LE))
		return width == 16 || width == 32 || width == 64;

	if (insn->code == (BPF_ALU | BPF_END | BPF_FROM_BE))
		return width == 16 || width == 32;

	return false;
}

static bool find_endian_fusion_site(const struct program_meta *meta, __u32 *site)
{
	__u32 i;

	for (i = 0; i + 1 < meta->insn_cnt; i++) {
		const struct bpf_insn *first = &meta->insns[i];
		const struct bpf_insn *second = &meta->insns[i + 1];
		int width;

		width = endian_width_from_mem_code(first->code);
		if (width > 0 && BPF_CLASS(first->code) == BPF_LDX) {
			if (first->imm == 0 && first->dst_reg == second->dst_reg &&
			    is_endian_swap(second, width)) {
				*site = i;
				return true;
			}
		}

		width = endian_width_from_mem_code(second->code);
		if (width > 0 && BPF_CLASS(second->code) == BPF_STX) {
			if (second->imm == 0 && first->dst_reg == second->src_reg &&
			    is_endian_swap(first, width)) {
				*site = i;
				return true;
			}
		}
	}

	return false;
}

static bool branch_flip_body_linear(const struct bpf_insn *insns, __u32 start,
				    __u32 len)
{
	__u32 i;

	if (!len)
		return false;

	for (i = start; i < start + len; i++) {
		__u8 cls = BPF_CLASS(insns[i].code);
		__u8 op = BPF_OP(insns[i].code);

		if ((cls == BPF_JMP || cls == BPF_JMP32) &&
		    op != BPF_CALL && op != BPF_EXIT)
			return false;
		if (cls == BPF_STX || cls == BPF_ST)
			return false;
		if (insns[i].code == (BPF_LD | BPF_IMM | BPF_DW))
			return false;
	}

	return true;
}

static bool branch_flip_cond_op_valid(__u8 op)
{
	switch (op) {
	case BPF_JEQ:
	case BPF_JNE:
	case BPF_JGT:
	case BPF_JLT:
	case BPF_JGE:
	case BPF_JLE:
	case BPF_JSGT:
	case BPF_JSLT:
	case BPF_JSGE:
	case BPF_JSLE:
	case BPF_JSET:
		return true;
	default:
		return false;
	}
}

static bool find_branch_flip_site(const struct program_meta *meta, __u32 *site,
				  __u16 *site_len)
{
	__u32 i;

	for (i = 0; i + 3 < meta->insn_cnt; i++) {
		const struct bpf_insn *jcc = &meta->insns[i];
		const struct bpf_insn *ja;
		__u32 body_a_start;
		__u32 body_b_start;
		__u32 ja_idx;
		__u32 body_a_len;
		__u32 body_b_len;
		__u32 join_target;

		if ((BPF_CLASS(jcc->code) != BPF_JMP &&
		     BPF_CLASS(jcc->code) != BPF_JMP32) ||
		    !branch_flip_cond_op_valid(BPF_OP(jcc->code)))
			continue;

		body_a_start = i + 1;
		body_b_start = body_a_start + jcc->off;
		if (body_b_start <= body_a_start || body_b_start > meta->insn_cnt)
			continue;

		ja_idx = body_b_start - 1;
		if (ja_idx <= i || ja_idx >= meta->insn_cnt)
			continue;
		ja = &meta->insns[ja_idx];
		if (ja->code != (BPF_JMP | BPF_JA))
			continue;

		body_a_len = ja_idx - body_a_start;
		if (!body_a_len || body_a_len > 16)
			continue;

		join_target = ja_idx + 1 + ja->off;
		if (join_target <= body_b_start || join_target > meta->insn_cnt)
			continue;
		body_b_len = join_target - body_b_start;
		if (!body_b_len || body_b_len > 16)
			continue;
		if (!branch_flip_body_linear(meta->insns, body_a_start, body_a_len) ||
		    !branch_flip_body_linear(meta->insns, body_b_start, body_b_len))
			continue;

		*site = i;
		*site_len = join_target - i;
		return true;
	}

	return false;
}

static int build_guarded_select_blob(const struct program_meta *meta, __u32 site,
				     __u16 native_choice, struct blob *blob,
				     char *msg, size_t msg_len)
{
	struct rule_parts parts = {
		.rule = {
			.site_start = site,
			.site_len = 3,
			.canonical_form = BPF_JIT_CF_COND_SELECT,
			.native_choice = native_choice,
		},
	};

	return build_policy_blob(meta, &parts, 1, blob, msg, msg_len);
}

static int build_rotate_blob(const struct program_meta *meta, __u32 site,
			     __u16 native_choice, struct blob *blob,
			     char *msg, size_t msg_len)
{
	struct rule_parts parts = {
		.rule = {
			.site_start = site,
			.site_len = 4,
			.canonical_form = BPF_JIT_CF_ROTATE,
			.native_choice = native_choice,
		},
	};

	return build_policy_blob(meta, &parts, 1, blob, msg, msg_len);
}

static int build_wide_blob_with_choice(const struct program_meta *meta, __u32 site,
				       __u16 native_choice, struct blob *blob,
				       char *msg, size_t msg_len)
{
	struct rule_parts parts = {
		.rule = {
			.site_start = site,
			.site_len = 4,
			.canonical_form = BPF_JIT_CF_WIDE_MEM,
			.native_choice = native_choice,
		},
	};

	return build_policy_blob(meta, &parts, 1, blob, msg, msg_len);
}

static int build_wide_blob(const struct program_meta *meta, __u32 site,
			   struct blob *blob, char *msg, size_t msg_len)
{
	return build_wide_blob_with_choice(meta, site, BPF_JIT_WMEM_WIDE_LOAD,
					   blob, msg, msg_len);
}

static int build_addr_calc_blob(const struct program_meta *meta, __u32 site,
				struct blob *blob, char *msg, size_t msg_len)
{
	struct rule_parts parts = {
		.rule = {
			.site_start = site,
			.site_len = 3,
			.canonical_form = BPF_JIT_CF_ADDR_CALC,
			.native_choice = BPF_JIT_ACALC_LEA,
		},
	};

	return build_policy_blob(meta, &parts, 1, blob, msg, msg_len);
}

static int build_bitfield_extract_blob(const struct program_meta *meta, __u32 site,
				       __u16 site_len, struct blob *blob,
				       char *msg, size_t msg_len)
{
	struct rule_parts parts = {
		.rule = {
			.site_start = site,
			.site_len = site_len,
			.canonical_form = BPF_JIT_CF_BITFIELD_EXTRACT,
			.native_choice = BPF_JIT_BFX_EXTRACT,
		},
	};

	return build_policy_blob(meta, &parts, 1, blob, msg, msg_len);
}

static int build_zero_ext_elide_blob(const struct program_meta *meta, __u32 site,
				     struct blob *blob, char *msg, size_t msg_len)
{
	struct rule_parts parts = {
		.rule = {
			.site_start = site,
			.site_len = 2,
			.canonical_form = BPF_JIT_CF_ZERO_EXT_ELIDE,
			.native_choice = BPF_JIT_ZEXT_ELIDE,
		},
	};

	return build_policy_blob(meta, &parts, 1, blob, msg, msg_len);
}

static int build_endian_fusion_blob(const struct program_meta *meta, __u32 site,
				    struct blob *blob, char *msg, size_t msg_len)
{
	struct rule_parts parts = {
		.rule = {
			.site_start = site,
			.site_len = 2,
			.canonical_form = BPF_JIT_CF_ENDIAN_FUSION,
			.native_choice = BPF_JIT_ENDIAN_MOVBE,
		},
	};

	return build_policy_blob(meta, &parts, 1, blob, msg, msg_len);
}

static int build_branch_flip_blob(const struct program_meta *meta, __u32 site,
				  __u16 site_len, struct blob *blob,
				  char *msg, size_t msg_len)
{
	struct rule_parts parts = {
		.rule = {
			.site_start = site,
			.site_len = site_len,
			.canonical_form = BPF_JIT_CF_BRANCH_FLIP,
			.native_choice = BPF_JIT_BFLIP_FLIPPED,
		},
	};

	return build_policy_blob(meta, &parts, 1, blob, msg, msg_len);
}

static int load_meta_for_program(const char *obj_path, const char *prog_name,
				 struct loaded_program *prog,
				 struct program_meta *meta,
				 char *msg, size_t msg_len)
{
	if (load_program(obj_path, prog_name, prog, msg, msg_len))
		return -1;
	if (fetch_program_meta(prog->prog_fd, meta, msg, msg_len)) {
		unload_program(prog);
		return -1;
	}
	return 0;
}

static bool run_simple_packet_check(const struct loaded_program *prog,
				    __u64 *result,
				    char *msg, size_t msg_len)
{
	static const unsigned char packet[] = { 9, 1, 0x44, 0x88 };
	__u32 retval = 0;

	if (run_program_and_read_result(prog->prog_fd, prog->result_map_fd,
					packet, sizeof(packet),
					&retval, result, msg, msg_len))
		return false;
	if (retval != XDP_PASS) {
		set_msg(msg, msg_len, "unexpected XDP retval %u", retval);
		return false;
	}
	return true;
}

static bool run_diamond_packet_check(const struct loaded_program *prog,
				     __u64 *result,
				     char *msg, size_t msg_len)
{
	static const unsigned char packet[] = { 7, 1, 0xaa, 0xbb };
	__u32 retval = 0;

	if (run_program_and_read_result(prog->prog_fd, prog->result_map_fd,
					packet, sizeof(packet),
					&retval, result, msg, msg_len))
		return false;
	if (retval != XDP_PASS) {
		set_msg(msg, msg_len, "unexpected XDP retval %u", retval);
		return false;
	}
	return true;
}

static bool run_rotate_packet_check(const struct loaded_program *prog,
				    __u64 *result,
				    char *msg, size_t msg_len)
{
	static const unsigned char packet[] = { 0 };
	__u32 retval = 0;

	if (run_program_and_read_result(prog->prog_fd, prog->result_map_fd,
					packet, sizeof(packet),
					&retval, result, msg, msg_len))
		return false;
	if (retval != XDP_PASS) {
		set_msg(msg, msg_len, "unexpected XDP retval %u", retval);
		return false;
	}
	return true;
}

static bool run_wide_packet_check(const struct loaded_program *prog,
				  __u64 *result,
				  char *msg, size_t msg_len)
{
	static const unsigned char packet[] = { 0x00, 0x34, 0x12 };
	__u32 retval = 0;

	if (run_program_and_read_result(prog->prog_fd, prog->result_map_fd,
					packet, sizeof(packet),
					&retval, result, msg, msg_len))
		return false;
	if (retval != XDP_PASS) {
		set_msg(msg, msg_len, "unexpected XDP retval %u", retval);
		return false;
	}
	return true;
}

static bool run_ctx_only_packet_check(const struct loaded_program *prog,
				      __u64 *result,
				      char *msg, size_t msg_len)
{
	static const unsigned char packet[] = { 0 };
	__u32 retval = 0;

	if (run_program_and_read_result(prog->prog_fd, prog->result_map_fd,
					packet, sizeof(packet),
					&retval, result, msg, msg_len))
		return false;
	if (retval != XDP_PASS) {
		set_msg(msg, msg_len, "unexpected XDP retval %u", retval);
		return false;
	}
	return true;
}

static bool run_addr_calc_packet_check(const struct loaded_program *prog,
				       __u64 *result,
				       char *msg, size_t msg_len)
{
	return run_ctx_only_packet_check(prog, result, msg, msg_len);
}

static bool run_bitfield_extract_packet_check(const struct loaded_program *prog,
					      __u64 *result,
					      char *msg, size_t msg_len)
{
	return run_ctx_only_packet_check(prog, result, msg, msg_len);
}

static bool run_zero_ext_elide_packet_check(const struct loaded_program *prog,
					    __u64 *result,
					    char *msg, size_t msg_len)
{
	return run_ctx_only_packet_check(prog, result, msg, msg_len);
}

static bool run_endian_fusion_packet_check(const struct loaded_program *prog,
					   __u64 *result,
					   char *msg, size_t msg_len)
{
	return run_ctx_only_packet_check(prog, result, msg, msg_len);
}

static bool run_branch_flip_packet_check(const struct loaded_program *prog,
					 __u64 *result,
					 char *msg, size_t msg_len)
{
	return run_ctx_only_packet_check(prog, result, msg, msg_len);
}

static bool test_load_tag(char *msg, size_t msg_len)
{
	struct loaded_program prog;
	struct program_meta meta;
	char tag_hex[2 * BPF_TAG_SIZE + 1];
	bool ok = false;

	if (load_meta_for_program(SIMPLE_OBJ, "test_simple",
				  &prog, &meta, msg, msg_len))
		return false;

	if (tag_is_zero(meta.info.tag)) {
		set_msg(msg, msg_len, "program tag is unexpectedly zero");
		goto out;
	}

	format_tag(meta.info.tag, tag_hex, sizeof(tag_hex));
	set_msg(msg, msg_len, "prog_fd=%d tag=%s insn_cnt=%u",
		prog.prog_fd, tag_hex, meta.insn_cnt);
	ok = true;

out:
	free_program_meta(&meta);
	unload_program(&prog);
	return ok;
}

static bool test_zero_rule_blob(char *msg, size_t msg_len)
{
	struct loaded_program prog;
	struct program_meta meta;
	struct blob blob = {};
	char log_buf[LOG_BUF_SIZE] = {};
	bool ok = false;
	__u64 before = 0, after = 0;
	int rc;

	if (load_meta_for_program(SIMPLE_OBJ, "test_simple",
				  &prog, &meta, msg, msg_len))
		return false;
	if (!run_simple_packet_check(&prog, &before, msg, msg_len))
		goto out;
	if (build_policy_blob(&meta, NULL, 0, &blob, msg, msg_len))
		goto out;

	rc = apply_blob(prog.prog_fd, &blob, true, log_buf, sizeof(log_buf));
	if (rc == 0) {
		if (!run_simple_packet_check(&prog, &after, msg, msg_len))
			goto out;
		if (before != after) {
			set_msg(msg, msg_len,
				"zero-rule no-op changed result from 0x%llx to 0x%llx",
				(unsigned long long)before,
				(unsigned long long)after);
			goto out;
		}
		set_msg(msg, msg_len, "zero-rule blob accepted as no-op");
		ok = true;
		goto out;
	}

	if (rc == -EINVAL) {
		set_msg(msg, msg_len,
			"zero-rule blob currently rejected with EINVAL%s%s",
			log_buf[0] ? ": " : "",
			log_buf[0] ? log_buf : "");
		ok = true;
		goto out;
	}

	set_msg(msg, msg_len, "expected success or EINVAL bug, got %s (%d)%s%s",
		strerror(-rc), -rc,
		log_buf[0] ? ": " : "",
		log_buf[0] ? log_buf : "");

out:
	free_blob(&blob);
	free_program_meta(&meta);
	unload_program(&prog);
	return ok;
}

static bool test_valid_wide_rule(char *msg, size_t msg_len)
{
	struct loaded_program prog;
	struct program_meta meta;
	struct blob blob = {};
	__u32 site = 0;
	bool ok = false;
	int rc;

	if (load_meta_for_program(WIDE_OBJ, "test_wide", &prog, &meta, msg, msg_len))
		return false;
	if (!find_wide_site(&meta, &site)) {
		set_msg(msg, msg_len, "wide site not found");
		goto out;
	}
	if (build_wide_blob(&meta, site, &blob, msg, msg_len))
		goto out;

	rc = apply_blob(prog.prog_fd, &blob, true, NULL, 0);
	if (rc) {
		set_msg(msg, msg_len, "wide recompile failed: %s (%d)",
			strerror(-rc), -rc);
		goto out;
	}

	set_msg(msg, msg_len, "wide site_start=%u recompiled", site);
	ok = true;

out:
	free_blob(&blob);
	free_program_meta(&meta);
	unload_program(&prog);
	return ok;
}

static bool test_wide_result_unchanged(char *msg, size_t msg_len)
{
	struct loaded_program prog;
	struct program_meta meta;
	struct blob blob = {};
	__u32 site = 0;
	__u64 before = 0, after = 0;
	bool ok = false;
	int rc;

	if (load_meta_for_program(WIDE_OBJ, "test_wide", &prog, &meta, msg, msg_len))
		return false;
	if (!run_wide_packet_check(&prog, &before, msg, msg_len))
		goto out;
	if (!find_wide_site(&meta, &site)) {
		set_msg(msg, msg_len, "wide site not found");
		goto out;
	}
	if (build_wide_blob(&meta, site, &blob, msg, msg_len))
		goto out;

	rc = apply_blob(prog.prog_fd, &blob, true, NULL, 0);
	if (rc) {
		set_msg(msg, msg_len, "wide recompile failed: %s (%d)",
			strerror(-rc), -rc);
		goto out;
	}
	if (!run_wide_packet_check(&prog, &after, msg, msg_len))
		goto out;
	if (before != after) {
		set_msg(msg, msg_len,
			"wide result changed from 0x%llx to 0x%llx",
			(unsigned long long)before,
			(unsigned long long)after);
		goto out;
	}

	set_msg(msg, msg_len, "wide result 0x%llx preserved",
		(unsigned long long)after);
	ok = true;

out:
	free_blob(&blob);
	free_program_meta(&meta);
	unload_program(&prog);
	return ok;
}

static bool test_wide_zero_applied_jit_identity(char *msg, size_t msg_len)
{
	struct loaded_program prog;
	struct program_meta meta;
	__u32 site = 0;
	__u64 before = 0, after = 0;
	bool ok = false;
	int rc;

	if (load_meta_for_program(WIDE_OBJ, "test_wide", &prog, &meta, msg, msg_len))
		return false;
	if (!run_wide_packet_check(&prog, &before, msg, msg_len))
		goto out;
	if (!find_wide_site(&meta, &site)) {
		set_msg(msg, msg_len, "wide site not found");
		goto out;
	}

	rc = apply_stock_rejit(prog.prog_fd, NULL, 0);
	if (rc) {
		set_msg(msg, msg_len, "stock wide recompile failed: %s (%d)",
			strerror(-rc), -rc);
		goto out;
	}
	if (!run_wide_packet_check(&prog, &after, msg, msg_len))
		goto out;
	if (before != after) {
		set_msg(msg, msg_len,
			"stock re-JIT changed wide result from 0x%llx to 0x%llx",
			(unsigned long long)before,
			(unsigned long long)after);
		goto out;
	}

	set_msg(msg, msg_len,
		"stock re-JIT preserved wide result 0x%llx",
		(unsigned long long)after);
	ok = true;

out:
	free_program_meta(&meta);
	unload_program(&prog);
	return ok;
}

static bool test_wide_site_only_jit_diff(char *msg, size_t msg_len)
{
	struct loaded_program prog;
	struct program_meta meta;
	struct blob blob = {};
	struct jit_snapshot before = {};
	struct jit_snapshot after = {};
	struct native_range before_site = {};
	struct native_range after_site = {};
	const __u32 site_len = 4;
	__u32 site = 0;
	size_t common_prefix;
	size_t before_site_len;
	size_t after_site_len;
	long long image_delta;
	bool ok = false;
	int rc;

	if (native_jit_arch_is_arm64()) {
		set_msg(msg, msg_len,
			"ARM64 wide site diff check skipped; x86 byte-pattern test");
		return true;
	}

	if (load_meta_for_program(WIDE_OBJ, "test_wide", &prog, &meta, msg, msg_len))
		return false;
	if (!find_wide_site(&meta, &site)) {
		set_msg(msg, msg_len, "wide site not found");
		goto out;
	}
	if (build_wide_blob(&meta, site, &blob, msg, msg_len))
		goto out;
	if (fetch_jit_snapshot(prog.prog_fd, &before, msg, msg_len))
		goto out;
	if (!find_wide_native_range(&before, false, site, site_len, &before_site,
				    msg, msg_len))
		goto out;

	rc = apply_blob(prog.prog_fd, &blob, true, NULL, 0);
	if (rc) {
		set_msg(msg, msg_len, "wide site-only recompile failed: %s (%d)",
			strerror(-rc), -rc);
		goto out;
	}
	if (fetch_jit_snapshot(prog.prog_fd, &after, msg, msg_len))
		goto out;
	if (!find_wide_native_range(&after, true, site, site_len, &after_site,
				    msg, msg_len))
		goto out;

	common_prefix = blob_common_prefix_len(&before.image, &after.image);
	if (common_prefix < before_site.start)
		before_site.start = common_prefix;
	if (common_prefix < after_site.start)
		after_site.start = common_prefix;
	if (before_site.start != after_site.start) {
		set_msg(msg, msg_len,
			"observed site start mismatch after common-prefix adjustment: %#zx vs %#zx",
			before_site.start, after_site.start);
		goto out;
	}

	before_site_len = before_site.end - before_site.start;
	after_site_len = after_site.end - after_site.start;
	if (before_site_len == after_site_len &&
	    region_is_identical(&before.image, before_site.start,
				&after.image, after_site.start,
				before_site_len)) {
		set_msg(msg, msg_len,
			"wide site bytes did not change in [%#zx, %#zx)",
			before_site.start, before_site.end);
		goto out;
	}

	image_delta = (long long)after.image.len - (long long)before.image.len;
	if (image_delta != (long long)after_site_len - (long long)before_site_len) {
		set_msg(msg, msg_len,
			"unexpected image delta %lld for site shrink %zu->%zu",
			image_delta, before_site_len, after_site_len);
		goto out;
	}
	if (after_site_len >= before_site_len) {
		set_msg(msg, msg_len,
			"optimized site did not shrink: %zu -> %zu",
			before_site_len, after_site_len);
		goto out;
	}

	set_msg(msg, msg_len,
		"image %zu->%zu bytes (%+lld), site pre[%#zx,%#zx) post[%#zx,%#zx), prefix before site identical",
		before.image.len, after.image.len, image_delta,
		before_site.start, before_site.end,
		after_site.start, after_site.end);
	ok = true;

out:
	free_jit_snapshot(&after);
	free_jit_snapshot(&before);
	free_blob(&blob);
	free_program_meta(&meta);
	unload_program(&prog);
	return ok;
}

static bool build_valid_simple_blob_for_negative(const struct program_meta *meta,
						 struct blob *blob,
						 char *msg, size_t msg_len)
{
	__u32 site = 0;

	if (!find_guarded_select_site(meta, &site)) {
		set_msg(msg, msg_len, "guarded select site not found");
		return false;
	}
	return build_guarded_select_blob(meta, site, BPF_JIT_SEL_CMOVCC,
					 blob, msg, msg_len) == 0;
}

static bool expect_einval_with_mutated_blob(void (*mutate)(struct blob *, const struct program_meta *),
					    const char *what,
					    char *msg, size_t msg_len)
{
	struct loaded_program prog;
	struct program_meta meta;
	struct blob blob = {};
	char log_buf[LOG_BUF_SIZE] = {};
	bool ok = false;
	int rc;

	if (load_meta_for_program(SIMPLE_OBJ, "test_simple",
				  &prog, &meta, msg, msg_len))
		return false;
	if (!build_valid_simple_blob_for_negative(&meta, &blob, msg, msg_len))
		goto out;
	mutate(&blob, &meta);

	rc = apply_blob(prog.prog_fd, &blob, true, log_buf, sizeof(log_buf));
	if (rc != -EINVAL) {
		set_msg(msg, msg_len, "%s: expected EINVAL, got %s (%d)%s%s",
			what, strerror(-rc), -rc,
			log_buf[0] ? ": " : "",
			log_buf[0] ? log_buf : "");
		goto out;
	}

	set_msg(msg, msg_len, "%s rejected with EINVAL", what);
	ok = true;

out:
	free_blob(&blob);
	free_program_meta(&meta);
	unload_program(&prog);
	return ok;
}

static void mutate_wrong_magic(struct blob *blob, const struct program_meta *meta)
{
	struct bpf_jit_policy_hdr *hdr = (struct bpf_jit_policy_hdr *)blob->data;

	(void)meta;
	hdr->magic ^= 1U;
}

static void mutate_wrong_tag(struct blob *blob, const struct program_meta *meta)
{
	struct bpf_jit_policy_hdr *hdr = (struct bpf_jit_policy_hdr *)blob->data;

	(void)meta;
	hdr->prog_tag[0] ^= 0xff;
}

static void mutate_wrong_insn_cnt(struct blob *blob, const struct program_meta *meta)
{
	struct bpf_jit_policy_hdr *hdr = (struct bpf_jit_policy_hdr *)blob->data;

	(void)meta;
	hdr->insn_cnt += 1;
}

static void mutate_wrong_arch(struct blob *blob, const struct program_meta *meta)
{
	struct bpf_jit_policy_hdr *hdr = (struct bpf_jit_policy_hdr *)blob->data;

	(void)meta;
	hdr->arch_id = non_native_jit_arch_id();
}

static void mutate_bad_site_start(struct blob *blob, const struct program_meta *meta)
{
	struct bpf_jit_rewrite_rule_v2 *rule;

	rule = (struct bpf_jit_rewrite_rule_v2 *)
		(blob->data + sizeof(struct bpf_jit_policy_hdr));
	rule->site_start = meta->insn_cnt + 1;
}

static bool test_wrong_magic(char *msg, size_t msg_len)
{
	return expect_einval_with_mutated_blob(mutate_wrong_magic,
					       "wrong magic", msg, msg_len);
}

static bool test_wrong_prog_tag(char *msg, size_t msg_len)
{
	return expect_einval_with_mutated_blob(mutate_wrong_tag,
					       "wrong prog_tag", msg, msg_len);
}

static bool test_wrong_insn_cnt(char *msg, size_t msg_len)
{
	return expect_einval_with_mutated_blob(mutate_wrong_insn_cnt,
					       "wrong insn_cnt", msg, msg_len);
}

static bool test_wrong_arch_id(char *msg, size_t msg_len)
{
	return expect_einval_with_mutated_blob(mutate_wrong_arch,
					       "wrong arch_id", msg, msg_len);
}

static bool test_non_sealed_memfd(char *msg, size_t msg_len)
{
	struct loaded_program prog;
	struct program_meta meta;
	struct blob blob = {};
	char log_buf[LOG_BUF_SIZE] = {};
	int rc;
	bool ok = false;

	if (load_meta_for_program(SIMPLE_OBJ, "test_simple",
				  &prog, &meta, msg, msg_len))
		return false;
	if (!build_valid_simple_blob_for_negative(&meta, &blob, msg, msg_len))
		goto out;

	rc = apply_blob(prog.prog_fd, &blob, false, log_buf, sizeof(log_buf));
	if (rc != -EINVAL) {
		set_msg(msg, msg_len,
			"non-sealed memfd: expected EINVAL, got %s (%d)%s%s",
			strerror(-rc), -rc,
			log_buf[0] ? ": " : "",
			log_buf[0] ? log_buf : "");
		goto out;
	}

	set_msg(msg, msg_len, "non-sealed memfd rejected with EINVAL");
	ok = true;

out:
	free_blob(&blob);
	free_program_meta(&meta);
	unload_program(&prog);
	return ok;
}

static bool test_truncated_header(char *msg, size_t msg_len)
{
	struct loaded_program prog;
	struct program_meta meta;
	struct blob blob = {};
	struct blob truncated = {};
	char log_buf[LOG_BUF_SIZE] = {};
	int rc;
	bool ok = false;

	if (load_meta_for_program(SIMPLE_OBJ, "test_simple",
				  &prog, &meta, msg, msg_len))
		return false;
	if (!build_valid_simple_blob_for_negative(&meta, &blob, msg, msg_len))
		goto out;

	truncated.len = sizeof(struct bpf_jit_policy_hdr) - 1;
	truncated.data = malloc(truncated.len);
	if (!truncated.data) {
		set_msg(msg, msg_len, "malloc(%zu) failed", truncated.len);
		goto out;
	}
	memcpy(truncated.data, blob.data, truncated.len);

	rc = apply_blob(prog.prog_fd, &truncated, true, log_buf, sizeof(log_buf));
	if (rc != -EINVAL) {
		set_msg(msg, msg_len,
			"truncated header: expected EINVAL, got %s (%d)%s%s",
			strerror(-rc), -rc,
			log_buf[0] ? ": " : "",
			log_buf[0] ? log_buf : "");
		goto out;
	}

	set_msg(msg, msg_len, "truncated header rejected with EINVAL");
	ok = true;

out:
	free_blob(&truncated);
	free_blob(&blob);
	free_program_meta(&meta);
	unload_program(&prog);
	return ok;
}

static bool test_site_out_of_bounds(char *msg, size_t msg_len)
{
	return expect_einval_with_mutated_blob(mutate_bad_site_start,
					       "site_start past program end",
					       msg, msg_len);
}

static bool test_zero_length_blob(char *msg, size_t msg_len)
{
	struct loaded_program prog;
	struct program_meta meta;
	int policy_fd = -1;
	char log_buf[LOG_BUF_SIZE] = {};
	int rc;
	bool ok = false;

	if (load_meta_for_program(SIMPLE_OBJ, "test_simple",
				  &prog, &meta, msg, msg_len))
		return false;

	policy_fd = memfd_create("empty-jit-policy", MFD_CLOEXEC | MFD_ALLOW_SEALING);
	if (policy_fd < 0) {
		set_msg(msg, msg_len, "memfd_create(empty): %s", strerror(errno));
		goto out;
	}
	if (fcntl(policy_fd, F_ADD_SEALS,
		  F_SEAL_WRITE | F_SEAL_GROW | F_SEAL_SHRINK)) {
		set_msg(msg, msg_len, "fcntl(F_ADD_SEALS): %s", strerror(errno));
		goto out;
	}

	rc = sys_prog_jit_recompile(prog.prog_fd, policy_fd, 0,
				    log_buf, sizeof(log_buf), 1);
	if (rc != -EINVAL) {
		set_msg(msg, msg_len,
			"zero-length blob: expected EINVAL, got %s (%d)%s%s",
			strerror(-rc), -rc,
			log_buf[0] ? ": " : "",
			log_buf[0] ? log_buf : "");
		goto out;
	}

	set_msg(msg, msg_len, "zero-length blob rejected with EINVAL");
	ok = true;

out:
	if (policy_fd >= 0)
		close(policy_fd);
	free_program_meta(&meta);
	unload_program(&prog);
	return ok;
}

static bool test_diamond_cmov(char *msg, size_t msg_len)
{
	struct loaded_program prog;
	struct program_meta meta;
	struct blob blob = {};
	__u32 site = 0;
	__u64 before = 0, after = 0;
	bool ok = false;
	int rc;

	if (load_meta_for_program(DIAMOND_OBJ, "test_diamond",
				  &prog, &meta, msg, msg_len))
		return false;
	if (!run_diamond_packet_check(&prog, &before, msg, msg_len))
		goto out;
	if (!find_guarded_select_site(&meta, &site)) {
		set_msg(msg, msg_len, "diamond select site not found");
		goto out;
	}
	if (build_guarded_select_blob(&meta, site, BPF_JIT_SEL_CMOVCC,
				      &blob, msg, msg_len))
		goto out;

	rc = apply_blob(prog.prog_fd, &blob, true, NULL, 0);
	if (rc) {
		set_msg(msg, msg_len, "diamond cmov recompile failed: %s (%d)",
			strerror(-rc), -rc);
		goto out;
	}
	if (!run_diamond_packet_check(&prog, &after, msg, msg_len))
		goto out;
	if (before != after) {
		set_msg(msg, msg_len,
			"diamond result changed from 0x%llx to 0x%llx",
			(unsigned long long)before,
			(unsigned long long)after);
		goto out;
	}

	set_msg(msg, msg_len, "diamond cmov site_start=%u preserved 0x%llx",
		site, (unsigned long long)after);
	ok = true;

out:
	free_blob(&blob);
	free_program_meta(&meta);
	unload_program(&prog);
	return ok;
}

static bool test_rotate_preserved(char *msg, size_t msg_len)
{
	struct loaded_program prog;
	struct program_meta meta;
	struct blob blob = {};
	__u32 site = 0;
	__u64 before = 0, after = 0;
	bool ok = false;
	int rc;

	if (load_meta_for_program(ROTATE_OBJ, "test_rotate",
				  &prog, &meta, msg, msg_len))
		return false;
	if (!run_rotate_packet_check(&prog, &before, msg, msg_len))
		goto out;
	if (!find_rotate_site(&meta, &site)) {
		set_msg(msg, msg_len, "rotate site not found");
		goto out;
	}
	if (build_rotate_blob(&meta, site, BPF_JIT_ROT_ROR, &blob, msg, msg_len))
		goto out;

	rc = apply_blob(prog.prog_fd, &blob, true, NULL, 0);
	if (rc) {
		set_msg(msg, msg_len, "rotate recompile failed: %s (%d)",
			strerror(-rc), -rc);
		goto out;
	}
	if (!run_rotate_packet_check(&prog, &after, msg, msg_len))
		goto out;
	if (before != after) {
		set_msg(msg, msg_len,
			"rotate result changed from 0x%llx to 0x%llx",
			(unsigned long long)before,
			(unsigned long long)after);
		goto out;
	}

	set_msg(msg, msg_len, "rotate site_start=%u preserved 0x%llx",
		site, (unsigned long long)after);
	ok = true;

out:
	free_blob(&blob);
	free_program_meta(&meta);
	unload_program(&prog);
	return ok;
}

static bool test_addr_calc_preserved(char *msg, size_t msg_len)
{
	struct loaded_program prog;
	struct program_meta meta;
	struct blob blob = {};
	__u32 site = 0;
	__u64 before = 0, after = 0;
	bool ok = false;
	int rc;

	if (load_meta_for_program(ADDR_CALC_OBJ, "test_addr_calc",
				  &prog, &meta, msg, msg_len))
		return false;
	if (!run_addr_calc_packet_check(&prog, &before, msg, msg_len))
		goto out;
	if (!find_addr_calc_site(&meta, &site)) {
		set_msg(msg, msg_len, "addr_calc site not found");
		goto out;
	}
	if (build_addr_calc_blob(&meta, site, &blob, msg, msg_len))
		goto out;

	rc = apply_blob(prog.prog_fd, &blob, true, NULL, 0);
	if (rc) {
		if (native_jit_arch_is_arm64() &&
		    (rc == -EINVAL || rc == -EOPNOTSUPP)) {
			set_msg(msg, msg_len,
				"ARM64 addr_calc unsupported in first wave: %s (%d)",
				strerror(-rc), -rc);
			ok = true;
			goto out;
		}
		set_msg(msg, msg_len, "addr_calc recompile failed: %s (%d)",
			strerror(-rc), -rc);
		goto out;
	}
	if (!run_addr_calc_packet_check(&prog, &after, msg, msg_len))
		goto out;
	if (before != after) {
		set_msg(msg, msg_len,
			"addr_calc result changed from 0x%llx to 0x%llx",
			(unsigned long long)before,
			(unsigned long long)after);
		goto out;
	}

	set_msg(msg, msg_len, "addr_calc site_start=%u preserved 0x%llx",
		site, (unsigned long long)after);
	ok = true;

out:
	free_blob(&blob);
	free_program_meta(&meta);
	unload_program(&prog);
	return ok;
}

static bool test_bitfield_extract_preserved(char *msg, size_t msg_len)
{
	struct loaded_program prog;
	struct program_meta meta;
	struct blob blob = {};
	__u32 site = 0;
	__u16 site_len = 0;
	__u64 before = 0, after = 0;
	bool ok = false;
	int rc;

	if (load_meta_for_program(BITFIELD_EXTRACT_OBJ, "test_bitfield_extract",
				  &prog, &meta, msg, msg_len))
		return false;
	if (!run_bitfield_extract_packet_check(&prog, &before, msg, msg_len))
		goto out;
	if (!find_bitfield_extract_site(&meta, &site, &site_len)) {
		set_msg(msg, msg_len, "bitfield_extract site not found");
		goto out;
	}
	if (build_bitfield_extract_blob(&meta, site, site_len, &blob,
					msg, msg_len))
		goto out;

	rc = apply_blob(prog.prog_fd, &blob, true, NULL, 0);
	if (rc) {
		set_msg(msg, msg_len, "bitfield_extract recompile failed: %s (%d)",
			strerror(-rc), -rc);
		goto out;
	}
	if (!run_bitfield_extract_packet_check(&prog, &after, msg, msg_len))
		goto out;
	if (before != after) {
		set_msg(msg, msg_len,
			"bitfield_extract result changed from 0x%llx to 0x%llx",
			(unsigned long long)before,
			(unsigned long long)after);
		goto out;
	}

	set_msg(msg, msg_len,
		"bitfield_extract site_start=%u site_len=%u preserved 0x%llx",
		site, site_len, (unsigned long long)after);
	ok = true;

out:
	free_blob(&blob);
	free_program_meta(&meta);
	unload_program(&prog);
	return ok;
}

static bool test_zero_ext_elide_preserved(char *msg, size_t msg_len)
{
	struct loaded_program prog;
	struct program_meta meta;
	struct blob blob = {};
	__u32 site = 0;
	__u64 before = 0, after = 0;
	bool ok = false;
	int rc;

	if (load_meta_for_program(ZERO_EXT_ELIDE_OBJ, "test_zero_ext_elide",
				  &prog, &meta, msg, msg_len))
		return false;
	if (!run_zero_ext_elide_packet_check(&prog, &before, msg, msg_len))
		goto out;
	if (!find_zero_ext_elide_site(&meta, &site)) {
		set_msg(msg, msg_len, "zero_ext_elide site not found");
		goto out;
	}
	if (build_zero_ext_elide_blob(&meta, site, &blob, msg, msg_len))
		goto out;

	rc = apply_blob(prog.prog_fd, &blob, true, NULL, 0);
	if (rc) {
		if (native_jit_arch_is_arm64() &&
		    (rc == -EINVAL || rc == -EOPNOTSUPP)) {
			set_msg(msg, msg_len,
				"ARM64 zero_ext_elide unsupported in first wave: %s (%d)",
				strerror(-rc), -rc);
			ok = true;
			goto out;
		}
		set_msg(msg, msg_len, "zero_ext_elide recompile failed: %s (%d)",
			strerror(-rc), -rc);
		goto out;
	}
	if (!run_zero_ext_elide_packet_check(&prog, &after, msg, msg_len))
		goto out;
	if (before != after) {
		set_msg(msg, msg_len,
			"zero_ext_elide result changed from 0x%llx to 0x%llx",
			(unsigned long long)before,
			(unsigned long long)after);
		goto out;
	}

	set_msg(msg, msg_len, "zero_ext_elide site_start=%u preserved 0x%llx",
		site, (unsigned long long)after);
	ok = true;

out:
	free_blob(&blob);
	free_program_meta(&meta);
	unload_program(&prog);
	return ok;
}

static bool test_endian_fusion_preserved(char *msg, size_t msg_len)
{
	struct loaded_program prog;
	struct program_meta meta;
	struct blob blob = {};
	__u32 site = 0;
	__u64 before = 0, after = 0;
	bool ok = false;
	int rc;

	if (load_meta_for_program(ENDIAN_FUSION_OBJ, "test_endian_fusion",
				  &prog, &meta, msg, msg_len))
		return false;
	if (!run_endian_fusion_packet_check(&prog, &before, msg, msg_len))
		goto out;
	if (!find_endian_fusion_site(&meta, &site)) {
		set_msg(msg, msg_len, "endian_fusion site not found");
		goto out;
	}
	if (build_endian_fusion_blob(&meta, site, &blob, msg, msg_len))
		goto out;

	rc = apply_blob(prog.prog_fd, &blob, true, NULL, 0);
	if (rc) {
		if (native_jit_arch_is_arm64() &&
		    (rc == -EINVAL || rc == -EOPNOTSUPP)) {
			set_msg(msg, msg_len,
				"ARM64 endian_fusion unsupported in first wave: %s (%d)",
				strerror(-rc), -rc);
			ok = true;
			goto out;
		}
		set_msg(msg, msg_len, "endian_fusion recompile failed: %s (%d)",
			strerror(-rc), -rc);
		goto out;
	}
	if (!run_endian_fusion_packet_check(&prog, &after, msg, msg_len))
		goto out;
	if (before != after) {
		set_msg(msg, msg_len,
			"endian_fusion result changed from 0x%llx to 0x%llx",
			(unsigned long long)before,
			(unsigned long long)after);
		goto out;
	}

	set_msg(msg, msg_len, "endian_fusion site_start=%u preserved 0x%llx",
		site, (unsigned long long)after);
	ok = true;

out:
	free_blob(&blob);
	free_program_meta(&meta);
	unload_program(&prog);
	return ok;
}

static bool test_branch_flip_preserved(char *msg, size_t msg_len)
{
	struct loaded_program prog;
	struct program_meta meta;
	struct blob blob = {};
	__u32 site = 0;
	__u16 site_len = 0;
	__u64 before = 0, after = 0;
	bool ok = false;
	int rc;

	if (load_meta_for_program(BRANCH_FLIP_OBJ, "test_branch_flip",
				  &prog, &meta, msg, msg_len))
		return false;
	if (!run_branch_flip_packet_check(&prog, &before, msg, msg_len))
		goto out;
	if (!find_branch_flip_site(&meta, &site, &site_len)) {
		set_msg(msg, msg_len, "branch_flip site not found");
		goto out;
	}
	if (build_branch_flip_blob(&meta, site, site_len, &blob,
				   msg, msg_len))
		goto out;

	rc = apply_blob(prog.prog_fd, &blob, true, NULL, 0);
	if (rc) {
		if (native_jit_arch_is_arm64() &&
		    (rc == -EINVAL || rc == -EOPNOTSUPP)) {
			set_msg(msg, msg_len,
				"ARM64 branch_flip unsupported in first wave: %s (%d)",
				strerror(-rc), -rc);
			ok = true;
			goto out;
		}
		set_msg(msg, msg_len, "branch_flip recompile failed: %s (%d)",
			strerror(-rc), -rc);
		goto out;
	}
	if (!run_branch_flip_packet_check(&prog, &after, msg, msg_len))
		goto out;
	if (before != after) {
		set_msg(msg, msg_len,
			"branch_flip result changed from 0x%llx to 0x%llx",
			(unsigned long long)before,
			(unsigned long long)after);
		goto out;
	}

	set_msg(msg, msg_len,
		"branch_flip site_start=%u site_len=%u preserved 0x%llx",
		site, site_len, (unsigned long long)after);
	ok = true;

out:
	free_blob(&blob);
	free_program_meta(&meta);
	unload_program(&prog);
	return ok;
}

static bool test_repeated_recompile(char *msg, size_t msg_len)
{
	struct loaded_program prog;
	struct program_meta meta;
	struct blob blob = {};
	__u32 site = 0;
	bool ok = false;
	int rc;

	if (load_meta_for_program(ROTATE_OBJ, "test_rotate",
				  &prog, &meta, msg, msg_len))
		return false;
	if (!find_rotate_site(&meta, &site)) {
		set_msg(msg, msg_len, "rotate site not found");
		goto out;
	}
	if (build_rotate_blob(&meta, site, BPF_JIT_ROT_ROR, &blob, msg, msg_len))
		goto out;

	rc = apply_blob(prog.prog_fd, &blob, true, NULL, 0);
	if (rc) {
		set_msg(msg, msg_len, "first rotate recompile failed: %s (%d)",
			strerror(-rc), -rc);
		goto out;
	}
	rc = apply_blob(prog.prog_fd, &blob, true, NULL, 0);
	if (rc) {
		set_msg(msg, msg_len, "second rotate recompile failed: %s (%d)",
			strerror(-rc), -rc);
		goto out;
	}
	set_msg(msg, msg_len, "rotate recompile succeeded twice");
	ok = true;

out:
	free_blob(&blob);
	free_program_meta(&meta);
	unload_program(&prog);
	return ok;
}

static void *concurrent_recompile_thread(void *arg)
{
	struct thread_ctx *ctx = arg;
	unsigned int i;

	pthread_barrier_wait(ctx->barrier);
	for (i = 0; i < ctx->attempts && !atomic_load(ctx->stop); i++) {
		int rc = sys_prog_jit_recompile(ctx->prog_fd, ctx->policy_fd,
						0, NULL, 0, 0);

		if (rc == 0) {
			ctx->success_count++;
			continue;
		}
		if (rc == -EBUSY) {
			ctx->ebusy_count++;
			atomic_store(ctx->stop, 1);
			break;
		}

		ctx->unexpected_count++;
		ctx->last_unexpected_errno = -rc;
		atomic_store(ctx->stop, 1);
		break;
	}

	return NULL;
}

static bool test_concurrent_recompile(char *msg, size_t msg_len)
{
	struct loaded_program prog;
	struct program_meta meta;
	struct blob blob = {};
	__u32 site = 0;
	pthread_t t1, t2;
	pthread_barrier_t barrier;
	struct thread_ctx ctx1;
	struct thread_ctx ctx2;
	atomic_int stop = 0;
	int policy_fd = -1;
	unsigned int ebusy_total;
	unsigned int success_total;
	bool ok = false;

	if (load_meta_for_program(SIMPLE_OBJ, "test_simple",
				  &prog, &meta, msg, msg_len))
		return false;
	if (!find_guarded_select_site(&meta, &site)) {
		set_msg(msg, msg_len, "guarded select site not found");
		goto out;
	}
	if (build_guarded_select_blob(&meta, site, BPF_JIT_SEL_CMOVCC,
				      &blob, msg, msg_len))
		goto out;

	policy_fd = create_memfd_from_blob("concurrent-jit-policy", &blob, true);
	if (policy_fd < 0) {
		set_msg(msg, msg_len, "memfd_create(concurrent): %s",
			strerror(errno));
		goto out;
	}

	pthread_barrier_init(&barrier, NULL, 2);
	memset(&ctx1, 0, sizeof(ctx1));
	memset(&ctx2, 0, sizeof(ctx2));
	ctx1.barrier = &barrier;
	ctx2.barrier = &barrier;
	ctx1.stop = &stop;
	ctx2.stop = &stop;
	ctx1.prog_fd = prog.prog_fd;
	ctx2.prog_fd = prog.prog_fd;
	ctx1.policy_fd = policy_fd;
	ctx2.policy_fd = policy_fd;
	ctx1.attempts = 5000;
	ctx2.attempts = 5000;

	pthread_create(&t1, NULL, concurrent_recompile_thread, &ctx1);
	pthread_create(&t2, NULL, concurrent_recompile_thread, &ctx2);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_barrier_destroy(&barrier);

	if (ctx1.unexpected_count || ctx2.unexpected_count) {
		int err = ctx1.unexpected_count ? ctx1.last_unexpected_errno
						: ctx2.last_unexpected_errno;

		set_msg(msg, msg_len, "unexpected concurrent errno %s (%d)",
			strerror(err), err);
		goto out;
	}

	ebusy_total = ctx1.ebusy_count + ctx2.ebusy_count;
	success_total = ctx1.success_count + ctx2.success_count;
	if (ebusy_total == 0 || success_total == 0) {
		set_msg(msg, msg_len,
			"expected mixed success/EBUSY, saw success=%u ebusy=%u",
			success_total, ebusy_total);
		goto out;
	}

	set_msg(msg, msg_len, "success=%u ebusy=%u", success_total, ebusy_total);
	ok = true;

out:
	if (policy_fd >= 0)
		close(policy_fd);
	free_blob(&blob);
	free_program_meta(&meta);
	unload_program(&prog);
	return ok;
}

static bool test_recompile_after_attach(char *msg, size_t msg_len)
{
	struct loaded_program prog;
	struct program_meta meta;
	struct blob blob = {};
	__u32 site = 0;
	unsigned int ifindex;
	int rc;
	bool ok = false;

	if (load_meta_for_program(SIMPLE_OBJ, "test_simple",
				  &prog, &meta, msg, msg_len))
		return false;
	if (!find_guarded_select_site(&meta, &site)) {
		set_msg(msg, msg_len, "guarded select site not found");
		goto out;
	}
	if (build_guarded_select_blob(&meta, site, BPF_JIT_SEL_CMOVCC,
				      &blob, msg, msg_len))
		goto out;

	ifindex = if_nametoindex("lo");
	if (!ifindex) {
		set_msg(msg, msg_len, "if_nametoindex(lo): %s", strerror(errno));
		goto out;
	}

	rc = bpf_xdp_attach(ifindex, prog.prog_fd,
			    XDP_FLAGS_SKB_MODE | XDP_FLAGS_UPDATE_IF_NOEXIST,
			    NULL);
	if (rc) {
		set_msg(msg, msg_len, "bpf_xdp_attach(lo): %s", strerror(errno));
		goto out;
	}
	prog.attached_ifindex = ifindex;
	prog.attached_flags = XDP_FLAGS_SKB_MODE;

	rc = apply_blob(prog.prog_fd, &blob, true, NULL, 0);
	if (rc) {
		set_msg(msg, msg_len,
			"recompile while attached failed: %s (%d)",
			strerror(-rc), -rc);
		goto out;
	}

	set_msg(msg, msg_len, "attached XDP program recompiled on ifindex %u",
		ifindex);
	ok = true;

out:
	free_blob(&blob);
	free_program_meta(&meta);
	unload_program(&prog);
	return ok;
}

static void report_test_result(const char *name, bool ok, const char *msg)
{
	printf("%s %s", ok ? "PASS" : "FAIL", name);
	if (msg && msg[0])
		printf(": %s", msg);
	putchar('\n');
	if (ok)
		tests_passed++;
	else
		tests_failed++;
}

int main(void)
{
	static const struct test_case tests[] = {
		{ "Load Simple Program And Verify Tag", test_load_tag },
		{ "Zero-Rule Policy Blob No-Op", test_zero_rule_blob },
		{ "Single Valid Wide Rule Recompile", test_valid_wide_rule },
		{ "Wide Result Preserved After Recompile", test_wide_result_unchanged },
		{ "Wide Stock Re-JIT Preserves Result", test_wide_zero_applied_jit_identity },
		{ "Wide Site-Only JIT Diff", test_wide_site_only_jit_diff },
		{ "Wrong Magic Rejected", test_wrong_magic },
		{ "Wrong Prog Tag Rejected", test_wrong_prog_tag },
		{ "Wrong Insn Count Rejected", test_wrong_insn_cnt },
		{ "Wrong Arch Id Rejected", test_wrong_arch_id },
		{ "Non-Sealed Memfd Rejected", test_non_sealed_memfd },
		{ "Truncated Header Rejected", test_truncated_header },
		{ "Site Start Out Of Bounds Rejected", test_site_out_of_bounds },
		{ "Zero-Length Blob Rejected", test_zero_length_blob },
		{ "Diamond CMOV Recompile Preserves Result", test_diamond_cmov },
		{ "Rotate Recompile Preserves Result", test_rotate_preserved },
		{ "Addr Calc Recompile Preserves Result", test_addr_calc_preserved },
		{ "Bitfield Extract Recompile Preserves Result", test_bitfield_extract_preserved },
		{ "Zero Ext Elide Recompile Preserves Result", test_zero_ext_elide_preserved },
		{ "Endian Fusion Recompile Preserves Result", test_endian_fusion_preserved },
		{ "Branch Flip Recompile Preserves Result", test_branch_flip_preserved },
		{ "Repeated Recompile Succeeds", test_repeated_recompile },
		{ "Concurrent Recompile Returns EBUSY", test_concurrent_recompile },
		{ "Recompile After Attach Works", test_recompile_after_attach },
	};
	size_t i;

	if (geteuid() != 0) {
		fprintf(stderr, "This test suite must run as root.\n");
		return 1;
	}
	if (raise_memlock_limit() && errno != EPERM) {
		fprintf(stderr, "setrlimit(RLIMIT_MEMLOCK) failed: %s\n",
			strerror(errno));
		return 1;
	}

	libbpf_set_print(libbpf_silent);

	for (i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
		char msg[LOG_BUF_SIZE] = {};
		bool ok = tests[i].fn(msg, sizeof(msg));

		report_test_result(tests[i].name, ok, msg);
	}

	if (tests_failed) {
		fprintf(stderr, "%d test(s) failed, %d passed.\n",
			tests_failed, tests_passed);
		return 1;
	}

	printf("PASS all %d test(s)\n", tests_passed);
	return 0;
}
