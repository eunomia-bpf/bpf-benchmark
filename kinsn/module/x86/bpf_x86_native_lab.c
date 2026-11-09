// SPDX-License-Identifier: GPL-2.0
/* Trusted service creates immutable linked P chunks; verifier and JIT use
 * these allocations through ordinary kernel handles. */
#include <linux/bpf.h>
#include <linux/btf.h>
#include <linux/bpf_verifier.h>
#include <linux/debugfs.h>
#include <linux/err.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/uaccess.h>
#include <linux/xarray.h>
#include <asm/extable.h>
#include <asm/extable_fixup_types.h>
#include <linux/ptrace.h>
#include "kinsn_x86_emit.h"
#include "native_lab_binding.h"
#define NATIVE_LAB_BINDING_ARCH NATIVE_LAB_ARCH_X86
#include "native_lab_trusted.h"
#define NATIVE_LAB_RELOC_HELPER_CALL_REL32 1
#define NATIVE_LAB_ABI_RBX 1U
#define NATIVE_LAB_ABI_R13 2U
#define NATIVE_LAB_ABI_R14 4U
#define NATIVE_LAB_ABI_R15 8U
struct native_lab_reloc_record { u32 offset, kind; u64 target; };
struct native_blob {
    struct list_head list;
    u32 id;
    u8 *bytes;
    size_t len, reloc_count, proof_len;
    struct native_lab_reloc_record *relocs;
    struct bpf_insn *proof;
    struct native_lab_load_site *load_sites;
    u32 load_site_count;
    struct bpf_map **maps;
    u32 map_count;
    struct native_lab_trusted_capsule *capsule;
};
static DEFINE_XARRAY_ALLOC(blobs);
static DEFINE_MUTEX(blobs_lock);
static struct dentry *debugfs_root;
#include "native_lab_group.h"

static void native_lab_free_blob(struct native_blob *blob)
{
    while (blob->map_count)
        bpf_map_put(blob->maps[--blob->map_count]);
    kfree(blob->maps);
    kvfree(blob->bytes);
    kvfree(blob->relocs);
    kvfree(blob->proof);
    kvfree(blob->load_sites);
    kfree(blob);
}
static void native_lab_free_chunks(struct native_lab_trusted_capsule *capsule)
{
    struct native_blob *blob, *next;
    mutex_lock(&blobs_lock);
    list_for_each_entry_safe(blob, next, &capsule->chunks, list) {
        xa_erase(&blobs, blob->id);
        list_del(&blob->list);
        native_lab_free_blob(blob);
    }
    mutex_unlock(&blobs_lock);
}
static int native_lab_store_chunk(void __user *argument)
{
    struct native_lab_trusted_chunk input;
    struct native_lab_trusted_capsule *capsule;
    struct native_blob *blob;
    size_t i;
    int err;
    if (copy_from_user(&input, argument, sizeof(input)))
        return -EFAULT;
    capsule = native_lab_active_capsule(input.request_id);
    if (IS_ERR(capsule))
        return PTR_ERR(capsule);
    blob = kzalloc(sizeof(*blob), GFP_KERNEL);
    if (!blob) { err = -ENOMEM; goto out; }
    blob->len = input.native_size;
    blob->proof_len = input.proof_insns;
    blob->reloc_count = input.reloc_count;
    blob->capsule = capsule;
    blob->load_site_count = input.load_site_count;
    if (blob->load_site_count) {
        blob->load_sites = vmemdup_user(u64_to_user_ptr(input.load_sites_user),
            array_size(blob->load_site_count, sizeof(*blob->load_sites)));
        if (IS_ERR(blob->load_sites)) {
            err = PTR_ERR(blob->load_sites); blob->load_sites = NULL; goto fail;
        }
    }
    blob->bytes = vmemdup_user(u64_to_user_ptr(input.native_user), blob->len);
    if (IS_ERR(blob->bytes)) { err = PTR_ERR(blob->bytes); blob->bytes = NULL; goto fail; }
    if (blob->reloc_count) {
        blob->relocs = vmemdup_user(u64_to_user_ptr(input.relocs_user),
            array_size(blob->reloc_count, sizeof(*blob->relocs)));
        if (IS_ERR(blob->relocs)) { err = PTR_ERR(blob->relocs); blob->relocs = NULL; goto fail; }
    }
    blob->proof = vmemdup_user(u64_to_user_ptr(input.proof_user),
        array_size(blob->proof_len, sizeof(*blob->proof)));
    if (IS_ERR(blob->proof)) { err = PTR_ERR(blob->proof); blob->proof = NULL; goto fail; }
    blob->maps = kcalloc(blob->reloc_count, sizeof(*blob->maps), GFP_KERNEL);
    if (!blob->maps && blob->reloc_count) { err = -ENOMEM; goto fail; }
    for (i = 0; i < blob->reloc_count; i++) {
        u32 id = (u32)blob->relocs[i].target;
        struct bpf_map *map;
        if (blob->relocs[i].kind != NATIVE_LAB_RELOC_MAP_POINTER &&
            blob->relocs[i].kind != NATIVE_LAB_RELOC_MAP_VALUE &&
            blob->relocs[i].kind != NATIVE_LAB_RELOC_READONLY_DATA)
            continue;
        map = bpf_map_get_curr_or_next(&id);
        if (!map || id != (u32)blob->relocs[i].target) {
            if (map) bpf_map_put(map);
            err = -ENOENT; goto fail;
        }
        blob->maps[blob->map_count++] = map;
    }
    mutex_lock(&blobs_lock);
    err = xa_alloc(&blobs, &blob->id, blob, XA_LIMIT(1, U32_MAX), GFP_KERNEL);
    if (!err) {
        list_add_tail(&blob->list, &capsule->chunks);
        capsule->release_chunks = native_lab_free_chunks;
        input.chunk_id = blob->id;
    }
    mutex_unlock(&blobs_lock);
    if (err) goto fail;
    err = copy_to_user(argument, &input, sizeof(input)) ? -EFAULT : 0;
    goto out;
fail:
    native_lab_free_blob(blob);
out:
    native_lab_trusted_put(capsule);
    return err;
}

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_native_lab_emit(u64 arg0) { (void)arg0; }
__bpf_kfunc_end_defs();
BTF_KFUNCS_START(bpf_x86_native_lab_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_native_lab_emit)
BTF_KFUNCS_END(bpf_x86_native_lab_kfunc_ids)

