# Benchmarks using the code for sparse matrices

The code here tests the performance of the MUMPS Sparse Solver.

The **case** keywords in the tables have the following meanings:

- **mpi1_omp#** compiled with MPI but with varying number of OpenMP threads (mpirun -np 1)

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
    <th>Factorize</th>
    <td>open_mpi1_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi1_omp1.txt">6.4647s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi1_omp2.txt">18.3009s</a>:worried:<br/>(0.353)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi1_omp3.txt">16.6833s</a>:worried:<br/>(0.387)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi1_omp4.txt">19.058s</a>:worried:<br/>(0.339)</td>
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
    <th>Factorize</th>
    <td>open_mpi1_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi1_omp1.txt">1m38.6689s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi1_omp2.txt">4m1.1184s</a>:worried:<br/>(0.409)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi1_omp3.txt">3m7.80238s</a>:worried:<br/>(0.525)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi1_omp4.txt">2m52.3749s</a>:worried:<br/>(0.572)</td>
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
    <th>Factorize</th>
    <td>open_mpi1_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi1_omp1.txt">5.49944s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi1_omp2.txt">13.8721s</a>:worried:<br/>(0.396)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi1_omp3.txt">9.49158s</a>:worried:<br/>(0.579)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi1_omp4.txt">9.22161s</a>:worried:<br/>(0.596)</td>
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
    <th>Factorize</th>
    <td>open_mpi1_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi1_omp1.txt">2.80763s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi1_omp2.txt">11.4492s</a>:worried:<br/>(0.245)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi1_omp3.txt">5.44067s</a>:worried:<br/>(0.516)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi1_omp4.txt">7.76523s</a>:worried:<br/>(0.362)</td>
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
    <th>Factorize</th>
    <td>open_mpi1_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi1_omp1.txt">1.64748ms</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi1_omp2.txt">2.08928ms</a><br/>(0.789)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi1_omp3.txt">1.20363ms</a><br/>(1.369)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi1_omp4.txt">6.424ms</a>:worried:<br/>(0.256)</td>
  </tr>
</table>



