# Benchmarks using the code for sparse matrices

The code here tests the perfomance of the MUMPS Sparse Solver.

## GHS_psdef / inline_1 matrix

Reference: https://sparse.tamu.edu/GHS_psdef/inline_1

* Symmetric matrix
* Dimension = 503,712
* Number of non-zero values = 18,660,027
* L-infinity norm of the matrix = 1.146e+8

_results with "metis" ordering:_

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">inline_1</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">case</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Analyze</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_seq_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.43877s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.45666s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.44702s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.43961s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_seq_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.4235s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.40954s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.42198s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.41027s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.43497s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.45678s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.47627s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.50701s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.49923s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.50413s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.48573s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.48659s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.45024s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.81873s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.84917s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.98114s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.47452s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.75216s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.84196s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.97809s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.43497s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.83077s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.916s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.97353s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.49923s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.75398s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.85331s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.97897s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.43497s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.45678s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.83077s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.83301s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.49923s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.50413s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.75398s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.77035s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_seq_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_seq_omp1.txt">6.36252s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_seq_omp2.txt">4.62749s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_seq_omp3.txt">3.97806s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_seq_omp4.txt">4.25562s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_seq_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_seq_omp1.txt">5.68874s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_seq_omp2.txt">3.91832s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_seq_omp3.txt">3.34294s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_seq_omp4.txt">3.02957s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi1_omp1.txt">6.4647s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi1_omp2.txt">18.3009s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi1_omp3.txt">16.6833s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi1_omp4.txt">19.058s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi1_omp1.txt">5.7887s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi1_omp2.txt">4.02575s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi1_omp3.txt">3.42749s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi1_omp4.txt">3.12079s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi1.txt">6.13648s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi2.txt">3.79339s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi3.txt">2.95808s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi4.txt">2.63815s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi1.txt">5.67728s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi2.txt">3.52923s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi3.txt">2.739s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi4.txt">2.55059s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi1_omp1.txt">6.4647s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi2_omp1.txt">3.99489s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi3_omp1.txt">3.06911s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi4_omp1.txt">2.77405s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi1_omp1.txt">5.7887s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi2_omp1.txt">3.59257s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi3_omp1.txt">2.78585s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi4_omp1.txt">2.57212s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi1_omp1.txt">6.4647s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi1_omp2.txt">18.3009s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi2_omp1.txt">3.99489s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi2_omp2.txt">11.2702s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi1_omp1.txt">5.7887s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi1_omp2.txt">4.02575s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi2_omp1.txt">3.59257s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi2_omp2.txt">2.73908s</a></td>
  </tr>
</table>



## Janna / Flan_1565 matrix

Reference: https://sparse.tamu.edu/Janna/Flan_1565

* Symmetric matrix
* Dimension = 1,564,794
* Number of non-zero values = 59,485,419
* L-infinity norm of the matrix = 1.529e+7

_results with "metis" ordering:_

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">Flan_1565</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">case</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Analyze</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_seq_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.4714s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.7625s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.4362s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.7432s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_seq_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.3808s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.3738s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.3762s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.3777s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.4693s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.4779s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.4794s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.4995s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.5105s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.5257s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.5019s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.5067s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.5068s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">14.9886s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">15.2054s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.4484s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.4706s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">14.7774s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">15.0129s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.2584s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.4693s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">15.0778s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">15.3213s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.4301s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.5105s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">14.777s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">15.0228s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.2734s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.4693s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.4779s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">15.0778s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">15.0726s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.5105s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.5257s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">14.777s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">14.7902s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_seq_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_seq_omp1.txt">1m37.4251s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_seq_omp2.txt">1m0.324837s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_seq_omp3.txt">47.8449s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_seq_omp4.txt">49.1331s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_seq_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_seq_omp1.txt">1m30.7773s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_seq_omp2.txt">53.0423s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_seq_omp3.txt">40.2833s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_seq_omp4.txt">34.0186s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi1_omp1.txt">1m38.6689s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi1_omp2.txt">4m1.1184s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi1_omp3.txt">3m7.80238s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi1_omp4.txt">2m52.3749s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi1_omp1.txt">1m30.6453s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi1_omp2.txt">53.6015s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi1_omp3.txt">40.3981s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi1_omp4.txt">34.3459s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi1.txt">1m37.76s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi2.txt">54.4157s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi3.txt">41.9622s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi4.txt">35.3765s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi1.txt">1m30.9377s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi2.txt">51.4988s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi3.txt">39.1596s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi4.txt">34.4584s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi1_omp1.txt">1m38.6689s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi2_omp1.txt">55.0578s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi3_omp1.txt">41.3877s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi4_omp1.txt">35.3778s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi1_omp1.txt">1m30.6453s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi2_omp1.txt">51.307s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi3_omp1.txt">39.1394s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi4_omp1.txt">34.1555s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi1_omp1.txt">1m38.6689s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi1_omp2.txt">4m1.1184s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi2_omp1.txt">55.0578s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi2_omp2.txt">2m5.67456s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi1_omp1.txt">1m30.6453s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi1_omp2.txt">53.6015s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi2_omp1.txt">51.307s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi2_omp2.txt">32.9528s</a></td>
  </tr>
