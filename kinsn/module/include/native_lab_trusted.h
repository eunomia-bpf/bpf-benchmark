/* SPDX-License-Identifier: GPL-2.0 */
#ifndef NATIVE_LAB_TRUSTED_H
#define NATIVE_LAB_TRUSTED_H
#include <linux/elf.h>
#include <linux/kref.h>
#include <linux/list.h>
#include <linux/pid.h>
#include <linux/sched.h>
#include <linux/wait.h>
#include "native_lab_trusted_wire.h"

/* One immutable native submission, retained independently by its request,
 * sealed chunks and every program that emits those chunks. */
struct native_lab_trusted_capsule {
	struct kref refs;
	u64 id;
	struct bpf_prog *source;
	struct bpf_map **resource_maps;
	u32 resource_count;
	void *native, *metadata;
	char *entry;
	u32 native_size, metadata_size, entry_size;
	struct list_head chunks;
	void (*release_chunks)(struct native_lab_trusted_capsule *);
};
struct native_lab_trusted_job {
	struct kref refs;
	struct list_head pending;
	struct native_lab_trusted_capsule *capsule;
	struct bpf_prog *result;
	wait_queue_head_t wait;
	int status;
	bool done, abandoned;
};
struct native_lab_trusted_file {
	bool service;
	struct native_lab_trusted_job *job;
};
static DEFINE_MUTEX(native_lab_service_lock);
static LIST_HEAD(native_lab_service_pending);
static DECLARE_WAIT_QUEUE_HEAD(native_lab_service_wait);
static atomic_t native_lab_pending_count = ATOMIC_INIT(0);
static struct file *native_lab_service_file;
static struct native_lab_trusted_job *native_lab_service_active;
static u64 native_lab_request_sequence;

static void native_lab_capsule_release(struct kref *ref)
{
	struct native_lab_trusted_capsule *capsule = container_of(ref,
		struct native_lab_trusted_capsule, refs);
	u32 i;
	if (capsule->release_chunks)
		capsule->release_chunks(capsule);
	for (i = 0; i < capsule->resource_count; i++)
		bpf_map_put(capsule->resource_maps[i]);
	kfree(capsule->resource_maps);
	if (capsule->source)
		bpf_prog_put(capsule->source);
	kvfree(capsule->native);
	kvfree(capsule->metadata);
	kfree(capsule->entry);
	kfree(capsule);
}
static void native_lab_trusted_put(void *pointer)
{
	struct native_lab_trusted_capsule *capsule = pointer;
	if (capsule)
		kref_put(&capsule->refs, native_lab_capsule_release);
}
static void native_lab_job_release(struct kref *ref)
{
	struct native_lab_trusted_job *job = container_of(ref,
		struct native_lab_trusted_job, refs);
	if (job->result)
		bpf_prog_put(job->result);
	native_lab_trusted_put(job->capsule);
	kfree(job);
}
static void native_lab_job_put(struct native_lab_trusted_job *job)
{
	if (job)
		kref_put(&job->refs, native_lab_job_release);
}
static int native_lab_store_chunk(void __user *argument);

/* Called under blobs_lock by the actual native JIT callback. The core owns
 * the callback module reference until after it releases the capsule. */
static int native_lab_retain_program(struct native_lab_trusted_capsule *capsule,
		const struct bpf_prog *prog)
{
	if (prog->aux->native_trusted_request)
		return 0;
	if (!try_module_get(THIS_MODULE))
		return -ENODEV;
	kref_get(&capsule->refs);
	prog->aux->native_trusted_request = capsule;
	prog->aux->native_trusted_put = native_lab_trusted_put;
	prog->aux->native_trusted_owner = THIS_MODULE;
	return 0;
}

/* Each successful FD resolution pins the actual kernel object. Capsule
 * release handles every partial-copy, queue and completion failure path. */
