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

use serde::Deserialize;

const XVM_MAGIC: u32 = 0x314d5658;
const XVM_OUTPUT_OFF: usize = 0;
const XVM_HEADER_OFF: usize = 8;
const XVM_CODE_OFF: usize = 16;
const XVM_INSN_SIZE: usize = 16;
const XVM_MAX_INSNS: usize = 32;
const XVM_OP_MOV_IMM64: u8 = 0x01;
const XVM_OP_RET: u8 = 0xff;
const XVM_RAX: u8 = 0;

const BPF_PROG_TYPE_XDP: u32 = 6;
const XDP_PASS: u32 = 2;
const SIMPLE_EXPECTED: u64 = 12_345_678;

type Result<T> = std::result::Result<T, String>;

struct Cli {
    object: Option<PathBuf>,
    json: Option<PathBuf>,
    case_name: String,
    expected_result: Option<u64>,
    expect_retval: u32,
    input: Option<PathBuf>,
    load_only: bool,
    program: String,
    repeat: i32,
}

#[derive(Deserialize)]
struct JsonProof {
    bpf_program: Option<JsonBpfProgram>,
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

struct BpfObject {
    ptr: *mut c_void,
}

#[repr(C)]
#[derive(Clone, Copy)]
struct BpfInsn {
    code: u8,
    regs: u8,
    off: i16,
    imm: i32,
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
    fn bpf_object__open_file(path: *const c_char, opts: *const c_void) -> *mut c_void;
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
    let (prog_fd, loaded_name): (c_int, String) = if let Some(json) = &cli.json {
        let insns = build_json_linked_program(json)?;
        (load_raw_xdp_program(&cli.program, &insns)?, json.display().to_string())
    } else {
        let object_path = cli
            .object
            .as_ref()
            .ok_or_else(|| "--object or --json is required".to_string())?;
        let mut object = open_object(object_path)?;
        load_object(&mut object)?;
        let fd = program_fd(&object, &cli.program)?;
        if cli.load_only {
            println!(
                "loaded object={} program={} fd={}",
                object_path.display(),
                cli.program,
                fd
            );
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
        return Ok(());
    }

    let mut input = if let Some(path) = &cli.input {
        build_packet_input(path)?
    } else {
        build_default_case_input(&cli.case_name, json_mode)?
    };
    let mut output = input.clone();
    let mut opts = BpfTestRunOpts {
        data_in: input.as_mut_ptr().cast::<c_void>(),
        data_out: output.as_mut_ptr().cast::<c_void>(),
        data_size_in: input.len() as u32,
        data_size_out: output.len() as u32,
        repeat: cli.repeat,
        ..Default::default()
    };

    let ret = unsafe { bpf_prog_test_run_opts(prog_fd, &mut opts) };
    if ret != 0 {
        return Err(format!(
            "bpf_prog_test_run_opts failed: {}",
            io::Error::last_os_error()
        ));
    }
    if opts.retval != cli.expect_retval {
        return Err(format!(
            "unexpected XDP retval: got {}, expected {}",
            opts.retval, cli.expect_retval
        ));
    }
    if opts.data_size_out < 8 {
        return Err(format!("short data_size_out: {}", opts.data_size_out));
    }

    let result = read_le_u64(&output[XVM_OUTPUT_OFF..XVM_OUTPUT_OFF + 8]);
    let expected_result = cli.expected_result.unwrap_or(SIMPLE_EXPECTED);
    if result != expected_result {
        return Err(format!(
            "result mismatch: got {result}, expected {expected_result}"
        ));
    }

    println!(
        "case={} retval={} result={} repeat={} data_size_out={}",
        cli.case_name, opts.retval, result, cli.repeat, opts.data_size_out
    );
    Ok(())
}

fn parse_cli() -> Result<Cli> {
    let mut args = env::args().skip(1);
    let mut object = None;
    let mut json = None;
    let mut case_name = String::from("simple");
    let mut expected_result = None;
    let mut expect_retval = XDP_PASS;
    let mut input = None;
    let mut load_only = false;
    let mut program = String::from("x86_vm_xdp");
    let mut repeat = 1;

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
        load_only,
        program,
        repeat,
    })
}

