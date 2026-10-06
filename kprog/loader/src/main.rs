use std::collections::HashMap;
use std::env;
use std::ffi::{c_void, CString};
use std::fs;
use std::io;
use std::mem;
use std::os::raw::{c_char, c_int, c_long};
use std::os::unix::ffi::OsStrExt;
use std::path::PathBuf;
use std::process;
use std::ptr;
use std::time::Instant;

use libbpf_sys::{bpf_object_open_opts, size_t};
use object::{Object, ObjectSection, ObjectSymbol};
use serde::Deserialize;

const XSIM_MAGIC: u32 = 0x314d5658;
const XSIM_OUTPUT_OFF: usize = 0;
const XSIM_HEADER_OFF: usize = 8;
const XSIM_CODE_OFF: usize = 16;
const XSIM_INSN_SIZE: usize = 16;
const XSIM_MAX_INSNS: usize = 32;
const XSIM_OP_MOV_IMM64: u8 = 0x01;
const XSIM_OP_RET: u8 = 0xff;
const XSIM_RAX: u8 = 0;

const BPF_PROG_TYPE_XDP: u32 = 6;
const XDP_PASS: u32 = 2;
const SIMPLE_EXPECTED: u64 = 12_345_678;
const ETHERNET_HEADER_SIZE: usize = 14;

const X86_SIM_DONE: i32 = 1;
const FLOW_NORMAL: u8 = 0;
const FLOW_JCC: u8 = 1;
const FLOW_JMP: u8 = 2;
const FLOW_CALL: u8 = 3;
const FLOW_RET: u8 = 4;

const BPF_PSEUDO_CALL: u8 = 1;
const BPF_REG_FP: u8 = 10;
const BPF_CALL_INSN: u8 = 0x85;
const BPF_EXIT_INSN: u8 = 0x95;
const BPF_LD_IMM64_DW: u8 = 0x18;
const BPF_MOV64_REG: u8 = 0xbf;
const BPF_ADD64_IMM: u8 = 0x07;
const BPF_LDX_MEM_W: u8 = 0x61;
const BPF_LDX_MEM_DW: u8 = 0x79;
const BPF_ST_MEM_DW: u8 = 0x7a;
const BPF_JA: u8 = 0x05;
const BPF_JNE_IMM: u8 = 0x55;

const X86_STATE_STACK_OFF: i16 = -432;
const X86_STATE_SIZE: i16 = 280;
const X86_CTX_STACK_OFF: i16 = -448;
const X86_STATE_RAX_OFF: i16 = 0;
const X86_STATE_P_RDI_OFF: i16 = 184;
const X86_PTR_CTX: i32 = 1;
const VERIFIER_LOG_SIZE: usize = 128 * 1024 * 1024;

type Result<T> = std::result::Result<T, String>;

struct Cli {
    object: Option<PathBuf>,
    json: Option<PathBuf>,
    case_name: String,
    expected_result: Option<u64>,
    expect_retval: u32,
    input: Option<PathBuf>,
    result_channel: ResultChannel,
    cgroup_skb_input: bool,
    load_only: bool,
    program: String,
    repeat: i32,
    template_object: Option<PathBuf>,
    verifier_log: Option<PathBuf>,
}

#[derive(Clone, Copy, PartialEq, Eq)]
enum ResultChannel {
    Packet,
    SkbCb,
}

#[derive(Deserialize)]
struct JsonProof {
    bpf_program: Option<JsonBpfProgram>,
    verifier_templates: Option<JsonVerifierTemplates>,
    linked_program: Option<JsonLinkedProgram>,
}

#[derive(Deserialize)]
struct JsonBpfProgram {
    insns: Vec<JsonBpfInsn>,
}

#[derive(Deserialize)]
struct JsonBpfInsn {
    code: u8,
    dst: u8,
    src: u8,
    #[serde(default)]
    off: i16,
    imm: i32,
    #[serde(default)]
    label: Option<String>,
    #[serde(default)]
    target: Option<String>,
    #[serde(default)]
    comment: Option<String>,
}

#[derive(Deserialize)]
struct JsonVerifierTemplates {
    steps: Vec<JsonTemplateStep>,
}

#[derive(Clone, Deserialize)]
struct JsonTemplateStep {
    index: usize,
    helper: String,
    args: JsonTemplateArgs,
    flow: u8,
    target: usize,
}

#[derive(Clone, Deserialize)]
struct JsonTemplateArgs {
    op: u8,
    dst: u8,
    src: u8,
    flags: u8,
    aux: u32,
    imm: u64,
}

#[derive(Deserialize)]
struct JsonLinkedProgram {
    insns: Vec<JsonLinkedInsn>,
}

#[derive(Deserialize)]
struct JsonLinkedInsn {
    index: usize,
    helper: String,
    op: u8,
    dst: u8,
    src: u8,
    flags: u8,
    aux: u32,
    imm: u64,
    flow: u8,
    target: usize,
}

struct LinkedProgram {
    insns: Vec<BpfInsn>,
}

struct BpfObject {
    ptr: *mut c_void,
    verifier_log: Option<VerifierLog>,
}

struct VerifierLog {
    path: PathBuf,
    buf: Vec<u8>,
}

#[repr(C)]
#[derive(Clone, Copy)]
struct BpfInsn {
    code: u8,
    regs: u8,
    off: i16,
    imm: i32,
}

struct TemplateCatalog {
    functions: HashMap<String, Vec<BpfInsn>>,
}

