# Benchmarks using the code for sparse matrices

The code here tests the performance of the MUMPS Sparse Solver.

The **case** keywords in the tables have the following meanings:

- **seq_omp#** sequential (no mpi) with varying number of OpenMP threads

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
    <th>Analyze</th>
    <td>open_seq_omp#</td>
    <td>3.38483s</td>
    <td>3.40521s</td>
    <td>3.4027s</td>
    <td>3.40982s</td>
  </tr>
  <tr>
    <th>Factorize</th>
    <td>open_seq_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/latest/mumps_inline_1_metis_open_seq_omp1.txt">6.34252s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/latest/mumps_inline_1_metis_open_seq_omp2.txt">4.66872s</a><br/>(1.359)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/latest/mumps_inline_1_metis_open_seq_omp3.txt">3.99374s</a><br/>(1.588)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/latest/mumps_inline_1_metis_open_seq_omp4.txt">4.34756s</a><br/>(1.459)</td>
  </tr>
  <tr>
    <th>Total</th>
    <td>open_seq_omp#</td>
    <td>10.0962s</td>
    <td>8.4344s</td>
    <td>7.75277s</td>
    <td>8.11826s</td>
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
    <th>Analyze</th>
    <td>open_seq_omp#</td>
    <td>10.3829s</td>
    <td>10.4321s</td>
    <td>10.4273s</td>
    <td>10.3844s</td>
  </tr>
  <tr>
    <th>Factorize</th>
    <td>open_seq_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/latest/mumps_Flan_1565_metis_open_seq_omp1.txt">1m37.1963s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/latest/mumps_Flan_1565_metis_open_seq_omp2.txt">1m0.00271017s</a><br/>(1.620)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/latest/mumps_Flan_1565_metis_open_seq_omp3.txt">47.7004s</a><br/>(2.038)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/latest/mumps_Flan_1565_metis_open_seq_omp4.txt">44.6016s</a><br/>(2.179)</td>
  </tr>
  <tr>
    <th>Total</th>
    <td>open_seq_omp#</td>
    <td>1m50.2458s</td>
    <td>1m12.6538s</td>
    <td>1m0.209924s</td>
    <td>57.0271s</td>
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
    <th>Analyze</th>
    <td>open_seq_omp#</td>
    <td>5.16896s</td>
    <td>5.15426s</td>
    <td>5.15529s</td>
    <td>5.13033s</td>
  </tr>
  <tr>
    <th>Factorize</th>
    <td>open_seq_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/latest/mumps_pre2_metis_open_seq_omp1.txt">5.32965s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/latest/mumps_pre2_metis_open_seq_omp2.txt">3.68975s</a><br/>(1.444)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/latest/mumps_pre2_metis_open_seq_omp3.txt">3.15916s</a><br/>(1.687)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/latest/mumps_pre2_metis_open_seq_omp4.txt">3.01845s</a><br/>(1.766)</td>
  </tr>
  <tr>
    <th>Total</th>
    <td>open_seq_omp#</td>
    <td>11.3998s</td>
    <td>9.75269s</td>
    <td>9.23565s</td>
    <td>9.08247s</td>
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
    <th>Analyze</th>
    <td>open_seq_omp#</td>
    <td>3.98419s</td>
    <td>4.00929s</td>
    <td>3.97342s</td>
    <td>3.98054s</td>
  </tr>
  <tr>
    <th>Factorize</th>
    <td>open_seq_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/latest/mumps_tmt_unsym_metis_open_seq_omp1.txt">2.57749s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/latest/mumps_tmt_unsym_metis_open_seq_omp2.txt">2.43118s</a><br/>(1.060)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/latest/mumps_tmt_unsym_metis_open_seq_omp3.txt">2.3755s</a><br/>(1.085)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/latest/mumps_tmt_unsym_metis_open_seq_omp4.txt">2.48729s</a><br/>(1.036)</td>
  </tr>
  <tr>
    <th>Total</th>
    <td>open_seq_omp#</td>
    <td>8.15029s</td>
    <td>8.06895s</td>
    <td>7.96464s</td>
    <td>8.08189s</td>
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
    <th>Analyze</th>
    <td>open_seq_omp#</td>
    <td>817.612µs</td>
    <td>428.714µs</td>
    <td>582.933µs</td>
    <td>424.82µs</td>
  </tr>
  <tr>
    <th>Factorize</th>
    <td>open_seq_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/latest/mumps_bfwb62_metis_open_seq_omp1.txt">718.964µs</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/latest/mumps_bfwb62_metis_open_seq_omp2.txt">2.49391ms</a>:worried:<br/>(0.288)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/latest/mumps_bfwb62_metis_open_seq_omp3.txt">8.67061ms</a>:worried:<br/>(0.083)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/latest/mumps_bfwb62_metis_open_seq_omp4.txt">9.46407ms</a>:worried:<br/>(0.076)</td>
  </tr>
  <tr>
    <th>Total</th>
    <td>open_seq_omp#</td>
    <td>1.78449ms</td>
    <td>3.12266ms</td>
    <td>9.39697ms</td>
    <td>10.0863ms</td>
  </tr>
</table>



