.PHONY: c-test c-coverage c-sanitize c-lint c-format c-format-check c-clean
.PHONY: rust-build rust-test rust-coverage
.PHONY: rust-lint rust-format rust-format-check rust-clean

c-test:
	$(MAKE) -f config/c/Makefile test

c-coverage:
	$(MAKE) -f config/c/Makefile coverage

c-sanitize:
	$(MAKE) -f config/c/Makefile sanitize

c-lint:
	$(MAKE) -f config/c/Makefile lint

c-format:
	$(MAKE) -f config/c/Makefile format

c-format-check:
	$(MAKE) -f config/c/Makefile format-check

c-clean:
	$(MAKE) -f config/c/Makefile clean

rust-build rust-test rust-coverage rust-lint rust-format rust-format-check rust-clean:
	$(MAKE) -f config/rust/Makefile $@
