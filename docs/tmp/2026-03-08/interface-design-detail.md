# Interface Design Detail: Safe Userspace Guidance for the Kernel JIT

This document refines the interface layer sketched in `docs/tmp/bpf-jit-advisor-v5r2.md` and `docs/tmp/bpf-jit-advisor-v6.md`. The goal is not to restate the mechanism/policy split. The goal is to make the load-time ABI, blob format, digest binding, CPU contract, logging, and deployment workflow concrete enough to implement.

The design point stays the same:

- userspace decides profitability;
- the kernel decides legality;
- the interface is bounded, load-time only, and fail-closed;
- v1 is x86-64 first, but the transport and legality envelope are arch-neutral.

## 1. Syscall Interface Design

### 1.1 Exact `BPF_PROG_LOAD` changes

As of Sunday, March 8, 2026, upstream `union bpf_attr` ends the `BPF_PROG_LOAD` arm with `keyring_id`. The new fields must be appended after that tail:

```c
/* prog_flags bit: jit_directives_fd/jit_directives_flags are valid */
#define BPF_F_JIT_DIRECTIVES_FD (1U << 20)

enum bpf_jit_directives_load_flags {
	BPF_F_JIT_DIRECTIVES_STRICT_CPU = (1U << 0),
	BPF_F_JIT_DIRECTIVES_LOG        = (1U << 1),
};

union bpf_attr {
	struct { /* BPF_PROG_LOAD */
		/* existing fields omitted */
		__aligned_u64 signature;
		__u32         signature_size;
		__s32         keyring_id;

		/*
		 * Sealed memfd containing one JIT directive blob.
		 * Valid only when prog_flags has BPF_F_JIT_DIRECTIVES_FD.
		 */
		__s32         jit_directives_fd;
		__u32         jit_directives_flags;
	};
};
```

The `prog_flags` gate is required. Relying on `jit_directives_fd >= 0` would be incorrect, because short old-user-space `bpf_attr` copies leave tail bytes zeroed. Without a gate bit, old callers would accidentally look like `fd=0`.

`jit_directives_flags` are intentionally separate from `prog_flags`:

- `prog_flags` says whether the extra FD field is present;
- `jit_directives_flags` control how that blob is handled.

### 1.2 How the directive blob FD is passed and consumed

Userspace passes exactly one sealed `memfd` per `BPF_PROG_LOAD` call. The kernel consumes it once, copies it into kernel memory, parses it, and then detaches from the FD. The blob is not pinned after load and there is no later attach step.

Load-time flow:

```text
userspace
  -> finalize exact pre-verifier insn stream
  -> build directive blob for that exact image
  -> memfd_create("bpf-jit-dir", MFD_CLOEXEC | MFD_ALLOW_SEALING)
  -> write(blob)
  -> fcntl(F_ADD_SEALS, F_SEAL_WRITE | F_SEAL_GROW | F_SEAL_SHRINK)
  -> bpf(BPF_PROG_LOAD, {
         prog_flags |= BPF_F_JIT_DIRECTIVES_FD,
         jit_directives_fd = fd,
         jit_directives_flags = ...
     })

kernel
  -> copy insns from attr.insns into kernel-owned bpf_prog
  -> fdget(jit_directives_fd)
  -> verify "is memfd" and required seals
  -> read i_size bytes from offset 0 into kernel buffer
  -> parse + validate blob header/records
  -> compute digest on copied insn stream
  -> compare digest and orig_insn_cnt
  -> check CPU contract
  -> verifier
  -> remap original ranges to post-verifier ranges
  -> kind-specific validation + emit or per-site fallback
```

Recommended kernel-side skeleton:

```c
static int bpf_prog_load(union bpf_attr *attr, bpfptr_t uattr, u32 uattr_size)
{
	struct bpf_prog *prog;
	struct bpf_jit_dir_state *dir_state = NULL;
	int err;

	prog = bpf_prog_create_from_attr(attr);
	if (IS_ERR(prog))
		return PTR_ERR(prog);

	if (attr->prog_flags & BPF_F_JIT_DIRECTIVES_FD) {
		err = bpf_jit_dir_authorize(attr);
		if (err)
			goto err_free_prog;

		dir_state = bpf_jit_dir_copy_from_memfd(attr->jit_directives_fd);
		if (IS_ERR(dir_state)) {
			err = PTR_ERR(dir_state);
			goto err_free_prog;
		}

		err = bpf_jit_dir_bind_to_prog(dir_state, prog, attr->jit_directives_flags);
		if (err)
			goto err_free_dir;
	}

	err = bpf_check(prog, attr, uattr, uattr_size);
	if (err)
		goto err_free_dir;

	err = bpf_jit_dir_finalize_after_verifier(prog, dir_state);
	if (err)
		goto err_free_dir;

	return bpf_prog_new_fd(prog);

err_free_dir:
	bpf_jit_dir_state_put(dir_state);
err_free_prog:
	bpf_prog_put(prog);
	return err;
}
```

### 1.3 `memfd` sealing requirements and why

Required:

- `F_SEAL_WRITE`
- `F_SEAL_GROW`
- `F_SEAL_SHRINK`

Accepted but not required:

- `F_SEAL_SEAL`

Why these three are mandatory:

- `F_SEAL_WRITE` prevents in-place mutation after userspace computed the blob digest and site layout.
- `F_SEAL_GROW` prevents appending extra records after the kernel checked `i_size`.
- `F_SEAL_SHRINK` prevents truncation races after the kernel checked `i_size`.

Why `F_SEAL_SEAL` is not required:

- seals are irreversible already;
- adding more seals later is harmless;
- requiring `F_SEAL_SEAL` would reject otherwise safe producers for no security gain.

Why require `memfd`, not an arbitrary file:

- seal semantics are explicit and queryable with `F_GET_SEALS`;
- the kernel gets immutable contents without trusting a pathname, mount namespace, or page cache policy;
- lifetime is tied to an FD, not a file path;
- the blob stays per-load, not global mutable state.

### 1.4 Error reporting

There are two classes of outcomes.

Fatal load errors abort `BPF_PROG_LOAD`:

| Condition | `errno` | Notes |
| --- | --- | --- |
| `BPF_F_JIT_DIRECTIVES_FD` set but `jit_directives_fd < 0` | `EINVAL` | malformed attr |
| invalid FD | `EBADF` | standard fd failure |
| FD is not a sealed `memfd` | `EINVAL` | file type / seal contract violation |
| blob length is `0` or exceeds `64 KiB` | `E2BIG` | bounded parser footprint |
| malformed header, bad offsets, non-zero reserved bytes, overlapping original ranges | `EINVAL` | protocol violation |
| unsupported blob ABI major or unsupported directive kind/version | `EOPNOTSUPP` | feature not implemented |
| digest mismatch or `orig_insn_cnt` mismatch | `EINVAL` | stale or wrong blob |
| authorization failure (`CAP_BPF + CAP_PERFMON` or delegated equivalent missing) | `EPERM` | privileged steering denied |
| strict CPU mismatch | `EOPNOTSUPP` | host does not satisfy requested contract |

Non-fatal outcomes preserve stock program loading and are reported through logging/telemetry:

- non-strict CPU mismatch: drop the entire blob, continue with ordinary verifier + stock JIT;
- constant blinding requested: drop the entire blob, continue with ordinary blinded JIT;
- JIT disabled or offloaded program: drop the entire blob, continue normally;
- per-site remap/validation/emission failure: reject only that site, emit stock code for that region.

This split is intentional:

- malformed or stale inputs are API misuse and should fail loudly;
- legality failures discovered only after verification are normal fail-closed cases and should not break availability.

### 1.5 Backward compatibility

Old userspace on a new kernel:

- unaffected;
- old callers never set `BPF_F_JIT_DIRECTIVES_FD`;
- short `bpf_attr` copies therefore behave exactly as before.

New userspace on an old kernel:

- if it passes a larger `attr_size` with non-zero tail bytes, the old kernel returns `E2BIG`;
- loaders should treat `E2BIG` on a directive-enabled load as "kernel lacks JIT-directive UAPI" and retry once without `BPF_F_JIT_DIRECTIVES_FD`;
- that retry path is mandatory in libbpf and any production loader.

New userspace on a kernel that knows the new fields but not this blob ABI or directive kind:

- `EOPNOTSUPP`;
- loader may retry without directives if policy says "availability first".

Compatibility rule for optional deployment:

```text
first attempt: load with directives
if errno in { E2BIG, EOPNOTSUPP }:
    retry once without directives
else:
    surface the real load error
```

### 1.6 Interaction with BPF token delegation

Directive use is more privileged than ordinary `BPF_PROG_LOAD`, so token delegation must not inherit it implicitly.

Required token-side rule:

- token must already authorize `BPF_PROG_LOAD` for the target program type and attach type;
- if `BPF_F_JIT_DIRECTIVES_FD` is set, the token must also carry a new delegated permission bit, for example `BPF_TOKEN_CAP_JIT_DIRECTIVES`;
- the token's associated user namespace must satisfy the equivalent of `CAP_BPF` and `CAP_PERFMON` checks for this operation.

If `prog_token_fd` is present but the token does not authorize JIT steering:

- return `EPERM`;
- userspace may retry without directives.

This avoids an unsafe delegation escalation where a token intended for "load this program type" would silently also allow backend steering.

## 2. Blob Format Deep Dive

### 2.1 Top-level layout

The blob is a compact little-endian binary object:

```text
+------------------------------+
| blob header                  |
+------------------------------+
| CPU contract                 |
+------------------------------+
| directive record 0           |
+------------------------------+
| 0-7 bytes zero padding       |
+------------------------------+
| directive record 1           |
+------------------------------+
| ...                          |
+------------------------------+
```

Global invariants:

- entire blob is little-endian;
- `total_len <= 64 * 1024`;
- all section offsets are within `total_len`;
- all section offsets are 8-byte aligned;
- all reserved bytes must be zero;
- directive records are sorted by `(subprog_id, orig_start_off, orig_end_off)`;
- original ranges are non-overlapping and remain within one subprogram.

### 2.2 Exact header layout

```c
#define BPF_JIT_DIR_BLOB_MAGIC     0x424a4156U /* "BJAV" */
#define BPF_JIT_DIR_BLOB_ABI_MAJOR 1
#define BPF_JIT_DIR_BLOB_ABI_MINOR 0
#define BPF_JIT_DIR_BLOB_MAX_LEN   (64 * 1024)
#define BPF_JIT_DIR_MAX_RECORDS    1024
#define BPF_JIT_DIR_MAX_REC_LEN    256

enum bpf_jit_blob_endian {
	BPF_JIT_BLOB_LE = 1,
};

struct bpf_jit_dir_blob_hdr_v1 {
	__le32 magic;            /* 0x00 */
	__le16 abi_major;        /* 0x04 */
	__le16 abi_minor;        /* 0x06 */
	__le16 hdr_len;          /* 0x08, == sizeof(*hdr) in v1 */
	__le16 endian;           /* 0x0a, == BPF_JIT_BLOB_LE */
	__le32 total_len;        /* 0x0c */
	__le32 flags;            /* 0x10, zero in v1 */
	__le32 nr_directives;    /* 0x14 */
	__le32 orig_insn_cnt;    /* 0x18 */
	__u8   prog_digest[32];  /* 0x1c */
	__le32 cpu_off;          /* 0x3c */
	__le32 cpu_len;          /* 0x40 */
	__le32 dir_off;          /* 0x44 */
	__le32 dir_len;          /* 0x48 */
	__le32 reserved[3];      /* 0x4c */
}; /* 88 bytes */
```