</table>



## ATandT / pre2 matrix

Reference: https://sparse.tamu.edu/ATandT/pre2

* General matrix (unsymmetric)
* Dimension = 659,033
* Number of non-zero values = 5,959,282
* L-infinity norm of the matrix = 1.478e+10

_results with "metis" ordering:_

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">pre2</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">case</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Analyze</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_seq_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.16108s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.16252s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.15114s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.17366s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_seq_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.1467s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.17294s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.15579s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.15162s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.28481s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.31992s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.20533s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.21709s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.20867s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.21626s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.2164s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.21278s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.18899s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.71946s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.82549s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.20831s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.19335s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.84912s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.92301s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.27752s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.28481s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.96467s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.94145s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.28749s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.20867s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.83506s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.95504s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.28104s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.28481s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.31992s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.96467s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.05336s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.20867s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.21626s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.83506s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.85903s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_seq_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_seq_omp1.txt">5.37544s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_seq_omp2.txt">3.64571s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_seq_omp3.txt">3.12367s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_seq_omp4.txt">2.95089s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_seq_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_seq_omp1.txt">4.99453s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_seq_omp2.txt">3.39196s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_seq_omp3.txt">2.90294s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_seq_omp4.txt">2.62193s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi1_omp1.txt">5.49944s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi1_omp2.txt">13.8721s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi1_omp3.txt">9.49158s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi1_omp4.txt">9.22161s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi1_omp1.txt">6.37469s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi1_omp2.txt">4.88673s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi1_omp3.txt">4.42781s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi1_omp4.txt">4.12234s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi1.txt">4.91764s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi2.txt">22.9564s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi3.txt">22.4854s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi4.txt">2m16.8747s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi1.txt">6.18684s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi2.txt">31.8467s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi3.txt">26.9357s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi4.txt">1m50.7227s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi1_omp1.txt">5.49944s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi2_omp1.txt">23.8411s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi3_omp1.txt">22.5868s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi4_omp1.txt">2m16.6926s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi1_omp1.txt">6.37469s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi2_omp1.txt">31.9531s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi3_omp1.txt">26.953s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi4_omp1.txt">1m50.6222s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi1_omp1.txt">5.49944s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi1_omp2.txt">13.8721s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi2_omp1.txt">23.8411s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi2_omp2.txt">42.3962s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi1_omp1.txt">6.37469s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi1_omp2.txt">4.88673s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi2_omp1.txt">31.9531s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi2_omp2.txt">23.9735s</a></td>
  </tr>
</table>



## CEMW / tmt_unsym matrix

Reference: https://sparse.tamu.edu/CEMW/tmt_unsym

* General matrix (unsymmetric)
* Dimension = 917,825
* Number of non-zero values = 4,584,801
* L-infinity norm of the matrix = 4.000e+0

