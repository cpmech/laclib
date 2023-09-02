# Benchmarks using the code for sparse matrices (Intel)

The code here tests the performance of the MUMPS Sparse Solver.

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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analyze</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.47452s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.75216s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.84196s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.97809s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.67728s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.52923s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.739s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.55059s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">211.88ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">183.492ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">165.233ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">145.55ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.3609s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.46179s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.72897s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.67092s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.67e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.19e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.84e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.49e-15</td>
  </tr>
</table>


Log files: [mpi1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_mpi1.txt), [mpi2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_mpi2.txt), [mpi3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_mpi3.txt), [mpi4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_mpi4.txt)

_OpenMP results with "metis" ordering:_

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">inline_1</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analyze</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.4235s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.40954s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.42198s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.41027s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.68874s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.91832s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.34294s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.02957s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">191.322ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">174.88ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">172.652ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">171.027ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.30027s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.49945s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.9341s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.60747s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.67e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.08e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.02e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.88e-15</td>
  </tr>
</table>


Log files: [omp1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_seq_omp1.txt), [omp2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_seq_omp2.txt), [omp3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_seq_omp3.txt), [omp4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_inline_1_metis_intel_seq_omp4.txt)


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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analyze</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.4706s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">14.7774s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">15.0129s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.2584s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m30.9377s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">51.4988s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">39.1596s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">34.4584s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.29658s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.03492s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">978.593ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">966.403ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m42.6981s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m7.26741s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">55.1435s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">46.6755s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.58e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.56e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.55e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.75e-15</td>
  </tr>
</table>


Log files: [mpi1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_mpi1.txt), [mpi2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_mpi2.txt), [mpi3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_mpi3.txt), [mpi4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_mpi4.txt)

_OpenMP results with "metis" ordering:_

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">Flan_1565</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analyze</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.3808s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.3738s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.3762s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.3777s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m30.7773s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">53.0423s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">40.2833s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">34.0186s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.27118s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.13197s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.10842s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.10123s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m42.4219s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m4.54069s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">51.7605s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">45.4902s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.58e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.70e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.52e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.54e-15</td>
  </tr>
</table>


Log files: [omp1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_seq_omp1.txt), [omp2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_seq_omp2.txt), [omp3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_seq_omp3.txt), [omp4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_Flan_1565_metis_intel_seq_omp4.txt)


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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analyze</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.19335s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.84912s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.92301s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.27752s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.18684s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">31.8467s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">26.9357s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m50.7227s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">641.791ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">759.845ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">472.974ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">445.232ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">12.0187s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">38.4368s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">33.3276s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m55.4409s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.87e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.46e-12</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.61e-12</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.11e-10</td>
  </tr>
</table>


Log files: [mpi1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_mpi1.txt), [mpi2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_mpi2.txt), [mpi3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_mpi3.txt), [mpi4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_mpi4.txt)

_OpenMP results with "metis" ordering:_

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">pre2</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analyze</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.1467s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.17294s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.15579s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.15162s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.99453s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.39196s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.90294s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.62193s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">249.003ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">244.099ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">245.391ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">247.739ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.3862s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.80507s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.30012s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.01736s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.87e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.10e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.03e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.07e-16</td>
  </tr>
</table>


Log files: [omp1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_seq_omp1.txt), [omp2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_seq_omp2.txt), [omp3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_seq_omp3.txt), [omp4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_pre2_metis_intel_seq_omp4.txt)


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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analyze</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.92812s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.08249s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.13813s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.06626s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.45923s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.24104s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.6458s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.3016s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.13734s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.09567s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">818.971ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">835.588ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.52037s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.41426s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.59761s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.19793s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.43e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.31e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.31e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.31e-7</td>
  </tr>
</table>


Log files: [mpi1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_mpi1.txt), [mpi2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_mpi2.txt), [mpi3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_mpi3.txt), [mpi4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_mpi4.txt)

_OpenMP results with "metis" ordering:_

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">tmt_unsym</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analyze</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.92365s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.92163s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.95337s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.92853s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.07689s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.96206s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.90929s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.90546s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">374.934ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">383.105ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">389.589ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">393.051ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.37048s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.2618s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.24711s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.22207s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.43e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.37e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.37e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.61e-7</td>
  </tr>
</table>


Log files: [omp1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_seq_omp1.txt), [omp2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_seq_omp2.txt), [omp3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_seq_omp3.txt), [omp4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_tmt_unsym_metis_intel_seq_omp4.txt)


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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analyze</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.23238ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.30394ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">14.0877ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">19.079ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.48603ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.62667ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.69428ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">23.6338ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">517.196µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">874.599µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">988.607µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.76049ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.5367ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.11955ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">13.1135ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">39.3206ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.55e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.55e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.55e-16</td>
  </tr>
</table>


Log files: [mpi1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_mpi1.txt), [mpi2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_mpi2.txt), [mpi3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_mpi3.txt), [mpi4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_mpi4.txt)

_OpenMP results with "metis" ordering:_

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">bfwb62</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analyze</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.26055ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.37454ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.10867ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.7606ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">22.5825ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.8315ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.69297ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.9224ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">756.743µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">916.4µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">894.864µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">527.42µs</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">24.2767ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.68645ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.59073ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">13.0515ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
  </tr>
</table>


Log files: [omp1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_seq_omp1.txt), [omp2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_seq_omp2.txt), [omp3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_seq_omp3.txt), [omp4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/intel/mumps_bfwb62_metis_intel_seq_omp4.txt)