Header field meanings:

| Offset | Size | Field | Meaning |
| --- | ---: | --- | --- |
| `0x00` | 4 | `magic` | rejects wrong object type early |
| `0x04` | 2 | `abi_major` | incompatible format boundary |
| `0x06` | 2 | `abi_minor` | compatible format evolution within one major |
| `0x08` | 2 | `hdr_len` | lets future kernels append header fields |
| `0x0a` | 2 | `endian` | fixed to little-endian wire format |
| `0x0c` | 4 | `total_len` | exact memfd length expected by parser |
| `0x10` | 4 | `flags` | blob-global knobs; must be zero in v1 |
| `0x14` | 4 | `nr_directives` | directive count for linear bounds checking |
| `0x18` | 4 | `orig_insn_cnt` | cheap precheck before digest compare |
| `0x1c` | 32 | `prog_digest` | SHA-256 of exact pre-verifier insn byte stream |
| `0x3c` | 4 | `cpu_off` | byte offset of CPU contract |
| `0x40` | 4 | `cpu_len` | size of CPU contract |
| `0x44` | 4 | `dir_off` | first directive record |
| `0x48` | 4 | `dir_len` | total bytes occupied by records |
| `0x4c` | 12 | `reserved` | must be zero |

### 2.3 CPU contract layout

The CPU contract stays fixed-size in v1:

```c
enum bpf_jit_arch {
	BPF_JIT_ARCH_X86_64 = 1,
	BPF_JIT_ARCH_ARM64  = 2,
};

enum bpf_jit_cpu_vendor {
	BPF_JIT_CPU_VENDOR_UNKNOWN = 0,
	BPF_JIT_CPU_VENDOR_INTEL   = 1,
	BPF_JIT_CPU_VENDOR_AMD     = 2,
	BPF_JIT_CPU_VENDOR_ARM     = 3,
};

enum bpf_jit_cpu_contract_flags {
	BPF_JIT_CPU_F_MATCH_MODEL_SET  = (1U << 0),
	BPF_JIT_CPU_F_MATCH_STEPPING   = (1U << 1),
	BPF_JIT_CPU_F_REQUIRE_HOMOGENEOUS = (1U << 2),
};

struct bpf_jit_cpu_contract_v1 {
	__le32 arch;                    /* enum bpf_jit_arch */
	__le32 vendor;                  /* enum bpf_jit_cpu_vendor */
	__le32 family;                  /* x86 family or arch-defined class */
	__le32 model;                   /* x86 model or arch-defined class */
	__le32 stepping_mask;           /* zero means "ignore stepping" */
	__le32 flags;                   /* enum bpf_jit_cpu_contract_flags */
	__le64 required_features[2];    /* 128 feature bits */
	__le64 forbidden_features[2];   /* 128 feature bits */
	__le64 policy_id;               /* opaque userspace policy DB id */
	__le32 policy_version;          /* monotonically increasing */
	__le32 workload_class;          /* opaque userspace label */
}; /* 72 bytes */
```

The feature namespace is arch-specific but UAPI-stable:

- when `arch == BPF_JIT_ARCH_X86_64`, feature bit positions map to an x86-specific enum derived from kernel CPUID capability bits relevant to JIT lowering;
- when `arch == BPF_JIT_ARCH_ARM64`, bit positions map to an arm64 enum derived from ID register / HWCAP features relevant to JIT lowering.

The kernel never interprets `policy_id` or `workload_class`. They exist only for logging, rollout correlation, and post-load telemetry.

### 2.4 Common directive record layout

```c
enum bpf_jit_dir_kind {
	BPF_JIT_DIR_WIDE_LOAD   = 1,
	BPF_JIT_DIR_CMOV_SELECT = 2,
};

enum bpf_jit_precond_bits {
	BPF_JIT_PC_STRAIGHT_LINE      = (1U << 0),
	BPF_JIT_PC_ONE_DIAMOND        = (1U << 1),
	BPF_JIT_PC_NO_INTERIOR_TARGET = (1U << 2),
	BPF_JIT_PC_NO_CALLS           = (1U << 3),
	BPF_JIT_PC_NO_STORES          = (1U << 4),
	BPF_JIT_PC_CONST_OFFSET_MEM   = (1U << 5),
	BPF_JIT_PC_SAME_BASE_MEM      = (1U << 6),
};

struct bpf_jit_dir_rec_hdr_v1 {
	__le16 kind;
	__u8   kind_version;
	__u8   hdr_len;
	__le16 rec_len;
	__le16 flags;                  /* zero in v1 */
	__le32 site_id;
	__le16 subprog_id;
	__u8   reserved0[2];
	__le32 orig_start_off;
	__le32 orig_end_off;           /* exclusive */
	__le32 precond_mask;
	__le32 reserved1;
	__le64 required_features[2];
	__le64 forbidden_features[2];
	/* payload starts at rec + hdr_len */
}; /* 64 bytes */
```

Record header field meanings:

| Offset | Size | Field | Meaning |
| --- | ---: | --- | --- |
| `0x00` | 2 | `kind` | directive kind selector |
| `0x02` | 1 | `kind_version` | per-kind payload ABI |
| `0x03` | 1 | `hdr_len` | common header size |
| `0x04` | 2 | `rec_len` | total record size including payload and padding |
| `0x06` | 2 | `flags` | zero in v1 |
| `0x08` | 4 | `site_id` | opaque userspace correlation id |
| `0x0c` | 2 | `subprog_id` | original subprogram id |
| `0x0e` | 2 | `reserved0` | must be zero |
| `0x10` | 4 | `orig_start_off` | original start instruction index |
| `0x14` | 4 | `orig_end_off` | original exclusive end instruction index |
| `0x18` | 4 | `precond_mask` | shared structural expectations |
| `0x1c` | 4 | `reserved1` | must be zero |
| `0x20` | 16 | `required_features` | per-site required CPU features |
| `0x30` | 16 | `forbidden_features` | per-site forbidden CPU features |

