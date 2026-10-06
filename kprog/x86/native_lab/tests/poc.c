// SPDX-License-Identifier: GPL-2.0
/*
 * Userspace POC for the bpf_x86_native_lab kop module.
 *
 *   1. Upload a hand-written x86 byte blob into debugfs slot 0.
 *   2. Load a tiny BPF program that calls the native_lab kop:
 *
 *          r1 = imm                ; argument staged into rdi
 *          sidecar(blob_id=0)
 *          call bpf_x86_native_lab_emit
 *          exit
 *
 *      The kop replaces the call site with the blob's bytes verbatim.
 *      The blob sets rax (= BPF r0) and falls through into the BPF exit
 *      epilogue, so the program returns whatever the blob put in rax.
 *
 *   3. Run via BPF_PROG_TEST_RUN and report the returned value.
 *
 * Build: see Makefile in this directory.
 * Run as root after `insmod bpf_x86_native_lab.ko`.
 *
 * BPF_PROG_TEST_RUN is used here only to verify the mechanism end-to-end.
 * Per CLAUDE.md, real latency measurements must come from realistic
 * attached workloads, not synthetic TEST_RUN injection.
 */

#define _GNU_SOURCE
#include <bpf/btf.h>
#include <bpf/libbpf.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/bpf.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#define MODULE_NAME			"bpf_x86_native_lab"
#define KFUNC_NAME			"bpf_x86_native_lab_emit"
#define DEBUGFS_BLOB_TPL		"/sys/kernel/debug/bpf_x86_native_lab/blob%u"
#define MODULE_BTF_PATH			"/sys/kernel/btf/" MODULE_NAME
#define VMLINUX_BTF_PATH		"/sys/kernel/btf/vmlinux"

#ifndef BPF_PSEUDO_KOP_SIDECAR
#define BPF_PSEUDO_KOP_SIDECAR	3
#endif
#ifndef BPF_PSEUDO_KOP_CALL
#define BPF_PSEUDO_KOP_CALL		4
#endif

#define BPF_ALU64			0x07
#define BPF_MOV				0xb0
#define BPF_K				0x00
#define BPF_JMP				0x05
#define BPF_CALL			0x80
#define BPF_EXIT			0x90

#ifndef BPF_REG_0
#define BPF_REG_0			0
#define BPF_REG_1			1
#endif

struct bpf_insn_native {
	uint8_t	code;
	uint8_t	dst_src;	/* dst_reg in low 4 bits, src_reg in high 4 */
	int16_t	off;
	int32_t	imm;
};

static int sys_bpf(enum bpf_cmd cmd, union bpf_attr *attr, unsigned int size)
{
	return syscall(__NR_bpf, cmd, attr, size);
}

static int upload_blob(unsigned int blob_id, const void *bytes, size_t len)
{
	char path[128];
	int fd;
	ssize_t n;

	snprintf(path, sizeof(path), DEBUGFS_BLOB_TPL, blob_id);
	fd = open(path, O_WRONLY | O_TRUNC);
	if (fd < 0) {
		fprintf(stderr, "open(%s): %s\n", path, strerror(errno));
		return -1;
	}
	n = write(fd, bytes, len);
	close(fd);
	if (n != (ssize_t)len) {
		fprintf(stderr, "write(%s, %zu): got %zd: %s\n", path, len, n,
			strerror(errno));
		return -1;
	}
	return 0;
}