static int instantiate_native_lab(u64 payload, struct bpf_insn *insn_buf)
{
    struct native_blob *blob;
    u32 id, abi;
    int count;
    payload = kinsn_payload_decode(payload);
    id = payload >> 8;
    abi = (payload >> 4) & 15;
    mutex_lock(&blobs_lock);
    blob = xa_load(&blobs, id);
    if (!blob) { mutex_unlock(&blobs_lock); return -ENOENT; }
    count = blob->proof_len;
    if (insn_buf) {
        memcpy(insn_buf, blob->proof, count * sizeof(*insn_buf));
        if (abi & NATIVE_LAB_ABI_RBX) insn_buf[count++] = BPF_MOV64_REG(BPF_REG_6, BPF_REG_0);
        if (abi & NATIVE_LAB_ABI_R13) insn_buf[count++] = BPF_MOV64_REG(BPF_REG_7, BPF_REG_0);
        if (abi & NATIVE_LAB_ABI_R14) insn_buf[count++] = BPF_MOV64_REG(BPF_REG_8, BPF_REG_0);
        if (abi & NATIVE_LAB_ABI_R15) insn_buf[count++] = BPF_MOV64_REG(BPF_REG_9, BPF_REG_0);
    } else count += hweight32(abi);
    mutex_unlock(&blobs_lock);
    return count;
}
static void native_lab_emit_error(const char *reason, int err, u64 payload,
				  u32 blob_id, size_t blob_len,
				  size_t reloc_count, size_t reloc_index,
				  u32 reloc_offset, u32 reloc_kind,
				  u64 reloc_target)
{
	pr_err_ratelimited("bpf_x86_native_lab: emit failed reason=%s err=%d payload=0x%llx blob=%u len=%zu relocs=%zu reloc_index=%zu reloc_offset=%u reloc_kind=%u reloc_target=0x%llx\n",
			   reason, err, (unsigned long long)payload, blob_id,
			   blob_len, reloc_count, reloc_index, reloc_offset,
			   reloc_kind, (unsigned long long)reloc_target);
}