The parser walks records like this:

```c
for (off = hdr->dir_off; off < hdr->dir_off + hdr->dir_len; off += rec->rec_len) {
	rec = blob + off;
	require(rec->hdr_len >= sizeof(*rec));
	require(rec->rec_len >= rec->hdr_len);
	require(rec->rec_len <= BPF_JIT_DIR_MAX_REC_LEN);
	require(IS_ALIGNED(rec->rec_len, 8));
	payload = (void *)rec + rec->hdr_len;
	payload_len = rec->rec_len - rec->hdr_len;
}
```

### 2.5 Exact payload layout for v1 directive kinds

`wide_load`:

```c
enum bpf_jit_mem_class {
	BPF_JIT_MEM_STACK     = 1,
	BPF_JIT_MEM_MAP_VALUE = 2,
};

struct bpf_jit_dir_wide_load_v1 {
	__u8  width;            /* 4 or 8 */
	__u8  mem_class;        /* enum bpf_jit_mem_class */
	__u8  dst_reg;
	__u8  base_reg;
	__le16 base_off;
	__u8  min_align_log2;
	__u8  liveout_reg;
}; /* 8 bytes, rec_len = 72 */
```

`cmov_select`:

```c
enum bpf_jit_val_kind {
	BPF_JIT_VAL_REG = 1,
	BPF_JIT_VAL_IMM = 2,
};

struct bpf_jit_value_ref_v1 {
	__u8   kind;
	__u8   reg;
	__u8   reserved[2];
	__le32 imm;
}; /* 8 bytes */

struct bpf_jit_dir_cmov_select_v1 {
	__u8  cc;
	__u8  width;            /* 32 or 64 */
	__u8  dst_reg;
	__u8  lhs_reg;
	struct bpf_jit_value_ref_v1 rhs;
	struct bpf_jit_value_ref_v1 true_val;
	struct bpf_jit_value_ref_v1 false_val;
	__u8  pad[4];
}; /* 32 bytes, rec_len = 96 */
```

### 2.6 Versioning strategy

The format uses four compatibility levers:

1. `abi_major`
   - incompatible parser changes bump this;
   - mismatched major returns `EOPNOTSUPP`.
2. `abi_minor`
   - compatible, append-only evolution within one major;
   - v1 kernel accepts only `1.0`, but the parser structure already supports a later relaxation.
3. `hdr_len` / `cpu_len` / `rec_len`
   - allow append-only growth;
   - extra bytes must be zero when parsed by an older kernel.
4. `kind_version`
   - version each directive payload independently.

Conservative v1 rule:

- accept only `abi_major == 1`, `abi_minor == 0`, and `kind_version == 1`;
- require all unknown tail bytes to be zero;
- reject unknown kinds and non-zero reserved fields.

That rule is intentionally strict. This interface is new, safety-critical, and optional. Strict rejection is better than permissive misparse.

### 2.7 Endianness handling

The blob wire format is always little-endian, regardless of host endianness.

Why:

- the initial prototype is x86-64;
- little-endian is already the common case for x86-64 and arm64 Linux deployments;
- one canonical byte order simplifies offline tools, test vectors, and diffing.

Producer rules:

- pack all integer fields as little-endian;
- set `endian = BPF_JIT_BLOB_LE`.

Kernel rules:

- parse with `get_unaligned_le16/32/64()`;
- reject any `endian` value other than `BPF_JIT_BLOB_LE`.

### 2.8 Size limits and why

Recommended hard limits:

- blob total size: `64 KiB`
- number of directives: `1024`
- maximum record length: `256` bytes

Why these limits are enough for v1:

- the supported directives are local rewrites, so practical site counts are in the low hundreds, not tens of thousands;
- `1024` records at `64-96` bytes each fit comfortably under `64 KiB`;
- bounded length keeps parser memory usage trivial and blocks "upload an arbitrary binary DSL" creep.

If userspace finds more than `1024` candidates, it must prioritize:

- hottest sites first;
- highest expected code-size or runtime win first;
- emit telemetry that the cap was hit.

### 2.9 Variable-length payload handling

Even though v1 payloads are fixed-size, records are already length-prefixed. Future payloads can add variable-sized trailing data without changing the transport:

```text
record header
  -> fixed fields
  -> fixed payload prefix
  -> optional variable-length tail
  -> zero padding to next 8-byte boundary
```

Kernel parsing rule:

- the kind-specific validator receives `(payload, payload_len)`;
- it must reject any record where `payload_len` is smaller than the minimum versioned payload;
- it may accept a larger `payload_len` only if the extra tail is zero and the version defines append-only semantics.

### 2.10 Alignment requirements inside the blob

Required:

- `hdr_len`, `cpu_off`, `dir_off`, and every `rec_len` are multiples of 8;
- each record starts on an 8-byte boundary;
- padding bytes are zero.

Reason:

- simplifies direct casting after a safe bounds check;
- keeps future `u64` additions naturally aligned;
- makes diffing/test vectors deterministic.

The parser must still be robust to unaligned access and use LE helpers. Alignment is a producer obligation, not a trust assumption.

## 3. Digest Binding

### 3.1 Hash algorithm

Use SHA-256.

Why SHA-256:

- already widely available in-kernel;
- collision resistance is comfortably beyond what this binding needs;
- cost is negligible relative to verifier and JIT time for the small input sizes involved.

### 3.2 What exactly is hashed

The digest is:

```text
SHA-256(attr.insn_cnt * sizeof(struct bpf_insn) bytes)
```

More precisely:

- the kernel first copies the instruction array from `attr.insns` into kernel-owned memory;
- it hashes exactly `attr.insn_cnt` consecutive `struct bpf_insn` objects from that copied image;
- `orig_insn_cnt` is checked separately against `attr.insn_cnt`.

