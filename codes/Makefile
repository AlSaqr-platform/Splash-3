.PHONY: all clean

runtest :
	echo "cd /perf/splash3/codes/apps/barnes" > $@
	echo "./BARNES < inputs/n16384-p2" >> $@

	echo "cd /perf/splash3/codes/apps/fmm" >> $@
	echo "./FMM < inputs/input.2.16384" >> $@

	echo "cd /perf/splash3/codes/apps/ocean/contiguous_partitions" >> $@
	echo "./OCEAN -p2 -n258" >> $@

	echo "cd /perf/splash3/codes/apps/ocean/non_contiguous_partitions" >> $@
	echo "./OCEAN -p2 -n258" >> $@

	echo "cd /perf/splash3/codes/apps/radiosity" >> $@
	echo "./RADIOSITY -p 2 -ae 5000 -bf 0.1 -en 0.05 -room -batch" >> $@

	echo "cd /perf/splash3/codes/apps/raytrace" >> $@
	echo "./RAYTRACE -p2 -m64 inputs/car.env" >> $@

	echo "cd /perf/splash3/codes/apps/water-nsquared" >> $@
	echo "./WATER-NSQUARED < inputs/n512-p2" >> $@

	echo "cd /perf/splash3/codes/apps/water-spatial" >> $@
	echo "./WATER-SPATIAL < inputs/n512-p2" >> $@

	echo "cd /perf/splash3/codes/kernels/cholesky" >> $@
	echo "./CHOLESKY -p2 < inputs/tk15.O" >> $@

	echo "cd /perf/splash3/codes/kernels/fft" >> $@
	echo "./FFT -p2 -m16" >> $@

	echo "cd /perf/splash3/codes/kernels/lu/contiguous_blocks" >> $@
	echo "./LU -p2 -n512" >> $@

	echo "cd /perf/splash3/codes/kernels/lu/non_contiguous_blocks" >> $@
	echo "./LU -p2 -n512" >> $@

	echo "cd /perf/splash3/codes/kernels/radix" >> $@
	echo "./RADIX -p2 -n1048576" >> $@

	chmod +x $@

XLEN = 64
CVA_SDK_ROOT = $(abspath ../../culsans/cva6-sdk)

all: export TOOLCHAIN_PREFIX = $(CVA_SDK_ROOT)/buildroot/output/host/bin/riscv$(XLEN)-buildroot-linux-gnu-
all: runtest
	$(MAKE) --no-print-directory -C apps/barnes
	$(MAKE) --no-print-directory -C apps/fmm
	$(MAKE) --no-print-directory -C apps/ocean/contiguous_partitions
	$(MAKE) --no-print-directory -C apps/ocean/non_contiguous_partitions
	$(MAKE) --no-print-directory -C apps/radiosity
	$(MAKE) --no-print-directory -C apps/raytrace
	# $(MAKE) --no-print-directory -C apps/volrend
	$(MAKE) --no-print-directory -C apps/water-nsquared
	$(MAKE) --no-print-directory -C apps/water-spatial
	$(MAKE) --no-print-directory -C kernels/cholesky
	$(MAKE) --no-print-directory -C kernels/fft
	$(MAKE) --no-print-directory -C kernels/lu/contiguous_blocks
	$(MAKE) --no-print-directory -C kernels/lu/non_contiguous_blocks
	$(MAKE) --no-print-directory -C kernels/radix

clean:
	rm -f runtest
	$(MAKE) --no-print-directory -C apps/barnes clean
	$(MAKE) --no-print-directory -C apps/fmm clean
	$(MAKE) --no-print-directory -C apps/ocean/contiguous_partitions clean
	$(MAKE) --no-print-directory -C apps/ocean/non_contiguous_partitions clean
	$(MAKE) --no-print-directory -C apps/radiosity clean
	$(MAKE) --no-print-directory -C apps/raytrace clean
	# $(MAKE) --no-print-directory -C apps/volrend clean
	$(MAKE) --no-print-directory -C apps/water-nsquared clean
	$(MAKE) --no-print-directory -C apps/water-spatial clean
	$(MAKE) --no-print-directory -C kernels/cholesky clean
	$(MAKE) --no-print-directory -C kernels/fft clean
	$(MAKE) --no-print-directory -C kernels/lu/contiguous_blocks clean
	$(MAKE) --no-print-directory -C kernels/lu/non_contiguous_blocks clean
	$(MAKE) --no-print-directory -C kernels/radix clean
