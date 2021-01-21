# Benchmarks using the code for sparse matrices

The code here tests the perfomance of the MUMPS Sparse Solver.

The **case** keywords in the tables have the following meanings:

- **seq_omp#** sequential (no mpi) with varying number of OpenMP threads
- **mpi1_omp#** compiled with MPI but with varying number of OpenMP threads (mpirun -np 1)
- **mpi#** varying number of MPI procs; without OpenMP
- **mpi#_omp1** varying number of MPI procs, but compiled with OpenMP (ignored)
- **mpi#_omp#** 1 and 2 MPI procs combined with 1 and 2 OpenMP threads (1-1, 1-2, 2-1, 2-2)

The values in blue are links to the log files.


## GHS_psdef / inline_1 matrix

Reference: https://sparse.tamu.edu/GHS_psdef/inline_1

* Symmetric matrix
* Dimension = 503,712
* Number of non-zero values = 18,660,027
* L-infinity norm of the matrix = 1.146e+8

_results with "metis" ordering:_

<table>
  <tr>
    <td>inline_1</td>
    <th>case</th>
    <th>NP or NT 1</th>
    <th>NP or NT 2</th>
    <th>NP or NT 3</th>
    <th>NP or NT 4</th>
  </tr>
  <tr>
    <th rowspan="10">Factorize</th>
    <td>open_seq_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_seq_omp1.txt">6.36252s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_seq_omp2.txt">4.62749s</a><br/>(1.375)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_seq_omp3.txt">3.97806s</a><br/>(1.599)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_seq_omp4.txt">4.25562s</a><br/>(1.495)</td>
  </tr>
  <tr>
    <td>intel_seq_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_seq_omp1.txt">5.68874s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_seq_omp2.txt">3.91832s</a><br/>(1.452)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_seq_omp3.txt">3.34294s</a><br/>(1.702)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_seq_omp4.txt">3.02957s</a><br/>(1.878)</td>
  </tr>
  <tr>
    <td>open_mpi1_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi1_omp1.txt">6.4647s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi1_omp2.txt">18.3009s</a>:worried:<br/>(0.353)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi1_omp3.txt">16.6833s</a>:worried:<br/>(0.387)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi1_omp4.txt">19.058s</a>:worried:<br/>(0.339)</td>
  </tr>
  <tr>
    <td>intel_mpi1_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_mpi1_omp1.txt">5.7887s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_mpi1_omp2.txt">4.02575s</a><br/>(1.438)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_mpi1_omp3.txt">3.42749s</a><br/>(1.689)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_mpi1_omp4.txt">3.12079s</a><br/>(1.855)</td>
  </tr>
  <tr>
    <td>open_mpi#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi1.txt">6.13648s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi2.txt">3.79339s</a><br/>(1.618)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi3.txt">2.95808s</a><br/>(2.074)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi4.txt">2.63815s</a><br/>(2.326)</td>
  </tr>
  <tr>
    <td>intel_mpi#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_mpi1.txt">5.67728s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_mpi2.txt">3.52923s</a><br/>(1.609)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_mpi3.txt">2.739s</a><br/>(2.073)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_mpi4.txt">2.55059s</a><br/>(2.226)</td>
  </tr>
  <tr>
    <td>open_mpi#_omp1<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi1_omp1.txt">6.4647s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi2_omp1.txt">3.99489s</a><br/>(1.618)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi3_omp1.txt">3.06911s</a><br/>(2.106)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi4_omp1.txt">2.77405s</a><br/>(2.330)</td>
  </tr>
  <tr>
    <td>intel_mpi#_omp1<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_mpi1_omp1.txt">5.7887s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_mpi2_omp1.txt">3.59257s</a><br/>(1.611)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_mpi3_omp1.txt">2.78585s</a><br/>(2.078)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_mpi4_omp1.txt">2.57212s</a><br/>(2.251)</td>
  </tr>
  <tr>
    <td>open_mpi#_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi1_omp1.txt">6.4647s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi1_omp2.txt">18.3009s</a>:worried:<br/>(0.353)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi2_omp1.txt">3.99489s</a><br/>(1.618)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi2_omp2.txt">11.2702s</a>:worried:<br/>(0.574)</td>
  </tr>
  <tr>
    <td>intel_mpi#_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_mpi1_omp1.txt">5.7887s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_mpi1_omp2.txt">4.02575s</a><br/>(1.438)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_mpi2_omp1.txt">3.59257s</a><br/>(1.611)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_mpi2_omp2.txt">2.73908s</a><br/>(2.113)</td>
  </tr>
