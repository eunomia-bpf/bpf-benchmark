#!/usr/bin/env bash
# Start dockerd in the background for dockerd-in-docker use; envbuilder has no
# init system, so lifecycle hooks (devcontainer.json onCreateCommand /
# postStartCommand) launch it. Pattern from the envbuilder DinD docs:
# https://raw.githubusercontent.com/coder/envbuilder/main/docs/docker.md
# Non-fatal when dockerd cannot run (e.g. pod privileged capability pending):
# workspace creation must not be blocked; `docker info` is authoritative.
set -euo pipefail

if [ -c /dev/kvm ] && [ -w /dev/kvm ]; then
	echo "kvm: /dev/kvm writable"
elif [ -c /dev/kvm ]; then
	echo "kvm: /dev/kvm exists but is not writable (needs device permissions in the pod)" >&2
else
	echo "kvm: /dev/kvm absent (needs device passthrough in the pod)" >&2
fi

if docker info >/dev/null 2>&1; then
	echo "dockerd: already running"
	exit 0
fi

if ! command -v dockerd >/dev/null 2>&1; then
	echo "dockerd: not installed; rebuild the devcontainer image" >&2
	exit 0
fi

mkdir -p /run /var/run /var/lib/docker /var/log

# Keep Docker's normal daemon networking and runtime defaults.
nohup dockerd > /var/log/dockerd.log 2>&1 &
dockerd_pid=$!

for _ in $(seq 1 15); do
	if docker info >/dev/null 2>&1; then
		echo "dockerd: ready (pid ${dockerd_pid}, log /var/log/dockerd.log)"
		break
	fi
	sleep 1
	if [ "${_}" = 15 ]; then
		echo "dockerd: not ready after 15s; see /var/log/dockerd.log" >&2
		echo "dockerd: typical cause: pod lacks the privileged capability" >&2
	fi
done

exit 0
