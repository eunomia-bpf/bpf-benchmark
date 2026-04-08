#!/usr/bin/env bash
set -euo pipefail

# Internal shared AWS control-plane library.
# Callers must set:
# - ACTION
# - MANIFEST_PATH
# Optional caller-provided state:
# - LOCAL_STATE_PATH
# - AWS_REMOTE_PREP_STATE_PATH
# - ROOT_DIR
ROOT_DIR="${ROOT_DIR:-$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)}"
ACTION="${ACTION:-}"
MANIFEST_PATH="${MANIFEST_PATH:-}"
LOCAL_STATE_PATH="${LOCAL_STATE_PATH:-}"
AWS_REMOTE_PREP_STATE_PATH="${AWS_REMOTE_PREP_STATE_PATH:-}"
RUN_CONTRACT_PYTHON_BIN="${RUN_CONTRACT_PYTHON_BIN:-}"

[[ -n "$ACTION" ]] || {
    printf '[aws-common][ERROR] ACTION must be set before sourcing aws_common_lib.sh\n' >&2
    exit 1
}
[[ -n "$MANIFEST_PATH" ]] || {
    printf '[aws-common][ERROR] MANIFEST_PATH must be set before sourcing aws_common_lib.sh\n' >&2
    exit 1
}
[[ -f "$MANIFEST_PATH" ]] || {
    printf '[aws-common][ERROR] manifest is missing: %s\n' "$MANIFEST_PATH" >&2
    exit 1
}
[[ -n "$RUN_CONTRACT_PYTHON_BIN" ]] || {
    printf '[aws-common][ERROR] RUN_CONTRACT_PYTHON_BIN must be set before sourcing aws_common_lib.sh\n' >&2
    exit 1
}

load_shell_contract_file() {
    local path="$1"
    [[ -f "$path" ]] || {
        printf '[aws-common][ERROR] contract file is missing: %s\n' "$path" >&2
        exit 1
    }
    while IFS= read -r -d '' assignment; do
        export "$assignment"
    done < <(
        PYTHONPATH="$ROOT_DIR${PYTHONPATH:+:$PYTHONPATH}" \
            "$RUN_CONTRACT_PYTHON_BIN" -m runner.libs.run_contract export0 "$path"
    )
}

load_shell_state_file() {
    local path="$1"
    [[ -f "$path" ]] || {
        printf '[aws-common][ERROR] state file is missing: %s\n' "$path" >&2
        exit 1
    }
    while IFS= read -r -d '' assignment; do
        export "$assignment"
    done < <(
        PYTHONPATH="$ROOT_DIR${PYTHONPATH:+:$PYTHONPATH}" \
            "$RUN_CONTRACT_PYTHON_BIN" -m runner.libs.state_file export0 "$path"
    )
}

load_shell_contract_file "$MANIFEST_PATH"

RUN_AWS_INSTANCE_MODE="${RUN_AWS_INSTANCE_MODE:-shared}"
case "$RUN_AWS_INSTANCE_MODE" in
    shared|dedicated) ;;
    *)
        printf '[aws-common][ERROR] unsupported RUN_AWS_INSTANCE_MODE: %s\n' "$RUN_AWS_INSTANCE_MODE" >&2
        exit 1
        ;;
esac

RUN_TOKEN="${RUN_TOKEN:-}"
[[ -n "$RUN_TOKEN" ]] || {
    printf '[aws-common][ERROR] manifest RUN_TOKEN is empty\n' >&2
    exit 1
}
TARGET_CACHE_DIR="$ROOT_DIR/.cache/${RUN_TARGET_NAME}"
SHARED_STATE_DIR="$TARGET_CACHE_DIR/state"
RUN_STATE_DIR="$TARGET_CACHE_DIR/run-state/$RUN_TOKEN"
if [[ "$ACTION" != "terminate" && "$RUN_AWS_INSTANCE_MODE" == "dedicated" ]]; then
    RUN_NAME_TAG="${RUN_NAME_TAG}-${RUN_TOKEN}"
    STATE_DIR="$RUN_STATE_DIR"
else
    STATE_DIR="$SHARED_STATE_DIR"