static int resolve_kfunc_btf_id(int *btf_fd_out)
{
	struct btf *vmlinux, *mod;
	int id;

	vmlinux = btf__parse(VMLINUX_BTF_PATH, NULL);
	if (libbpf_get_error(vmlinux)) {
		fprintf(stderr, "btf__parse(vmlinux): %s\n",
			strerror(-libbpf_get_error(vmlinux)));
		return -1;
	}
	mod = btf__parse_split(MODULE_BTF_PATH, vmlinux);
	if (libbpf_get_error(mod)) {
		fprintf(stderr, "btf__parse_split(%s): %s\n", MODULE_NAME,
			strerror(-libbpf_get_error(mod)));
		btf__free(vmlinux);
		return -1;
	}

	id = btf__find_by_name_kind(mod, KFUNC_NAME, BTF_KIND_FUNC);
	if (id < 0) {
		fprintf(stderr, "%s not found in module BTF: %s\n", KFUNC_NAME,
			strerror(-id));
		btf__free(mod);
		btf__free(vmlinux);
		return -1;
	}

	*btf_fd_out = btf__load_into_kernel(mod);
	/* btf__load_into_kernel reuses an existing fd if the BTF is already
	 * registered (which it is, the module loaded it); for parse-from-file
	 * we just need any fd that names this BTF. Easier: open it directly.
	 */
	if (*btf_fd_out < 0) {
		/* Fallback: get a module BTF fd via BPF_BTF_GET_FD_BY_ID after
		 * iterating BPF_BTF_GET_NEXT_ID. Cheaper here: just dup the
		 * sysfs file descriptor. The kernel accepts an fd referring to
		 * the module's BTF binary.
		 */
		*btf_fd_out = open(MODULE_BTF_PATH, O_RDONLY | O_CLOEXEC);
		if (*btf_fd_out < 0) {
			fprintf(stderr, "open(%s): %s\n", MODULE_BTF_PATH,
				strerror(errno));
			btf__free(mod);
			btf__free(vmlinux);
			return -1;
		}
	}

	btf__free(mod);
	btf__free(vmlinux);
	return id;
}

/*
 * Resolve the module's in-kernel BTF id (the id the kernel internally
 * assigns to the loaded module) and obtain a kernel fd for it. The
 * fd_array slot must reference the kernel-side BTF, not a userspace-parsed
 * copy. Iterate BPF_BTF_GET_NEXT_ID looking for a match by name.
 */
static int find_module_btf_fd(void)
{
	__u32 id = 0;
	int fd = -1;

	for (;;) {
		union bpf_attr attr = {};
		struct bpf_btf_info info = {};
		char name[64] = {};

		attr.start_id = id;
		if (sys_bpf(BPF_BTF_GET_NEXT_ID, &attr,
			    sizeof(attr.start_id) + sizeof(attr.next_id)) < 0) {
			if (errno == ENOENT)
				break;
			fprintf(stderr, "BPF_BTF_GET_NEXT_ID: %s\n",
				strerror(errno));
			return -1;
		}
		id = attr.next_id;

		memset(&attr, 0, sizeof(attr));
		attr.btf_id = id;
		fd = sys_bpf(BPF_BTF_GET_FD_BY_ID, &attr, sizeof(attr));
		if (fd < 0)
			continue;

		info.name = (uintptr_t)name;
		info.name_len = sizeof(name);
		memset(&attr, 0, sizeof(attr));
		attr.info.bpf_fd = fd;
		attr.info.info_len = sizeof(info);
		attr.info.info = (uintptr_t)&info;
		if (sys_bpf(BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) == 0) {
			if (strcmp(name, MODULE_NAME) == 0)
				return fd;
		}
		close(fd);
		fd = -1;
	}

	fprintf(stderr, "module BTF for %s not registered in kernel\n",
		MODULE_NAME);
	return -1;
}

/*
 * Splice an arbitrarily-sized native blob into the BPF program by uploading
 * 128-byte chunks to consecutive blob_ids starting at first_blob_id, and
 * emitting one sidecar+call pair per chunk. The JIT splats chunks back-to-
 * back into the image, so the runtime sees a single contiguous run of
 * native code.
 */
#define NATIVE_LAB_CHUNK_BYTES	128