static int native_lab_snapshot_resources(struct native_lab_trusted_capsule *capsule,
		const struct native_lab_trusted_submission *submission)
{
	s32 *fds;
	u32 i;
	int err = 0;
	if (!submission->map_count)
		return 0;
	fds = memdup_user(u64_to_user_ptr(submission->map_fds_user),
		array_size(submission->map_count, sizeof(*fds)));
	if (IS_ERR(fds))
		return PTR_ERR(fds);
	capsule->resource_maps = kcalloc(submission->map_count,
		sizeof(*capsule->resource_maps), GFP_KERNEL);
	if (!capsule->resource_maps) {
		err = -ENOMEM;
		goto out;
	}
	for (i = 0; i < submission->map_count; i++) {
		struct bpf_map *map = bpf_map_get(fds[i]);
		if (IS_ERR(map)) {
			err = PTR_ERR(map);
			goto out;
		}
		capsule->resource_maps[capsule->resource_count++] = map;
	}
out:
	kfree(fds);
	return err;
}

static int native_lab_trusted_submit(struct native_lab_trusted_file *owner,
		void __user *argument, bool resources)
{
	struct native_lab_trusted_request request;
	struct native_lab_trusted_submission submission = {};
	struct native_lab_trusted_capsule *capsule;
	struct native_lab_trusted_job *job;
	int err;
	mutex_lock(&native_lab_service_lock);
	err = owner->job ? -EBUSY : 0;
	mutex_unlock(&native_lab_service_lock);
	if (err)
		return err;
	if (resources) {
		if (copy_from_user(&submission, argument, sizeof(submission)))
			return -EFAULT;
		request = submission.request;
	} else if (copy_from_user(&request, argument, sizeof(request))) {
		return -EFAULT;
	}
	capsule = kzalloc(sizeof(*capsule), GFP_KERNEL);
	if (!capsule)
		return -ENOMEM;
	kref_init(&capsule->refs);
	INIT_LIST_HEAD(&capsule->chunks);
	capsule->source = bpf_prog_by_id(request.source_prog_id);
	if (IS_ERR(capsule->source)) {
		err = PTR_ERR(capsule->source);
		capsule->source = NULL;
		goto fail;
	}
	capsule->native = vmemdup_user(u64_to_user_ptr(request.native_user), request.native_size);
	if (IS_ERR(capsule->native)) {
		err = PTR_ERR(capsule->native);
		capsule->native = NULL;
		goto fail;
	}
	capsule->entry = memdup_user_nul(u64_to_user_ptr(request.entry_user), request.entry_size);
	if (IS_ERR(capsule->entry)) {
		err = PTR_ERR(capsule->entry);
		capsule->entry = NULL;
		goto fail;
	}
	if (request.metadata_size) {
		capsule->metadata = vmemdup_user(u64_to_user_ptr(request.metadata_user), request.metadata_size);
		if (IS_ERR(capsule->metadata)) {
			err = PTR_ERR(capsule->metadata);
			capsule->metadata = NULL;
			goto fail;
		}
	}
	err = native_lab_snapshot_resources(capsule, &submission);
	if (err)
		goto fail;
	capsule->native_size = request.native_size;
	capsule->entry_size = request.entry_size;
	capsule->metadata_size = request.metadata_size;
	job = kzalloc(sizeof(*job), GFP_KERNEL);
	if (!job) {
		err = -ENOMEM;
		goto fail;
	}
	kref_init(&job->refs);
	INIT_LIST_HEAD(&job->pending);
	init_waitqueue_head(&job->wait);
	job->status = -EINPROGRESS;
	job->capsule = capsule;
	mutex_lock(&native_lab_service_lock);
	if (owner->job)
		err = -EBUSY;
	else if (!native_lab_service_file)
		err = -ENOTCONN;
	else if (native_lab_request_sequence == U64_MAX)
		err = -EOVERFLOW;
	else {
		capsule->id = ++native_lab_request_sequence;
		request.request_id = capsule->id;
		if (copy_to_user(argument, &request, sizeof(request)))
			err = -EFAULT;
		else {
			owner->job = job;
			list_add_tail(&job->pending, &native_lab_service_pending);
			atomic_inc(&native_lab_pending_count);
			err = 0;
		}
	}
	mutex_unlock(&native_lab_service_lock);
	if (err)
		native_lab_job_put(job);
	else
		wake_up_interruptible(&native_lab_service_wait);
	return err;
fail:
	native_lab_trusted_put(capsule);
	return err;
}