static int emit_native_lab_x86(u8 *image, u32 *off, bool emit, u64 payload,
                              const struct bpf_prog *prog, const u8 *final_ip)
{
    struct native_blob *blob;
    size_t snapshot_len;
    u32 blob_id;
    int err = 0;
    payload = kinsn_payload_decode(payload);
    blob_id = payload >> 8;
    mutex_lock(&blobs_lock);
    blob = xa_load(&blobs, blob_id);
    if (!blob) { mutex_unlock(&blobs_lock); return -ENOENT; }
    err = native_lab_retain_program(blob->capsule, prog);
    if (err) { mutex_unlock(&blobs_lock); return err; }
    snapshot_len = blob->len;
    if (emit) {
			u8 *emit_at = image + *off;
			const u8 *final_emit_at = final_ip ? final_ip + *off : NULL;
			size_t i;

			memcpy(emit_at, blob->bytes, snapshot_len);

			/* Apply each side-band relocation after the blob lands in
			 * final JIT memory.
			 */
			for (i = 0; i < blob->reloc_count; i++) {
				const struct native_lab_reloc_record *r =
					&blob->relocs[i];
				switch (r->kind) {
				case NATIVE_LAB_RELOC_READONLY_DATA:
					/* Immutable-data binding metadata; emits no patch. */
					break;
				case NATIVE_LAB_RELOC_MAP_POINTER:
				case NATIVE_LAB_RELOC_MAP_VALUE:
				case NATIVE_LAB_RELOC_HELPER_POINTER:
					err = native_lab_emit_literal(r,
						blob->bytes, snapshot_len, emit_at, blob->maps, blob->map_count);
					break;

				case NATIVE_LAB_RELOC_X86_TAIL_COUNT:
				case NATIVE_LAB_RELOC_X86_TAIL_STACK: {
					u32 depth = prog->aux->priv_stack_ptr ? 0 : round_up(prog->aux->stack_depth, 8);
					s32 value = r->kind == NATIVE_LAB_RELOC_X86_TAIL_COUNT ? -16 - depth : depth;

					memcpy(emit_at + r->offset, &value, sizeof(value));
					break;
				}

				case NATIVE_LAB_RELOC_HELPER_CALL_REL32: {
					u64 slot_va;
					u64 rip_after;
					s64 disp64;
					s32 disp;

					if ((size_t)r->offset + 5 >
					    snapshot_len) {
						err = -ERANGE;
						native_lab_emit_error("reloc_bounds", err,
								      payload, blob_id,
								      snapshot_len,
								      blob->reloc_count,
								      i, r->offset,
								      r->kind, r->target);
						break;
					}
					if (!final_emit_at) {
						err = -EINVAL;
						native_lab_emit_error("missing_final_ip",
								      err, payload,
								      blob_id,
								      snapshot_len,
								      blob->reloc_count,
								      i, r->offset,
								      r->kind, r->target);
						break;
					}
					slot_va = (u64)final_emit_at + r->offset;
					rip_after = slot_va + 5;
					disp64 = (s64)r->target - (s64)rip_after;
					disp = (s32)disp64;
					if ((s64)disp != disp64) {
						err = -ERANGE;
						native_lab_emit_error("rel32_out_of_range",
								      err, payload,
								      blob_id,
								      snapshot_len,
								      blob->reloc_count,
								      i, r->offset,
								      r->kind, r->target);
						break;
					}
					memcpy(emit_at + r->offset + 1, &disp, 4);
					break;
				}
				default:
					err = -EINVAL;
					native_lab_emit_error("unknown_reloc_kind",
							      err, payload,
							      blob_id, snapshot_len,
							      blob->reloc_count,
							      i, r->offset,
							      r->kind, r->target);
					break;
				}
				if (err)
					break;
			}
			if (err) {
				mutex_unlock(&blobs_lock);
				return err;
			}
		}
    mutex_unlock(&blobs_lock);
    *off += snapshot_len;
    return snapshot_len;
}
static u32 native_lab_num_exentries(u64 payload)
{
    struct native_blob *blob;
    u32 count = 0;
    mutex_lock(&blobs_lock);
    blob = xa_load(&blobs, kinsn_payload_decode(payload) >> 8);
    if (blob) count = blob->load_site_count;
    mutex_unlock(&blobs_lock);
    return count;
}

static int native_lab_emit_exentries(u64 payload, void *rw_table,
                                    const void *rx_table, const void *native_ip)
{
    static const u16 registers[] = {
        offsetof(struct pt_regs, ax), offsetof(struct pt_regs, cx),
        offsetof(struct pt_regs, dx), offsetof(struct pt_regs, bx),
        offsetof(struct pt_regs, sp), offsetof(struct pt_regs, bp),
        offsetof(struct pt_regs, si), offsetof(struct pt_regs, di),
        offsetof(struct pt_regs, r8), offsetof(struct pt_regs, r9),
        offsetof(struct pt_regs, r10), offsetof(struct pt_regs, r11),
        offsetof(struct pt_regs, r12), offsetof(struct pt_regs, r13),
        offsetof(struct pt_regs, r14), offsetof(struct pt_regs, r15),
    };
    struct exception_table_entry *rw = rw_table;
    const struct exception_table_entry *rx = rx_table;
    struct native_blob *blob;
    u32 i;
    int count;
    mutex_lock(&blobs_lock);
    blob = xa_load(&blobs, kinsn_payload_decode(payload) >> 8);
    if (!blob) { mutex_unlock(&blobs_lock); return -ENOENT; }
    count = blob->load_site_count;
    for (i = 0; i < blob->load_site_count; i++) {
        const struct native_lab_load_site *site = &blob->load_sites[i];
        u32 reg = site->destination < ARRAY_SIZE(registers) ?
            registers[site->destination] : 1; /* stock DONT_CLEAR */
        rw[i].insn = (const u8 *)native_ip + site->offset - (const u8 *)&rx[i].insn;
        rw[i].fixup = site->insn_len | (reg << 8);
        rw[i].data = EX_TYPE_BPF;
    }
    mutex_unlock(&blobs_lock);
    return count;
}