</table>



## Janna / Flan_1565 matrix

Reference: https://sparse.tamu.edu/Janna/Flan_1565

* Symmetric matrix
* Dimension = 1,564,794
* Number of non-zero values = 59,485,419
* L-infinity norm of the matrix = 1.529e+7

_results with "metis" ordering:_

<table>
  <tr>
    <td>Flan_1565</td>
    <th>case</th>
    <th>NP or NT 1</th>
    <th>NP or NT 2</th>
    <th>NP or NT 3</th>
    <th>NP or NT 4</th>
  </tr>
  <tr>
    <th rowspan="10">Factorize</th>
    <td>open_seq_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_seq_omp1.txt">1m37.4251s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_seq_omp2.txt">1m0.324837s</a><br/>(1.615)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_seq_omp3.txt">47.8449s</a><br/>(2.036)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_seq_omp4.txt">49.1331s</a><br/>(1.983)</td>
  </tr>
  <tr>
    <td>intel_seq_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_seq_omp1.txt">1m30.7773s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_seq_omp2.txt">53.0423s</a><br/>(1.711)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_seq_omp3.txt">40.2833s</a><br/>(2.253)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_seq_omp4.txt">34.0186s</a><br/>(2.668)</td>
  </tr>
  <tr>
    <td>open_mpi1_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi1_omp1.txt">1m38.6689s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi1_omp2.txt">4m1.1184s</a>:worried:<br/>(0.409)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi1_omp3.txt">3m7.80238s</a>:worried:<br/>(0.525)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi1_omp4.txt">2m52.3749s</a>:worried:<br/>(0.572)</td>
  </tr>
  <tr>
    <td>intel_mpi1_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_mpi1_omp1.txt">1m30.6453s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_mpi1_omp2.txt">53.6015s</a><br/>(1.691)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_mpi1_omp3.txt">40.3981s</a><br/>(2.244)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_mpi1_omp4.txt">34.3459s</a><br/>(2.639)</td>
  </tr>
  <tr>
    <td>open_mpi#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi1.txt">1m37.76s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi2.txt">54.4157s</a><br/>(1.797)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi3.txt">41.9622s</a><br/>(2.330)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi4.txt">35.3765s</a><br/>(2.763)</td>
  </tr>
  <tr>
    <td>intel_mpi#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_mpi1.txt">1m30.9377s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_mpi2.txt">51.4988s</a><br/>(1.766)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_mpi3.txt">39.1596s</a><br/>(2.322)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_mpi4.txt">34.4584s</a><br/>(2.639)</td>
  </tr>
  <tr>
    <td>open_mpi#_omp1<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi1_omp1.txt">1m38.6689s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi2_omp1.txt">55.0578s</a><br/>(1.792)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi3_omp1.txt">41.3877s</a><br/>(2.384)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi4_omp1.txt">35.3778s</a><br/>(2.789)</td>
  </tr>
  <tr>
    <td>intel_mpi#_omp1<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_mpi1_omp1.txt">1m30.6453s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_mpi2_omp1.txt">51.307s</a><br/>(1.767)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_mpi3_omp1.txt">39.1394s</a><br/>(2.316)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_mpi4_omp1.txt">34.1555s</a><br/>(2.654)</td>
  </tr>
  <tr>
    <td>open_mpi#_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi1_omp1.txt">1m38.6689s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi1_omp2.txt">4m1.1184s</a>:worried:<br/>(0.409)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi2_omp1.txt">55.0578s</a><br/>(1.792)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi2_omp2.txt">2m5.67456s</a><br/>(0.785)</td>
  </tr>
  <tr>
    <td>intel_mpi#_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_mpi1_omp1.txt">1m30.6453s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_mpi1_omp2.txt">53.6015s</a><br/>(1.691)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_mpi2_omp1.txt">51.307s</a><br/>(1.767)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_mpi2_omp2.txt">32.9528s</a><br/>(2.751)</td>
  </tr>
