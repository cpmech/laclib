# Benchmarks using the code for sparse matrices

The code here tests the perfomance of the MUMPS Sparse Solver.

The **case** keywords in the tables have the following meanings:

- **mpi#** varying number of MPI procs; without OpenMP

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
    <td>open_mpi#</td>
    <td>3.45024s</td>
    <td>4.81873s</td>
    <td>4.84917s</td>
    <td>3.98114s</td>
  </tr>
  <tr>
    <th>Factorize</th>
    <td>open_mpi#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi1.txt">6.13648s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi2.txt">3.79339s</a><br/>(1.618)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi3.txt">2.95808s</a><br/>(2.074)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi4.txt">2.63815s</a><br/>(2.326)</td>
  </tr>
  <tr>
    <th>Total</th>
    <td>open_mpi#</td>
    <td>9.9356s</td>
    <td>8.85142s</td>
    <td>8.0272s</td>
    <td>6.80468s</td>
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
    <td>open_mpi#</td>
    <td>10.5068s</td>
    <td>14.9886s</td>
    <td>15.2054s</td>
    <td>11.4484s</td>
  </tr>
  <tr>
    <th>Factorize</th>
    <td>open_mpi#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi1.txt">1m37.76s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi2.txt">54.4157s</a><br/>(1.797)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi3.txt">41.9622s</a><br/>(2.330)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi4.txt">35.3765s</a><br/>(2.763)</td>
  </tr>
  <tr>
    <th>Total</th>
    <td>open_mpi#</td>
    <td>1m50.9532s</td>
    <td>1m10.9827s</td>
    <td>58.5448s</td>
    <td>48.0881s</td>
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
    <td>open_mpi#</td>
    <td>5.18899s</td>
    <td>5.71946s</td>
    <td>5.82549s</td>
    <td>4.20831s</td>
  </tr>
  <tr>
    <th>Factorize</th>
    <td>open_mpi#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi1.txt">4.91764s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi2.txt">22.9564s</a>:worried:<br/>(0.214)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi3.txt">22.4854s</a>:worried:<br/>(0.219)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi4.txt">2m16.8747s</a>:worried:<br/>(0.036)</td>
  </tr>
  <tr>
    <th>Total</th>
    <td>open_mpi#</td>
    <td>10.4153s</td>
    <td>29.0707s</td>
    <td>28.6719s</td>
    <td>2m21.5046s</td>
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
    <td>open_mpi#</td>
    <td>3.97998s</td>
    <td>3.05053s</td>
    <td>3.09479s</td>
    <td>2.01186s</td>
  </tr>
  <tr>
    <th>Factorize</th>
    <td>open_mpi#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi1.txt">1.76627s</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi2.txt">1.032s</a><br/>(1.712)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi3.txt">830.282ms</a><br/>(2.127)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi4.txt">720.785ms</a><br/>(2.450)</td>
  </tr>
  <tr>
    <th>Total</th>
    <td>open_mpi#</td>
    <td>6.16798s</td>
    <td>4.39151s</td>
    <td>4.20654s</td>
    <td>3.02747s</td>
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
    <td>open_mpi#</td>
    <td>1.66629ms</td>
    <td>8.2673ms</td>
    <td>5.41377ms</td>
    <td>6.06771ms</td>
  </tr>
  <tr>
    <th>Factorize</th>
    <td>open_mpi#<br/>(speedup)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi1.txt">1.28033ms</a><br/>(1)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi2.txt">1.6484ms</a><br/>(0.777)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi3.txt">926.544µs</a><br/>(1.382)</td>
    <td><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi4.txt">1.05918ms</a><br/>(1.209)</td>
  </tr>
  <tr>
    <th>Total</th>
    <td>open_mpi#</td>
    <td>3.19027ms</td>
    <td>10.1939ms</td>
    <td>6.24688ms</td>
    <td>6.87157ms</td>
  </tr>
</table>



