# Benchmarks using the code for sparse matrices

## Previous results from 2021

- [Open: sequential + OpenMP](https://github.com/cpmech/laclib/tree/previous-2021-code/benchmarks/sparse/README-open_seq_ana_fact_total.md)
- [Open: MPI without OpenMP](https://github.com/cpmech/laclib/tree/previous-2021-code/benchmarks/sparse/README-open_mpionly_ana_fact_total.md)
- [Problem with Open: varying OMP_NUM_THREADS with MPI enabled](https://github.com/cpmech/laclib/tree/previous-2021-code/benchmarks/sparse/README-open_mpi1_omp_fact_problem.md)
- [Open and Intel](https://github.com/cpmech/laclib/tree/previous-2021-code/benchmarks/sparse/README-open_intel_all_fact.md)

## Details of my system used for benchmarks

Output of `free -h`

```
       total   used  free  shared  buff/cache   available
Mem:    46Gi  3.1Gi  30Gi   183Mi        13Gi        43Gi
Swap:   14Gi     0B  14Gi
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
