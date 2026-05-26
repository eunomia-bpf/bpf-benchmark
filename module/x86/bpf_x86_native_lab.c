// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 native-code lab kinsn.
 *
 * Test-only escape hatch: lets userspace upload an arbitrary x86-64 byte
 * sequence (a "native blob") and then have a BPF program splat those bytes
 * inline at JIT time via a kinsn. The verifier sees only a trivial proof
 * (`r0 = blob_id`); the actual emitted x86 is whatever userspace handed in.
 *
 * Use cases:
 *  - Establish a hand-tuned "pure native" performance lower bound to compare
 *    against the production kinsn passes.
 *  - Bring up new optimization ideas at the x86 level without going through
 *    bpfopt+kinsn+REJIT first.
 *
 * Safety: this module disables every verifier guarantee for any BPF program
 * that calls into it. Do NOT load on production kernels. Upload requires
 * CAP_SYS_ADMIN, the debugfs nodes are root-only by default, and the module
 * intentionally has no in-tree Kconfig: build it out-of-tree on purpose.
 *
 * ABI considerations the caller must respect:
 *  - Blob is splatted in the middle of a JITted BPF function. It must reach
 *    the next BPF insn by falling through (no `ret`). To return a value from
 *    the BPF program, set rax in the blob and follow with BPF `exit`.
 *  - Callee-saved registers (rbx, rbp, r12-r15) map to BPF r6-r10 and to the
 *    BPF JIT frame pointer; clobber them only if the surrounding BPF program
 *    doesn't use those registers. native-link may strip RBX/R13-R15 saves from
 *    the blob only when the sidecar ABI mask below asks the JIT proof to mark
 *    the corresponding BPF callee-saved regs as used, forcing the BPF JIT
 *    prologue/epilogue to preserve the host registers.
 *  - Caller-saved (rdi, rsi, rdx, rcx, r8, r9, r10, r11) and rax are free.
 *  - The kfunc takes a single u64 argument so the BPF program can stage one
 *    value (e.g. a context pointer cast to u64) into rdi before the call.
 */

#include <linux/bpf.h>
#include <linux/debugfs.h>
#include <linux/err.h>
#include <linux/filter.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/uaccess.h>

#include "kinsn_x86_emit.h"

#define NATIVE_LAB_MAX_BLOBS	512
/*
 * BPF_MAX_INSN_SIZE in arch/x86/net/bpf_jit_comp.c bounds a single kinsn
 * emit at 128 bytes. Userspace uploads longer programs as multiple
 * back-to-back sidecar/call pairs.
 */
#define NATIVE_LAB_MAX_BLOB_BYTES	128

/*
 * Stage 2 side-band relocations:
 *
 * Userspace native-link can't compute a helper call's rel32 displacement,
 * because that depends on where the BPF JIT will splat the blob. The blob
 * ships a `call rel32` placeholder and a separate `relocs` array describing
 * each patch site. After memcpy'ing the blob bytes into the JIT image,
 * emit_x86 patches the displacement. Out-of-range targets fail load instead
 * of falling back to an indirect call.
 *
 * relocs are uploaded via a sibling debugfs file blob<N>.relocs whose
 * payload is a tightly packed array of `struct native_lab_reloc_record`.
 */
#define NATIVE_LAB_RELOC_HELPER_CALL_REL32	1
#define NATIVE_LAB_MAX_RELOCS		32
#define NATIVE_LAB_MAP_GEN_MAX_INSN	256
#define NATIVE_LAB_ABI_RBX		(1U << 0)
#define NATIVE_LAB_ABI_R13		(1U << 1)
#define NATIVE_LAB_ABI_R14		(1U << 2)
#define NATIVE_LAB_ABI_R15		(1U << 3)
#define NATIVE_LAB_ABI_MASK		(NATIVE_LAB_ABI_RBX | \
					 NATIVE_LAB_ABI_R13 | \
					 NATIVE_LAB_ABI_R14 | \
					 NATIVE_LAB_ABI_R15)