static int native_lab_trusted_next(void __user *argument)
{
	struct native_lab_trusted_request request;
	struct native_lab_trusted_capsule *capsule;
	struct native_lab_trusted_job *job;
	u32 native_capacity, entry_capacity, metadata_capacity;
	int err;
	if (copy_from_user(&request, argument, sizeof(request)))
		return -EFAULT;
	native_capacity = request.native_size;
	entry_capacity = request.entry_size;
	metadata_capacity = request.metadata_size;
again:
	err = wait_event_interruptible(native_lab_service_wait,
		atomic_read(&native_lab_pending_count) || READ_ONCE(native_lab_service_active) || !READ_ONCE(native_lab_service_file));
	if (err)
		return err;
	mutex_lock(&native_lab_service_lock);
	if (!native_lab_service_file) {
		err = -ENOTCONN;
		goto out;
	}
	if (native_lab_service_active) {
		err = -EBUSY;
		goto out;
	}
	if (list_empty(&native_lab_service_pending)) {
		mutex_unlock(&native_lab_service_lock);
		goto again;
	}
	job = list_first_entry(&native_lab_service_pending, struct native_lab_trusted_job, pending);
	capsule = job->capsule;
	request.arch = NATIVE_LAB_BINDING_ARCH;
	request.source_prog_id = capsule->source->aux->id;
	request.request_id = capsule->id;
	request.native_size = capsule->native_size;
	request.entry_size = capsule->entry_size;
	request.metadata_size = capsule->metadata_size;
	if (copy_to_user(argument, &request, sizeof(request))) {
		err = -EFAULT;
		goto out;
	}
	if (native_capacity < request.native_size || entry_capacity < request.entry_size ||
	    metadata_capacity < request.metadata_size) {
		err = -EMSGSIZE;
		goto out;
	}
	if (copy_to_user(u64_to_user_ptr(request.native_user), capsule->native, request.native_size) ||
	    copy_to_user(u64_to_user_ptr(request.entry_user), capsule->entry, request.entry_size) ||
	    (request.metadata_size && copy_to_user(u64_to_user_ptr(request.metadata_user),
		capsule->metadata, request.metadata_size))) {
		err = -EFAULT;
		goto out;
	}
	list_del_init(&job->pending);
	atomic_dec(&native_lab_pending_count);
	kref_get(&job->refs);
	native_lab_service_active = job;
	err = 0;
out:
	mutex_unlock(&native_lab_service_lock);
	return err;
}

static int native_lab_trusted_activate(void __user *argument)
{
    struct native_lab_trusted_activate activate;
    int err = 0;
    if (copy_from_user(&activate, argument, sizeof(activate)))
        return -EFAULT;
    mutex_lock(&native_lab_service_lock);
    if (!native_lab_service_active ||
        native_lab_service_active->capsule->id != activate.request_id)
        err = -ENOENT;
    mutex_unlock(&native_lab_service_lock);
    return err;
}

static int native_lab_trusted_complete(void __user *argument)
{
	struct native_lab_trusted_result result;
	struct native_lab_trusted_job *job;
	struct bpf_prog *prog = NULL;
	int err = 0;
	if (copy_from_user(&result, argument, sizeof(result)))
		return -EFAULT;
	mutex_lock(&native_lab_service_lock);
	job = native_lab_service_active;
	if (!job || job->capsule->id != result.request_id) {
		err = -ENOENT;
		goto out;
	}
	if (!result.status) {
		prog = bpf_prog_by_id(result.prog_id);
		if (IS_ERR(prog)) {
			err = PTR_ERR(prog);
			prog = NULL;
			goto out;
		}
	}
	job->status = job->abandoned ? -ECANCELED : result.status;
	job->result = prog;
	prog = NULL;
	WRITE_ONCE(job->done, true);
	native_lab_service_active = NULL;
	wake_up_interruptible(&job->wait);
	mutex_unlock(&native_lab_service_lock);
	native_lab_job_put(job);
	return 0;
out:
	mutex_unlock(&native_lab_service_lock);
	if (prog)
		bpf_prog_put(prog);
	return err;
}