_results with "metis" ordering:_

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">tmt_unsym</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">case</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Analyze</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_seq_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.95934s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.04847s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.02533s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.01646s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_seq_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.92365s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.92163s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.95337s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.92853s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.10631s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.20557s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.04296s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.07705s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.93193s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.93328s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.94777s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.94314s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.97998s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.05053s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.09479s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.01186s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.92812s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.08249s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.13813s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.06626s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.10631s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.15589s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.121s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.33191s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.93193s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.08121s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.19899s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.09254s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.10631s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.20557s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.15589s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.19529s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.93193s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.93328s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.08121s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.11612s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_seq_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_seq_omp1.txt">2.54191s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_seq_omp2.txt">2.37828s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_seq_omp3.txt">2.31647s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_seq_omp4.txt">2.38263s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_seq_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_seq_omp1.txt">2.07689s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_seq_omp2.txt">1.96206s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_seq_omp3.txt">1.90929s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_seq_omp4.txt">1.90546s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi1_omp1.txt">2.80763s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi1_omp2.txt">11.4492s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi1_omp3.txt">5.44067s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi1_omp4.txt">7.76523s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi1_omp1.txt">4.74725s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi1_omp2.txt">4.81892s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi1_omp3.txt">4.76848s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi1_omp4.txt">4.7263s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi1.txt">1.76627s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi2.txt">1.032s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi3.txt">830.282ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi4.txt">720.785ms</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi1.txt">4.45923s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi2.txt">2.24104s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi3.txt">1.6458s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi4.txt">1.3016s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi1_omp1.txt">2.80763s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi2_omp1.txt">1.59082s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi3_omp1.txt">1.20099s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi4_omp1.txt">970.823ms</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi1_omp1.txt">4.74725s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi2_omp1.txt">2.37848s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi3_omp1.txt">1.77018s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi4_omp1.txt">1.39746s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi1_omp1.txt">2.80763s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi1_omp2.txt">11.4492s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi2_omp1.txt">1.59082s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi2_omp2.txt">6.29106s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi1_omp1.txt">4.74725s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi1_omp2.txt">4.81892s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi2_omp1.txt">2.37848s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi2_omp2.txt">2.42056s</a></td>
  </tr>
</table>



## Bai / bfwb62 matrix

Reference: https://sparse.tamu.edu/Bai/bfwb62

* Symmetric matrix
* Dimension = 62
* Number of non-zero values = 202
* L-infinity norm of the matrix = 1.000e-4

_results with "metis" ordering:_

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">bfwb62</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">case</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">NP or NT 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Analyze</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_seq_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">463.178µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">709.094µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">732.382µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">726.987µs</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_seq_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.26055ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.37454ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.10867ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.7606ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.7058ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.80039ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.37454ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.98261ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.92038ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.21484ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.29034ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.64976ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.66629ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.2673ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.41377ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.06771ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.23238ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.30394ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">14.0877ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">19.079ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.7058ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.60622ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.66633ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.14488ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.92038ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.2438ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.49033ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.49058ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.7058ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.80039ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.60622ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.50725ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.92038ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.21484ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.2438ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.5611ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_seq_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_seq_omp1.txt">376.599µs</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_seq_omp2.txt">8.76785ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_seq_omp3.txt">28.5722ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_seq_omp4.txt">9.00163ms</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_seq_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_seq_omp1.txt">22.5825ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_seq_omp2.txt">4.8315ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_seq_omp3.txt">4.69297ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_seq_omp4.txt">11.9224ms</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi1_omp1.txt">1.64748ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi1_omp2.txt">2.08928ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi1_omp3.txt">1.20363ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi1_omp4.txt">6.424ms</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi1_omp1.txt">10.297ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi1_omp2.txt">6.58081ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi1_omp3.txt">8.18585ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi1_omp4.txt">14.3465ms</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi1.txt">1.28033ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi2.txt">1.6484ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi3.txt">926.544µs</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi4.txt">1.05918ms</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi1.txt">7.48603ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi2.txt">3.62667ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi3.txt">3.69428ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi4.txt">23.6338ms</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi1_omp1.txt">1.64748ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi2_omp1.txt">656.11µs</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi3_omp1.txt">1.33194ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi4_omp1.txt">998.586µs</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi1_omp1.txt">10.297ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi2_omp1.txt">4.06645ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi3_omp1.txt">3.24646ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi4_omp1.txt">3.20821ms</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi1_omp1.txt">1.64748ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi1_omp2.txt">2.08928ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi2_omp1.txt">656.11µs</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi2_omp2.txt">506.321µs</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi1_omp1.txt">10.297ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi1_omp2.txt">6.58081ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi2_omp1.txt">4.06645ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi2_omp2.txt">3.36536ms</a></td>
  </tr>
</table>