</table>



## ATandT / pre2 matrix

Reference: https://sparse.tamu.edu/ATandT/pre2

* General matrix (unsymmetric)
* Dimension = 659,033
* Number of non-zero values = 5,959,282
* L-infinity norm of the matrix = 1.478e+10

_results with "metis" ordering:_

<table>
  <tr>
    <td>pre2</td>
    <th>case</th>
    <th>NP or NT 1</th>
    <th>NP or NT 2</th>
    <th>NP or NT 3</th>
    <th>NP or NT 4</th>
  </tr>
  <tr>
    <th rowspan="10">Factorize</th>
    <td>open_seq_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_seq_omp1.txt">5.37544s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_seq_omp2.txt">3.64571s</a><br/>(1.474)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_seq_omp3.txt">3.12367s</a><br/>(1.721)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_seq_omp4.txt">2.95089s</a><br/>(1.822)</td>
  </tr>
  <tr>
    <td>intel_seq_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_seq_omp1.txt">4.99453s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_seq_omp2.txt">3.39196s</a><br/>(1.472)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_seq_omp3.txt">2.90294s</a><br/>(1.721)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_seq_omp4.txt">2.62193s</a><br/>(1.905)</td>
  </tr>
  <tr>
    <td>open_mpi1_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi1_omp1.txt">5.49944s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi1_omp2.txt">13.8721s</a>:worried:<br/>(0.396)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi1_omp3.txt">9.49158s</a>:worried:<br/>(0.579)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi1_omp4.txt">9.22161s</a>:worried:<br/>(0.596)</td>
  </tr>
  <tr>
    <td>intel_mpi1_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_mpi1_omp1.txt">6.37469s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_mpi1_omp2.txt">4.88673s</a><br/>(1.304)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_mpi1_omp3.txt">4.42781s</a><br/>(1.440)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_mpi1_omp4.txt">4.12234s</a><br/>(1.546)</td>
  </tr>
  <tr>
    <td>open_mpi#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi1.txt">4.91764s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi2.txt">22.9564s</a>:worried:<br/>(0.214)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi3.txt">22.4854s</a>:worried:<br/>(0.219)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi4.txt">2m16.8747s</a>:worried:<br/>(0.036)</td>
  </tr>
  <tr>
    <td>intel_mpi#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_mpi1.txt">6.18684s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_mpi2.txt">31.8467s</a>:worried:<br/>(0.194)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_mpi3.txt">26.9357s</a>:worried:<br/>(0.230)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_mpi4.txt">1m50.7227s</a>:worried:<br/>(0.056)</td>
  </tr>
  <tr>
    <td>open_mpi#_omp1<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi1_omp1.txt">5.49944s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi2_omp1.txt">23.8411s</a>:worried:<br/>(0.231)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi3_omp1.txt">22.5868s</a>:worried:<br/>(0.243)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi4_omp1.txt">2m16.6926s</a>:worried:<br/>(0.040)</td>
  </tr>
  <tr>
    <td>intel_mpi#_omp1<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_mpi1_omp1.txt">6.37469s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_mpi2_omp1.txt">31.9531s</a>:worried:<br/>(0.200)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_mpi3_omp1.txt">26.953s</a>:worried:<br/>(0.237)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_mpi4_omp1.txt">1m50.6222s</a>:worried:<br/>(0.058)</td>
  </tr>
  <tr>
    <td>open_mpi#_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi1_omp1.txt">5.49944s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi1_omp2.txt">13.8721s</a>:worried:<br/>(0.396)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi2_omp1.txt">23.8411s</a>:worried:<br/>(0.231)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi2_omp2.txt">42.3962s</a>:worried:<br/>(0.130)</td>
  </tr>
  <tr>
    <td>intel_mpi#_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_mpi1_omp1.txt">6.37469s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_mpi1_omp2.txt">4.88673s</a><br/>(1.304)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_mpi2_omp1.txt">31.9531s</a>:worried:<br/>(0.200)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_mpi2_omp2.txt">23.9735s</a>:worried:<br/>(0.266)</td>
  </tr>