static struct native_lab_trusted_capsule *native_lab_active_capsule(u64 id)
{
	struct native_lab_trusted_capsule *capsule = ERR_PTR(-ENOENT);
	mutex_lock(&native_lab_service_lock);
	if (native_lab_service_active && !native_lab_service_active->abandoned &&
	    native_lab_service_active->capsule->id == id) {
		capsule = native_lab_service_active->capsule;
		kref_get(&capsule->refs);
	}
	mutex_unlock(&native_lab_service_lock);
	return capsule;
}
static int native_lab_trusted_context(void __user *argument)
{
	struct native_lab_trusted_context context;
	struct native_lab_trusted_capsule *capsule;
	struct bpf_prog *source, *target;
	struct btf *attach;
	int err = 0;
	if (copy_from_user(&context, argument, sizeof(context)))
		return -EFAULT;
	capsule = native_lab_active_capsule(context.request_id);
	if (IS_ERR(capsule))
		return PTR_ERR(capsule);
	source = capsule->source;
	context.prog_type = source->type;
	context.expected_attach_type = source->expected_attach_type;
	context.prog_flags = source->aux->native_load_flags;
	context.prog_ifindex = source->aux->native_load_ifindex;
	context.attach_btf_id = source->aux->attach_btf_id;
	context.gpl_compatible = source->gpl_compatible;
	context.source_btf_id = source->aux->btf ? btf_obj_id(source->aux->btf) : 0;
	context.token_present = !!source->aux->token;
	mutex_lock(&source->aux->dst_mutex);
	target = source->aux->dst_prog;
	attach = target ? target->aux->btf : source->aux->attach_btf;
	context.attach_prog_id = target ? target->aux->id : 0;
	context.attach_btf_obj_id = attach ? btf_obj_id(attach) : 0;
	mutex_unlock(&source->aux->dst_mutex);
	if (copy_to_user(argument, &context, sizeof(context)))
		err = -EFAULT;
	native_lab_trusted_put(capsule);
	return err;
}
static int native_lab_trusted_map(void __user *argument)
{
	struct native_lab_trusted_map shape;
	struct native_lab_trusted_capsule *capsule;
	struct bpf_map *map = NULL;
	u32 i;
	int err = 0;
	if (copy_from_user(&shape, argument, sizeof(shape)))
		return -EFAULT;
	capsule = native_lab_active_capsule(shape.request_id);
	if (IS_ERR(capsule))
		return PTR_ERR(capsule);
	for (i = 0; i < capsule->source->aux->used_map_cnt; i++) {
		struct bpf_map *candidate = capsule->source->aux->used_maps[i];
		if (candidate->id == shape.map_id) {
			map = candidate;
			break;
		}
	}
	if (!map)
		for (i = 0; i < capsule->resource_count; i++)
			if (capsule->resource_maps[i]->id == shape.map_id) {
				map = capsule->resource_maps[i];
				break;
			}
	if (!map) {
		err = -ENOENT;
		goto out;
	}
	for (i = 0; i < shape.depth; i++) {
		map = map->inner_map_meta;
		if (!map) {
			err = -ENOENT;
			goto out;
		}
	}
	shape.map_type = map->map_type;
	shape.key_size = map->key_size;
	shape.value_size = map->value_size;
	shape.max_entries = map->max_entries;
	shape.map_flags = map->map_flags;
	shape.btf_id = map->btf ? btf_obj_id(map->btf) : 0;
	shape.btf_key_type_id = map->btf_key_type_id;
	shape.btf_value_type_id = map->btf_value_type_id;
	shape.has_inner = !!map->inner_map_meta;
	if (copy_to_user(argument, &shape, sizeof(shape)))
		err = -EFAULT;
out:
	native_lab_trusted_put(capsule);
	return err;
}