fi
STATE_FILE="$STATE_DIR/instance.json"
RUN_PREP_ROOT="$TARGET_CACHE_DIR/runs/$RUN_TOKEN"
ARTIFACT_DIR="$RUN_PREP_ROOT/artifacts"
RESULTS_DIR="$TARGET_CACHE_DIR/results"
SETUP_ARTIFACT_CACHE_ROOT="$TARGET_CACHE_DIR/setup-artifacts"
AWS_REGION_VALUE="${RUN_AWS_REGION:-}"
AWS_PROFILE_VALUE="${RUN_AWS_PROFILE:-}"
STATE_INSTANCE_ID=""
STATE_INSTANCE_IP=""
STATE_REGION=""
STATE_KERNEL_RELEASE=""
DEDICATED_RUN_ACTIVE=0

log() {
    printf '[aws-common] %s\n' "$*" >&2
}

die() {
    printf '[aws-common][ERROR] %s\n' "$*" >&2
    exit 1
}

# shellcheck disable=SC1090
source "$ROOT_DIR/runner/scripts/local_prep_common_lib.sh"

ensure_dirs() {
    mkdir -p "$TARGET_CACHE_DIR" "$STATE_DIR" "$ARTIFACT_DIR" "$RESULTS_DIR" "$RUN_PREP_ROOT"
}

with_locked_file() {
    local lock_path="$1"
    local lock_fd
    local status=0
    shift
    mkdir -p "$(dirname "$lock_path")"
    exec {lock_fd}>"$lock_path"
    flock "$lock_fd"
    "$@" || status=$?
    exec {lock_fd}>&-
    return "$status"
}

with_state_lock() {
    with_locked_file "$STATE_DIR/instance.lock" "$@"
}

remote_base_prereq_dir() {
    printf '%s\n' "$RUN_REMOTE_STAGE_DIR/prereq/base"
}

remote_base_prereq_stamp_path() {
    printf '%s\n' "$(remote_base_prereq_dir)/base.ready"
}

load_state() {
    unset \
        STATE_INSTANCE_ID \
        STATE_INSTANCE_IP \
        STATE_REGION \
        STATE_KERNEL_RELEASE
    STATE_INSTANCE_ID=""
    STATE_INSTANCE_IP=""
    STATE_REGION=""
    STATE_KERNEL_RELEASE=""
    if [[ -f "$STATE_FILE" ]]; then
        load_shell_state_file "$STATE_FILE"
    fi
}

load_remote_prep_state() {
    unset \
        STATE_INSTANCE_ID \
        STATE_INSTANCE_IP \
        STATE_REGION \
        STATE_KERNEL_RELEASE
    STATE_INSTANCE_ID=""
    STATE_INSTANCE_IP=""
    STATE_REGION=""
    STATE_KERNEL_RELEASE=""
    [[ -n "$AWS_REMOTE_PREP_STATE_PATH" ]] || die "AWS remote-prep state path is required for canonical AWS local prep"
    [[ -f "$AWS_REMOTE_PREP_STATE_PATH" ]] || die "AWS remote-prep state file is missing: ${AWS_REMOTE_PREP_STATE_PATH}"
    load_shell_state_file "$AWS_REMOTE_PREP_STATE_PATH"
}

save_state() {
    local instance_id="$1"
    local instance_ip="$2"
    local region="$3"
    local kernel_release="${4:-}"
    ensure_dirs
    PYTHONPATH="$ROOT_DIR${PYTHONPATH:+:$PYTHONPATH}" \
        "$RUN_CONTRACT_PYTHON_BIN" -m runner.libs.state_file write "$STATE_FILE" \
            "STATE_INSTANCE_ID=$instance_id" \
            "STATE_INSTANCE_IP=$instance_ip" \
            "STATE_REGION=$region" \
            "STATE_KERNEL_RELEASE=$kernel_release"
}

clear_state() {
    rm -f "$STATE_FILE"
    unset \
        STATE_INSTANCE_ID \
        STATE_INSTANCE_IP \
        STATE_REGION \
        STATE_KERNEL_RELEASE
    STATE_INSTANCE_ID=""
    STATE_INSTANCE_IP=""
    STATE_REGION=""
    STATE_KERNEL_RELEASE=""
}