struct Linker {
    insns: Vec<BpfInsn>,
    branch_fixups: Vec<(usize, LinkTarget)>,
}

enum LinkTarget {
    Step(usize),
}

#[repr(C)]
#[derive(Clone, Copy)]
struct BpfTestRunOpts {
    sz: usize,
    data_in: *const c_void,
    data_out: *mut c_void,
    data_size_in: u32,
    data_size_out: u32,
    ctx_in: *const c_void,
    ctx_out: *mut c_void,
    ctx_size_in: u32,
    ctx_size_out: u32,
    retval: u32,
    repeat: c_int,
    duration: u32,
    flags: u32,
    cpu: u32,
    batch_size: u32,
}

#[repr(C)]
#[derive(Default)]
struct SkBuffCtx {
    len: u32,
    pkt_type: u32,
    mark: u32,
    queue_mapping: u32,
    protocol: u32,
    vlan_present: u32,
    vlan_tci: u32,
    vlan_proto: u32,
    priority: u32,
    ingress_ifindex: u32,
    ifindex: u32,
    tc_index: u32,
    cb: [u32; 5],
    hash: u32,
    tc_classid: u32,
    data: u32,
    data_end: u32,
    napi_id: u32,
    family: u32,
    remote_ip4: u32,
    local_ip4: u32,
    remote_ip6: [u32; 4],
    local_ip6: [u32; 4],
    remote_port: u32,
    local_port: u32,
    data_meta: u32,
    flow_keys: u64,
    tstamp: u64,
    wire_len: u32,
    gso_segs: u32,
    sk: u64,
    gso_size: u32,
    tstamp_type: u8,
    pad: [u8; 3],
    hwtstamp: u64,
}

impl Default for BpfTestRunOpts {
    fn default() -> Self {
        Self {
            sz: mem::size_of::<Self>(),
            data_in: ptr::null(),
            data_out: ptr::null_mut(),
            data_size_in: 0,
            data_size_out: 0,
            ctx_in: ptr::null(),
            ctx_out: ptr::null_mut(),
            ctx_size_in: 0,
            ctx_size_out: 0,
            retval: 0,
            repeat: 0,
            duration: 0,
            flags: 0,
            cpu: 0,
            batch_size: 0,
        }
    }
}

#[link(name = "bpf")]
extern "C" {
    fn bpf_object__open_file(path: *const c_char, opts: *const bpf_object_open_opts)
        -> *mut c_void;
    fn bpf_object__close(obj: *mut c_void);
    fn bpf_object__load(obj: *mut c_void) -> c_int;
    fn bpf_object__find_program_by_name(obj: *const c_void, name: *const c_char) -> *mut c_void;
    fn bpf_program__fd(prog: *const c_void) -> c_int;
    fn bpf_prog_test_run_opts(prog_fd: c_int, opts: *mut BpfTestRunOpts) -> c_int;
    fn libbpf_get_error(ptr: *const c_void) -> c_long;
}

impl Drop for BpfObject {
    fn drop(&mut self) {
        if !self.ptr.is_null() {
            unsafe { bpf_object__close(self.ptr) };
        }
    }
}

fn main() {
    if let Err(err) = run() {
        eprintln!("error: {err}");
        process::exit(1);
    }
}

fn run() -> Result<()> {
    let cli = parse_cli()?;
    let json_mode = cli.json.is_some();
    let verify_s: f64;
    let (prog_fd, loaded_name): (c_int, String) = if let Some(json) = &cli.json {
        let linked = build_json_linked_program(json, cli.template_object.as_ref())?;
        let start = Instant::now();
        let fd = match load_raw_xdp_program(&cli.program, &linked.insns) {
            Ok(fd) => fd,
            Err(err) => {
                print_timing(start.elapsed().as_secs_f64(), 0.0);
                return Err(err);
            }
        };
        verify_s = start.elapsed().as_secs_f64();
        (fd, json.display().to_string())
    } else {
        let object_path = cli
            .object
            .as_ref()
            .ok_or_else(|| "--object or --json is required".to_string())?;
        let mut object = open_object(object_path, cli.verifier_log.clone())?;
        let start = Instant::now();
        if let Err(err) = load_object(&mut object) {
            print_timing(start.elapsed().as_secs_f64(), 0.0);
            return Err(err);
        }
        verify_s = start.elapsed().as_secs_f64();
        let fd = program_fd(&object, &cli.program)?;
        if cli.load_only {
            println!(
                "loaded object={} program={} fd={}",
                object_path.display(),
                cli.program,
                fd
            );
            print_timing(verify_s, 0.0);
            return Ok(());
        }
        std::mem::forget(object);
        (fd, object_path.display().to_string())
    };

    if cli.load_only {
        println!(
            "loaded input={} program={} fd={}",
            loaded_name, cli.program, prog_fd
        );
        print_timing(verify_s, 0.0);
        return Ok(());
    }

    let mut input = if let Some(path) = &cli.input {
        build_packet_input(path, cli.cgroup_skb_input)?
    } else {
        build_default_case_input(&cli.case_name, json_mode, cli.cgroup_skb_input)?
    };
    let mut output = input.clone();
    let mut skb_ctx_out = SkBuffCtx::default();
    let mut opts = BpfTestRunOpts {
        data_in: input.as_mut_ptr().cast::<c_void>(),
        data_out: output.as_mut_ptr().cast::<c_void>(),
        data_size_in: input.len() as u32,
        data_size_out: output.len() as u32,
        repeat: cli.repeat,
        ..Default::default()
    };
    if cli.result_channel == ResultChannel::SkbCb {
        opts.ctx_out = (&mut skb_ctx_out as *mut SkBuffCtx).cast::<c_void>();
        opts.ctx_size_out = mem::size_of::<SkBuffCtx>() as u32;
    }

    let start = Instant::now();
    let ret = unsafe { bpf_prog_test_run_opts(prog_fd, &mut opts) };
    let test_s = start.elapsed().as_secs_f64();
    if ret != 0 {
        print_timing(verify_s, test_s);
        return Err(format!(
            "bpf_prog_test_run_opts failed: {}",
            io::Error::last_os_error()
        ));
    }
    if opts.retval != cli.expect_retval {
        print_timing(verify_s, test_s);
        return Err(format!(
            "unexpected XDP retval: got {}, expected {}",
            opts.retval, cli.expect_retval
        ));
    }
    if opts.data_size_out < 8 {
        print_timing(verify_s, test_s);
        return Err(format!("short data_size_out: {}", opts.data_size_out));
    }

    let result = match cli.result_channel {
        ResultChannel::Packet => read_le_u64(&output[XSIM_OUTPUT_OFF..XSIM_OUTPUT_OFF + 8]),
        ResultChannel::SkbCb => u64::from(skb_ctx_out.cb[0]) | (u64::from(skb_ctx_out.cb[1]) << 32),
    };
    let expected_result = cli.expected_result.unwrap_or(SIMPLE_EXPECTED);
    if result != expected_result {
        print_timing(verify_s, test_s);
        return Err(format!(
            "result mismatch: got {result}, expected {expected_result}"
        ));
    }

    println!(
        "case={} retval={} result={} repeat={} data_size_out={}",
        cli.case_name, opts.retval, result, cli.repeat, opts.data_size_out
    );
    print_timing(verify_s, test_s);
    Ok(())
}

