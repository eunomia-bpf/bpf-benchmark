# Verified-path coverage, recounted by simulator failure (2026-11-25T00:2xZ, coordinator)

Capture: /workspaces/kprog-raw/omp/classfg-20261124T070800Z/{tetragon,tracee}/service.tar.gz (OMP, 11-24, current
tree with the 11-23 B fixes and 439b53c92). Each request archive (service/requests/N.success.tar.gz) is opened; a
request with simulator-failure.json fell back to direct-native, one without it installed checked-sim-c. The
service's status 0 covers both, so "81 of 85" and "169 of 169" (2dc7f4fbb, COORDINATION 11:30Z and 18:42Z) count
the fallback too; the coordinator relayed them in the 11-24 reports, and this file corrects them.

| App | Requests | Verified path (checked-sim-c) | Fallback to direct-native | Fallback stage |
|---|---|---|---|---|
| Tetragon | 85 | **16** | 69 | verification 68, generation 1 |
| Tracee | 169 | **49** | 120 | verification 115, verification-preparation 5 |

Tetragon's 68 verifier rejections (native-link-refusals README in the coordinator's analysis directory): 35 invalid
write to stack R10 (class F, B frame past 512 bytes), 20 invalid mem access 'scalar' (class G), 12 E2BIG (over 1M
instructions), 1 too complex.

Script: count.py in this directory (one pass over the outer archive, each request archive opened in memory).
