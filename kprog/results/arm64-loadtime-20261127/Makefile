.PHONY: profile
profile:
	prlimit --as=51539607552 taskset -c 18 python3 profile.py

.PHONY: early-promote
early-promote:
	prlimit --as=51539607552 taskset -c 18 python3 profile.py early-promote

.PHONY: const-selectors
const-selectors:
	prlimit --as=51539607552 taskset -c 18 python3 profile.py const-selectors
