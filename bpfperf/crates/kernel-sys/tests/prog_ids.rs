#[cfg(target_os = "linux")]
#[test]
fn prog_get_next_id_enumerates_or_reports_unsupported_environment() {
    match kernel_sys::prog_get_next_id(0) {
        Ok(_) => {}
        Err(err) => {
            let msg = err.to_string();
            let unsupported = [
                "Operation not permitted",
                "Permission denied",
                "Function not implemented",
                "Invalid argument",
            ]
            .iter()
            .any(|needle| msg.contains(needle));

            if unsupported {
                eprintln!("skipping BPF program enumeration test: {err:#}");
                return;
            }

            panic!("BPF program enumeration failed unexpectedly: {err:#}");
        }
    }
}
