#define read_csr(reg) ({ unsigned long __tmp;    \
  __asm__ volatile ("csrr %0, " #reg : "=r"(__tmp)); \
  __tmp; })

#if PL_TARGET

#define START_STATS()                                               \
  volatile long unsigned cycles_cntr_start           = read_csr(cycle);   \
  volatile long unsigned instrs_cntr_start           = read_csr(instret); \
  volatile long unsigned icachemiss_start            = read_csr(0xC03);   \
  volatile long unsigned dcachemiss_start            = read_csr(0xC04);   \
  volatile long unsigned levent_start                = read_csr(0xC05);   \
  volatile long unsigned sevent_start                = read_csr(0xC06);   \
  volatile long unsigned ifempty_start               = read_csr(0xC07);   \
  volatile long unsigned stall_start                 = read_csr(0xC08);   \
  volatile long unsigned in_snoop_read_once_start       = read_csr(0xC09);   \
  volatile long unsigned in_snoop_read_shared_start     = read_csr(0xC0A);   \
  volatile long unsigned in_snoop_read_clean_start      = read_csr(0xC0B);   \
  volatile long unsigned in_snoop_read_no_shared_start  = read_csr(0xC0C);   \
  volatile long unsigned in_snoop_read_unique_start     = read_csr(0xC0D);   \
  volatile long unsigned in_snoop_clean_shared_start    = read_csr(0xC0E);   \
  volatile long unsigned in_snoop_clean_invalid_start   = read_csr(0xC0F);   \
  volatile long unsigned in_snoop_clean_unique_start    = read_csr(0xC10);   \
  volatile long unsigned in_snoop_make_invalid_start    = read_csr(0xC11);   \
  volatile long unsigned out_snoop_read_once_start      = read_csr(0xC12);   \
  volatile long unsigned out_snoop_read_shared_start    = read_csr(0xC13);   \
  volatile long unsigned out_snoop_read_unique_start    = read_csr(0xC14);   \
  volatile long unsigned out_snoop_read_no_snoop_start  = read_csr(0xC15);   \
  volatile long unsigned out_snoop_clean_unique_start   = read_csr(0xC16);   \
  volatile long unsigned out_snoop_wr_unique_start      = read_csr(0xC17);   \
  volatile long unsigned out_snoop_wr_nosnoop_start     = read_csr(0xC18);   \
  volatile long unsigned out_snoop_snoop_wrback_start   = read_csr(0xC19)

#define STOP_STATS() \
  volatile long unsigned cycles_cntr           =  read_csr(cycle)   - cycles_cntr_start;       \
  volatile long unsigned instrs_cntr           =  read_csr(instret) - instrs_cntr_start;     \
  volatile long unsigned icachemiss            =  read_csr(0xC03)   - icachemiss_start ; \
  volatile long unsigned dcachemiss            =  read_csr(0xC04)   - dcachemiss_start ; \
  volatile long unsigned levent                =  read_csr(0xC05)   - levent_start     ; \
  volatile long unsigned sevent                =  read_csr(0xC06)   - sevent_start     ; \
  volatile long unsigned ifempty               =  read_csr(0xC07)   - ifempty_start    ; \
  volatile long unsigned stall                 =  read_csr(0xC08)   - stall_start      ; \
  volatile long unsigned in_snoop_read_once       = read_csr(0xC09) - in_snoop_read_once_start     ;   \
  volatile long unsigned in_snoop_read_shared     = read_csr(0xC0A) - in_snoop_read_shared_start   ;   \
  volatile long unsigned in_snoop_read_clean      = read_csr(0xC0B) - in_snoop_read_clean_start    ;   \
  volatile long unsigned in_snoop_read_no_shared  = read_csr(0xC0C) - in_snoop_read_no_shared_start;   \
  volatile long unsigned in_snoop_read_unique     = read_csr(0xC0D) - in_snoop_read_unique_start   ;   \
  volatile long unsigned in_snoop_clean_shared    = read_csr(0xC0E) - in_snoop_clean_shared_start  ;   \
  volatile long unsigned in_snoop_clean_invalid   = read_csr(0xC0F) - in_snoop_clean_invalid_start ;   \
  volatile long unsigned in_snoop_clean_unique    = read_csr(0xC10) - in_snoop_clean_unique_start  ;   \
  volatile long unsigned in_snoop_make_invalid    = read_csr(0xC11) - in_snoop_make_invalid_start  ;   \
  volatile long unsigned out_snoop_read_once      = read_csr(0xC12) - out_snoop_read_once_start    ;   \
  volatile long unsigned out_snoop_read_shared    = read_csr(0xC13) - out_snoop_read_shared_start  ;   \
  volatile long unsigned out_snoop_read_unique    = read_csr(0xC14) - out_snoop_read_unique_start  ;   \
  volatile long unsigned out_snoop_read_no_snoop  = read_csr(0xC15) - out_snoop_read_no_snoop_start;   \
  volatile long unsigned out_snoop_clean_unique   = read_csr(0xC16) - out_snoop_clean_unique_start ;   \
  volatile long unsigned out_snoop_wr_unique      = read_csr(0xC17) - out_snoop_wr_unique_start    ;   \
  volatile long unsigned out_snoop_wr_nosnoop     = read_csr(0xC18) - out_snoop_wr_nosnoop_start   ;   \
  volatile long unsigned out_snoop_snoop_wrback   = read_csr(0xC19) - out_snoop_snoop_wrback_start 

#define PRINT_STATS() \
printf("%lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu ,%lu, %lu , %lu, %lu, %lu, %lu, %lu, %lu ,%lu, %lu \n ", \
         cycles_cntr         , instrs_cntr          , icachemiss, dcachemiss, levent               , sevent              , ifempty             , stall  , \
         in_snoop_read_once     , in_snoop_read_shared    , in_snoop_read_clean      , in_snoop_read_no_shared , in_snoop_read_unique   , in_snoop_clean_shared  , in_snoop_clean_invalid , \
         in_snoop_clean_unique  , in_snoop_make_invalid   , out_snoop_read_once     , out_snoop_read_shared    , out_snoop_read_unique     , out_snoop_read_no_snoop  , out_snoop_clean_unique   , \
         out_snoop_wr_unique  , out_snoop_wr_nosnoop ,   out_snoop_snoop_wrback )

#else

#define START_STATS()                                               \
  volatile long unsigned cycles_cntr_start = read_csr(cycle);       \
  volatile long unsigned instrs_cntr_start = read_csr(instret);     

#define STOP_STATS() \
  volatile long unsigned cycles_cntr = read_csr(cycle) - cycles_cntr_start;       \
  volatile long unsigned instrs_cntr = read_csr(instret) - instrs_cntr_start;     

#define PRINT_STATS() \
  printf("%lu, %lu \n", cycles_cntr, instrs_cntr)

#endif