cleanup_local_run_prep_root() {
    [[ -n "${RUN_PREP_ROOT:-}" ]] || return 0
    [[ -e "$RUN_PREP_ROOT" ]] || return 0
    rm -rf "$RUN_PREP_ROOT" 2>/dev/null || true
    if [[ -e "$RUN_PREP_ROOT" ]]; then
        sudo rm -rf "$RUN_PREP_ROOT" || true
    fi
}

resolve_region() {
    [[ -n "$AWS_REGION_VALUE" ]] || die "manifest AWS region is empty for ${RUN_TARGET_NAME}"
    printf '%s\n' "$AWS_REGION_VALUE"
}

_aws() {
    [[ -n "$AWS_PROFILE_VALUE" ]] || die "manifest AWS profile is empty for ${RUN_TARGET_NAME}"
    AWS_PAGER="" aws --profile "$AWS_PROFILE_VALUE" "$@"
}

aws_cmd() {
    local region="$1"
    shift
    _aws --region "$region" "$@"
}

ensure_aws_identity() {
    local region
    region="$(resolve_region)"
    aws_cmd "$region" sts get-caller-identity >/dev/null
}

lookup_existing_instance() {
    local region="$1"
    local ami_id="$2"
    local key_name="$3"
    local security_group_id="$4"
    local subnet_id="$5"
    aws_cmd "$region" ec2 describe-instances \
        --filters \
            "Name=tag:Name,Values=${RUN_NAME_TAG}" \
            "Name=image-id,Values=${ami_id}" \
            "Name=instance-type,Values=${RUN_INSTANCE_TYPE}" \
            "Name=key-name,Values=${key_name}" \
            "Name=instance.group-id,Values=${security_group_id}" \
            "Name=subnet-id,Values=${subnet_id}" \
            "Name=instance-state-name,Values=pending,running" \
        --query 'Reservations[].Instances[0].[InstanceId,State.Name,PublicIpAddress]' \
        --output text 2>/dev/null || true
}

lookup_target_instance_ids() {
    local region="$1"
    aws_cmd "$region" ec2 describe-instances \
        --filters \
            "Name=tag:Project,Values=bpf-benchmark" \
            "Name=tag:Role,Values=${RUN_TARGET_NAME}" \
            "Name=instance-state-name,Values=pending,running,stopping,stopped" \
        --query 'Reservations[].Instances[].InstanceId' \
        --output text 2>/dev/null || true
}

describe_instance() {
    local region="$1"
    local instance_id="$2"
    aws_cmd "$region" ec2 describe-instances \
        --instance-ids "$instance_id" \
        --query 'Reservations[0].Instances[0].[InstanceId,State.Name,PublicIpAddress]' \
        --output text 2>/dev/null || true
}

describe_instance_type() {
    local region="$1"
    local instance_id="$2"
    aws_cmd "$region" ec2 describe-instances \
        --instance-ids "$instance_id" \
        --query 'Reservations[0].Instances[0].InstanceType' \
        --output text 2>/dev/null || true
}

describe_instance_launch_contract() {
    local region="$1"
    local instance_id="$2"
    aws_cmd "$region" ec2 describe-instances \
        --instance-ids "$instance_id" \
        --query "Reservations[0].Instances[0].[ImageId,KeyName,SubnetId,join(',', sort_by(SecurityGroups,&GroupId)[].GroupId)]" \
        --output text 2>/dev/null || true
}

instance_state_is_reusable() {
    case "${1:-}" in
        pending|running) return 0 ;;
    esac
    return 1
}

ssh_base_args() {
    local ip="$1"
    printf '%s\n' \
        -o BatchMode=yes \
        -o StrictHostKeyChecking=no \
        -o UserKnownHostsFile=/dev/null \
        -o ConnectTimeout=15 \
        -i "${RUN_AWS_KEY_PATH}"
}

ssh_bash() {
    local ip="$1"
    shift
    ssh $(ssh_base_args "$ip") "${RUN_REMOTE_USER}@${ip}" "bash -s -- $*"
}

