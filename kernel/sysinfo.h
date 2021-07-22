// the freemem field should be set to the number of bytes of free memory
// the nproc field should be set to the number of processes whose state is not UNUSED

struct sysinfo {
  uint64 freemem;   // amount of free memory (bytes)
  uint64 nproc;     // number of process
};
