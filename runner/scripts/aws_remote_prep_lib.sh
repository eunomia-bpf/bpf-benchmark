#!/usr/bin/env bash
set -euo pipefail

# Internal AWS remote-prep library.
# This file must be sourced only after aws_common_lib.sh so that shared AWS
# state, SSH, and kernel-build helpers are already defined.

setup_x86_instance() {
    local ip="$1"
    local region instance_id kernel_release kernel_image modules_tar setup_stamp setup_result_dir verify_log
    load_state
    region="${STATE_REGION:-$(resolve_region)}"
    instance_id="${STATE_INSTANCE_ID:-}"
    [[ -n "$instance_id" ]] || die "x86 setup requires a cached instance ID"
    wait_for_ssh "$ip"
    setup_remote_base_prereqs "$ip"
    build_x86_kernel_artifacts
    kernel_release="$BUILD_KERNEL_RELEASE"
    [[ -n "$kernel_release" ]] || die "x86 kernel build did not produce a kernel release"
    kernel_image="$ARTIFACT_DIR/bzImage-$kernel_release"
    modules_tar="$ARTIFACT_DIR/modules-$kernel_release.tar.gz"
    setup_stamp="setup_${kernel_release}_$(date -u +%Y%m%d_%H%M%S)"
    setup_result_dir="$RESULTS_DIR/$setup_stamp"
    verify_log="$setup_result_dir/setup_verify.log"
    mkdir -p "$setup_result_dir"

    ssh_bash "$ip" "$RUN_REMOTE_KERNEL_STAGE_DIR" <<'EOF'
set -euo pipefail
mkdir -p "$1/boot"
EOF
    scp_to "$ip" "$kernel_image" "$RUN_REMOTE_KERNEL_STAGE_DIR/boot/"
    scp_to "$ip" "$modules_tar" "$RUN_REMOTE_KERNEL_STAGE_DIR/"
    ssh_bash "$ip" "$kernel_release" "$RUN_REMOTE_KERNEL_STAGE_DIR" <<'EOF'
set -euo pipefail
ver="$1"
stage_dir="$2"
title="Codex x86 ($ver)"
primary_netdev="$(ip -brief link | awk '$1 != "lo" { print $1; exit }')"
[[ -n "$primary_netdev" ]] || exit 1
primary_mac="$(cat "/sys/class/net/$primary_netdev/address")"
[[ -n "$primary_mac" ]] || exit 1

sudo tar -xzf "$stage_dir/modules-$ver.tar.gz" -C /
sudo install -o root -g root -m 0755 "$stage_dir/boot/bzImage-$ver" "/boot/vmlinuz-$ver"
sudo depmod -a "$ver"
sudo dracut --force --no-hostonly --add-drivers "nvme nvme-core xfs ext4 virtio_blk" "/boot/initramfs-$ver.img" "$ver"
cat <<EOF_LINK | sudo tee /etc/systemd/network/10-codex-ena.link >/dev/null
[Match]
MACAddress=${primary_mac}

[Link]
Name=ens5
EOF_LINK
cat <<EOF_NET | sudo tee /etc/systemd/network/10-codex-ena.network >/dev/null
[Match]
MACAddress=${primary_mac}

[Network]
DHCP=yes
LinkLocalAddressing=yes
IPv6AcceptRA=yes
EOF_NET
sudo grubby --add-kernel "/boot/vmlinuz-$ver" \
    --initrd "/boot/initramfs-$ver.img" \
    --title "$title" \
    --copy-default
sudo grubby --set-default "/boot/vmlinuz-$ver"
EOF
    aws_cmd "$region" ec2 reboot-instances --instance-ids "$instance_id" >/dev/null
    aws_cmd "$region" ec2 wait instance-status-ok --instance-ids "$instance_id"
    read -r _ _ ip <<<"$(describe_instance "$region" "$instance_id")"
    [[ -n "$ip" && "$ip" != "None" ]] || die "instance ${instance_id} has no public IP after x86 reboot"
    wait_for_ssh "$ip"
    ssh_bash "$ip" "$kernel_release" <<'EOF' | tee "$verify_log" >&2
set -euo pipefail
ver="$1"
uname -r
ip -brief addr show ens5 || ip -brief addr
sudo grubby --default-kernel
test "$(uname -r)" = "$ver"
test "$(sudo grubby --default-kernel)" = "/boot/vmlinuz-$ver"
test -s /sys/kernel/btf/vmlinux
test -e /sys/kernel/sched_ext/state
EOF
    save_state "$instance_id" "$ip" "$region" "$kernel_release"
}