fn print_timing(verify_s: f64, test_s: f64) {
    println!("timing verify_s={verify_s:.6} test_s={test_s:.6}");
}

fn parse_cli() -> Result<Cli> {
    let mut args = env::args().skip(1);
    let mut object = None;
    let mut json = None;
    let mut case_name = String::from("simple");
    let mut expected_result = None;
    let mut expect_retval = XDP_PASS;
    let mut input = None;
    let mut result_channel = ResultChannel::Packet;
    let mut cgroup_skb_input = false;
    let mut load_only = false;
    let mut program = String::from("x86_sim_xdp");
    let mut repeat = 1;
    let mut template_object = None;
    let mut verifier_log = None;

    while let Some(arg) = args.next() {
        match arg.as_str() {
            "--object" => {
                object = Some(PathBuf::from(
                    args.next()
                        .ok_or_else(|| "--object requires a path".to_string())?,
                ));
            }
            "--json" => {
                json = Some(PathBuf::from(
                    args.next()
                        .ok_or_else(|| "--json requires a path".to_string())?,
                ));
            }
            "--case" => {
                case_name = args
                    .next()
                    .ok_or_else(|| "--case requires a name".to_string())?;
            }
            "--expected-result" => {
                let value = args
                    .next()
                    .ok_or_else(|| "--expected-result requires a u64".to_string())?;
                expected_result = Some(
                    value
                        .parse::<u64>()
                        .map_err(|err| format!("invalid --expected-result {value}: {err}"))?,
                );
            }
            "--expect-retval" => {
                let value = args
                    .next()
                    .ok_or_else(|| "--expect-retval requires a u32".to_string())?;
                expect_retval = value
                    .parse::<u32>()
                    .map_err(|err| format!("invalid --expect-retval {value}: {err}"))?;
            }
            "--input" => {
                input = Some(PathBuf::from(
                    args.next()
                        .ok_or_else(|| "--input requires a path".to_string())?,
                ));
            }
            "--result-channel" => {
                let value = args
                    .next()
                    .ok_or_else(|| "--result-channel requires packet or skb-cb".to_string())?;
                result_channel = match value.as_str() {
                    "packet" => ResultChannel::Packet,
                    "skb-cb" => ResultChannel::SkbCb,
                    _ => {
                        return Err(format!(
                            "invalid --result-channel {value}: expected packet or skb-cb"
                        ));
                    }
                };
            }
            "--cgroup-skb-input" => {
                cgroup_skb_input = true;
            }
            "--load-only" => {
                load_only = true;
            }
            "--program" => {
                program = args
                    .next()
                    .ok_or_else(|| "--program requires a BPF program name".to_string())?;
            }
            "--repeat" => {
                let value = args
                    .next()
                    .ok_or_else(|| "--repeat requires a count".to_string())?;
                repeat = value
                    .parse::<i32>()
                    .map_err(|err| format!("invalid --repeat {value}: {err}"))?;
                if repeat <= 0 {
                    return Err("--repeat must be positive".to_string());
                }
            }
            "--template-object" => {
                template_object =
                    Some(PathBuf::from(args.next().ok_or_else(|| {
                        "--template-object requires a path".to_string()
                    })?));
            }
            "--verifier-log" => {
                verifier_log =
                    Some(PathBuf::from(args.next().ok_or_else(|| {
                        "--verifier-log requires a path".to_string()
                    })?));
            }
            "-h" | "--help" => {
                print_help();
                process::exit(0);
            }
            other => return Err(format!("unknown argument: {other}")),
        }
    }

    if object.is_some() == json.is_some() {
        return Err("exactly one of --object or --json is required".to_string());
    }

    Ok(Cli {
        object,
        json,
        case_name,
        expected_result,
        expect_retval,
        input,
        result_channel,
        cgroup_skb_input,
        load_only,
        program,
        repeat,
        template_object,
        verifier_log,
    })
}

