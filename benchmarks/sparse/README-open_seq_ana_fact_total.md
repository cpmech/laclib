# Benchmarks using the code for sparse matrices

The code here tests the perfomance of the MUMPS Sparse Solver.

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
    <td>3.43877s</td>
    <td>3.45666s</td>
    <td>3.44702s</td>
    <td>3.43961s</td>
  </tr>
  <tr>
    <th>Factorize</th>
    <td>open_seq_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_seq_omp1.txt">6.36252s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_seq_omp2.txt">4.62749s</a><br/>(1.375)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_seq_omp3.txt">3.97806s</a><br/>(1.599)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_seq_omp4.txt">4.25562s</a><br/>(1.495)</td>
  </tr>
  <tr>
    <th>Total</th>
    <td>open_seq_omp#</td>
    <td>10.1813s</td>
    <td>8.44883s</td>
    <td>7.78587s</td>
    <td>8.05917s</td>
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
    <td>10.4714s</td>
    <td>10.7625s</td>
    <td>10.4362s</td>
    <td>10.7432s</td>
  </tr>
  <tr>
    <th>Factorize</th>
    <td>open_seq_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_seq_omp1.txt">1m37.4251s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_seq_omp2.txt">1m0.324837s</a><br/>(1.615)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_seq_omp3.txt">47.8449s</a><br/>(2.036)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_seq_omp4.txt">49.1331s</a><br/>(1.983)</td>
  </tr>
  <tr>
    <th>Total</th>
    <td>open_seq_omp#</td>
    <td>1m50.5844s</td>
    <td>1m13.2857s</td>
    <td>1m0.388855s</td>
    <td>1m1.94887s</td>
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
    <td>5.16108s</td>
    <td>5.16252s</td>
    <td>5.15114s</td>
    <td>5.17366s</td>
  </tr>
  <tr>
    <th>Factorize</th>
    <td>open_seq_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_seq_omp1.txt">5.37544s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_seq_omp2.txt">3.64571s</a><br/>(1.474)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_seq_omp3.txt">3.12367s</a><br/>(1.721)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_seq_omp4.txt">2.95089s</a><br/>(1.822)</td>
  </tr>
  <tr>
    <th>Total</th>
    <td>open_seq_omp#</td>
    <td>11.3963s</td>
    <td>9.67999s</td>
    <td>9.16406s</td>
    <td>9.02354s</td>
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
    <td>3.95934s</td>
    <td>4.04847s</td>
    <td>4.02533s</td>
    <td>4.01646s</td>
  </tr>
  <tr>
    <th>Factorize</th>
    <td>open_seq_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_seq_omp1.txt">2.54191s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_seq_omp2.txt">2.37828s</a><br/>(1.069)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_seq_omp3.txt">2.31647s</a><br/>(1.097)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_seq_omp4.txt">2.38263s</a><br/>(1.067)</td>
  </tr>
  <tr>
    <th>Total</th>
    <td>open_seq_omp#</td>
    <td>7.99578s</td>
    <td>7.95623s</td>
    <td>7.87811s</td>
    <td>7.93864s</td>
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
    <td>463.178µs</td>
    <td>709.094µs</td>
    <td>732.382µs</td>
    <td>726.987µs</td>
  </tr>
  <tr>
    <th>Factorize</th>
    <td>open_seq_omp#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_seq_omp1.txt">376.599µs</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_seq_omp2.txt">8.76785ms</a>:worried:<br/>(0.043)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_seq_omp3.txt">28.5722ms</a>:worried:<br/>(0.013)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_seq_omp4.txt">9.00163ms</a>:worried:<br/>(0.042)</td>
  </tr>
  <tr>
    <th>Total</th>
    <td>open_seq_omp#</td>
    <td>1.08693ms</td>
    <td>9.8105ms</td>
    <td>29.6152ms</td>
    <td>11.0598ms</td>
  </tr>
</table>