</table>



## CEMW / tmt_unsym matrix

Reference: https://sparse.tamu.edu/CEMW/tmt_unsym

* General matrix (unsymmetric)
* Dimension = 917,825
* Number of non-zero values = 4,584,801
* L-infinity norm of the matrix = 4.000e+0

_results with "metis" ordering:_

<table>
  <tr>
    <td>tmt_unsym</td>
    <th>case</th>
    <th>NP or NT 1</th>
    <th>NP or NT 2</th>
    <th>NP or NT 3</th>
    <th>NP or NT 4</th>
  </tr>
  <tr>
    <th rowspan="10">Factorize</th>
    <td>open_seq_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_seq_omp1.txt">2.54191s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_seq_omp2.txt">2.37828s</a><br/>(1.069)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_seq_omp3.txt">2.31647s</a><br/>(1.097)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_seq_omp4.txt">2.38263s</a><br/>(1.067)</td>
  </tr>
  <tr>
    <td>intel_seq_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_seq_omp1.txt">2.07689s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_seq_omp2.txt">1.96206s</a><br/>(1.059)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_seq_omp3.txt">1.90929s</a><br/>(1.088)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_seq_omp4.txt">1.90546s</a><br/>(1.090)</td>
  </tr>
  <tr>
    <td>open_mpi1_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi1_omp1.txt">2.80763s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi1_omp2.txt">11.4492s</a>:worried:<br/>(0.245)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi1_omp3.txt">5.44067s</a>:worried:<br/>(0.516)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi1_omp4.txt">7.76523s</a>:worried:<br/>(0.362)</td>
  </tr>
  <tr>
    <td>intel_mpi1_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_mpi1_omp1.txt">4.74725s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_mpi1_omp2.txt">4.81892s</a><br/>(0.985)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_mpi1_omp3.txt">4.76848s</a><br/>(0.996)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_mpi1_omp4.txt">4.7263s</a><br/>(1.004)</td>
  </tr>
  <tr>
    <td>open_mpi#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi1.txt">1.76627s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi2.txt">1.032s</a><br/>(1.712)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi3.txt">830.282ms</a><br/>(2.127)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi4.txt">720.785ms</a><br/>(2.450)</td>
  </tr>
  <tr>
    <td>intel_mpi#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_mpi1.txt">4.45923s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_mpi2.txt">2.24104s</a><br/>(1.990)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_mpi3.txt">1.6458s</a><br/>(2.709)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_mpi4.txt">1.3016s</a><br/>(3.426)</td>
  </tr>
  <tr>
    <td>open_mpi#_omp1<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi1_omp1.txt">2.80763s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi2_omp1.txt">1.59082s</a><br/>(1.765)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi3_omp1.txt">1.20099s</a><br/>(2.338)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi4_omp1.txt">970.823ms</a><br/>(2.892)</td>
  </tr>
  <tr>
    <td>intel_mpi#_omp1<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_mpi1_omp1.txt">4.74725s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_mpi2_omp1.txt">2.37848s</a><br/>(1.996)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_mpi3_omp1.txt">1.77018s</a><br/>(2.682)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_mpi4_omp1.txt">1.39746s</a><br/>(3.397)</td>
  </tr>
  <tr>
    <td>open_mpi#_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi1_omp1.txt">2.80763s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi1_omp2.txt">11.4492s</a>:worried:<br/>(0.245)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi2_omp1.txt">1.59082s</a><br/>(1.765)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi2_omp2.txt">6.29106s</a>:worried:<br/>(0.446)</td>
  </tr>
  <tr>
    <td>intel_mpi#_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_mpi1_omp1.txt">4.74725s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_mpi1_omp2.txt">4.81892s</a><br/>(0.985)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_mpi2_omp1.txt">2.37848s</a><br/>(1.996)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_mpi2_omp2.txt">2.42056s</a><br/>(1.961)</td>
  </tr>