static long native_lab_trusted_ioctl(struct file *file, unsigned int command, unsigned long argument)
{
	struct native_lab_trusted_file *owner = file->private_data;
	void __user *pointer = (void __user *)argument;
	if (owner->service) {
		switch (command) {
		case NATIVE_LAB_TRUSTED_NEXT: return native_lab_trusted_next(pointer);
		case NATIVE_LAB_TRUSTED_ACTIVATE: return native_lab_trusted_activate(pointer);
		case NATIVE_LAB_TRUSTED_COMPLETE: return native_lab_trusted_complete(pointer);
		case NATIVE_LAB_TRUSTED_CONTEXT: return native_lab_trusted_context(pointer);
		case NATIVE_LAB_TRUSTED_MAP: return native_lab_trusted_map(pointer);
		case NATIVE_LAB_TRUSTED_CHUNK: return native_lab_store_chunk(pointer);
		default: return -EPERM;
		}
	}
	if (command == NATIVE_LAB_TRUSTED_SUBMIT)
		return native_lab_trusted_submit(owner, pointer, false);
	if (command == NATIVE_LAB_TRUSTED_SUBMIT_RESOURCES)
		return native_lab_trusted_submit(owner, pointer, true);
	if (command == NATIVE_LAB_TRUSTED_WAIT) {
		struct native_lab_trusted_result result = {};
		struct native_lab_trusted_job *job;
		int err;
		mutex_lock(&native_lab_service_lock);
		job = owner->job;
		if (job)
			kref_get(&job->refs);
		mutex_unlock(&native_lab_service_lock);
		if (!job)
			return -ENODATA;
		err = wait_event_interruptible(job->wait, READ_ONCE(job->done));
		if (!err) {
			result.request_id = job->capsule->id;
			result.status = job->status;
			result.prog_id = job->result ? job->result->aux->id : 0;
			if (copy_to_user(pointer, &result, sizeof(result)))
				err = -EFAULT;
		}
		native_lab_job_put(job);
		return err;
	}
	return -EPERM;
}

static int native_lab_trusted_open(struct inode *inode, struct file *file)
{
	struct native_lab_trusted_file *owner;
	int err = 0;
	if (inode->i_private && !capable(CAP_SYS_ADMIN))
		return -EPERM;
	owner = kzalloc(sizeof(*owner), GFP_KERNEL);
	if (!owner)
		return -ENOMEM;
	owner->service = !!inode->i_private;
	if (owner->service) {
		mutex_lock(&native_lab_service_lock);
		if (native_lab_service_file)
			err = -EBUSY;
		else {
			native_lab_service_file = file;
		}
		mutex_unlock(&native_lab_service_lock);
	}
	if (err)
		kfree(owner);
	else
		file->private_data = owner;
	return err;
}
static int native_lab_trusted_release(struct inode *inode, struct file *file)
{
	struct native_lab_trusted_file *owner = file->private_data;
	struct native_lab_trusted_job *active = NULL, *job, *temporary;
	mutex_lock(&native_lab_service_lock);
	if (owner->service) {
		native_lab_service_file = NULL;
		list_for_each_entry_safe(job, temporary, &native_lab_service_pending, pending) {
			list_del_init(&job->pending);
			job->status = -ENOTCONN;
			WRITE_ONCE(job->done, true);
			wake_up_interruptible(&job->wait);
		}
		atomic_set(&native_lab_pending_count, 0);
		active = native_lab_service_active;
		native_lab_service_active = NULL;
		if (active) {
			active->status = -ENOTCONN;
			WRITE_ONCE(active->done, true);
			wake_up_interruptible(&active->wait);
		}
		wake_up_interruptible(&native_lab_service_wait);
	} else if (owner->job) {
		owner->job->abandoned = true;
		if (!list_empty(&owner->job->pending)) {
			list_del_init(&owner->job->pending);
			atomic_dec(&native_lab_pending_count);
		}
	}
	mutex_unlock(&native_lab_service_lock);
	native_lab_job_put(active);
	native_lab_job_put(owner->job);
	kfree(owner);
	return 0;
}
static const struct file_operations native_lab_trusted_fops = {
	.owner = THIS_MODULE, .open = native_lab_trusted_open,
	.unlocked_ioctl = native_lab_trusted_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl = native_lab_trusted_ioctl,
#endif
	.release = native_lab_trusted_release,
};
#endif
