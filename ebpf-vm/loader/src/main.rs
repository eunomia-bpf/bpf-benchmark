use std::env;
use std::ffi::{c_void, CString};
use std::io;
use std::mem;
use std::os::raw::{c_char, c_int, c_long};
use std::os::unix::ffi::OsStrExt;
use std::path::PathBuf;
use std::process;
use std::ptr;

const XVM_MAGIC: u32 = 0x314d5658;
const XVM_OUTPUT_OFF: usize = 0;
const XVM_HEADER_OFF: usize = 8;
const XVM_CODE_OFF: usize = 16;
const XVM_INSN_SIZE: usize = 16;
const XVM_MAX_INSNS: usize = 32;

const XVM_OP_MOV_IMM64: u8 = 0x01;
const XVM_OP_RET: u8 = 0xff;

const XVM_RAX: u8 = 0;

const XDP_PASS: u32 = 2;
const SIMPLE_EXPECTED: u64 = 12_345_678;

type Result<T> = std::result::Result<T, String>;

struct Cli {
    object: PathBuf,
    case_name: String,
    program: String,
    repeat: i32,
}

struct BpfObject {
    ptr: *mut c_void,
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
    let mut object = open_object(&cli.object)?;
    load_object(&mut object)?;
    let prog_fd = program_fd(&object, &cli.program)?;
    let mut input = match cli.case_name.as_str() {
        "simple" => build_simple_case(),
        other => return Err(format!("unsupported case: {other}")),
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
    if opts.retval != XDP_PASS {
        return Err(format!("unexpected XDP retval: {}", opts.retval));
    }
    if opts.data_size_out < 8 {
        return Err(format!("short data_size_out: {}", opts.data_size_out));
    }

    let result = read_le_u64(&output[XVM_OUTPUT_OFF..XVM_OUTPUT_OFF + 8]);
    if result != SIMPLE_EXPECTED {
        return Err(format!(
            "simple result mismatch: got {result}, expected {SIMPLE_EXPECTED}"
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
    let mut case_name = String::from("simple");
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
            "--case" => {
                case_name = args
                    .next()
                    .ok_or_else(|| "--case requires a name".to_string())?;
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

    let object = object.ok_or_else(|| "--object is required".to_string())?;
    Ok(Cli {
        object,
        case_name,
        program,
        repeat,
    })
}

fn print_help() {
    println!(
        "Usage: ebpf-vm-loader --object <vm.bpf.o> [--case simple] [--program x86_vm_xdp] [--repeat N]"
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

fn build_simple_case() -> Vec<u8> {
    let mut data = vec![0u8; XVM_CODE_OFF + 2 * XVM_INSN_SIZE];
    write_le_u32(&mut data[XVM_HEADER_OFF..XVM_HEADER_OFF + 4], XVM_MAGIC);
    write_le_u16(&mut data[XVM_HEADER_OFF + 4..XVM_HEADER_OFF + 6], 2);
    encode_insn(&mut data, 0, XVM_OP_MOV_IMM64, XVM_RAX, 0, SIMPLE_EXPECTED);
    encode_insn(&mut data, 1, XVM_OP_RET, 0, 0, 0);
    data
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
