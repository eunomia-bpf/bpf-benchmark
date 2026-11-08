set -eu
D=/workspaces/.agent-state/kprog-lanes/C/design-only
A="$D/apps"
trap 'echo $? > "$A/retry.exit"' EXIT
cd /workspaces/repository
sh "$A/run.sh"