fn print_help() {
    println!(
        "Usage: reversesim-loader (--object <sim.bpf.o>|--json proof.json) [--template-object helpers.bpf.o] [--program x86_sim_xdp] [--load-only] [--verifier-log log.txt] [--case simple|--input payload.mem --expected-result N] [--result-channel packet|skb-cb] [--cgroup-skb-input] [--repeat N]"
    );
}

fn open_object(path: &PathBuf, verifier_log_path: Option<PathBuf>) -> Result<BpfObject> {
    let c_path = CString::new(path.as_os_str().as_bytes())
        .map_err(|_| format!("path contains NUL byte: {}", path.display()))?;
    let mut verifier_log = verifier_log_path.map(|path| VerifierLog {
        path,
        buf: vec![0; VERIFIER_LOG_SIZE],
    });
    let opts = verifier_log.as_mut().map(|log| {
        let mut opts = bpf_object_open_opts::default();
        opts.sz = mem::size_of::<bpf_object_open_opts>() as size_t;
        opts.kernel_log_buf = log.buf.as_mut_ptr().cast::<c_char>();
        opts.kernel_log_size = log.buf.len() as size_t;
        opts.kernel_log_level = 1;
        opts
    });
    let opts_ptr = opts
        .as_ref()
        .map(|opts| opts as *const bpf_object_open_opts)
        .unwrap_or(ptr::null());
    let obj = unsafe { bpf_object__open_file(c_path.as_ptr(), opts_ptr) };
    if obj.is_null() {
        return Err(format!(
            "failed to open {}: {}",
            path.display(),
            io::Error::last_os_error()
        ));
    }
    let err = unsafe { libbpf_get_error(obj.cast::<c_void>()) };
    if err != 0 {
        return Err(format!(
            "failed to open {}: libbpf error {err}",
            path.display()
        ));
    }
    Ok(BpfObject {
        ptr: obj,
        verifier_log,
    })
}

fn load_object(object: &mut BpfObject) -> Result<()> {
    let ret = unsafe { bpf_object__load(object.ptr) };
    let log_path = flush_verifier_log(object)?;
    if ret != 0 {
        let mut message = format!("bpf_object__load failed: {}", io::Error::last_os_error());
        if let Some(path) = log_path {
            message.push_str(&format!("; verifier log: {}", path.display()));
        }
        return Err(message);
    }
    Ok(())
}

fn flush_verifier_log(object: &BpfObject) -> Result<Option<PathBuf>> {
    let Some(log) = object.verifier_log.as_ref() else {
        return Ok(None);
    };
    let end = log
        .buf
        .iter()
        .position(|byte| *byte == 0)
        .unwrap_or(log.buf.len());
    fs::write(&log.path, &log.buf[..end])
        .map_err(|err| format!("write verifier log {}: {err}", log.path.display()))?;
    Ok(Some(log.path.clone()))
}

fn program_fd(object: &BpfObject, name: &str) -> Result<i32> {
    let c_name = CString::new(name).map_err(|_| format!("program name contains NUL: {name}"))?;
    let prog = unsafe { bpf_object__find_program_by_name(object.ptr, c_name.as_ptr()) };
    if prog.is_null() {
        return Err(format!("program not found in object: {name}"));
    }
    let fd = unsafe { bpf_program__fd(prog) };
    if fd < 0 {
        return Err(format!("invalid fd for program {name}: {fd}"));
    }
    Ok(fd)
}

fn build_json_linked_program(
    path: &PathBuf,
    template_object: Option<&PathBuf>,
) -> Result<LinkedProgram> {
    let text = fs::read_to_string(path).map_err(|err| format!("read {}: {err}", path.display()))?;
    let proof: JsonProof =
        serde_json::from_str(&text).map_err(|err| format!("parse {}: {err}", path.display()))?;
    if let Some(program) = proof.bpf_program.as_ref() {
        return Ok(LinkedProgram {
            insns: link_bpf_program(program)?,
        });
    }
    let steps = json_template_steps(&proof)
        .ok_or_else(|| format!("{} has no verifier_templates section", path.display()))?;
    let template_object = template_object.ok_or_else(|| {
        format!(
            "{} uses verifier_templates and requires --template-object",
            path.display()
        )
    })?;
    let catalog = TemplateCatalog::load(template_object)?;
    let insns = link_template_program(&steps, &catalog)?;
    if let Ok(path) = env::var("REVERSESIM_DUMP_INSNS") {
        dump_bpf_insns(&PathBuf::from(path), &insns)?;
    }
    Ok(LinkedProgram { insns })
}

