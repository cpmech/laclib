# Benchmarks using the code for sparse matrices

The code here tests the perfomance of the MUMPS Sparse Solver.

## inline_1 matrix

Reference: https://sparse.tamu.edu/GHS_psdef/inline_1

* Symmetric matrix
* Dimension = 503,712
* Number of non-zero values = 18,660,027
* L-infinity norm of the matrix = 1.146e+8

_MPI results with "metis" ordering:_

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">inline_1</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analysis</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.45024s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.81873s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.84917s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.98114s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.13648s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.79339s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.95808s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.63815s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">351.158ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">241.715ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">222.393ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">187.941ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.9356s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.85142s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.0272s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.80468s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.64e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.78e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.03e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.11e-15</td>
  </tr>
</table>


Log files: [mpi1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi1.txt), [mpi2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi2.txt), [mpi3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi3.txt), [mpi4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_mpi4.txt)

_OpenMP results with "metis" ordering:_

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">inline_1</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analysis</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.43877s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.45666s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.44702s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.43961s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.36252s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.62749s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.97806s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.25562s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">382.338ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">366.95ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">363.001ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">366.241ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.1813s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.44883s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.78587s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.05917s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.64e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.73e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.03e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.63e-15</td>
  </tr>
</table>


Log files: [omp1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_seq_omp1.txt), [omp2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_seq_omp2.txt), [omp3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_seq_omp3.txt), [omp4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_inline_1_metis_open_seq_omp4.txt)


## Flan_1565 matrix

Reference: https://sparse.tamu.edu/Janna/Flan_1565

* Symmetric matrix
* Dimension = 1,564,794
* Number of non-zero values = 59,485,419
* L-infinity norm of the matrix = 1.529e+7

_MPI results with "metis" ordering:_

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">Flan_1565</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analysis</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.5068s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">14.9886s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">15.2054s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.4484s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m37.76s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">54.4157s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">41.9622s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">35.3765s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.69291s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.60805s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.38408s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.27821s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m50.9532s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m10.9827s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">58.5448s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">48.0881s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.71e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.58e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.21e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.65e-16</td>
  </tr>
</table>


Log files: [mpi1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi1.txt), [mpi2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi2.txt), [mpi3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi3.txt), [mpi4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_mpi4.txt)

_OpenMP results with "metis" ordering:_

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">Flan_1565</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analysis</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.4714s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.7625s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.4362s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.7432s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m37.4251s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m0.324837s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">47.8449s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">49.1331s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.69422s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.20496s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.11424s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.07895s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m50.5844s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m13.2857s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m0.388855s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m1.94887s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.71e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.32e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.10e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.48e-16</td>
  </tr>
</table>


Log files: [omp1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_seq_omp1.txt), [omp2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_seq_omp2.txt), [omp3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_seq_omp3.txt), [omp4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_Flan_1565_metis_open_seq_omp4.txt)


## pre2 matrix

Reference: https://sparse.tamu.edu/ATandT/pre2

* General matrix (unsymmetric)
* Dimension = 659,033
* Number of non-zero values = 5,959,282
* L-infinity norm of the matrix = 1.478e+10

_MPI results with "metis" ordering:_

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">pre2</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analysis</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.18899s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.71946s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.82549s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.20831s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.91764s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">22.9564s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">22.4854s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2m16.8747s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">311.597ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">397.929ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">364.367ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">428.075ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.4153s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">29.0707s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">28.6719s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2m21.5046s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.68e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.61e-14</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.83e-14</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.96e-11</td>
  </tr>
</table>


Log files: [mpi1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi1.txt), [mpi2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi2.txt), [mpi3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi3.txt), [mpi4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_mpi4.txt)

_OpenMP results with "metis" ordering:_

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">pre2</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analysis</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.16108s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.16252s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.15114s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.17366s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.37544s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.64571s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.12367s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.95089s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">862.703ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">874.656ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">892.098ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">901.935ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.3963s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.67999s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.16406s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.02354s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.68e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.68e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.02e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.52e-16</td>
  </tr>
</table>


Log files: [omp1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_seq_omp1.txt), [omp2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_seq_omp2.txt), [omp3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_seq_omp3.txt), [omp4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_pre2_metis_open_seq_omp4.txt)


## tmt_unsym matrix

Reference: https://sparse.tamu.edu/CEMW/tmt_unsym

* General matrix (unsymmetric)
* Dimension = 917,825
* Number of non-zero values = 4,584,801
* L-infinity norm of the matrix = 4.000e+0

_MPI results with "metis" ordering:_

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">tmt_unsym</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analysis</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.97998s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.05053s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.09479s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.01186s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.76627s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.032s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">830.282ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">720.785ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">425.746ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">313.424ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">285.904ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">299.337ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.16798s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.39151s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.20654s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.02747s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.21e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.85e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.09e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.79e-7</td>
  </tr>
</table>


Log files: [mpi1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi1.txt), [mpi2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi2.txt), [mpi3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi3.txt), [mpi4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_mpi4.txt)

_OpenMP results with "metis" ordering:_

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">tmt_unsym</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analysis</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.95934s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.04847s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.02533s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.01646s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.54191s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.37828s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.31647s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.38263s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.49853s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.53421s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.54051s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.54422s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.99578s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.95623s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.87811s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.93864s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.21e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.73e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.91e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.21e-7</td>
  </tr>
</table>


Log files: [omp1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_seq_omp1.txt), [omp2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_seq_omp2.txt), [omp3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_seq_omp3.txt), [omp4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_tmt_unsym_metis_open_seq_omp4.txt)


## bfwb62 matrix

Reference: https://sparse.tamu.edu/Bai/bfwb62

* Symmetric matrix
* Dimension = 62
* Number of non-zero values = 202
* L-infinity norm of the matrix = 1.000e-4

_MPI results with "metis" ordering:_

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">bfwb62</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analysis</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.66629ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.2673ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.41377ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.06771ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.28033ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.6484ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">926.544µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.05918ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">723.914µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.09976ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">610.829µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">719.884µs</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.19027ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.1939ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.24688ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.87157ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.44e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.44e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.44e-16</td>
  </tr>
</table>


Log files: [mpi1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi1.txt), [mpi2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi2.txt), [mpi3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi3.txt), [mpi4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_mpi4.txt)

_OpenMP results with "metis" ordering:_

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">bfwb62</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analysis</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">463.178µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">709.094µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">732.382µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">726.987µs</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">376.599µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.76785ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">28.5722ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.00163ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">392.563µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">537.068µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">522.288µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.53828ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.08693ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.8105ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">29.6152ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.0598ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
  </tr>
</table>


Log files: [omp1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_seq_omp1.txt), [omp2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_seq_omp2.txt), [omp3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_seq_omp3.txt), [omp4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/open/mumps_bfwb62_metis_open_seq_omp4.txt)