This means the digest covers the entire submitted instruction stream, not just a "text section". For BPF, the instruction stream is the relevant executable artifact.

### 3.3 Are maps, BTF, and relocations part of the digest

Maps:

- yes, indirectly, if they affect the instruction bytes;
- pseudo-instructions such as `BPF_PSEUDO_MAP_FD` are hashed exactly as passed in `attr.insns`, including their immediate fields.

BTF and CO-RE relocations:

- not as separate objects;
- only their materialized effect on the final instruction stream is hashed.

External ELF metadata:

- no;
- the kernel does not consume ELF at `BPF_PROG_LOAD` time, so binding the blob to ELF sections would be the wrong layer.

This is intentionally strict. A blob is bound to one exact load image, not to a source file or object file identity.

### 3.4 Verification timing

Digest verification happens before verifier rewriting:

1. copy insns from user memory;
2. copy blob from sealed `memfd`;
3. parse blob header;
4. compare `orig_insn_cnt`;
5. compute SHA-256 on copied insns;
6. compare `prog_digest`;
7. only then run the verifier.

This guarantees that:

- the blob is tied to the exact pre-verifier image;
- `orig_idx` remap starts from the same coordinate system userspace saw.

### 3.5 TOCTOU analysis

There is no meaningful TOCTOU window between digest computation and verifier use:

- the kernel hashes the kernel-owned instruction copy, not the userspace pointer;
- the kernel parses a kernel-owned copy of the sealed blob, not the live `memfd`;
- verifier rewrites operate on the same instruction copy that was hashed.

Userspace can mutate its original buffers after the syscall returns to kernel mode; it does not matter.

## 4. Security Analysis

### 4.1 Capability model: why `CAP_BPF + CAP_PERFMON`

This interface is not a harmless hint channel. It is privileged performance steering.

`CAP_BPF` is required because:

- the operation is still fundamentally a privileged `BPF_PROG_LOAD`;
- the blob influences how the kernel turns verified BPF into native code.

`CAP_PERFMON` is required because:

- the whole point is performance-sensitive backend steering;
- the chosen lowering can intentionally change timing, branch predictor state, cache footprint, and speculation shape;
- the closest existing capability boundary for privileged performance observation/control is already `CAP_PERFMON`.

Token-equivalent delegation must preserve the same effective boundary.

### 4.2 What attacks become possible

New attack surface:

- blob parser bugs;
- kind-specific validator bugs;
- arch emitter bugs triggered only through directive handling;
- load-time CPU/memory consumption from adversarial but bounded blobs;
- intentional timing perturbation by privileged loaders.

What does not become possible by design:

- arbitrary native code injection;
- verifier bypass;
- cross-program retargeting;
- runtime mutation of already loaded directives.

### 4.3 Can directives bypass verifier safety checks

No, not if the interface is implemented as specified.

Reasons:

- directives are advisory over a program the verifier has already accepted;
- the kernel never trusts userspace-supplied post-verifier coordinates;
- the remap is computed from preserved `orig_idx`, entirely in kernel;
- validators can only consume retained facts the verifier itself recorded;
- any site that fails remap or fact checks falls back to stock emission.

The directive blob cannot widen memory access, change helper semantics, or skip verifier-imposed guards. It can only request an alternative native lowering for a region that is already legal in BPF semantics.

### 4.4 Can directives cause kernel crashes

Only through kernel bugs in the new parser/validator/emitter path. That is a real TCB increase, so the interface must stay narrow:

- bounded blob size;
- fixed declarative payloads;
- exact validators;
- no pointer fields in the blob;
- no self-modifying or runtime-patched directives;
- selftests for malformed blobs and boundary conditions.

The safe failure mode is either:

- abort load before verifier, or
- reject the site and emit stock code.

### 4.5 Can directives create new side channels

They can change timing and speculation behavior for the loader's own program. That is allowed.

They should not create a qualitatively new side channel beyond what privileged JITed BPF already enables, because:

- the interface is privileged;
- there is no new kernel feedback channel other than ordinary load results and optional logs;
- there is no cross-program control path.

The main difference is degree, not kind.

### 4.6 Can a malicious privileged user influence programs loaded by other users

Not directly.

The blob:

- is consumed only inside the caller's own `BPF_PROG_LOAD`;
- is digest-bound to that program image;
- is never attached to an existing program by FD later.

Indirect hardware-level interference remains possible in the same way as any privileged program deployment:

- cache contention;
- branch predictor contention;
- front-end bandwidth contention.

That is not new to this interface.

### 4.7 How fail-closed prevents safety violations

Fail-closed means "directive adoption can only reduce to stock semantics":

- parse/auth/digest errors abort the advisory attempt before any optimization is trusted;
- CPU mismatch in non-strict mode drops the blob entirely;
- post-verifier remap failure rejects that site;
- validator failure rejects that site;
- emitter refusal rejects that site.

The fallback path is always the existing stock JIT for the verified BPF region.

There is no partial semantic trust. A site is either:

- fully proven safe for that directive kind, or
- emitted exactly as it is today.

### 4.8 Speculative execution posture

Directives may change branch-versus-`cmov` behavior, so they do change speculation shape. They must not change speculation safety rules.

Required exclusions:

- no directives spanning packet/ctx accesses that rely on speculation hardening rewrites;
- no directives across exception-table or `PROBE_MEM`-style faulting accesses;
- no directives across helper/tail-call/exit boundaries;
- no directives across regions where the stock JIT inserts speculation barriers or fixups.

`cmov_select` changes whether the CPU predicts a branch. It does not authorize new speculative memory accesses. `wide_load` is limited to verifier-proven non-faulting stack/map-value accesses and therefore cannot introduce speculative faulting behavior.

## 5. CPU Contract

### 5.1 How to represent CPU features portably