</table>



## Bai / bfwb62 matrix

Reference: https://sparse.tamu.edu/Bai/bfwb62

* Symmetric matrix
* Dimension = 62
* Number of non-zero values = 202
* L-infinity norm of the matrix = 1.000e-4

_results with "metis" ordering:_

<table>
  <tr>
    <td>bfwb62</td>
    <th>case</th>
    <th>NP or NT 1</th>
    <th>NP or NT 2</th>
    <th>NP or NT 3</th>
    <th>NP or NT 4</th>
  </tr>
  <tr>
    <th rowspan="10">Factorize</th>
    <td>open_seq_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_seq_omp1.txt">376.599µs</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_seq_omp2.txt">8.76785ms</a>:worried:<br/>(0.043)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_seq_omp3.txt">28.5722ms</a>:worried:<br/>(0.013)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_seq_omp4.txt">9.00163ms</a>:worried:<br/>(0.042)</td>
  </tr>
  <tr>
    <td>intel_seq_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_seq_omp1.txt">22.5825ms</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_seq_omp2.txt">4.8315ms</a><br/>(4.674)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_seq_omp3.txt">4.69297ms</a><br/>(4.812)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_seq_omp4.txt">11.9224ms</a><br/>(1.894)</td>
  </tr>
  <tr>
    <td>open_mpi1_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi1_omp1.txt">1.64748ms</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi1_omp2.txt">2.08928ms</a><br/>(0.789)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi1_omp3.txt">1.20363ms</a><br/>(1.369)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi1_omp4.txt">6.424ms</a>:worried:<br/>(0.256)</td>
  </tr>
  <tr>
    <td>intel_mpi1_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_mpi1_omp1.txt">10.297ms</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_mpi1_omp2.txt">6.58081ms</a><br/>(1.565)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_mpi1_omp3.txt">8.18585ms</a><br/>(1.258)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_mpi1_omp4.txt">14.3465ms</a>:worried:<br/>(0.718)</td>
  </tr>
  <tr>
    <td>open_mpi#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi1.txt">1.28033ms</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi2.txt">1.6484ms</a><br/>(0.777)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi3.txt">926.544µs</a><br/>(1.382)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi4.txt">1.05918ms</a><br/>(1.209)</td>
  </tr>
  <tr>
    <td>intel_mpi#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_mpi1.txt">7.48603ms</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_mpi2.txt">3.62667ms</a><br/>(2.064)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_mpi3.txt">3.69428ms</a><br/>(2.026)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_mpi4.txt">23.6338ms</a>:worried:<br/>(0.317)</td>
  </tr>
  <tr>
    <td>open_mpi#_omp1<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi1_omp1.txt">1.64748ms</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi2_omp1.txt">656.11µs</a><br/>(2.511)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi3_omp1.txt">1.33194ms</a><br/>(1.237)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi4_omp1.txt">998.586µs</a><br/>(1.650)</td>
  </tr>
  <tr>
    <td>intel_mpi#_omp1<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_mpi1_omp1.txt">10.297ms</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_mpi2_omp1.txt">4.06645ms</a><br/>(2.532)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_mpi3_omp1.txt">3.24646ms</a><br/>(3.172)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_mpi4_omp1.txt">3.20821ms</a><br/>(3.210)</td>
  </tr>
  <tr>
    <td>open_mpi#_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi1_omp1.txt">1.64748ms</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi1_omp2.txt">2.08928ms</a><br/>(0.789)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi2_omp1.txt">656.11µs</a><br/>(2.511)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi2_omp2.txt">506.321µs</a><br/>(3.254)</td>
  </tr>
  <tr>
    <td>intel_mpi#_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_mpi1_omp1.txt">10.297ms</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_mpi1_omp2.txt">6.58081ms</a><br/>(1.565)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_mpi2_omp1.txt">4.06645ms</a><br/>(2.532)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_mpi2_omp2.txt">3.36536ms</a><br/>(3.060)</td>
  </tr>
</table>