scp_to() {
    local ip="$1"
    local src="$2"
    local dest="$3"
    scp $(ssh_base_args "$ip") "$src" "${RUN_REMOTE_USER}@${ip}:$dest"
}

scp_from() {
    local ip="$1"
    local src="$2"
    local dest="$3"
    scp $(ssh_base_args "$ip") "${RUN_REMOTE_USER}@${ip}:$src" "$dest"
}

wait_for_ssh() {
    local ip="$1"
    local attempt
    for attempt in $(seq 1 60); do
        if ssh $(ssh_base_args "$ip") "${RUN_REMOTE_USER}@${ip}" true >/dev/null 2>&1; then
            return 0
        fi
        sleep 5
    done
    die "timed out waiting for SSH on ${ip}"
}

resolve_root_device_name() {
    local region="$1"
    local ami_id="$2"
    local root_device_name
    root_device_name="$(aws_cmd "$region" ec2 describe-images \
        --image-ids "$ami_id" \
        --query 'Images[0].RootDeviceName' \
        --output text)"
    if [[ -z "$root_device_name" || "$root_device_name" == "None" ]]; then
        printf '/dev/xvda\n'
    else
        printf '%s\n' "$root_device_name"
    fi
}

launch_instance() {
    ensure_dirs
    load_state
    ensure_aws_identity

    local region key_path key_name security_group_id subnet_id instance_id="" instance_state="" instance_ip="" instance_type="" ami_id root_device_name current_image_id="" current_key_name="" current_subnet_id="" current_security_groups=""
    region="$(resolve_region)"
    key_name="${RUN_AWS_KEY_NAME:-}"
    key_path="${RUN_AWS_KEY_PATH:-}"
    security_group_id="${RUN_AWS_SECURITY_GROUP_ID:-}"
    subnet_id="${RUN_AWS_SUBNET_ID:-}"
    [[ -n "$key_name" ]] || die "AWS key name is unset for ${RUN_TARGET_NAME}"
    [[ -n "$key_path" ]] || die "AWS key path is unset for ${RUN_TARGET_NAME}"
    [[ -n "$security_group_id" ]] || die "AWS security group id is unset for ${RUN_TARGET_NAME}"
    [[ -n "$subnet_id" ]] || die "AWS subnet id is unset for ${RUN_TARGET_NAME}"
    [[ -f "$key_path" ]] || die "SSH key does not exist: $key_path"
    [[ "$RUN_ROOT_VOLUME_GB" =~ ^[0-9]+$ ]] || die "RUN_ROOT_VOLUME_GB must be a positive integer"
    (( RUN_ROOT_VOLUME_GB > 0 )) || die "RUN_ROOT_VOLUME_GB must be greater than zero"
    if [[ -n "${RUN_AMI_ID:-}" ]]; then
        ami_id="${RUN_AMI_ID}"
    else
        ami_id="$(aws_cmd "$region" ssm get-parameter --name "$RUN_AMI_PARAM" --query 'Parameter.Value' --output text)"
    fi

    if [[ -n "${STATE_INSTANCE_ID:-}" ]]; then
        read -r instance_id instance_state instance_ip <<<"$(describe_instance "$region" "$STATE_INSTANCE_ID")"
        instance_type="$(describe_instance_type "$region" "$STATE_INSTANCE_ID")"
        read -r current_image_id current_key_name current_subnet_id current_security_groups <<<"$(describe_instance_launch_contract "$region" "$STATE_INSTANCE_ID")"
        case "$instance_state" in
            stopped|stopping)
                terminate_instance "${STATE_INSTANCE_ID}"
                instance_id=""
                instance_state=""
                instance_ip=""
                ;;
        esac
        if [[ -n "$instance_id" && "$instance_id" != "None" && "$instance_type" != "$RUN_INSTANCE_TYPE" ]]; then
            terminate_instance "${STATE_INSTANCE_ID}"
            instance_id=""
            instance_state=""
            instance_ip=""
        fi
        if [[ -n "$instance_id" && "$instance_id" != "None" ]] && { [[ "$current_image_id" != "$ami_id" ]] || [[ "$current_key_name" != "$key_name" ]] || [[ "$current_subnet_id" != "$subnet_id" ]] || [[ "$current_security_groups" != "$security_group_id" ]]; }; then
            terminate_instance "${STATE_INSTANCE_ID}"
            instance_id=""
            instance_state=""
            instance_ip=""
        fi
    fi
    if [[ -z "$instance_id" || "$instance_id" == "None" ]] || ! instance_state_is_reusable "$instance_state"; then
        read -r instance_id instance_state instance_ip <<<"$(lookup_existing_instance "$region" "$ami_id" "$key_name" "$security_group_id" "$subnet_id")"
        if [[ -n "$instance_id" && "$instance_id" != "None" ]]; then
            read -r current_image_id current_key_name current_subnet_id current_security_groups <<<"$(describe_instance_launch_contract "$region" "$instance_id")"
            if [[ "$current_image_id" != "$ami_id" || "$current_key_name" != "$key_name" || "$current_subnet_id" != "$subnet_id" || "$current_security_groups" != "$security_group_id" ]]; then
                instance_id=""
                instance_state=""
                instance_ip=""
            fi
        fi
    fi

    if [[ -z "$instance_id" || "$instance_id" == "None" ]]; then
        root_device_name="$(resolve_root_device_name "$region" "$ami_id")"
        log "Launching ${RUN_TARGET_NAME} instance ${RUN_INSTANCE_TYPE} in ${region}"
        instance_id="$(aws_cmd "$region" ec2 run-instances \
            --image-id "$ami_id" \
            --instance-type "$RUN_INSTANCE_TYPE" \
            --key-name "$key_name" \
            --security-group-ids "$security_group_id" \
            --subnet-id "$subnet_id" \
            --block-device-mappings "DeviceName=${root_device_name},Ebs={VolumeSize=${RUN_ROOT_VOLUME_GB},VolumeType=gp3,DeleteOnTermination=true}" \
            --tag-specifications "ResourceType=instance,Tags=[{Key=Name,Value=${RUN_NAME_TAG}},{Key=Project,Value=bpf-benchmark},{Key=Role,Value=${RUN_TARGET_NAME}}]" \
            --count 1 \
            --query 'Instances[0].InstanceId' \
            --output text)"
    else
        log "Reusing existing EC2 instance ${instance_id} (${instance_state})"
    fi

    save_state "$instance_id" "${instance_ip:-}" "$region" "${STATE_KERNEL_RELEASE:-}"
    aws_cmd "$region" ec2 wait instance-running --instance-ids "$instance_id"
    aws_cmd "$region" ec2 wait instance-status-ok --instance-ids "$instance_id"
    read -r instance_id instance_state instance_ip <<<"$(describe_instance "$region" "$instance_id")"
    [[ -n "$instance_ip" && "$instance_ip" != "None" ]] || die "instance ${instance_id} has no public IP"
    save_state "$instance_id" "$instance_ip" "$region" "${STATE_KERNEL_RELEASE:-}"
}