The contract has two layers:

1. arch-neutral fields:
   - `arch`
   - `required_features`
   - `forbidden_features`
   - `policy_id`
   - `policy_version`
   - `workload_class`
2. arch-specific identity fields:
   - x86: `vendor`, `family`, `model`, `stepping_mask`
   - arm64: the same slots can encode an arch-defined CPU class or MIDR-derived identity class

Portability rule:

- the bitmaps are stable UAPI namespaces selected by `arch`;
- userspace tools never inspect kernel-internal `X86_FEATURE_*` numbers directly;
- instead, they map host CPUID/HWCAP data into `enum bpf_jit_cpu_feature_<arch>` values defined in the JIT-directive UAPI header.

That keeps the blob arch-neutral at the transport level while allowing arch-specific profitability policy.

### 5.2 Hybrid architectures

v1 does not support per-core or per-cpuset directive selection inside the kernel.

Kernel check rule:

- compute the effective common feature set for all CPUs on which the program may execute;
- if `BPF_JIT_CPU_F_REQUIRE_HOMOGENEOUS` is set, also require one common `(vendor, family, model, stepping-mask class)` across that domain;
- if not satisfied:
  - `STRICT_CPU` load flag set: return `EOPNOTSUPP`;
  - otherwise: drop the blob and continue with stock JIT.

Operational consequence:

- on Intel P-core/E-core or arm big.LITTLE systems, exact-model policies only work when the deployment constrains execution to a homogeneous domain outside the kernel, for example a homogeneous VM or a dedicated cpuset/IRQ-affinity regime;
- otherwise userspace should either emit a lowest-common-denominator contract or not use directives for that program.

### 5.3 What if CPU features or microcode change

Correctness and profitability must be separated.

Correctness-critical contract:

- only uses architecturally visible feature bits that the kernel guarantees system-wide for execution of generated native code;
- those are checked by the kernel.

Profitability-only contract:

- includes microcode-sensitive or tuning-sensitive information;
- should be folded into `policy_id` / `policy_version` by userspace;
- is not validated by the kernel, because a microcode mismatch is a performance issue, not a safety issue.

Recommended rollout rule:

- if a node's CPU signature or microcode revision changes, the userspace advisor invalidates its cached blobs and regenerates them on the next load or rollout.

Already loaded programs are not revoked solely because profitability assumptions changed.

### 5.4 Check at load time, JIT time, or both

Both.

Load-time precheck:

- fail early on obvious mismatch before verifier work.

Final pre-emission check:

- re-check inside the JIT consumer right before the first emission pass;
- covers rare races such as CPU hotplug or deferred JIT enablement between parse time and emit time.

For the common eager-JIT case the two checks are adjacent and cheap. Keeping both makes the contract explicit and avoids subtle state drift.

## 6. Logging and Telemetry

### 6.1 What the kernel should record per directive

For each directive, record:

- `site_id`
- `kind`
- `subprog_id`
- original range `[orig_start_off, orig_end_off)`
- remapped range `[post_start_off, post_end_off)` if available
- final status: accepted, dropped, rejected
- reason code
- `policy_id`, `policy_version`, `workload_class` from the blob CPU contract

Recommended result structure:

```c
enum bpf_jit_dir_status {
	BPF_JIT_DIR_STATUS_ACCEPTED = 0,
	BPF_JIT_DIR_STATUS_DROPPED  = 1, /* whole-blob or env-level drop */
	BPF_JIT_DIR_STATUS_REJECTED = 2, /* site-specific legality failure */
};

enum bpf_jit_dir_reason {
	BPF_JIT_DIR_REASON_OK = 0,
	BPF_JIT_DIR_REASON_DROP_CPU_MISMATCH,
	BPF_JIT_DIR_REASON_DROP_CONST_BLINDING,
	BPF_JIT_DIR_REASON_DROP_NO_SOFT_JIT,
	BPF_JIT_DIR_REASON_REMAP_EMPTY,
	BPF_JIT_DIR_REASON_REMAP_NONCONTIG,
	BPF_JIT_DIR_REASON_REMAP_OVERLAP,
	BPF_JIT_DIR_REASON_FACT_MISSING,
	BPF_JIT_DIR_REASON_PRECOND_MISMATCH,
	BPF_JIT_DIR_REASON_TEMPLATE_MISMATCH,
	BPF_JIT_DIR_REASON_CPU_FEATURE_MISMATCH,
	BPF_JIT_DIR_REASON_ARCH_UNSUPPORTED,
	BPF_JIT_DIR_REASON_EMIT_FAILED,
};

struct bpf_jit_dir_result_v1 {
	__u32 site_id;
	__u16 kind;
	__u16 status;
	__u32 reason;
	__u32 subprog_id;
	__u32 orig_start_off;
	__u32 orig_end_off;
	__u32 post_start_off;
	__u32 post_end_off;
}; /* 32 bytes */
```

### 6.2 How userspace retrieves rejection reasons

Use two channels.

Channel 1: existing verifier log buffer

- enabled when `jit_directives_flags & BPF_F_JIT_DIRECTIVES_LOG`;
- appended after ordinary verifier log text;
- intended for human debugging.

Example log lines:

```text
jitdir: site=42 kind=CMOV_SELECT subprog=1 orig=[153,158) post=[161,166) status=accepted policy=0x17 ver=9 workload=2
jitdir: site=17 kind=WIDE_LOAD subprog=0 orig=[30,52) status=rejected reason=FACT_MISSING
jitdir: blob status=dropped reason=CONST_BLINDING
```

Channel 2: structured program info

- extend `struct bpf_prog_info` with counts and an optional array pointer returned by `BPF_OBJ_GET_INFO_BY_FD`;
- intended for operator tooling, `bpftool`, and fleet telemetry.

Proposed `bpf_prog_info` tail:

