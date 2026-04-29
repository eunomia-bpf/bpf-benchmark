// SPDX-License-Identifier: MIT
//! Live host platform discovery for daemon policy construction.

use bpfopt::pass::{Arch, PlatformCapabilities};

/// Detect CPU capabilities for the current daemon host.
pub(crate) fn detect() -> PlatformCapabilities {
    #[cfg(target_arch = "x86_64")]
    {
        detect_x86_64()
    }
    #[cfg(target_arch = "aarch64")]
    {
        PlatformCapabilities {
            // ARM64 always has conditional select (CSEL).
            has_cmov: true,
            arch: Arch::Aarch64,
            ..Default::default()
        }
    }
    #[cfg(not(any(target_arch = "x86_64", target_arch = "aarch64")))]
    {
        PlatformCapabilities::default()
    }
}

/// Detect x86_64 CPU features by parsing /proc/cpuinfo flags.
#[cfg(target_arch = "x86_64")]
fn detect_x86_64() -> PlatformCapabilities {
    let flags = match std::fs::read_to_string("/proc/cpuinfo") {
        Ok(content) => content
            .lines()
            .find(|line| line.starts_with("flags"))
            .unwrap_or("")
            .to_string(),
        Err(_) => String::new(),
    };

    PlatformCapabilities {
        has_bmi1: flags.contains(" bmi1"),
        has_bmi2: flags.contains(" bmi2"),
        has_cmov: flags.contains(" cmov"),
        has_movbe: flags.contains(" movbe"),
        // RORX is part of BMI2.
        has_rorx: flags.contains(" bmi2"),
        arch: Arch::X86_64,
    }
}