remote_kernel_release() {
    local ip="$1"
    ssh_bash "$ip" <<'EOF'
set -euo pipefail
uname -r
EOF
}

remote_root_volume_size_gb() {
    local ip="$1"
    ssh_bash "$ip" <<'EOF'
set -euo pipefail
root_source="$(findmnt -n -o SOURCE /)"
[[ -n "$root_source" ]] || exit 1
root_device="$root_source"
parent_kname="$(lsblk -no PKNAME "$root_source" 2>/dev/null | head -n1 || true)"
if [[ -n "$parent_kname" ]]; then
    root_device="/dev/${parent_kname}"
fi
size_bytes="$(lsblk -nb -o SIZE "$root_device" 2>/dev/null | head -n1 || true)"
[[ -n "$size_bytes" ]] || exit 1
echo $(((size_bytes + 1073741824 - 1) / 1073741824))
EOF
}

remote_has_runtime_btf() {
    local ip="$1"
    ssh_bash "$ip" <<'EOF'
set -euo pipefail
test -s /sys/kernel/btf/vmlinux
EOF
}

remote_has_sched_ext() {
    local ip="$1"
    ssh_bash "$ip" <<'EOF'
set -euo pipefail
test -e /sys/kernel/sched_ext/state
EOF
}

setup_remote_base_prereqs() {
    local ip="$1"
    local remote_prereq_dir remote_stamp_path
    remote_prereq_dir="$(remote_base_prereq_dir)"
    remote_stamp_path="$(remote_base_prereq_stamp_path)"
    local remote_manifest="$remote_prereq_dir/run-contract.env"
    local remote_runner_root="$remote_prereq_dir/runner"
    local remote_runner_lib_root="$remote_runner_root/libs"
    ssh_bash "$ip" "$remote_prereq_dir" <<'EOF'
set -euo pipefail
mkdir -p "$1"
EOF
    ssh_bash "$ip" "$remote_runner_lib_root" <<'EOF'
set -euo pipefail
mkdir -p "$1"
EOF
    scp_to "$ip" "$MANIFEST_PATH" "$remote_manifest"
    scp_to "$ip" "$ROOT_DIR/runner/__init__.py" "$remote_runner_root/__init__.py"
    scp_to "$ip" "$ROOT_DIR/runner/libs/__init__.py" "$remote_runner_lib_root/__init__.py"
    scp_to "$ip" "$ROOT_DIR/runner/libs/prereq_contract.py" "$remote_runner_lib_root/prereq_contract.py"
    scp_to "$ip" "$ROOT_DIR/runner/libs/run_contract.py" "$remote_runner_lib_root/run_contract.py"
    scp_to "$ip" "$ROOT_DIR/runner/libs/aws_remote_prereqs.py" "$remote_runner_lib_root/aws_remote_prereqs.py"
    ssh_bash "$ip" "$remote_prereq_dir" "$remote_manifest" "$remote_stamp_path" <<'EOF' >&2
set -euo pipefail
prereq_root="$1"
manifest="$2"
stamp_path="$3"
python_bin=""
for candidate in python3 python; do
    if command -v "$candidate" >/dev/null 2>&1; then
        python_bin="$candidate"
        break
    fi
done
[[ -n "$python_bin" ]] || {
    echo "[aws-remote-prereqs][ERROR] no Python launcher is available" >&2
    exit 1
}
sudo env PATH="$PATH" PYTHONPATH="$prereq_root" \
    "$python_bin" -m runner.libs.aws_remote_prereqs "$manifest" "$stamp_path"
test -f "$stamp_path"
EOF
}