```c
struct bpf_prog_info {
	/* existing fields omitted */
	__u32 jit_dir_total;
	__u32 jit_dir_accepted;
	__u32 jit_dir_dropped;
	__u32 jit_dir_rejected;
	__u32 jit_dir_result_rec_size;   /* sizeof(struct bpf_jit_dir_result_v1) */
	__u32 nr_jit_dir_results;
	__aligned_u64 jit_dir_results;   /* user pointer */
};
```

This structured path is the recommended production API. Verifier text alone is not enough for large fleets.

`site_id` stability rule:

- kernel treats `site_id` as opaque;
- `site_id` is only meaningful together with the program digest;
- operator tooling should key any cross-build correlation on `(logical program identity, prog_digest, site_id)`, not on `site_id` alone.

### 6.3 Integration with the existing BPF verifier log

The JIT-directive logger should reuse the verifier log infrastructure, not create a separate load-time text buffer.

Rules:

- ordinary verifier logging remains unchanged;
- directive log lines are prefixed with `jitdir:` to stay machine-greppable;
- if the user did not provide a verifier log buffer, text lines are dropped silently but structured counters/results remain available after load;
- if the verifier log truncates, the kernel still stores complete structured results in `bpf_prog_info`.

### 6.4 Performance impact of logging

Runtime impact:

- none; all logging is load-time only.

Load-time impact:

- fixed `O(nr_directives)` bookkeeping for structured results;
- optional string formatting only if verifier logging is requested.

Bounds:

- `1024` result records max;
- `32 KiB` worst-case structured result storage;
- text logging limited by the caller's log buffer size.

This keeps telemetry cheap enough to enable by default in canary rollouts while remaining effectively free in steady state.

## 7. Userspace Advisor Architecture

### 7.1 Discovery: candidates come from finalized bytecode pattern matching

The advisor must run on the exact instruction stream that will be passed to `BPF_PROG_LOAD`, after:

- CO-RE relocation;
- subprogram finalization;
- any libbpf rewriting;
- map FD resolution in pseudo instructions.

It must not run on:

- source code;
- LLVM IR;
- ELF sections before relocation.

`wide_load` discovery:

```c
for each subprog:
	for i in [0, insn_cnt):
		try_match_byte_load_ladder(i)
		require:
			- only byte loads, shifts, ors
			- one base reg
			- contiguous byte offsets
			- one final liveout reg
		if match:
			emit candidate(kind=WIDE_LOAD, orig_range=[i, end))
```

`cmov_select` discovery:

```c
cfg = build_cfg(finalized_insns)
for each conditional jump J:
	find exactly two outgoing edges
	find one reconvergence point K
	require each arm:
		- no side effects except dst assignment
		- no calls, stores, exits, or interior targets
		- same destination register
	if match:
		emit candidate(kind=CMOV_SELECT, orig_range=[J, K))
```

### 7.2 Blob generation library API

The cleanest shape is a small packer library used by libbpf, `bpftool`, and higher-level agents:

```c
struct bpf_jitadv_program {
	const struct bpf_insn *insns;
	__u32 insn_cnt;
	__u32 prog_type;
	__u32 expected_attach_type;
	const char *logical_name;
};

struct bpf_jitadv_policy_view {
	struct bpf_jit_cpu_contract_v1 cpu;
	__u32 max_directives;
};

struct bpf_jitadv_blob;

int bpf_jitadv_discover(const struct bpf_jitadv_program *prog,
			struct bpf_jitadv_candidate **cands,
			size_t *nr_cands);
int bpf_jitadv_select(const struct bpf_jitadv_candidate *cands,
		      size_t nr_cands,
		      const struct bpf_jitadv_policy_view *policy,
		      struct bpf_jitadv_plan **out);
int bpf_jitadv_pack(const struct bpf_jitadv_program *prog,
		    const struct bpf_jitadv_plan *plan,
		    struct bpf_jitadv_blob **out);
int bpf_jitadv_memfd(const struct bpf_jitadv_blob *blob, int *fd_out);
void bpf_jitadv_blob_free(struct bpf_jitadv_blob *blob);
```

The library owns:

- digest computation;
- exact little-endian packing;
- memfd sealing;
- bounds checking before the kernel sees the blob.

That keeps every loader from reimplementing the wire format incorrectly.

### 7.3 Integration with existing loaders

`libbpf`

- extend `struct bpf_prog_load_opts` with `jit_directives_fd` and `jit_directives_flags`;
- add an optional callback hook invoked after final CO-RE relocation and before each `BPF_PROG_LOAD`;
- callback receives finalized insns and returns either a sealed FD or "no directives".

`cilium/ebpf`

- expose an optional `JITDirectives` field in the Go-side program load options;
- reuse the same packer library through cgo or a Go-native mirror of the binary format;
- generation still happens inline, immediately before `sys.ProgLoad`.

`bpftool`

- add a manual path for debugging and demos:
  - `bpftool prog advise OBJ` dumps discovered candidates in YAML/JSON;
  - `bpftool prog load OBJ PATH --jit-directives directives.yaml` packs and passes the blob.

### 7.4 Policy DB format and management

Use a versioned JSON file for the source of truth in v1. It is human-editable, easy to diff, and easy to embed into test artifacts.

Recommended schema:

```json
{
  "schema_version": 1,
  "policy_id": "0x0000000017ac0042",
  "policy_version": 9,
  "cpu_classes": [
    {
      "name": "intel-wide-ooo",
      "match": {
        "arch": "x86_64",
        "vendor": "intel",
        "family": 6,
        "models": [183, 186]
      },
      "rules": {
        "wide_load": { "min_align_log2": 0 },
        "cmov_select": { "allow_workload_classes": ["mixed", "unpredictable"] }
      }
    }
  ]
}
```

Management rules:

- atomically replace the DB file on update;
- loader parses it once and keeps an immutable in-memory snapshot;
- `policy_id` and `policy_version` are copied into the blob for later telemetry correlation;
- if the DB changes, newly loaded programs get new blobs; already loaded programs are left alone until operator rollout decides otherwise.

### 7.5 Workflow: advise inline, not load-then-reload

The safe default workflow is:

```text
compile -> CO-RE/finalize -> advise -> load once
```

Not:

```text
compile -> load -> advise -> reload
```

Why inline is required:

- the blob is digest-bound to the exact pre-verifier image;
- a post-load attach step would need re-JIT or delayed JIT materialization;
- availability fallback is easy already: retry once without directives.

Reload still exists as a rollout tool, not as the steady-state API shape.

## 8. Deployment Scenarios

### 8.1 Scenario A: single binary with embedded BPF plus advisor

Sequence:

```text
binary
  -> libbpf: open embedded ELF
  -> libbpf: CO-RE relocate + finalize
  -> advisor: discover candidates on finalized insns
  -> advisor: choose directives from embedded policy DB
  -> advisor: pack blob + seal memfd
  -> kernel: BPF_PROG_LOAD with blob
  -> kernel: parse, bind, verify, remap, adopt-or-fallback
  <- prog_fd
```

Pseudo-code:

```c
opts.prog_flags |= BPF_F_JIT_DIRECTIVES_FD;
opts.jit_directives_flags = BPF_F_JIT_DIRECTIVES_LOG;
fd = bpf_jitadv_prepare_memfd(prog_spec, embedded_policy);
opts.jit_directives_fd = fd;

err = bpf_object__load_skeleton(skel, &opts);
if (err == -E2BIG || err == -EOPNOTSUPP) {
	opts.prog_flags &= ~BPF_F_JIT_DIRECTIVES_FD;
	opts.jit_directives_fd = -1;
	opts.jit_directives_flags = 0;
	err = bpf_object__load_skeleton(skel, &opts);
}
```

Error handling:

- `E2BIG` / `EOPNOTSUPP`: retry without directives;
- `EPERM`: either retry without directives or fail, depending on whether the binary treats performance steering as optional;
- other errors: treat as real load failures.

Rollback:

- process-local only;
- rerun with advisory feature disabled by config or environment;
- no pinned program replacement machinery required.

### 8.2 Scenario B: Cilium-style central agent managing many programs

Sequence:

```text
controller
  -> resolves node CPU profile
  -> loads policy DB snapshot
  -> finalizes each BPF object for this node
  -> generates one blob per program digest
  -> loads new versioned programs under /sys/fs/bpf/$svc/$prog/$digest-$policyver
  -> reads structured jit_dir_results
  -> if canary healthy: atomically flips links to new prog FDs
  -> if regression: flips links back and deletes new version
```

Recommended exact mechanics:

1. Pin old program and links under versioned names.
2. Load new program with shared pinned maps.
3. Query `bpf_prog_info` for `jit_dir_*` results.
4. Attach new program using `bpf_link_update(..., BPF_F_REPLACE)` or equivalent atomic replacement path.
5. Keep old program pinned for rollback until canary window expires.

Error handling:

- load fails before attach: keep old program and mark rollout step failed;
- blob dropped/non-fatal site rejections: still allow canary, because program semantics are unchanged;
- health/SLO regression after attach: revert links to previous version and retire the canary.

Rollback:

- flip the links back to the previous pinned program;
- leave shared maps intact if map ABI did not change;
- retire the new blob with its `policy_version` in telemetry.

### 8.3 Scenario C: `bpftool`-style manual directive application

Sequence:

```text
developer
  -> bpftool prog advise foo.o > candidates.yaml
  -> edits candidates.yaml into directives.yaml
  -> bpftool prog load foo.o /sys/fs/bpf/foo --jit-directives directives.yaml --log-level verbose
  -> kernel returns prog_fd or errno
  -> bpftool prints jitdir: log lines and structured result summary
```

Manual path rules:

- the YAML/JSON is never the kernel ABI;
- `bpftool` always repacks it into the binary blob first;
- the same digest binding rules apply.

Error handling:

- malformed YAML/JSON: user-space packer error, no syscall made;
- kernel `EINVAL`: print parser/digest mismatch details and stop;
- kernel `E2BIG` / `EOPNOTSUPP`: tell the user whether the kernel or blob is unsupported;
- non-fatal site rejections: show structured summary, load still succeeds.

Rollback:

- rerun `bpftool prog load` without `--jit-directives`, or
- repin the previous program version if this was replacing a pinned one.

## 9. Recommended Implementation Notes

### 9.1 Kernel parsing and binding order

Recommended order inside `BPF_PROG_LOAD`:

1. copy insns into kernel memory;
2. authorize directive use;
3. copy blob from sealed memfd;
4. parse and bounds-check blob;
5. compare `orig_insn_cnt`;
6. compute digest and compare;
7. pre-check CPU contract;
8. run verifier;
9. remap original ranges through preserved `orig_idx`;
10. final CPU check + kind-specific validation + emit/fallback.

That order minimizes wasted work on stale or malformed blobs while preserving the exact-image binding model.

### 9.2 Result semantics

A loader should interpret outcomes like this:

- syscall success + `jit_dir_accepted > 0`: directives adopted;
- syscall success + `jit_dir_accepted == 0` but `jit_dir_total > 0`: advisory path ran but everything was dropped or rejected;
- syscall failure with `E2BIG`/`EOPNOTSUPP`: retry path candidate;
- syscall failure with anything else: treat as a real load failure unless explicitly configured otherwise.

### 9.3 What v1 intentionally does not do

Not in v1:

- attaching directives after load;
- per-core policy selection inside the kernel;
- mutable directive blobs;
- arbitrary code snippets;
- support on the constant-blinding path;
- speculative-hardening overrides;
- cross-program or global directive caches in kernel.

That scope discipline is what keeps the interface defensible.