const struct bpf_kinsn bpf_x86_native_lab_desc = {
    .owner = THIS_MODULE, .max_insn_cnt = U32_MAX,
    .native_proof = true,
    .instantiate_insn = instantiate_native_lab, .emit_x86 = emit_native_lab_x86,
    .num_exentries = native_lab_num_exentries,
    .emit_exentries = native_lab_emit_exentries,
};
static const struct bpf_kinsn * const bpf_x86_native_lab_kinsn_descs[] = { &bpf_x86_native_lab_desc };
struct map_ptr_file_priv {
	char response[32];
	size_t len;
};

static int map_ptr_open(struct inode *inode, struct file *file)
{
	struct map_ptr_file_priv *priv;

	priv = kzalloc(sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;
	file->private_data = priv;
	return 0;
}

static int map_ptr_release(struct inode *inode, struct file *file)
{
	kfree(file->private_data);
	return 0;
}

static ssize_t map_ptr_query_write(struct file *file, const char __user *ubuf,
				   size_t len, loff_t *ppos, bool direct_value,
				   bool update_elem)
{
	struct map_ptr_file_priv *priv = file->private_data;
	struct bpf_map *map;
	unsigned long ptr;
	unsigned int fd;
	char buf[32];
	int err;

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

	ptr = (unsigned long)map;
	if (direct_value) {
		u64 value = 0;

		if (!map->ops || !map->ops->map_direct_value_addr) {
			err = -EOPNOTSUPP;
			goto out_put;
		}
		err = map->ops->map_direct_value_addr(map, &value, 0);
		if (err)
			goto out_put;
		ptr = (unsigned long)value;
	} else if (update_elem) {
		if (!map->ops || !map->ops->map_update_elem) {
			err = -EOPNOTSUPP;
			goto out_put;
		}
		ptr = (unsigned long)map->ops->map_update_elem;
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
	return map_ptr_query_write(file, ubuf, len, ppos, false, false);
}

static ssize_t map_value_ptr_write(struct file *file, const char __user *ubuf,
				   size_t len, loff_t *ppos)
{
	return map_ptr_query_write(file, ubuf, len, ppos, true, false);
}

static ssize_t map_update_elem_write(struct file *file, const char __user *ubuf,
				     size_t len, loff_t *ppos)
{
	return map_ptr_query_write(file, ubuf, len, ppos, false, true);
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

static const struct file_operations map_update_elem_fops = {
	.owner = THIS_MODULE,
	.open = map_ptr_open,
	.release = map_ptr_release,
	.read = map_ptr_read,
	.write = map_update_elem_write,
	.llseek = default_llseek,
};

static const struct btf_kfunc_id_set bpf_x86_native_lab_kfunc_set = {
    .owner = THIS_MODULE, .set = &bpf_x86_native_lab_kfunc_ids,
    .kinsn_descs = bpf_x86_native_lab_kinsn_descs,
};
static int __init bpf_x86_native_lab_init(void)
{
    int err;
    debugfs_root = debugfs_create_dir("bpf_x86_native_lab", NULL);
    if (IS_ERR(debugfs_root)) return PTR_ERR(debugfs_root);
    debugfs_create_file("native_submit", 0600, debugfs_root, NULL, &native_lab_trusted_fops);
    debugfs_create_file("specializer", 0600, debugfs_root, (void *)1, &native_lab_trusted_fops);
    debugfs_create_file("map_ptr", 0600, debugfs_root, NULL, &map_ptr_fops);
    debugfs_create_file("map_value_ptr", 0600, debugfs_root, NULL, &map_value_ptr_fops);
    debugfs_create_file("map_update_elem", 0600, debugfs_root, NULL, &map_update_elem_fops);
    err = register_btf_kfunc_id_set(BPF_PROG_TYPE_UNSPEC, &bpf_x86_native_lab_kfunc_set);
    if (err) debugfs_remove_recursive(debugfs_root);
    return err;
}
static void __exit bpf_x86_native_lab_exit(void)
{
    debugfs_remove_recursive(debugfs_root);
    xa_destroy(&blobs);
}
module_init(bpf_x86_native_lab_init);
module_exit(bpf_x86_native_lab_exit);
MODULE_DESCRIPTION("NativeSim trusted native path");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("BpfReJIT");
MODULE_IMPORT_NS("BPF_INTERNAL");
