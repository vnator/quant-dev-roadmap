CC := gcc

ROOT := .
BUILD := $(ROOT)/.build/c
COVERAGE_DIR := $(ROOT)/coverage/c

CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -Werror -O0 -g
COVERAGE_FLAGS := --coverage
SANITIZER_FLAGS := -fsanitize=address,undefined -fno-omit-frame-pointer

TESTS := $(shell find $(ROOT)/P* -type f -path '*/c/main.test.c' 2>/dev/null | sort)

READY_TESTS := $(shell find $(ROOT)/P* -type f -path '*/c/main.test.c' \
	| while IFS= read -r test; do \
		src=$$(dirname "$$test")/main.c; \
		if ! grep -q 'Implement the mathematical algorithm here' "$$src"; then \
			printf '%s\n' "$$test"; \
		fi; \
	done)

.PHONY: test coverage sanitize lint format format-check clean

test:
	@set -e; \
	mkdir -p $(BUILD)/test; \
	for test in $(READY_TESTS); do \
		src=$$(dirname "$$test")/main.c; \
		id=$$(basename $$(dirname $$(dirname "$$test"))); \
		output="$(BUILD)/test/$$id"; \
		echo "Testing $$id"; \
		$(CC) $(CFLAGS) "$$src" "$$test" -lm -o "$$output"; \
		"$$output"; \
	done

coverage:
	@set -e; \
	mkdir -p $(BUILD)/coverage $(COVERAGE_DIR); \
	rm -f $(BUILD)/coverage/*; \
	for test in $(READY_TESTS); do \
		src=$$(dirname "$$test")/main.c; \
		id=$$(basename $$(dirname $$(dirname "$$test"))); \
		output="$(BUILD)/coverage/$$id"; \
		$(CC) $(CFLAGS) $(COVERAGE_FLAGS) \
			"$$src" "$$test" -lm -o "$$output"; \
		"$$output"; \
	done
	cd $(ROOT) && gcovr \
		--root . \
		--object-directory .build/c/coverage \
		--filter 'P.*/.*c/main\.c$$' \
		--html-details \
		--output coverage/c/index.html

sanitize:
	@set -e; \
	mkdir -p $(BUILD)/sanitize; \
	for test in $(READY_TESTS); do \
		src=$$(dirname "$$test")/main.c; \
		id=$$(basename $$(dirname $$(dirname "$$test"))); \
		output="$(BUILD)/sanitize/$$id"; \
		$(CC) $(CFLAGS) $(SANITIZER_FLAGS) \
			"$$src" "$$test" -lm -o "$$output"; \
		"$$output"; \
	done

lint:
	@find $(ROOT)/P* -type f -name '*.c' \
		| while IFS= read -r file; do \
			if grep -q 'Implement the mathematical algorithm here' "$$file"; then \
				continue; \
			fi; \
			clang-tidy "$$file" -- $(CFLAGS) || exit 1; \
		done

format:
	@find $(ROOT)/P* -type f \
		\( -name '*.c' -o -name '*.h' \) \
		-exec clang-format \
		-style=file:config/c/.clang-format -i {} +

format-check:
	@find $(ROOT)/P* -type f \
		\( -name '*.c' -o -name '*.h' \) \
		-exec clang-format \
		-style=file:config/c/.clang-format \
		--dry-run --Werror {} +

clean:
	rm -rf $(BUILD) $(COVERAGE_DIR)
