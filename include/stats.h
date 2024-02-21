#define read_csr(reg) ({ unsigned long __tmp;    \
  __asm__ volatile ("csrr %0, " #reg : "=r"(__tmp)); \
  __tmp; })

#define START_STATS() \
  volatile long unsigned cycles_cntr_start = read_csr(cycle);       \
  volatile long unsigned instrs_cntr_start = read_csr(instret);     \
  volatile long unsigned icachemiss_start  = read_csr(0xC03); \
  volatile long unsigned dcachemiss_start  = read_csr(0xC04); \
  volatile long unsigned levent_start      = read_csr(0xC05); \
  volatile long unsigned sevent_start      = read_csr(0xC06); \
  volatile long unsigned ifempty_start     = read_csr(0xC07); \
  volatile long unsigned stall_start       = read_csr(0xC08);

#define STOP_STATS() \
  volatile long unsigned cycles_cntr = cycles_cntr_start - read_csr(cycle);       \
  volatile long unsigned instrs_cntr = instrs_cntr_start - read_csr(instret);     \
  volatile long unsigned icachemiss  = icachemiss_start  - read_csr(0xC03); \
  volatile long unsigned dcachemiss  = dcachemiss_start  - read_csr(0xC04); \
  volatile long unsigned levent      = levent_start      - read_csr(0xC05); \
  volatile long unsigned sevent      = sevent_start      - read_csr(0xC06); \
  volatile long unsigned ifempty     = ifempty_start     - read_csr(0xC07); \
  volatile long unsigned stall       = stall_start       - read_csr(0xC08);

#define PRINT_STATS() \
  printf("%lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu\n", cycles_cntr, instrs_cntr, icachemiss, dcachemiss, levent    , sevent    , ifempty   , stall   );