struct native_lab_reloc_record {
	__u32 offset;   /* byte offset of the helper call placeholder */
	__u32 kind;     /* NATIVE_LAB_RELOC_* */
	__u64 target;   /* absolute kernel address */
};

struct native_blob {
	u8 *bytes;
	size_t len;
	struct native_lab_reloc_record *relocs;
	size_t reloc_count;
};

static struct native_blob blobs[NATIVE_LAB_MAX_BLOBS];
static DEFINE_MUTEX(blobs_lock);
static struct dentry *debugfs_root;

__bpf_kfunc_start_defs();
/*
 * The BPF stub. Verifier sees an empty void kfunc taking one u64; the JIT
 * never actually calls it because the kinsn descriptor below provides
 * emit_x86. The argument exists so BPF code can stage a value into rdi
 * before the call, which the blob can then consume.
 */
__bpf_kfunc void bpf_x86_native_lab_emit(u64 arg0)
{
	(void)arg0;
}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_native_lab_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_native_lab_emit)
BTF_KFUNCS_END(bpf_x86_native_lab_kfunc_ids)

static int decode_native_lab_payload(u64 payload, u32 *blob_id, u32 *abi_mask)
{
	payload = kinsn_payload_decode(payload);

	if (payload & 0xf)
		return -EINVAL;
	if (((payload >> 4) & 0xf) & ~NATIVE_LAB_ABI_MASK)
		return -EINVAL;
	if ((payload >> 8) & 0xfff)
		return -EINVAL;

	*blob_id = (u32)(payload >> 20);
	if (*blob_id >= NATIVE_LAB_MAX_BLOBS)
		return -EINVAL;
	if (abi_mask)
		*abi_mask = (u32)((payload >> 4) & 0xf);

	return 0;
}

/*
 * Verifier-side proof. We claim the kinsn is equivalent to `r0 = 0`.
 * This is a deliberate lie: the blob can produce any value or side
 * effect. validate_kinsn_proof_seq() accepts single ALU64 writes, and
 * constant 0 is a valid return value for every BPF program type the
 * paper benchmark uses (XDP_ABORTED, TC_ACT_OK, CGROUP_SKB_DROP, plain
 * socket_filter retval, ...). The native blob's actual `rax` value at
 * the rewritten exit decides the real retval at runtime.
 */
static int instantiate_native_lab(u64 payload, struct bpf_insn *insn_buf)
{
	u32 abi_mask = 0;
	u32 blob_id;
	int err;
	int cnt = 0;

	err = decode_native_lab_payload(payload, &blob_id, &abi_mask);
	if (err)
		return err;

	if (abi_mask & NATIVE_LAB_ABI_RBX)
		insn_buf[cnt++] = BPF_MOV64_REG(BPF_REG_6, BPF_REG_1);
	if (abi_mask & NATIVE_LAB_ABI_R13)
		insn_buf[cnt++] = BPF_MOV64_REG(BPF_REG_7, BPF_REG_1);
	if (abi_mask & NATIVE_LAB_ABI_R14)
		insn_buf[cnt++] = BPF_MOV64_REG(BPF_REG_8, BPF_REG_1);
	if (abi_mask & NATIVE_LAB_ABI_R15)
		insn_buf[cnt++] = BPF_MOV64_REG(BPF_REG_9, BPF_REG_1);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_MOV, BPF_REG_0, 0);
	return cnt;
}

