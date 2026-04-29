#[cfg(target_os = "linux")]
use std::os::fd::AsFd;

#[cfg(target_os = "linux")]
fn is_unsupported_environment(err: &anyhow::Error) -> bool {
    let msg = err.to_string();
    [
        "Operation not permitted",
        "Permission denied",
        "Function not implemented",
        "Invalid argument",
    ]
    .iter()
    .any(|needle| msg.contains(needle))
}

#[cfg(target_os = "linux")]
#[test]
fn prog_get_original_matches_fork_reported_orig_prog_len() -> anyhow::Result<()> {
    let mut start_id = 0;
    let mut saw_program = false;

    loop {
        let Some(prog_id) = (match kernel_sys::prog_get_next_id(start_id) {
            Ok(next) => next,
            Err(err) if is_unsupported_environment(&err) => {
                eprintln!("skipping original-bytecode test: {err:#}");
                return Ok(());
            }
            Err(err) => return Err(err),
        }) else {
            break;
        };
        start_id = prog_id;
        saw_program = true;

        let fd = match kernel_sys::prog_get_fd_by_id(prog_id) {
            Ok(fd) => fd,
            Err(err) if is_unsupported_environment(&err) => {
                eprintln!("skipping original-bytecode test: {err:#}");
                return Ok(());
            }
            Err(err) if err.to_string().contains("No such file or directory") => {
                continue;
            }
            Err(err) => return Err(err),
        };

        let info = match kernel_sys::obj_get_info_by_fd(fd.as_fd()) {
            Ok(info) => info,
            Err(err) if is_unsupported_environment(&err) => {
                eprintln!("skipping original-bytecode test: {err:#}");
                return Ok(());
            }
            Err(err) => return Err(err),
        };

        if info.orig_prog_len == 0 {
            continue;
        }

        let insns = kernel_sys::prog_get_original(fd.as_fd())?;
        assert_eq!(
            insns.len() * std::mem::size_of::<kernel_sys::bpf_insn>(),
            info.orig_prog_len as usize,
            "prog_get_original must return exactly orig_prog_len bytes as bpf_insn records"
        );
        return Ok(());
    }

    if saw_program {
        eprintln!("skipping original-bytecode test: no live BPF program exposes orig_prog_len");
    } else {
        eprintln!("skipping original-bytecode test: no live BPF programs found");
    }
    Ok(())
}