fn link_bpf_program(program: &JsonBpfProgram) -> Result<Vec<BpfInsn>> {
    let mut labels = HashMap::new();
    for (index, insn) in program.insns.iter().enumerate() {
        if let Some(label) = &insn.label {
            if labels.insert(label.as_str(), index).is_some() {
                return Err(format!("duplicate BPF label: {label}"));
            }
        }
    }

    let mut out = Vec::with_capacity(program.insns.len());
    for insn in &program.insns {
        let _comment = &insn.comment;
        out.push(BpfInsn {
            code: insn.code,
            regs: (insn.dst & 0x0f) | ((insn.src & 0x0f) << 4),
            off: insn.off,
            imm: insn.imm,
        });
    }

    for (index, insn) in program.insns.iter().enumerate() {
        if let Some(target) = &insn.target {
            let target_index = *labels
                .get(target.as_str())
                .ok_or_else(|| format!("missing BPF label: {target}"))?;
            let off = target_index as isize - index as isize - 1;
            if off < i16::MIN as isize || off > i16::MAX as isize {
                return Err(format!("branch offset out of range at insn {index}: {off}"));
            }
            out[index].off = off as i16;
        }
    }

    Ok(out)
}

fn json_template_steps(proof: &JsonProof) -> Option<Vec<JsonTemplateStep>> {
    if let Some(linked) = &proof.linked_program {
        return Some(
            linked
                .insns
                .iter()
                .map(|insn| JsonTemplateStep {
                    index: insn.index,
                    helper: insn.helper.clone(),
                    args: JsonTemplateArgs {
                        op: insn.op,
                        dst: insn.dst,
                        src: insn.src,
                        flags: insn.flags,
                        aux: insn.aux,
                        imm: insn.imm,
                    },
                    flow: insn.flow,
                    target: insn.target,
                })
                .collect(),
        );
    }
    proof.verifier_templates.as_ref().map(|templates| {
        templates
            .steps
            .iter()
            .map(|step| JsonTemplateStep {
                index: step.index,
                helper: step.helper.clone(),
                args: JsonTemplateArgs {
                    op: step.args.op,
                    dst: step.args.dst,
                    src: step.args.src,
                    flags: step.args.flags,
                    aux: step.args.aux,
                    imm: step.args.imm,
                },
                flow: step.flow,
                target: step.target,
            })
            .collect()
    })
}

fn link_template_program(
    steps: &[JsonTemplateStep],
    catalog: &TemplateCatalog,
) -> Result<Vec<BpfInsn>> {
    if steps.is_empty() {
        return Err("JSON template program has no steps".to_string());
    }
    for (expected, step) in steps.iter().enumerate() {
        if step.index != expected {
            return Err(format!(
                "template steps must be dense and ordered: got index {}, expected {expected}",
                step.index
            ));
        }
    }

    let reachable = reachable_template_steps(steps)?;
    let mut linker = Linker::new();
    linker.emit_prologue();
    let mut step_offsets = vec![None; steps.len()];
    for step in steps {
        if !reachable[step.index] {
            continue;
        }
        step_offsets[step.index] = Some(linker.insns.len());
        linker.emit_step(step, catalog)?;
    }
    linker.resolve(step_offsets)?;
    Ok(linker.insns)
}

fn reachable_template_steps(steps: &[JsonTemplateStep]) -> Result<Vec<bool>> {
    let mut reachable = vec![false; steps.len()];
    let mut stack = vec![0usize];
    while let Some(index) = stack.pop() {
        let Some(step) = steps.get(index) else {
            return Err(format!("CFG step out of range: {index}"));
        };
        if reachable[index] {
            continue;
        }
        reachable[index] = true;
        match step.flow {
            FLOW_NORMAL => {
                if index + 1 < steps.len() {
                    stack.push(index + 1);
                }
            }
            FLOW_JCC => {
                if step.target >= steps.len() {
                    return Err(format!(
                        "conditional branch target out of range at step {}: {}",
                        step.index, step.target
                    ));
                }
                stack.push(step.target);
                if index + 1 < steps.len() {
                    stack.push(index + 1);
                }
            }
            FLOW_JMP => {
                if step.target >= steps.len() {
                    return Err(format!(
                        "branch target out of range at step {}: {}",
                        step.index, step.target
                    ));
                }
                stack.push(step.target);
            }
            FLOW_CALL => {
                if step.target >= steps.len() {
                    return Err(format!(
                        "call target out of range at step {}: {}",
                        step.index, step.target
                    ));
                }
                stack.push(step.target);
                if index + 1 < steps.len() {
                    stack.push(index + 1);
                }
            }
            FLOW_RET => {}
            other => return Err(format!("unsupported flow {other} at step {}", step.index)),
        }
    }
    Ok(reachable)
}

fn template_symbol(helper: &str) -> String {
    let symbol = helper
        .strip_prefix("x86_exec_")
        .map(|suffix| format!("x86_tmpl_{suffix}"))
        .unwrap_or_else(|| helper.to_string());
    match symbol.as_str() {
        "x86_tmpl_add_imm" => "x86_tmpl_alu_imm".to_string(),
        "x86_tmpl_add_reg" | "x86_tmpl_xor_reg" => "x86_tmpl_alu_reg".to_string(),
        "x86_tmpl_jmp" | "x86_tmpl_call" => "x86_tmpl_nop".to_string(),
        _ => symbol,
    }
}

fn arg_template_symbol(helper: &str, args: &JsonTemplateArgs) -> Result<String> {
    let base = template_symbol(helper).replacen("x86_tmpl_", "x86_tmpl_arg_", 1);
    match base.as_str() {
        "x86_tmpl_arg_alu_imm" | "x86_tmpl_arg_alu_reg" => {
            Ok(format!("{base}_{}", alu_suffix(args.aux as u8)?))
        }
        "x86_tmpl_arg_alu_mem" => Ok(format!("{base}_{}", alu_suffix((args.aux >> 24) as u8)?)),
        _ => Ok(base),
    }
}