static int build_and_load_prog(int kfunc_btf_id, int mod_btf_fd,
			       int return_imm, unsigned int first_blob_id,
			       unsigned int chunk_count)
{
	/* Layout:
	 *   mov r1, return_imm                    ; 1 insn (stages rdi)
	 *   for each chunk i in [0, chunk_count):
	 *       sidecar(blob_id = first_blob_id+i)
	 *       call kop bpf_x86_native_lab_emit
	 *   exit                                  ; 1 insn
	 *
	 * Sidecar payload mapping (see linux/bpf.h bpf_kop_sidecar_payload):
	 *   payload = (dst_reg & 0xf)
	 *           | ((u16)off << 4)
	 *           | ((u32)imm << 20)
	 * decode_native_lab_payload reads `payload >> 20` for blob_id, so we
	 * encode blob_id directly into the sidecar's `imm` field.
	 */
	if (chunk_count == 0) {
		fprintf(stderr, "build_and_load_prog: chunk_count must be > 0\n");
		return -1;
	}

	size_t insn_cnt = 1u + 2u * chunk_count + 1u;
	struct bpf_insn_native *insns = calloc(insn_cnt, sizeof(*insns));
	if (!insns) {
		fprintf(stderr, "calloc failed\n");
		return -1;
	}

	size_t idx = 0;
	insns[idx++] = (struct bpf_insn_native){
		.code = BPF_ALU64 | BPF_MOV | BPF_K,
		.dst_src = (uint8_t)(BPF_REG_1 & 0xf),
		.off = 0,
		.imm = return_imm,
	};
	for (unsigned int i = 0; i < chunk_count; i++) {
		insns[idx++] = (struct bpf_insn_native){
			.code = BPF_ALU64 | BPF_MOV | BPF_K,
			.dst_src = (uint8_t)((BPF_PSEUDO_KOP_SIDECAR & 0xf) << 4),
			.off = 0,
			.imm = (int32_t)(first_blob_id + i),
		};
		insns[idx++] = (struct bpf_insn_native){
			.code = BPF_JMP | BPF_CALL,
			.dst_src = (uint8_t)((BPF_PSEUDO_KOP_CALL & 0xf) << 4),
			.off = 1,
			.imm = kfunc_btf_id,
		};
	}
	insns[idx++] = (struct bpf_insn_native){
		.code = BPF_JMP | BPF_EXIT,
		.dst_src = 0,
		.off = 0,
		.imm = 0,
	};

	/*
	 * fd_array[0] must be a valid fd: the verifier pre-scans the array
	 * even when no maps reference it. fd_array[1] is the module BTF fd
	 * that off=1 in the kop call insn addresses. Duplicating the BTF
	 * fd into slot 0 satisfies the verifier's fd_array pre-scan.
	 */
	int fd_array[2] = { mod_btf_fd, mod_btf_fd };
	char log_buf[16 * 1024] = {};
	union bpf_attr attr = {};

	attr.prog_type = BPF_PROG_TYPE_SOCKET_FILTER;
	attr.insn_cnt = (uint32_t)insn_cnt;
	attr.insns = (uintptr_t)insns;
	attr.license = (uintptr_t)"GPL";
	attr.log_level = 1;
	attr.log_size = sizeof(log_buf);
	attr.log_buf = (uintptr_t)log_buf;
	attr.fd_array = (uintptr_t)fd_array;

	int fd = sys_bpf(BPF_PROG_LOAD, &attr, sizeof(attr));
	free(insns);
	if (fd < 0) {
		fprintf(stderr, "BPF_PROG_LOAD failed: %s\nverifier log:\n%s\n",
			strerror(errno), log_buf);
		return -1;
	}
	return fd;
}

static int run_prog(int prog_fd, uint32_t *retval_out)
{
	uint8_t pkt_in[64] = {};
	uint8_t pkt_out[64] = {};
	union bpf_attr attr = {};

	/*
	 * The kernel rejects test_run with ctx_size_in==0 but ctx_in!=NULL
	 * (and vice versa) with EINVAL. Leave ctx_{in,out} unset since the
	 * blob doesn't consume ctx fields.
	 */
	attr.test.prog_fd = prog_fd;
	attr.test.data_size_in = sizeof(pkt_in);
	attr.test.data_in = (uintptr_t)pkt_in;
	attr.test.data_size_out = sizeof(pkt_out);
	attr.test.data_out = (uintptr_t)pkt_out;
	attr.test.repeat = 1;

	if (sys_bpf(BPF_PROG_TEST_RUN, &attr, sizeof(attr)) < 0) {
		fprintf(stderr, "BPF_PROG_TEST_RUN: %s\n", strerror(errno));
		return -1;
	}
	*retval_out = attr.test.retval;
	return 0;
}

