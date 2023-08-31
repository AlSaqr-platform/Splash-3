.PHONY: all clean

runtest :
	echo "cd /perf/splash3/codes/apps/barnes" > runtest
	echo "./BARNES < inputs/n16384-p2" >> runtest

	echo "cd /perf/splash3/codes/apps/fmm" >> runtest
	echo "./FMM < inputs/input.2.16384" >> runtest

	echo "cd /perf/splash3/codes/apps/ocean/contiguous_partitions" >> runtest
	echo "./OCEAN -p2 -n258" >> runtest

	echo "cd /perf/splash3/codes/apps/ocean/non_contiguous_partitions" >> runtest
	echo "./OCEAN -p2 -n258" >> runtest

	echo "cd /perf/splash3/codes/apps/radiosity" >> runtest
	echo "./RADIOSITY -p 2 -ae 5000 -bf 0.1 -en 0.05 -room -batch" >> runtest

	echo "cd /perf/splash3/codes/apps/raytrace" >> runtest
	echo "./RAYTRACE -p2 -m64 inputs/car.env" >> runtest

	echo "cd /perf/splash3/codes/apps/water-nsquared" >> runtest
	echo "./WATER-NSQUARED < inputs/n512-p2" >> runtest

	echo "cd /perf/splash3/codes/apps/water-spatial" >> runtest
	echo "./WATER-SPATIAL < inputs/n512-p2" >> runtest

	echo "cd /perf/splash3/codes/kernels/cholesky" >> runtest
	echo "./CHOLESKY -p2 < inputs/tk15.O" >> runtest

	echo "cd /perf/splash3/codes/kernels/fft" >> runtest
	echo "./FFT -p2 -m16" >> runtest

	echo "cd /perf/splash3/codes/kernels/lu/contiguous_blocks" >> runtest
	echo "./LU -p2 -n512" >> runtest

	echo "cd /perf/splash3/codes/kernels/lu/non_contiguous_blocks" >> runtest
	echo "./LU -p2 -n512" >> runtest

	echo "cd /perf/splash3/codes/kernels/radix" >> runtest
	echo "./RADIX -p2 -n1048576" >> runtest

	chmod +x runtest

all: runtest
	$(MAKE) -C apps/barnes
	$(MAKE) -C apps/fmm
	$(MAKE) -C apps/ocean/contiguous_partitions
	$(MAKE) -C apps/ocean/non_contiguous_partitions
	$(MAKE) -C apps/radiosity
	$(MAKE) -C apps/raytrace
        # $(MAKE) -C apps/volrend
	$(MAKE) -C apps/water-nsquared
	$(MAKE) -C apps/water-spatial
	$(MAKE) -C kernels/cholesky
	$(MAKE) -C kernels/fft
	$(MAKE) -C kernels/lu/contiguous_blocks
	$(MAKE) -C kernels/lu/non_contiguous_blocks
	$(MAKE) -C kernels/radix

clean:
	$(MAKE) -C apps/barnes clean
	$(MAKE) -C apps/fmm clean
	$(MAKE) -C apps/ocean/contiguous_partitions clean
	$(MAKE) -C apps/ocean/non_contiguous_partitions clean
	$(MAKE) -C apps/radiosity clean
	$(MAKE) -C apps/raytrace clean
        #$(MAKE) -C apps/volrend clean
	$(MAKE) -C apps/water-nsquared clean
	$(MAKE) -C apps/water-spatial clean
	$(MAKE) -C kernels/cholesky clean
	$(MAKE) -C kernels/fft clean
	$(MAKE) -C kernels/lu/contiguous_blocks clean
	$(MAKE) -C kernels/lu/non_contiguous_blocks clean
	$(MAKE) -C kernels/radix clean
