#define read_csr(reg) ({ unsigned long __tmp;    \
  __asm__ volatile ("csrr %0, " #reg : "=r"(__tmp)); \
  __tmp; })

#define START_STATS() \
  volatile long unsigned cycles_cntr_start = read_csr(cycle);       \
  volatile long unsigned instrs_cntr_start = read_csr(instret);     

#define STOP_STATS() \
  volatile long unsigned cycles_cntr = read_csr(cycle) - cycles_cntr_start;       \
  volatile long unsigned instrs_cntr = read_csr(instret) - instrs_cntr_start;     

#define PRINT_STATS() \
  printf("%lu, %lu \n", cycles_cntr, instrs_cntr)