int main(int argc, char **argv)
{
	/* Default blob: `mov eax, 0x2a; ret-less` -- but the JIT continues
	 * past the blob to the BPF exit, so no ret. We only need:
	 *
	 *   mov eax, 42        ; B8 2A 00 00 00      (5 bytes)
	 *
	 * BPF JIT epilogue picks rax up as the program return value.
	 */
	uint8_t default_blob[] = { 0xB8, 0x2A, 0x00, 0x00, 0x00 };
	const uint8_t *blob = default_blob;
	size_t blob_len = sizeof(default_blob);
	uint8_t *user_blob = NULL;
	uint32_t expected = 42;

	if (argc > 1) {
		FILE *fp = fopen(argv[1], "rb");
		if (!fp) {
			fprintf(stderr, "fopen(%s): %s\n", argv[1],
				strerror(errno));
			return 1;
		}
		fseek(fp, 0, SEEK_END);
		long n = ftell(fp);
		fseek(fp, 0, SEEK_SET);
		if (n <= 0) {
			fprintf(stderr, "blob size %ld invalid\n", n);
			fclose(fp);
			return 1;
		}
		user_blob = malloc(n);
		if (fread(user_blob, 1, n, fp) != (size_t)n) {
			fprintf(stderr, "short read on %s\n", argv[1]);
			fclose(fp);
			free(user_blob);
			return 1;
		}
		fclose(fp);
		blob = user_blob;
		blob_len = n;
		expected = 0; /* unknown */
	}
	if (argc > 2)
		expected = (uint32_t)strtoul(argv[2], NULL, 0);

	unsigned int chunk_count = (unsigned int)((blob_len + NATIVE_LAB_CHUNK_BYTES - 1)
						  / NATIVE_LAB_CHUNK_BYTES);
	if (chunk_count == 0)
		chunk_count = 1;
	if (chunk_count > 512) {
		fprintf(stderr, "blob requires %u chunks; module supports 512\n",
			chunk_count);
		goto out_free;
	}

	printf("uploading %zu-byte blob as %u chunk(s) of <=%d bytes\n",
	       blob_len, chunk_count, NATIVE_LAB_CHUNK_BYTES);
	for (unsigned int i = 0; i < chunk_count; i++) {
		size_t offset = (size_t)i * NATIVE_LAB_CHUNK_BYTES;
		size_t this_len = blob_len - offset;
		if (this_len > NATIVE_LAB_CHUNK_BYTES)
			this_len = NATIVE_LAB_CHUNK_BYTES;
		if (upload_blob(i, blob + offset, this_len))
			goto out_free;
	}

	int mod_btf_fd = find_module_btf_fd();
	if (mod_btf_fd < 0)
		goto out_free;

	int dummy_fd = -1;
	int kfunc_id = resolve_kfunc_btf_id(&dummy_fd);
	if (dummy_fd >= 0)
		close(dummy_fd);
	if (kfunc_id < 0) {
		close(mod_btf_fd);
		goto out_free;
	}
	printf("kfunc %s btf_id=%d module_btf_fd=%d\n", KFUNC_NAME, kfunc_id,
	       mod_btf_fd);

	int prog_fd = build_and_load_prog(kfunc_id, mod_btf_fd, 7, 0,
					  chunk_count);
	if (prog_fd < 0) {
		close(mod_btf_fd);
		goto out_free;
	}

	uint32_t retval = 0;
	if (run_prog(prog_fd, &retval) == 0) {
		printf("BPF_PROG_TEST_RUN returned retval = %u (0x%x)\n",
		       retval, retval);
		if (expected && retval == expected)
			printf("OK: blob executed in kernel (retval=%u)\n",
			       retval);
		else if (expected)
			printf("FAIL: expected %u, got %u\n", expected, retval);
		else
			printf("OK: blob ran (no expected value to check)\n");
	}

	close(prog_fd);
	close(mod_btf_fd);

out_free:
	free(user_blob);
	return 0;
}
