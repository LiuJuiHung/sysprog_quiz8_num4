CC := gcc
FLAGS := -O3

TEST := test
GIT_HOOKS := .git/hooks/applied

all: $(GIT_HOOKS) $(TEST) 

$(GIT_HOOKS):
	@scripts/install-git-hooks
	@echo

$(TEST):
	$(CC) $(FLAGS) -o $@ *.c

perf:
	echo 3 | sudo tee /proc/sys/vm/drop_caches;
	perf stat --repeat 100 \
		-e cache-misses,cache-references,instructions,cycles \
		./test 1
plot:
	gnuplot scripts/runtimeParity.gp
	eog runtimeParity.png 

clean:
	rm -f *.txt *.png test