static int emit_native_lab_x86(u8 *image, u32 *off, bool emit, u64 payload,
			       const struct bpf_prog *prog,
			       const u8 *final_ip)
{
	size_t snapshot_len = 0;
	u32 blob_id;
	int err;

	(void)prog;

	err = decode_native_lab_payload(payload, &blob_id, NULL);
	if (err)
		return err;

	mutex_lock(&blobs_lock);
	if (blobs[blob_id].bytes && blobs[blob_id].len) {
		snapshot_len = blobs[blob_id].len;
		if (snapshot_len > NATIVE_LAB_MAX_BLOB_BYTES) {
			mutex_unlock(&blobs_lock);
			return -E2BIG;
		}
		if (emit) {
			u8 *emit_at = image + *off;
			const u8 *final_emit_at = final_ip ? final_ip + *off : NULL;
			size_t i;

			memcpy(emit_at, blobs[blob_id].bytes, snapshot_len);

			/* Apply each side-band relocation after the blob lands in
			 * final JIT memory.
			 */
			for (i = 0; i < blobs[blob_id].reloc_count; i++) {
				const struct native_lab_reloc_record *r =
					&blobs[blob_id].relocs[i];
				switch (r->kind) {
				case NATIVE_LAB_RELOC_HELPER_CALL_REL32: {
					static const u8 rel32_slot[5] = {
						0xe8, 0, 0, 0, 0
					};
					u64 slot_va;
					u64 rip_after;
					s64 disp64;
					s32 disp;

					if ((size_t)r->offset + sizeof(rel32_slot) >
					    snapshot_len) {
						err = -ERANGE;
						break;
					}
					if (memcmp(emit_at + r->offset, rel32_slot,
						   sizeof(rel32_slot))) {
						err = -EINVAL;
						break;
					}
					if (!final_emit_at) {
						err = -EINVAL;
						break;
					}
					slot_va = (u64)final_emit_at + r->offset;
					rip_after = slot_va + 5;
					disp64 = (s64)r->target - (s64)rip_after;
					disp = (s32)disp64;
					if ((s64)disp != disp64) {
						err = -ERANGE;
						break;
					}
					memcpy(emit_at + r->offset + 1, &disp, 4);
					break;
				}
				default:
					err = -EINVAL;
					break;
				}
				if (err)
					break;
			}
			if (err) {
				const struct native_lab_reloc_record *r =
					i < blobs[blob_id].reloc_count ?
					&blobs[blob_id].relocs[i] : NULL;
				pr_err_ratelimited("bpf_x86_native_lab: emit failed blob=%u len=%zu reloc=%zu/%zu err=%d offset=%u kind=%u target=0x%llx final=0x%llx\n",
						   blob_id, snapshot_len, i,
						   blobs[blob_id].reloc_count,
						   err, r ? r->offset : 0,
						   r ? r->kind : 0,
						   r ? r->target : 0,
						   final_emit_at && r ?
						   (u64)(final_emit_at + r->offset) : 0);
				mutex_unlock(&blobs_lock);
				return err;
			}
		}
	}
	mutex_unlock(&blobs_lock);

	if (!snapshot_len) {
		pr_err_ratelimited("bpf_x86_native_lab: emit missing blob=%u\n",
				   blob_id);
		return -ENOENT;
	}

	*off += snapshot_len;
	return snapshot_len;
}

const struct bpf_kinsn bpf_x86_native_lab_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5,
	.max_emit_bytes = NATIVE_LAB_MAX_BLOB_BYTES,
	.instantiate_insn = instantiate_native_lab,
	.emit_x86 = emit_native_lab_x86,
};

static const struct bpf_kinsn * const bpf_x86_native_lab_kinsn_descs[] = {
	&bpf_x86_native_lab_desc,
};

/* ---- debugfs: /sys/kernel/debug/bpf_x86_native_lab/blob<id> ----
 *
 * Write: overwrite blob N with raw bytes (max NATIVE_LAB_MAX_BLOB_BYTES).
 * Truncate to zero length: unregister blob N.
 * Read: read back current blob bytes (debug aid).
 */

struct blob_file_priv {
	u32 id;
};

enum map_ptr_query_kind {
	MAP_PTR_QUERY_MAP = 0,
	MAP_PTR_QUERY_VALUE = 1,
	MAP_PTR_QUERY_LOOKUP = 2,
	MAP_PTR_QUERY_UPDATE = 3,
	MAP_PTR_QUERY_DELETE = 4,
	MAP_PTR_QUERY_LOOKUP_GEN = 5,
	MAP_PTR_QUERY_LOOKUP_ELEM = 6,
};