setup_arm64_instance() {
    local ip="$1"
    local region instance_id kernel_release kernel_image modules_tar setup_stamp setup_result_dir verify_log
    load_state
    region="${STATE_REGION:-$(resolve_region)}"
    instance_id="${STATE_INSTANCE_ID:-}"
    [[ -n "$instance_id" ]] || die "ARM64 setup requires a cached instance ID"
    wait_for_ssh "$ip"
    refresh_aws_arm64_base_config "$ip"
    setup_remote_base_prereqs "$ip"
    build_arm64_kernel_artifacts
    kernel_release="$BUILD_KERNEL_RELEASE"
    [[ -n "$kernel_release" ]] || die "ARM64 kernel build did not produce a kernel release"
    kernel_image="$ARTIFACT_DIR/vmlinuz-$kernel_release.efi"
    modules_tar="$ARTIFACT_DIR/modules-$kernel_release.tar.gz"
    setup_stamp="setup_${kernel_release}_$(date -u +%Y%m%d_%H%M%S)"
    setup_result_dir="$RESULTS_DIR/$setup_stamp"
    verify_log="$setup_result_dir/setup_verify.log"
    mkdir -p "$setup_result_dir"

    ssh_bash "$ip" "$RUN_REMOTE_KERNEL_STAGE_DIR" <<'EOF'
set -euo pipefail
mkdir -p "$1/boot"
EOF
    scp_to "$ip" "$kernel_image" "$RUN_REMOTE_KERNEL_STAGE_DIR/boot/"
    scp_to "$ip" "$modules_tar" "$RUN_REMOTE_KERNEL_STAGE_DIR/"
    ssh_bash "$ip" "$kernel_release" "$RUN_REMOTE_KERNEL_STAGE_DIR" <<'EOF'
set -euo pipefail
ver="$1"
stage_dir="$2"
title="Codex ARM64 ($ver)"
sudo tar -xzf "$stage_dir/modules-$ver.tar.gz" -C /
sudo install -o root -g root -m 0755 "$stage_dir/boot/vmlinuz-$ver.efi" "/boot/vmlinuz-$ver"
sudo depmod -a "$ver"
sudo dracut --force "/boot/initramfs-$ver.img" "$ver"
sudo grubby --add-kernel "/boot/vmlinuz-$ver" \
    --initrd "/boot/initramfs-$ver.img" \
    --title "$title" \
    --copy-default
sudo grubby --set-default "/boot/vmlinuz-$ver"
EOF
    aws_cmd "$region" ec2 reboot-instances --instance-ids "$instance_id" >/dev/null
    aws_cmd "$region" ec2 wait instance-status-ok --instance-ids "$instance_id"
    read -r _ _ ip <<<"$(describe_instance "$region" "$instance_id")"
    [[ -n "$ip" && "$ip" != "None" ]] || die "instance ${instance_id} has no public IP after ARM64 reboot"
    wait_for_ssh "$ip"
    ssh_bash "$ip" "$kernel_release" <<'EOF' | tee "$verify_log" >&2
set -euo pipefail
ver="$1"
uname -r
ip -brief addr show ens5 || ip -brief addr
sudo grubby --default-kernel
test "$(uname -r)" = "$ver"
test "$(sudo grubby --default-kernel)" = "/boot/vmlinuz-$ver"
test -s /sys/kernel/btf/vmlinux
test -e /sys/kernel/sched_ext/state
EOF
    save_state "$instance_id" "$ip" "$region" "$kernel_release"
}

