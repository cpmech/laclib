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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.32353s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.97966s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.90623s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.92506s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.46706s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.88146s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">12.2095s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.6268s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">580.473ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">393.598ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">826.162ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">941.092ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">13.3701s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.2544s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">17.9404s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">15.4919s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.73e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.71e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.59e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.58e-15</td>
  </tr>
</table>


Log files: [MPI-np1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_inline_1_metis_mpi1.txt), 
[MPI-np2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_inline_1_metis_mpi2.txt), 
[MPI-np3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_inline_1_metis_mpi3.txt), 
[MPI-np4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_inline_1_metis_mpi4.txt)

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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.36341s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.32619s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.37277s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.34766s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.53678s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.6085s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.06595s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.35595s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">380.55ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">364.093ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">361.871ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">394.11ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.2805s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.29855s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.80037s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.09746s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.64e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.73e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.03e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.63e-15</td>
  </tr>
</table>


Log files: [OMP-nt1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_inline_1_metis_omp1.txt), 
[OMP-nt2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_inline_1_metis_omp2.txt), 
[OMP-nt3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_inline_1_metis_omp3.txt), 
[OMP-nt4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_inline_1_metis_omp4.txt)


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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.2604s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">15.0531s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">15.1058s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.2828s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2m10.1793s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m10.7105s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m47.8073s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m56.9626s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.55013s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.09474s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.97835s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.23209s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2m23.9897s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m27.858s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2m6.89115s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2m12.4772s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.32e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.46e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.54e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.08e-16</td>
  </tr>
</table>


Log files: [MPI-np1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_Flan_1565_metis_mpi1.txt), 
[MPI-np2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_Flan_1565_metis_mpi2.txt), 
[MPI-np3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_Flan_1565_metis_mpi3.txt), 
[MPI-np4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_Flan_1565_metis_mpi4.txt)

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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.5802s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.0483s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.2172s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.5331s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m42.2192s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m0.0453414s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">47.6832s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">47.8214s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.87612s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.19242s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.21078s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.12207s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m55.6754s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m12.2859s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m0.110989s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m0.476257s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.71e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.32e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.10e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.48e-16</td>
  </tr>
</table>


Log files: [OMP-nt1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_Flan_1565_metis_omp1.txt), 
[OMP-nt2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_Flan_1565_metis_omp2.txt), 
[OMP-nt3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_Flan_1565_metis_omp3.txt), 
[OMP-nt4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_Flan_1565_metis_omp4.txt)


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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.16113s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.73524s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.77532s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.24709s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.34239s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">26.8421s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">56.4204s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3m51.1379s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">599.624ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">640.412ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.86862s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.24941s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">12.103s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">33.2175s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m4.06405s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3m59.6263s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.68e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.11e-14</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.03e-13</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.62e-11</td>
  </tr>
</table>


Log files: [MPI-np1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_pre2_metis_mpi1.txt), 
[MPI-np2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_pre2_metis_mpi2.txt), 
[MPI-np3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_pre2_metis_mpi3.txt), 
[MPI-np4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_pre2_metis_mpi4.txt)

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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.10259s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.28764s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.32071s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.0328s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.46246s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.87768s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.26438s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.98132s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">886.228ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">891.366ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">910.895ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">901.877ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.451s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.0564s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.49574s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.91576s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.68e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.68e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.02e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.52e-16</td>
  </tr>
</table>


Log files: [OMP-nt1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_pre2_metis_omp1.txt), 
[OMP-nt2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_pre2_metis_omp2.txt), 
[OMP-nt3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_pre2_metis_omp3.txt), 
[OMP-nt4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_pre2_metis_omp4.txt)


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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.91082s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.00606s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.03676s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.99243s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.11826s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.74073s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.72226s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.10618s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">732.349ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">530.649ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">534.122ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">636.194ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.76122s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.27715s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.29283s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.7345s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.73e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.91e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.09e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.91e-7</td>
  </tr>
</table>


Log files: [MPI-np1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_tmt_unsym_metis_mpi1.txt), 
[MPI-np2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_tmt_unsym_metis_mpi2.txt), 
[MPI-np3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_tmt_unsym_metis_mpi3.txt), 
[MPI-np4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_tmt_unsym_metis_mpi4.txt)

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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.11129s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.13131s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.0113s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.16609s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.03637s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.66514s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.40791s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.54435s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.62555s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.66196s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.62317s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.62405s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.77299s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.45817s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.04215s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.33426s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.21e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.73e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.91e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.21e-7</td>
  </tr>
</table>


Log files: [OMP-nt1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_tmt_unsym_metis_omp1.txt), 
[OMP-nt2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_tmt_unsym_metis_omp2.txt), 
[OMP-nt3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_tmt_unsym_metis_omp3.txt), 
[OMP-nt4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_tmt_unsym_metis_omp4.txt)


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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.74588ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.32125ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.77166ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.00618ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.29841ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.42466ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.68301ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.02728ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">824.39µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">926.289µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.12975ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">661.826µs</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.35807ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.94986ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.6946ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.51129ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.44e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.44e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.44e-16</td>
  </tr>
</table>


Log files: [MPI-np1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_bfwb62_metis_mpi1.txt), 
[MPI-np2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_bfwb62_metis_mpi2.txt), 
[MPI-np3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_bfwb62_metis_mpi3.txt), 
[MPI-np4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_bfwb62_metis_mpi4.txt)

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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.84588ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.81676ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">587.651µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.98696ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.61812ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.86769ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">640.493µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.65902ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.02714ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">950.4µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">380.934µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.50879ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.87429ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.01356ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.40495ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.49761ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
  </tr>
</table>


Log files: [OMP-nt1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_bfwb62_metis_omp1.txt), 
[OMP-nt2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_bfwb62_metis_omp2.txt), 
[OMP-nt3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_bfwb62_metis_omp3.txt), 
[OMP-nt4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/mumps_bfwb62_metis_omp4.txt)