struct map_ptr_file_priv {
	char response[8192];
	size_t len;
	enum map_ptr_query_kind kind;
};

static int map_lookup_gen_insns(struct bpf_map *map, struct bpf_insn *insns)
{
	int cnt;

	if (!map->ops || !map->ops->map_gen_lookup)
		return -EOPNOTSUPP;
	cnt = map->ops->map_gen_lookup(map, insns);
	if (cnt <= 0)
		return cnt ?: -EINVAL;
	if (cnt > NATIVE_LAB_MAP_GEN_MAX_INSN)
		return -E2BIG;
	return cnt;
}

static int map_lookup_gen_call_target(struct bpf_map *map, unsigned long *ptr)
{
	struct bpf_insn *insns;
	int cnt, i;

	insns = kcalloc(NATIVE_LAB_MAP_GEN_MAX_INSN, sizeof(*insns), GFP_KERNEL);
	if (!insns)
		return -ENOMEM;
	cnt = map_lookup_gen_insns(map, insns);
	if (cnt < 0)
		goto out;

	for (i = 0; i < cnt; i++) {
		if (insns[i].code == (BPF_JMP | BPF_CALL) &&
		    insns[i].src_reg == 0) {
			*ptr = (unsigned long)__bpf_call_base + insns[i].imm;
			cnt = 0;
			goto out;
		}
	}
	cnt = -ENOENT;
out:
	kfree(insns);
	return cnt;
}

static int map_lookup_gen_response(struct bpf_map *map,
				   struct map_ptr_file_priv *priv)
{
	struct bpf_insn *insns;
	const u8 *bytes;
	size_t byte_len;
	int cnt, pos;
	size_t i;

	insns = kcalloc(NATIVE_LAB_MAP_GEN_MAX_INSN, sizeof(*insns), GFP_KERNEL);
	if (!insns)
		return -ENOMEM;
	cnt = map_lookup_gen_insns(map, insns);
	if (cnt < 0)
		goto out;

	bytes = (const u8 *)insns;
	byte_len = cnt * sizeof(struct bpf_insn);
	pos = scnprintf(priv->response, sizeof(priv->response), "%d ", cnt);
	for (i = 0; i < byte_len; i++) {
		if (pos + 3 >= sizeof(priv->response)) {
			cnt = -E2BIG;
			goto out;
		}
		pos += scnprintf(priv->response + pos,
				 sizeof(priv->response) - pos,
				 "%02x", bytes[i]);
	}
	if (pos + 2 >= sizeof(priv->response)) {
		cnt = -E2BIG;
		goto out;
	}
	priv->response[pos++] = '\n';
	priv->response[pos] = '\0';
	priv->len = pos;
	cnt = 0;
out:
	kfree(insns);
	return cnt;
}

static ssize_t blob_write(struct file *file, const char __user *ubuf,
			  size_t len, loff_t *ppos)
{
	struct blob_file_priv *priv = file->private_data;
	u8 *kbuf = NULL;

	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;

	if (*ppos)
		return -EINVAL; /* whole-file writes only */

	if (len > NATIVE_LAB_MAX_BLOB_BYTES)
		return -E2BIG;

	if (len) {
		kbuf = kmalloc(len, GFP_KERNEL);
		if (!kbuf)
			return -ENOMEM;
		if (copy_from_user(kbuf, ubuf, len)) {
			kfree(kbuf);
			return -EFAULT;
		}
	}

	mutex_lock(&blobs_lock);
	kfree(blobs[priv->id].bytes);
	/* Reuploading the blob invalidates any previously uploaded relocs. */
	kfree(blobs[priv->id].relocs);
	blobs[priv->id].relocs = NULL;
	blobs[priv->id].reloc_count = 0;
	blobs[priv->id].bytes = kbuf;
	blobs[priv->id].len = len;
	mutex_unlock(&blobs_lock);

	*ppos = len;
	return len;
}