fn packed_template_args(args: &JsonTemplateArgs) -> u64 {
    (args.op as u64)
        | ((args.dst as u64) << 8)
        | ((args.src as u64) << 16)
        | ((args.flags as u64) << 24)
        | ((args.aux as u64) << 32)
}

fn alu_suffix(alu: u8) -> Result<&'static str> {
    match alu {
        0 => Ok("add"),
        1 => Ok("sub"),
        2 => Ok("xor"),
        3 => Ok("or"),
        4 => Ok("and"),
        5 => Ok("shl"),
        6 => Ok("shr"),
        7 => Ok("sar"),
        8 => Ok("rol"),
        9 => Ok("imul"),
        10 => Ok("inc"),
        11 => Ok("not"),
        12 => Ok("sbb"),
        other => Err(format!("unsupported ALU selector: {other}")),
    }
}

impl TemplateCatalog {
    fn load(path: &PathBuf) -> Result<Self> {
        let bytes = fs::read(path).map_err(|err| format!("read {}: {err}", path.display()))?;
        let file = object::File::parse(bytes.as_slice())
            .map_err(|err| format!("parse template object {}: {err}", path.display()))?;
        let text = file
            .section_by_name(".text")
            .ok_or_else(|| format!("{} has no .text section", path.display()))?;
        let text_data = text
            .data()
            .map_err(|err| format!("read .text from {}: {err}", path.display()))?;
        let text_addr = text.address();
        let text_index = text.index();
        let mut functions = HashMap::new();
        for symbol in file.symbols() {
            if symbol.section_index() != Some(text_index) {
                continue;
            }
            let Ok(name) = symbol.name() else {
                continue;
            };
            if !name.starts_with("x86_tmpl_") || symbol.size() == 0 {
                continue;
            }
            let start = symbol
                .address()
                .checked_sub(text_addr)
                .ok_or_else(|| format!("bad symbol address for {name}"))?
                as usize;
            let size = symbol.size() as usize;
            let end = start
                .checked_add(size)
                .ok_or_else(|| format!("symbol size overflow for {name}"))?;
            if end > text_data.len() || size % mem::size_of::<BpfInsn>() != 0 {
                return Err(format!("bad BPF text range for template symbol {name}"));
            }
            functions.insert(name.to_string(), parse_bpf_insns(&text_data[start..end])?);
        }
        Ok(Self { functions })
    }
}

fn parse_bpf_insns(bytes: &[u8]) -> Result<Vec<BpfInsn>> {
    if bytes.len() % 8 != 0 {
        return Err(format!(
            "BPF byte length is not instruction-aligned: {}",
            bytes.len()
        ));
    }
    let mut out = Vec::with_capacity(bytes.len() / 8);
    for chunk in bytes.chunks_exact(8) {
        let regs = chunk[1];
        out.push(BpfInsn {
            code: chunk[0],
            regs,
            off: i16::from_le_bytes([chunk[2], chunk[3]]),
            imm: i32::from_le_bytes([chunk[4], chunk[5], chunk[6], chunk[7]]),
        });
    }
    Ok(out)
}

fn dump_bpf_insns(path: &PathBuf, insns: &[BpfInsn]) -> Result<()> {
    let mut text = String::new();
    for (index, insn) in insns.iter().enumerate() {
        text.push_str(&format!(
            "{index:05}: code=0x{:02x} dst={} src={} off={} imm={}\n",
            insn.code,
            insn.regs & 0x0f,
            (insn.regs >> 4) & 0x0f,
            insn.off,
            insn.imm
        ));
    }
    fs::write(path, text).map_err(|err| format!("write {}: {err}", path.display()))
}

impl Linker {
    fn new() -> Self {
        Self {
            insns: Vec::new(),
            branch_fixups: Vec::new(),
        }
    }

    fn emit(&mut self, code: u8, dst: u8, src: u8, off: i16, imm: i32) -> usize {
        let index = self.insns.len();
        self.insns.push(BpfInsn {
            code,
            regs: (dst & 0x0f) | ((src & 0x0f) << 4),
            off,
            imm,
        });
        index
    }

    fn emit_raw(&mut self, insn: BpfInsn) -> usize {
        let index = self.insns.len();
        self.insns.push(insn);
        index
    }

    fn emit_prologue(&mut self) {
        self.emit_mov64_reg(6, 1);
        self.emit_stx_mem_dw(BPF_REG_FP, 6, X86_CTX_STACK_OFF);
        self.emit_ldx_mem_w(8, 6, 0);
        self.emit_ldx_mem_w(7, 6, 4);
        self.emit_mov64_reg(9, BPF_REG_FP);
        self.emit_add64_imm(9, X86_STATE_STACK_OFF as i32);
        for off in (X86_STATE_STACK_OFF..X86_STATE_STACK_OFF + X86_STATE_SIZE).step_by(8) {
            self.emit_st_mem_dw(BPF_REG_FP, off, 0);
        }
        self.emit_st_mem_dw(9, X86_STATE_P_RDI_OFF, X86_PTR_CTX);
        self.emit_reload_link_regs();
    }

