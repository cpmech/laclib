# Benchmarks using laclib

This directory contains some benchmarks using laclib.

```
├── benchmarks
    ├── blas    # tests the performance of some blas code
    └── sparse  # tests the performance of sparse solvers
``

First, we need to download some (large) test matrices in the data subdirectory:

```bash
cd benchmarks/sparse/data
./download.bash
```

Second, we need to compile the benchmark code:

```bash
./all-bench.bash
```

or

```bash
./all.bash OFF ON
```

Then, we can run the benchmarks as follows:

```bash
cd build/benchmarks/sparse
mpirun -np 2 ./benchmark_sparse pre2
```

to run the test with the "pre2" matrix.

The results will be stored in the `benchmarks/sparse/results` directory.

For instance:

```json
{
  "Platform": "laclib",
  "SolverKind": "mumps",
  "MatrixName": "pre2",
  "Ordering": "metis",
  "MpiSize": 1,
  "Symmetric": false,
  "NumberOfRows": 659033,
  "NumberOfCols": 659033,
  "NumberOfNonZeros": 5959282,
  "StepReadMatrix": {
    "ElapsedTimeNanoseconds": 1857100987,
    "ElapsedTimeString": "1.8571s",
    "MemoryBytes": 808529920,
    "MemoryMiB": "771"
  },
  "StepAnalyze": {
    "ElapsedTimeNanoseconds": 5408379292,
    "ElapsedTimeString": "5.40838s",
    "MemoryBytes": 1017524224,
    "MemoryMiB": "970"
  },
  "StepFactorize": {
    "ElapsedTimeNanoseconds": 4797668331,
    "ElapsedTimeString": "4.79767s",
    "MemoryBytes": 17145073664,
    "MemoryMiB": "16,350"
  },
  "StepSolve": {
    "ElapsedTimeNanoseconds": 697503634,
    "ElapsedTimeString": "697.504ms",
    "MemoryBytes": 17145073664,
    "MemoryMiB": "16,350"
  },
  "TimeSolverNanoseconds": 10903484008,
  "TimeSolverString": "10.9035s",
  "Stats": {
    "NormInfA": 1.47772e+10,
    "NormInfAx": 1.00001,
    "NormInfDiff": 1.21593e-05,
    "RelativeError": 8.22847e-16,
    "ElapsedTimeNanoseconds": 35116821,
    "ElapsedTimeString": "35.1168ms"
  }
}
```

indicates that the problem involving the **pre2** matrix took aobut 5.41s to analyze and 4.8s to factorize. The total time analyze+factorize+solve was 10.9s. In this problem, the maximum absolute value of the sparse matrix is 1.47772e+10 and the relative error was about 8e-16. The error calculation took 35ms to compute.

## System details

Output of `free -m`

```
              total        used        free      shared  buff/cache   available
Mem:          47903        3329       31419         193       13154       43903
Swap:         15257           0       15257
```

Output of `cat /proc/cpuinfo`

```
processor	: 11
vendor_id	: GenuineIntel
cpu family	: 6
model		: 158
model name	: Intel(R) Core(TM) i7-8700K CPU @ 3.70GHz
stepping	: 10
microcode	: 0xde
cpu MHz		: 900.081
cache size	: 12288 KB
physical id	: 0
siblings	: 12
core id		: 5
cpu cores	: 6
apicid		: 11
initial apicid	: 11
fpu		: yes
fpu_exception	: yes
cpuid level	: 22
wp		: yes
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp lm constant_tsc art arch_perfmon pebs bts rep_good nopl xtopology nonstop_tsc cpuid aperfmperf pni pclmulqdq dtes64 monitor ds_cpl vmx smx est tm2 ssse3 sdbg fma cx16 xtpr pdcm pcid sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand lahf_lm abm 3dnowprefetch cpuid_fault epb invpcid_single pti ssbd ibrs ibpb stibp tpr_shadow vnmi flexpriority ept vpid ept_ad fsgsbase tsc_adjust bmi1 hle avx2 smep bmi2 erms invpcid rtm mpx rdseed adx smap clflushopt intel_pt xsaveopt xsavec xgetbv1 xsaves dtherm ida arat pln pts hwp hwp_notify hwp_act_window hwp_epp md_clear flush_l1d
bugs		: cpu_meltdown spectre_v1 spectre_v2 spec_store_bypass l1tf mds swapgs taa itlb_multihit srbds
bogomips	: 7399.70
clflush size	: 64
cache_alignment	: 64
address sizes	: 39 bits physical, 48 bits virtual
power management:
```

Output of `lsb_release -a`

```
No LSB modules are available.
Distributor ID:	Ubuntu
Description:	Ubuntu 20.04.1 LTS
Release:	20.04
Codename:	focal
```