/*
 * relocs debugfs file: whole-file write of a packed array of
 * native_lab_reloc_record. Truncate to 0 to clear.
 */
static ssize_t relocs_write(struct file *file, const char __user *ubuf,
			    size_t len, loff_t *ppos)
{
	struct blob_file_priv *priv = file->private_data;
	struct native_lab_reloc_record *kbuf = NULL;
	size_t count;

	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;
	if (*ppos)
		return -EINVAL;
	if (len % sizeof(struct native_lab_reloc_record))
		return -EINVAL;
	count = len / sizeof(struct native_lab_reloc_record);
	if (count > NATIVE_LAB_MAX_RELOCS)
		return -E2BIG;

	if (len) {
		kbuf = kmalloc(len, GFP_KERNEL);
		if (!kbuf)
			return -ENOMEM;
		if (copy_from_user(kbuf, ubuf, len)) {
			kfree(kbuf);
			return -EFAULT;
		}
	}

	mutex_lock(&blobs_lock);
	kfree(blobs[priv->id].relocs);
	blobs[priv->id].relocs = kbuf;
	blobs[priv->id].reloc_count = count;
	mutex_unlock(&blobs_lock);

	*ppos = len;
	return len;
}

static ssize_t blob_read(struct file *file, char __user *ubuf, size_t len,
			 loff_t *ppos)
{
	struct blob_file_priv *priv = file->private_data;
	u8 stash[NATIVE_LAB_MAX_BLOB_BYTES];
	size_t copy_len;
	size_t blen;

	mutex_lock(&blobs_lock);
	blen = blobs[priv->id].len;
	if (blen)
		memcpy(stash, blobs[priv->id].bytes, blen);
	mutex_unlock(&blobs_lock);

	if (*ppos >= blen)
		return 0;
	copy_len = min(len, blen - (size_t)*ppos);
	if (copy_to_user(ubuf, stash + *ppos, copy_len))
		return -EFAULT;
	*ppos += copy_len;
	return copy_len;
}