setup_instance() {
    local ip="${1:-${STATE_INSTANCE_IP:-}}"
    [[ -n "$ip" ]] || die "setup requires an instance IP"
    case "$RUN_TARGET_NAME" in
        aws-arm64) setup_arm64_instance "$ip" ;;
        aws-x86) setup_x86_instance "$ip" ;;
        *) die "unsupported AWS target for setup: ${RUN_TARGET_NAME}" ;;
    esac
}

ensure_instance_for_suite() {
    local current_kernel root_volume_gb current_instance_id="" current_instance_state="" current_instance_ip="" current_instance_type=""
    load_state
    if [[ -n "${STATE_INSTANCE_ID:-}" ]]; then
        read -r current_instance_id current_instance_state current_instance_ip <<<"$(describe_instance "${STATE_REGION:-$(resolve_region)}" "$STATE_INSTANCE_ID")"
        current_instance_type="$(describe_instance_type "${STATE_REGION:-$(resolve_region)}" "$STATE_INSTANCE_ID")"
        case "$current_instance_state" in
            stopped|stopping)
                terminate_instance "${STATE_INSTANCE_ID}"
                load_state
                STATE_INSTANCE_ID=""
                STATE_INSTANCE_IP=""
                ;;
            pending|running)
                if [[ -n "$current_instance_ip" && "$current_instance_ip" != "None" ]]; then
                    STATE_INSTANCE_IP="$current_instance_ip"
                fi
                ;;
            *)
                STATE_INSTANCE_ID=""
                STATE_INSTANCE_IP=""
                ;;
        esac
        if [[ -n "${STATE_INSTANCE_ID:-}" && "$current_instance_type" != "$RUN_INSTANCE_TYPE" ]]; then
            terminate_instance "${STATE_INSTANCE_ID}"
            load_state
            STATE_INSTANCE_ID=""
            STATE_INSTANCE_IP=""
        fi
    fi
    if [[ -z "${STATE_INSTANCE_IP:-}" ]]; then
        launch_instance
        load_state
    fi
    [[ -n "${STATE_INSTANCE_IP:-}" ]] || die "failed to resolve ${RUN_TARGET_NAME} instance IP"
    wait_for_ssh "$STATE_INSTANCE_IP"

    root_volume_gb="$(remote_root_volume_size_gb "$STATE_INSTANCE_IP")"
    if [[ "$root_volume_gb" =~ ^[0-9]+$ ]] && (( root_volume_gb < RUN_ROOT_VOLUME_GB )); then
        terminate_instance "${STATE_INSTANCE_ID:-}"
        launch_instance
        load_state
        wait_for_ssh "$STATE_INSTANCE_IP"
    fi

    if [[ -z "${STATE_KERNEL_RELEASE:-}" ]]; then
        setup_instance "$STATE_INSTANCE_IP"
        load_state
        return 0
    fi

    current_kernel="$(remote_kernel_release "$STATE_INSTANCE_IP")"
    if [[ "$current_kernel" != "$STATE_KERNEL_RELEASE" ]]; then
        setup_instance "$STATE_INSTANCE_IP"
        load_state
        return 0
    fi
    if ! verify_remote_base_prereqs "$STATE_INSTANCE_IP"; then
        setup_remote_base_prereqs "$STATE_INSTANCE_IP"
        return 0
    fi
    if ! verify_remote_runtime_prereqs "$STATE_INSTANCE_IP"; then
        setup_remote_runtime_prereqs "$STATE_INSTANCE_IP"
        return 0
    fi
    if [[ "${RUN_SUITE_NEEDS_RUNTIME_BTF:-0}" == "1" ]] && ! remote_has_runtime_btf "$STATE_INSTANCE_IP"; then
        setup_instance "$STATE_INSTANCE_IP"
        load_state
        return 0
    fi
    if [[ "${RUN_SUITE_NEEDS_SCHED_EXT:-0}" == "1" ]] && ! remote_has_sched_ext "$STATE_INSTANCE_IP"; then
        setup_instance "$STATE_INSTANCE_IP"
        load_state
        return 0
    fi
}
