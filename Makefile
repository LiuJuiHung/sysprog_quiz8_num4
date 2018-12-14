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
	sudo taskset -c 0 nice --adjustment=-20 \
		perf stat \
		-e cache-misses,cache-references,instructions,cycles \
		./test 1
plot:
	gnuplot scripts/parityHeatmap.gp

clean:
	rm -f *.txt *.png test