static int blob_open(struct inode *inode, struct file *file)
{
	struct blob_file_priv *priv;
	long id = (long)inode->i_private;

	priv = kmalloc(sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;
	priv->id = (u32)id;
	file->private_data = priv;
	return 0;
}

static int blob_release(struct inode *inode, struct file *file)
{
	kfree(file->private_data);
	return 0;
}

static const struct file_operations blob_fops = {
	.owner = THIS_MODULE,
	.open = blob_open,
	.release = blob_release,
	.read = blob_read,
	.write = blob_write,
	.llseek = default_llseek,
};

static const struct file_operations relocs_fops = {
	.owner = THIS_MODULE,
	.open = blob_open,
	.release = blob_release,
	.write = relocs_write,
	.llseek = default_llseek,
};

static int map_ptr_open(struct inode *inode, struct file *file)
{
	struct map_ptr_file_priv *priv;

	priv = kzalloc(sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;
	priv->kind = (enum map_ptr_query_kind)(unsigned long)inode->i_private;
	file->private_data = priv;
	return 0;
}

static int map_ptr_release(struct inode *inode, struct file *file)
{
	kfree(file->private_data);
	return 0;
}

static ssize_t map_ptr_query_write(struct file *file, const char __user *ubuf,
				   size_t len, loff_t *ppos)
{
	struct map_ptr_file_priv *priv = file->private_data;
	struct bpf_map *map;
	unsigned long ptr;
	unsigned int fd;
	char buf[32];
	int err;

	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;
	if (*ppos)
		return -EINVAL;
	if (!len || len >= sizeof(buf))
		return -EINVAL;
	if (copy_from_user(buf, ubuf, len))
		return -EFAULT;
	buf[len] = '\0';

	err = kstrtouint(buf, 0, &fd);
	if (err)
		return err;

	map = bpf_map_get(fd);
	if (IS_ERR(map))
		return PTR_ERR(map);

	switch (priv->kind) {
	case MAP_PTR_QUERY_MAP:
		ptr = (unsigned long)map;
		break;
	case MAP_PTR_QUERY_VALUE: {
		u64 value = 0;

		if (!map->ops || !map->ops->map_direct_value_addr) {
			err = -EOPNOTSUPP;
			goto out_put;
		}
		err = map->ops->map_direct_value_addr(map, &value, 0);
		if (err)
			goto out_put;
		ptr = (unsigned long)value;
		break;
	}
	case MAP_PTR_QUERY_LOOKUP:
		err = map_lookup_gen_call_target(map, &ptr);
		if (err)
			goto out_put;
		break;
	case MAP_PTR_QUERY_LOOKUP_ELEM:
		if (!map->ops || !map->ops->map_lookup_elem) {
			err = -EOPNOTSUPP;
			goto out_put;
		}
		ptr = (unsigned long)map->ops->map_lookup_elem;
		break;
	case MAP_PTR_QUERY_LOOKUP_GEN:
		err = map_lookup_gen_response(map, priv);
		if (err)
			goto out_put;
		err = len;
		goto out_put;
		break;
	case MAP_PTR_QUERY_UPDATE:
		if (!map->ops || !map->ops->map_update_elem) {
			err = -EOPNOTSUPP;
			goto out_put;
		}
		ptr = (unsigned long)map->ops->map_update_elem;
		break;
	case MAP_PTR_QUERY_DELETE:
		if (!map->ops || !map->ops->map_delete_elem) {
			err = -EOPNOTSUPP;
			goto out_put;
		}
		ptr = (unsigned long)map->ops->map_delete_elem;
		break;
	default:
		err = -EINVAL;
		goto out_put;
	}

	priv->len = scnprintf(priv->response, sizeof(priv->response),
			      "0x%llx\n", (unsigned long long)ptr);
	err = len;
out_put:
	bpf_map_put(map);
	if (err < 0)
		return err;
	*ppos = len;
	return err;
}

static ssize_t map_ptr_write(struct file *file, const char __user *ubuf,
			     size_t len, loff_t *ppos)
{
	return map_ptr_query_write(file, ubuf, len, ppos);
}

static ssize_t map_value_ptr_write(struct file *file, const char __user *ubuf,
				   size_t len, loff_t *ppos)
{
	return map_ptr_query_write(file, ubuf, len, ppos);
}

static ssize_t map_ptr_read(struct file *file, char __user *ubuf, size_t len,
			    loff_t *ppos)
{
	struct map_ptr_file_priv *priv = file->private_data;

	return simple_read_from_buffer(ubuf, len, ppos, priv->response,
				       priv->len);
}

static const struct file_operations map_ptr_fops = {
	.owner = THIS_MODULE,
	.open = map_ptr_open,
	.release = map_ptr_release,
	.read = map_ptr_read,
	.write = map_ptr_write,
	.llseek = default_llseek,
};

static const struct file_operations map_value_ptr_fops = {
	.owner = THIS_MODULE,
	.open = map_ptr_open,
	.release = map_ptr_release,
	.read = map_ptr_read,
	.write = map_value_ptr_write,
	.llseek = default_llseek,
};

static const struct file_operations map_lookup_ptr_fops = {
	.owner = THIS_MODULE,
	.open = map_ptr_open,
	.release = map_ptr_release,
	.read = map_ptr_read,
	.write = map_ptr_write,
	.llseek = default_llseek,
};

static const struct file_operations map_update_ptr_fops = {
	.owner = THIS_MODULE,
	.open = map_ptr_open,
	.release = map_ptr_release,
	.read = map_ptr_read,
	.write = map_ptr_write,
	.llseek = default_llseek,
};

static const struct file_operations map_delete_ptr_fops = {
	.owner = THIS_MODULE,
	.open = map_ptr_open,
	.release = map_ptr_release,
	.read = map_ptr_read,
	.write = map_ptr_write,
	.llseek = default_llseek,
};

static int __init bpf_x86_native_lab_debugfs_init(void)
{
	long i;

	debugfs_root = debugfs_create_dir("bpf_x86_native_lab", NULL);
	if (IS_ERR(debugfs_root))
		return PTR_ERR(debugfs_root);

	debugfs_create_file("map_ptr", 0600, debugfs_root,
			    (void *)MAP_PTR_QUERY_MAP,
			    &map_ptr_fops);
	debugfs_create_file("map_value_ptr", 0600, debugfs_root,
			    (void *)MAP_PTR_QUERY_VALUE,
			    &map_value_ptr_fops);
	debugfs_create_file("map_lookup_ptr", 0600, debugfs_root,
			    (void *)MAP_PTR_QUERY_LOOKUP,
			    &map_lookup_ptr_fops);
	debugfs_create_file("map_lookup_gen", 0600, debugfs_root,
			    (void *)MAP_PTR_QUERY_LOOKUP_GEN,
			    &map_lookup_ptr_fops);
	debugfs_create_file("map_lookup_elem_ptr", 0600, debugfs_root,
			    (void *)MAP_PTR_QUERY_LOOKUP_ELEM,
			    &map_lookup_ptr_fops);
	debugfs_create_file("map_update_ptr", 0600, debugfs_root,
			    (void *)MAP_PTR_QUERY_UPDATE,
			    &map_update_ptr_fops);
	debugfs_create_file("map_delete_ptr", 0600, debugfs_root,
			    (void *)MAP_PTR_QUERY_DELETE,
			    &map_delete_ptr_fops);

	for (i = 0; i < NATIVE_LAB_MAX_BLOBS; i++) {
		char name[24];

		scnprintf(name, sizeof(name), "blob%ld", i);
		debugfs_create_file(name, 0600, debugfs_root, (void *)i,
				    &blob_fops);
		scnprintf(name, sizeof(name), "blob%ld.relocs", i);
		debugfs_create_file(name, 0600, debugfs_root, (void *)i,
				    &relocs_fops);
	}
	return 0;
}

static void bpf_x86_native_lab_debugfs_exit(void)
{
	int i;

	debugfs_remove_recursive(debugfs_root);
	debugfs_root = NULL;

	mutex_lock(&blobs_lock);
	for (i = 0; i < NATIVE_LAB_MAX_BLOBS; i++) {
		kfree(blobs[i].bytes);
		kfree(blobs[i].relocs);
		blobs[i].bytes = NULL;
		blobs[i].len = 0;
		blobs[i].relocs = NULL;
		blobs[i].reloc_count = 0;
	}
	mutex_unlock(&blobs_lock);
}

static const struct btf_kfunc_id_set bpf_x86_native_lab_kfunc_set = {
	.owner = THIS_MODULE,
	.set = &bpf_x86_native_lab_kfunc_ids,
	.kinsn_descs = bpf_x86_native_lab_kinsn_descs,
};

static int __init bpf_x86_native_lab_init(void)
{
	int err;

	err = bpf_x86_native_lab_debugfs_init();
	if (err)
		return err;

	err = register_btf_kfunc_id_set(BPF_PROG_TYPE_UNSPEC,
					&bpf_x86_native_lab_kfunc_set);
	if (err) {
		bpf_x86_native_lab_debugfs_exit();
		return err;
	}

	return 0;
}

static void __exit bpf_x86_native_lab_exit(void)
{
	bpf_x86_native_lab_debugfs_exit();
}

module_init(bpf_x86_native_lab_init);
module_exit(bpf_x86_native_lab_exit);

MODULE_DESCRIPTION("BpfReJIT x86 native-code lab kinsn (test only; bypasses verifier guarantees)");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("BpfReJIT");
MODULE_IMPORT_NS("BPF_INTERNAL");