    fn emit_step(&mut self, step: &JsonTemplateStep, catalog: &TemplateCatalog) -> Result<()> {
        match step.flow {
            FLOW_NORMAL => {
                self.emit_helper_step(step, catalog)?;
                self.emit_done_check_local();
            }
            FLOW_JCC => {
                self.emit_helper_step(step, catalog)?;
                self.emit_jne_imm_fixup(0, 0, LinkTarget::Step(step.target));
            }
            FLOW_JMP => {
                self.emit_jump(LinkTarget::Step(step.target));
            }
            FLOW_RET => {
                self.emit_helper_step(step, catalog)?;
                self.emit_return_rax_local();
            }
            FLOW_CALL => {
                return Err(format!(
                    "JSON template linker does not support native call flow yet at step {}",
                    step.index
                ));
            }
            other => return Err(format!("unsupported flow {other} at step {}", step.index)),
        }
        Ok(())
    }

    fn emit_done_check_local(&mut self) {
        self.emit(BPF_JNE_IMM, 0, 0, 2, X86_SIM_DONE);
        self.emit_return_rax_local();
    }

    fn emit_return_rax_local(&mut self) {
        self.emit_ldx_mem_dw(0, 9, X86_STATE_RAX_OFF);
        self.emit_exit();
    }

    fn emit_helper_step(
        &mut self,
        step: &JsonTemplateStep,
        catalog: &TemplateCatalog,
    ) -> Result<()> {
        self.emit_mov64_reg(1, 9);
        self.emit_mov64_reg(2, 8);
        self.emit_mov64_reg(3, 7);
        self.emit_ldimm64(4, packed_template_args(&step.args));
        self.emit_ldimm64(5, step.args.imm);
        self.emit_template_inline(&arg_template_symbol(&step.helper, &step.args)?, catalog)
    }

    fn emit_template_inline(&mut self, symbol: &str, catalog: &TemplateCatalog) -> Result<()> {
        let body = catalog
            .functions
            .get(symbol)
            .ok_or_else(|| format!("template helper missing from C object: {symbol}"))?;
        let mut exits = Vec::new();
        for (offset, insn) in body.iter().enumerate() {
            if insn.code == BPF_CALL_INSN && ((insn.regs >> 4) & 0x0f) == BPF_PSEUDO_CALL {
                return Err(format!(
                    "template fragment {symbol} contains unresolved BPF subprogram call at body insn {offset}"
                ));
            }
            if insn.code == BPF_EXIT_INSN {
                let index = self.emit(BPF_JA, 0, 0, 0, 0);
                exits.push(index);
            } else {
                self.emit_raw(*insn);
            }
        }
        let after = self.insns.len();
        for index in exits {
            let off = after as isize - index as isize - 1;
            if off < i16::MIN as isize || off > i16::MAX as isize {
                return Err(format!(
                    "template fragment exit offset out of range in {symbol}: {off}"
                ));
            }
            self.insns[index].off = off as i16;
        }
        self.emit_reload_link_regs();
        Ok(())
    }

    fn emit_reload_link_regs(&mut self) {
        self.emit_ldx_mem_dw(6, BPF_REG_FP, X86_CTX_STACK_OFF);
        self.emit_ldx_mem_w(8, 6, 0);
        self.emit_ldx_mem_w(7, 6, 4);
        self.emit_mov64_reg(9, BPF_REG_FP);
        self.emit_add64_imm(9, X86_STATE_STACK_OFF as i32);
    }

    fn emit_jump(&mut self, target: LinkTarget) {
        let index = self.emit(BPF_JA, 0, 0, 0, 0);
        self.branch_fixups.push((index, target));
    }

    fn emit_jne_imm_fixup(&mut self, dst: u8, imm: i32, target: LinkTarget) {
        let index = self.emit(BPF_JNE_IMM, dst, 0, 0, imm);
        self.branch_fixups.push((index, target));
    }

    fn emit_mov64_reg(&mut self, dst: u8, src: u8) {
        self.emit(BPF_MOV64_REG, dst, src, 0, 0);
    }

    fn emit_add64_imm(&mut self, dst: u8, imm: i32) {
        self.emit(BPF_ADD64_IMM, dst, 0, 0, imm);
    }

    fn emit_ldx_mem_w(&mut self, dst: u8, src: u8, off: i16) {
        self.emit(BPF_LDX_MEM_W, dst, src, off, 0);
    }

    fn emit_ldx_mem_dw(&mut self, dst: u8, src: u8, off: i16) {
        self.emit(BPF_LDX_MEM_DW, dst, src, off, 0);
    }

    fn emit_st_mem_dw(&mut self, dst: u8, off: i16, imm: i32) {
        self.emit(BPF_ST_MEM_DW, dst, 0, off, imm);
    }

    fn emit_stx_mem_dw(&mut self, dst: u8, src: u8, off: i16) {
        self.emit(0x7b, dst, src, off, 0);
    }

    fn emit_ldimm64(&mut self, dst: u8, imm: u64) {
        self.emit(BPF_LD_IMM64_DW, dst, 0, 0, imm as u32 as i32);
        self.emit(0, 0, 0, 0, (imm >> 32) as u32 as i32);
    }

    fn emit_exit(&mut self) {
        self.emit(BPF_EXIT_INSN, 0, 0, 0, 0);
    }

