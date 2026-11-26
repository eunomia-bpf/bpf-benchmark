.PHONY: reproduce
reproduce:
	python3 reproduce.py

.PHONY: loader-before loader-after
loader-before:
	python3 loader_check.py before
loader-after:
	python3 loader_check.py after

.PHONY: checked-before checked-after
checked-before:
	python3 checked_emit.py before
checked-after:
	python3 checked_emit.py after

.PHONY: base-smoke
base-smoke:
	python3 loader_check.py base

.PHONY: guest-check
guest-check:
	python3 guest_check.py

.PHONY: guest-outcome
guest-outcome:
	python3 guest_outcome.py $(CURDIR)/guest-20261126T220327Z/controller.json