fn print_help() {
    println!(
        "Usage: ebpf-vm-loader (--object <vm.bpf.o>|--json proof.json) [--program x86_vm_xdp] [--load-only] [--case simple|--input payload.mem --expected-result N] [--repeat N]"
    );
}

fn open_object(path: &PathBuf) -> Result<BpfObject> {
    let c_path = CString::new(path.as_os_str().as_bytes())
        .map_err(|_| format!("path contains NUL byte: {}", path.display()))?;
    let obj = unsafe { bpf_object__open_file(c_path.as_ptr(), ptr::null()) };
    if obj.is_null() {
        return Err(format!(
            "failed to open {}: {}",
            path.display(),
            io::Error::last_os_error()
        ));
    }
    let err = unsafe { libbpf_get_error(obj.cast::<c_void>()) };
    if err != 0 {
        return Err(format!("failed to open {}: libbpf error {err}", path.display()));
    }
    Ok(BpfObject { ptr: obj })
}

fn load_object(object: &mut BpfObject) -> Result<()> {
    let ret = unsafe { bpf_object__load(object.ptr) };
    if ret != 0 {
        return Err(format!(
            "bpf_object__load failed: {}",
            io::Error::last_os_error()
        ));
    }
    Ok(())
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

fn build_json_linked_program(path: &PathBuf) -> Result<Vec<BpfInsn>> {
    let text = fs::read_to_string(path).map_err(|err| format!("read {}: {err}", path.display()))?;
    let proof: JsonProof =
        serde_json::from_str(&text).map_err(|err| format!("parse {}: {err}", path.display()))?;
    let program = proof
        .bpf_program
        .as_ref()
        .ok_or_else(|| format!("{} has no bpf_program section", path.display()))?;
    link_bpf_program(program)
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
    let nul = log_buf.iter().position(|ch| *ch == 0).unwrap_or(log_buf.len());
    let bytes: Vec<u8> = log_buf[..nul].iter().map(|ch| *ch as u8).collect();
    String::from_utf8_lossy(&bytes).into_owned()
}

fn build_default_case_input(case_name: &str, json_mode: bool) -> Result<Vec<u8>> {
    if json_mode {
        let path = PathBuf::from("micro/generated-inputs").join(format!("{case_name}.mem"));
        return build_packet_input(&path);
    }
    match case_name {
        "simple" => Ok(build_simple_case()),
        other => Err(format!("unsupported case without --input: {other}")),
    }
}

fn build_simple_case() -> Vec<u8> {
    let mut data = vec![0u8; XVM_CODE_OFF + 2 * XVM_INSN_SIZE];
    write_le_u32(&mut data[XVM_HEADER_OFF..XVM_HEADER_OFF + 4], XVM_MAGIC);
    write_le_u16(&mut data[XVM_HEADER_OFF + 4..XVM_HEADER_OFF + 6], 2);
    encode_insn(&mut data, 0, XVM_OP_MOV_IMM64, XVM_RAX, 0, SIMPLE_EXPECTED);
    encode_insn(&mut data, 1, XVM_OP_RET, 0, 0, 0);
    data
}

fn build_packet_input(path: &PathBuf) -> Result<Vec<u8>> {
    let payload = fs::read(path).map_err(|err| format!("read {}: {err}", path.display()))?;
    let mut data = vec![XVM_OUTPUT_OFF as u8; XVM_OUTPUT_OFF + 8 + payload.len()];
    data[8..].copy_from_slice(&payload);
    Ok(data)
}

fn encode_insn(data: &mut [u8], index: usize, op: u8, dst: u8, src: u8, imm: u64) {
    assert!(index < XVM_MAX_INSNS);
    let off = XVM_CODE_OFF + index * XVM_INSN_SIZE;
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