    fn resolve(&mut self, step_offsets: Vec<Option<usize>>) -> Result<()> {
        for (index, target) in &self.branch_fixups {
            let target_index = match target {
                LinkTarget::Step(step) => step_offsets
                    .get(*step)
                    .ok_or_else(|| format!("branch target step out of range: {step}"))?
                    .ok_or_else(|| format!("branch target step was not emitted: {step}"))?,
            };
            let off = target_index as isize - *index as isize - 1;
            if off < i16::MIN as isize || off > i16::MAX as isize {
                return Err(format!("branch offset out of range at insn {index}: {off}"));
            }
            self.insns[*index].off = off as i16;
        }
        Ok(())
    }
}

fn load_raw_xdp_program(name: &str, insns: &[BpfInsn]) -> Result<c_int> {
    let c_name = CString::new(name).map_err(|_| format!("program name contains NUL: {name}"))?;
    let license = CString::new("GPL").expect("static license");
    let mut opts = libbpf_sys::bpf_prog_load_opts {
        sz: mem::size_of::<libbpf_sys::bpf_prog_load_opts>() as libbpf_sys::size_t,
        ..Default::default()
    };
    let fd = unsafe {
        libbpf_sys::bpf_prog_load(
            BPF_PROG_TYPE_XDP,
            c_name.as_ptr(),
            license.as_ptr(),
            insns.as_ptr().cast::<libbpf_sys::bpf_insn>(),
            insns.len() as libbpf_sys::size_t,
            &mut opts,
        )
    };
    if fd >= 0 {
        return Ok(fd);
    }

    let mut log_buf = vec![0 as c_char; 16 * 1024 * 1024];
    let mut opts = libbpf_sys::bpf_prog_load_opts {
        sz: mem::size_of::<libbpf_sys::bpf_prog_load_opts>() as libbpf_sys::size_t,
        log_level: 2,
        log_size: log_buf.len() as u32,
        log_buf: log_buf.as_mut_ptr(),
        ..Default::default()
    };
    let diagnostic_fd = unsafe {
        libbpf_sys::bpf_prog_load(
            BPF_PROG_TYPE_XDP,
            c_name.as_ptr(),
            license.as_ptr(),
            insns.as_ptr().cast::<libbpf_sys::bpf_insn>(),
            insns.len() as libbpf_sys::size_t,
            &mut opts,
        )
    };
    if diagnostic_fd >= 0 {
        return Ok(diagnostic_fd);
    }
    let verifier = log_buf_to_string(&log_buf);
    Err(format!(
        "bpf_prog_load JSON-linked program failed: {}\n{}",
        io::Error::last_os_error(),
        verifier
    ))
}

fn log_buf_to_string(log_buf: &[c_char]) -> String {
    let nul = log_buf
        .iter()
        .position(|ch| *ch == 0)
        .unwrap_or(log_buf.len());
    let bytes: Vec<u8> = log_buf[..nul].iter().map(|ch| *ch as u8).collect();
    String::from_utf8_lossy(&bytes).into_owned()
}

fn build_default_case_input(
    case_name: &str,
    json_mode: bool,
    cgroup_skb_input: bool,
) -> Result<Vec<u8>> {
    if json_mode {
        let path = PathBuf::from("micro/generated-inputs").join(format!("{case_name}.mem"));
        return build_packet_input(&path, cgroup_skb_input);
    }
    match case_name {
        "simple" => Ok(build_simple_case()),
        other => Err(format!("unsupported case without --input: {other}")),
    }
}

fn build_simple_case() -> Vec<u8> {
    let mut data = vec![0u8; XSIM_CODE_OFF + 2 * XSIM_INSN_SIZE];
    write_le_u32(&mut data[XSIM_HEADER_OFF..XSIM_HEADER_OFF + 4], XSIM_MAGIC);
    write_le_u16(&mut data[XSIM_HEADER_OFF + 4..XSIM_HEADER_OFF + 6], 2);
    encode_insn(
        &mut data,
        0,
        XSIM_OP_MOV_IMM64,
        XSIM_RAX,
        0,
        SIMPLE_EXPECTED,
    );
    encode_insn(&mut data, 1, XSIM_OP_RET, 0, 0, 0);
    data
}

fn build_packet_input(path: &PathBuf, cgroup_skb_input: bool) -> Result<Vec<u8>> {
    let payload = fs::read(path).map_err(|err| format!("read {}: {err}", path.display()))?;
    let prefix = if cgroup_skb_input {
        ETHERNET_HEADER_SIZE
    } else {
        0
    };
    let mut data = vec![0u8; prefix + 8 + payload.len()];
    if cgroup_skb_input {
        data[12] = 0x08;
        data[13] = 0x00;
    }
    data[prefix + 8..].copy_from_slice(&payload);
    Ok(data)
}

fn encode_insn(data: &mut [u8], index: usize, op: u8, dst: u8, src: u8, imm: u64) {
    assert!(index < XSIM_MAX_INSNS);
    let off = XSIM_CODE_OFF + index * XSIM_INSN_SIZE;
    data[off] = op;
    data[off + 1] = dst;
    data[off + 2] = src;
    write_le_u64(&mut data[off + 8..off + 16], imm);
}

fn write_le_u16(out: &mut [u8], value: u16) {
    out.copy_from_slice(&value.to_le_bytes());
}

fn write_le_u32(out: &mut [u8], value: u32) {
    out.copy_from_slice(&value.to_le_bytes());
}

fn write_le_u64(out: &mut [u8], value: u64) {
    out.copy_from_slice(&value.to_le_bytes());
}

fn read_le_u64(input: &[u8]) -> u64 {
    let mut bytes = [0u8; 8];
    bytes.copy_from_slice(input);
    u64::from_le_bytes(bytes)
}