verify_remote_base_prereqs() {
    local ip="$1"
    ssh_bash "$ip" "$(remote_base_prereq_stamp_path)" <<'EOF'
set -euo pipefail
test -f "$1"
EOF
}

terminate_instance() {
    load_state
    ensure_aws_identity
    local region explicit_instance_id="${1:-}" instance_id state
    local -a target_instance_ids=()
    region="$(resolve_region)"
    if [[ -z "$explicit_instance_id" || "$explicit_instance_id" == "None" ]]; then
        read -r -a target_instance_ids <<<"$(lookup_target_instance_ids "$region")"
        if [[ "${#target_instance_ids[@]}" -gt 0 ]]; then
            aws_cmd "$region" ec2 terminate-instances --instance-ids "${target_instance_ids[@]}" >/dev/null
            aws_cmd "$region" ec2 wait instance-terminated --instance-ids "${target_instance_ids[@]}"
        fi
        rm -rf "$SHARED_STATE_DIR" "$TARGET_CACHE_DIR/run-state"
        return 0
    fi
    instance_id="$explicit_instance_id"
    read -r _ state _ <<<"$(describe_instance "$region" "$instance_id")"
    [[ -n "$instance_id" && "$instance_id" != "None" ]] || die "terminate requires an instance ID"
    case "$state" in
        terminated|shutting-down|"") ;;
        *)
            aws_cmd "$region" ec2 terminate-instances --instance-ids "$instance_id" >/dev/null
            aws_cmd "$region" ec2 wait instance-terminated --instance-ids "$instance_id"
            ;;
    esac
    if [[ "$instance_id" == "${STATE_INSTANCE_ID:-}" ]]; then
        clear_state
    fi
}
