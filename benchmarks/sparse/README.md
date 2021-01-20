# Benchmarks using the code for sparse matrices

The code here tests the perfomance of the MUMPS Sparse Solver.

## inline_1 matrix

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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_seq_omp1.txt">3.43877s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_seq_omp2.txt">3.45666s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_seq_omp3.txt">3.44702s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_seq_omp4.txt">3.43961s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi1_omp1.txt">3.43497s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi1_omp2.txt">3.45678s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi1_omp3.txt">3.47627s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi1_omp4.txt">3.50701s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi1.txt">3.45024s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi2.txt">4.81873s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi3.txt">4.84917s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi4.txt">3.98114s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi1_omp1.txt">3.43497s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi2_omp1.txt">4.83077s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi3_omp1.txt">4.916s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi4_omp1.txt">3.97353s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi1_omp1.txt">3.43497s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi1_omp2.txt">3.45678s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi2_omp1.txt">4.83077s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_inline_1_metis_open_mpi2_omp2.txt">4.83301s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_seq_omp1.txt">3.4235s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_seq_omp2.txt">3.40954s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_seq_omp3.txt">3.42198s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_seq_omp4.txt">3.41027s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi1_omp1.txt">3.49923s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi1_omp2.txt">3.50413s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi1_omp3.txt">3.48573s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi1_omp4.txt">3.48659s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi1.txt">3.47452s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi2.txt">4.75216s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi3.txt">4.84196s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi4.txt">3.97809s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi1_omp1.txt">3.49923s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi2_omp1.txt">4.75398s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi3_omp1.txt">4.85331s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi4_omp1.txt">3.97897s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi1_omp1.txt">3.49923s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi1_omp2.txt">3.50413s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi2_omp1.txt">4.75398s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_inline_1_metis_intel_mpi2_omp2.txt">4.77035s</a></td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.36252s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.62749s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.97806s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.25562s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.4647s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">18.3009s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">16.6833s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">19.058s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.13648s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.79339s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.95808s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.63815s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.4647s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.99489s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.06911s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.77405s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.4647s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">18.3009s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.99489s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.2702s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.68874s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.91832s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.34294s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.02957s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.7887s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.02575s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.42749s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.12079s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.67728s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.52923s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.739s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.55059s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.7887s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.59257s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.78585s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.57212s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.7887s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.02575s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.59257s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.73908s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">382.338ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">366.95ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">363.001ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">366.241ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">386.84ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.06131s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">764.809ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.10419s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">351.158ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">241.715ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">222.393ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">187.941ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">386.84ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">260.703ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">236.088ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">198.199ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">386.84ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.06131s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">260.703ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">813.775ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">191.322ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">174.88ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">172.652ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">171.027ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">216.037ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">201.674ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">198.76ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">198.495ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">211.88ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">183.492ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">165.233ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">145.55ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">216.037ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">178.047ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">167.505ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">146.865ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">216.037ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">201.674ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">178.047ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">173.249ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.1813s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.44883s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.78587s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.05917s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.2843s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">22.8167s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">20.9203s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">23.6651s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.9356s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.85142s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.0272s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.80468s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.2843s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.08393s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.21871s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.94317s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.2843s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">22.8167s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.08393s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">16.9145s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.30027s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.49945s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.9341s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.60747s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.50055s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.72798s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.10863s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.8025s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.3609s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.46179s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.72897s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.67092s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.50055s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.52118s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.8029s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.69441s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.50055s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.72798s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.52118s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.66321s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.64e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.73e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.03e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.63e-15</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.64e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.73e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.03e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.63e-15</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.64e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.78e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.03e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.11e-15</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.64e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.78e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.18e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.90e-15</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.64e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.73e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.78e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.71e-15</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.67e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.08e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.02e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.88e-15</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.67e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.08e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.02e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.88e-15</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.67e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.19e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.84e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.49e-15</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.67e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.19e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.84e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.36e-15</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.67e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.08e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.19e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.05e-15</td>
  </tr>
</table>



## Flan_1565 matrix

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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_seq_omp1.txt">10.4714s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_seq_omp2.txt">10.7625s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_seq_omp3.txt">10.4362s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_seq_omp4.txt">10.7432s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi1_omp1.txt">10.4693s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi1_omp2.txt">10.4779s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi1_omp3.txt">10.4794s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi1_omp4.txt">10.4995s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi1.txt">10.5068s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi2.txt">14.9886s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi3.txt">15.2054s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi4.txt">11.4484s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi1_omp1.txt">10.4693s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi2_omp1.txt">15.0778s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi3_omp1.txt">15.3213s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi4_omp1.txt">11.4301s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi1_omp1.txt">10.4693s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi1_omp2.txt">10.4779s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi2_omp1.txt">15.0778s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_Flan_1565_metis_open_mpi2_omp2.txt">15.0726s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_seq_omp1.txt">10.3808s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_seq_omp2.txt">10.3738s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_seq_omp3.txt">10.3762s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_seq_omp4.txt">10.3777s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi1_omp1.txt">10.5105s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi1_omp2.txt">10.5257s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi1_omp3.txt">10.5019s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi1_omp4.txt">10.5067s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi1.txt">10.4706s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi2.txt">14.7774s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi3.txt">15.0129s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi4.txt">11.2584s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi1_omp1.txt">10.5105s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi2_omp1.txt">14.777s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi3_omp1.txt">15.0228s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi4_omp1.txt">11.2734s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi1_omp1.txt">10.5105s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi1_omp2.txt">10.5257s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi2_omp1.txt">14.777s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_Flan_1565_metis_intel_mpi2_omp2.txt">14.7902s</a></td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m37.4251s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m0.324837s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">47.8449s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">49.1331s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m38.6689s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4m1.1184s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3m7.80238s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2m52.3749s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m37.76s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">54.4157s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">41.9622s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">35.3765s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m38.6689s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">55.0578s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">41.3877s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">35.3778s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m38.6689s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4m1.1184s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">55.0578s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2m5.67456s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m30.7773s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">53.0423s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">40.2833s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">34.0186s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m30.6453s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">53.6015s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">40.3981s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">34.3459s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m30.9377s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">51.4988s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">39.1596s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">34.4584s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m30.6453s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">51.307s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">39.1394s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">34.1555s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m30.6453s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">53.6015s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">51.307s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">32.9528s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.69422s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.20496s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.11424s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.07895s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.76184s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.78874s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.86233s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.51989s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.69291s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.60805s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.38408s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.27821s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.76184s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.64924s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.40045s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.27922s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.76184s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.78874s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.64924s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.55148s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.27118s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.13197s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.10842s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.10123s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.32072s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.17772s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.15945s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.15543s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.29658s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.03492s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">978.593ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">966.403ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.32072s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.04263s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">982.91ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">964.873ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.32072s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.17772s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.04263s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.00411s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m50.5844s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m13.2857s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m0.388855s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m1.94887s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m51.8934s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4m18.3786s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3m23.1329s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3m8.38329s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m50.9532s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m10.9827s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">58.5448s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">48.0881s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m51.8934s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m11.778s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">58.1024s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">48.0729s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m51.8934s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4m18.3786s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m11.778s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2m25.2918s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m42.4219s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m4.54069s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">51.7605s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">45.4902s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m42.4673s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m5.29756s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">52.0521s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">46.0005s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m42.6981s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m7.26741s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">55.1435s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">46.6755s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m42.4673s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m7.11907s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">55.1373s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">46.386s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m42.4673s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m5.29756s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m7.11907s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">48.7389s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.71e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.32e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.10e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.48e-16</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.71e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.32e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.10e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.48e-16</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.71e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.58e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.21e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.65e-16</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.71e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.58e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.92e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.65e-16</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.71e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.32e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.58e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.46e-16</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.58e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.70e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.52e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.54e-15</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.58e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.70e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.52e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.54e-15</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.58e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.56e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.55e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.75e-15</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.58e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.56e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.55e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.75e-15</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.58e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.70e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.56e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.24e-15</td>
  </tr>
</table>



## pre2 matrix

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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_seq_omp1.txt">5.16108s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_seq_omp2.txt">5.16252s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_seq_omp3.txt">5.15114s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_seq_omp4.txt">5.17366s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi1_omp1.txt">5.28481s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi1_omp2.txt">5.31992s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi1_omp3.txt">5.20533s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi1_omp4.txt">5.21709s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi1.txt">5.18899s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi2.txt">5.71946s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi3.txt">5.82549s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi4.txt">4.20831s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi1_omp1.txt">5.28481s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi2_omp1.txt">5.96467s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi3_omp1.txt">5.94145s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi4_omp1.txt">4.28749s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi1_omp1.txt">5.28481s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi1_omp2.txt">5.31992s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi2_omp1.txt">5.96467s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_pre2_metis_open_mpi2_omp2.txt">6.05336s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_seq_omp1.txt">5.1467s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_seq_omp2.txt">5.17294s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_seq_omp3.txt">5.15579s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_seq_omp4.txt">5.15162s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi1_omp1.txt">5.20867s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi1_omp2.txt">5.21626s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi1_omp3.txt">5.2164s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi1_omp4.txt">5.21278s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi1.txt">5.19335s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi2.txt">5.84912s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi3.txt">5.92301s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi4.txt">4.27752s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi1_omp1.txt">5.20867s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi2_omp1.txt">5.83506s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi3_omp1.txt">5.95504s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi4_omp1.txt">4.28104s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi1_omp1.txt">5.20867s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi1_omp2.txt">5.21626s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi2_omp1.txt">5.83506s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_pre2_metis_intel_mpi2_omp2.txt">5.85903s</a></td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.37544s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.64571s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.12367s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.95089s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.49944s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">13.8721s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.49158s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.22161s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.91764s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">22.9564s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">22.4854s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2m16.8747s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.49944s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">23.8411s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">22.5868s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2m16.6926s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.49944s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">13.8721s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">23.8411s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">42.3962s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.99453s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.39196s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.90294s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.62193s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.37469s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.88673s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.42781s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.12234s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.18684s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">31.8467s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">26.9357s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m50.7227s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.37469s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">31.9531s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">26.953s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m50.6222s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.37469s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.88673s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">31.9531s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">23.9735s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">862.703ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">874.656ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">892.098ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">901.935ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">901.871ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.80291s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.4447s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.91478s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">311.597ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">397.929ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">364.367ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">428.075ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">901.871ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">589.256ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">527.875ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">532.304ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">901.871ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.80291s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">589.256ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.37082s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">249.003ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">244.099ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">245.391ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">247.739ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">676.096ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">697.602ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">711.092ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">718.853ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">641.791ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">759.845ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">472.974ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">445.232ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">676.096ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">786.472ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">487.069ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">457.621ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">676.096ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">697.602ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">786.472ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">803.996ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.3963s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.67999s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.16406s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.02354s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.6831s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">20.992s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">16.1362s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">16.348s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.4153s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">29.0707s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">28.6719s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2m21.5046s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.6831s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">30.3918s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">29.0506s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2m21.5091s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.6831s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">20.992s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">30.3918s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">49.8172s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.3862s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.80507s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.30012s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.01736s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">12.2554s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.7966s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.3513s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.05s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">12.0187s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">38.4368s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">33.3276s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m55.4409s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">12.2554s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">38.5705s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">33.3905s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m55.356s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">12.2554s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.7966s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">38.5705s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">30.6089s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.68e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.68e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.02e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.52e-16</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.68e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.68e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.02e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.52e-16</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.68e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.61e-14</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.83e-14</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.96e-11</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.68e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.61e-14</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.83e-14</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.16e-11</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.68e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.68e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.61e-14</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.62e-14</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.87e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.10e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.03e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.07e-16</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.87e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.10e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.03e-15</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.07e-16</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.87e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.46e-12</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.61e-12</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.11e-10</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.87e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.46e-12</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.61e-12</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.11e-10</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.87e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.10e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.46e-12</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.82e-13</td>
  </tr>
</table>



## tmt_unsym matrix

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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_seq_omp1.txt">3.95934s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_seq_omp2.txt">4.04847s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_seq_omp3.txt">4.02533s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_seq_omp4.txt">4.01646s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi1_omp1.txt">4.10631s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi1_omp2.txt">4.20557s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi1_omp3.txt">4.04296s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi1_omp4.txt">4.07705s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi1.txt">3.97998s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi2.txt">3.05053s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi3.txt">3.09479s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi4.txt">2.01186s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi1_omp1.txt">4.10631s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi2_omp1.txt">3.15589s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi3_omp1.txt">3.121s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi4_omp1.txt">2.33191s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi1_omp1.txt">4.10631s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi1_omp2.txt">4.20557s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi2_omp1.txt">3.15589s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_tmt_unsym_metis_open_mpi2_omp2.txt">3.19529s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_seq_omp1.txt">3.92365s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_seq_omp2.txt">3.92163s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_seq_omp3.txt">3.95337s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_seq_omp4.txt">3.92853s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi1_omp1.txt">3.93193s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi1_omp2.txt">3.93328s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi1_omp3.txt">3.94777s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi1_omp4.txt">3.94314s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi1.txt">3.92812s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi2.txt">3.08249s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi3.txt">3.13813s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi4.txt">2.06626s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi1_omp1.txt">3.93193s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi2_omp1.txt">3.08121s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi3_omp1.txt">3.19899s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi4_omp1.txt">2.09254s</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi1_omp1.txt">3.93193s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi1_omp2.txt">3.93328s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi2_omp1.txt">3.08121s</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_tmt_unsym_metis_intel_mpi2_omp2.txt">3.11612s</a></td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.54191s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.37828s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.31647s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.38263s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.80763s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.4492s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.44067s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.76523s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.76627s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.032s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">830.282ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">720.785ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.80763s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.59082s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.20099s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">970.823ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.80763s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.4492s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.59082s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.29106s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.07689s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.96206s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.90929s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.90546s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.74725s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.81892s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.76848s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.7263s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.45923s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.24104s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.6458s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.3016s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.74725s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.37848s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.77018s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.39746s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.74725s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.81892s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.37848s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.42056s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.49853s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.53421s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.54051s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.54422s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.53193s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.90795s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.74447s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.80844s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">425.746ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">313.424ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">285.904ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">299.337ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.53193s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">905.881ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">733.704ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">666.05ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.53193s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.90795s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">905.881ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.12208s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">374.934ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">383.105ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">389.589ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">393.051ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.21025s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.26756s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.28894s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.30007s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.13734s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.09567s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">818.971ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">835.588ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.21025s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.14202s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">854.596ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">866.488ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.21025s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.26756s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.14202s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.18602s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.99578s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.95623s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.87811s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.93864s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.44191s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">17.5585s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.2207s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">13.6432s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.16798s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.39151s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.20654s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.02747s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.44191s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.64828s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.05061s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.64102s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.44191s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">17.5585s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.64828s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.5946s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.37048s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.2618s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.24711s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.22207s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.88442s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.0148s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.0001s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.96442s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.52037s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.41426s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.59761s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.19793s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.88442s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.59611s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.79632s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.33405s</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.88442s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.0148s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.59611s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.71724s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.21e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.73e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.91e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.21e-7</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.21e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.73e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.91e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.21e-7</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.21e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.85e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.09e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.79e-7</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.21e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.85e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.09e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.91e-7</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.21e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.73e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.85e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.21e-7</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.43e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.37e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.37e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.61e-7</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.43e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.37e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.37e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.61e-7</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.43e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.31e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.31e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.31e-7</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.43e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.31e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.31e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.31e-7</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.43e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.37e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.31e-7</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.37e-7</td>
  </tr>
</table>



## bfwb62 matrix

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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_seq_omp1.txt">463.178µs</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_seq_omp2.txt">709.094µs</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_seq_omp3.txt">732.382µs</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_seq_omp4.txt">726.987µs</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi1_omp1.txt">1.7058ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi1_omp2.txt">1.80039ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi1_omp3.txt">1.37454ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi1_omp4.txt">3.98261ms</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi1.txt">1.66629ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi2.txt">8.2673ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi3.txt">5.41377ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi4.txt">6.06771ms</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi1_omp1.txt">1.7058ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi2_omp1.txt">8.60622ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi3_omp1.txt">7.66633ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi4_omp1.txt">5.14488ms</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi1_omp1.txt">1.7058ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi1_omp2.txt">1.80039ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi2_omp1.txt">8.60622ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//open/mumps_bfwb62_metis_open_mpi2_omp2.txt">7.50725ms</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_seq_omp1.txt">2.26055ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_seq_omp2.txt">9.37454ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_seq_omp3.txt">8.10867ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_seq_omp4.txt">1.7606ms</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi1_omp1.txt">6.92038ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi1_omp2.txt">3.21484ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi1_omp3.txt">7.29034ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi1_omp4.txt">7.64976ms</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi1.txt">5.23238ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi2.txt">8.30394ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi3.txt">14.0877ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi4.txt">19.079ms</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi1_omp1.txt">6.92038ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi2_omp1.txt">11.2438ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi3_omp1.txt">8.49033ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi4_omp1.txt">9.49058ms</a></td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi1_omp1.txt">6.92038ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi1_omp2.txt">3.21484ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi2_omp1.txt">11.2438ms</a></td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;"><a href="https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results//intel/mumps_bfwb62_metis_intel_mpi2_omp2.txt">11.5611ms</a></td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">376.599µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.76785ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">28.5722ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.00163ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.64748ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.08928ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.20363ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.424ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.28033ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.6484ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">926.544µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.05918ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.64748ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">656.11µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.33194ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">998.586µs</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.64748ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.08928ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">656.11µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">506.321µs</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">22.5825ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.8315ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.69297ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.9224ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.297ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.58081ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.18585ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">14.3465ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.48603ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.62667ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.69428ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">23.6338ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.297ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.06645ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.24646ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.20821ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.297ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.58081ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.06645ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.36536ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">392.563µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">537.068µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">522.288µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.53828ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.05724ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.27495ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">575.717µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">650.255µs</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">723.914µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.09976ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">610.829µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">719.884µs</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.05724ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">460.101µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">996.969µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">726.237µs</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.05724ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.27495ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">460.101µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">376.69µs</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">756.743µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">916.4µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">894.864µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">527.42µs</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">605.814µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">627.605µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">937.924µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">656.69µs</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">517.196µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">874.599µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">988.607µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.76049ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">605.814µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.31329ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">756.877µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">865.59µs</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">605.814µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">627.605µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.31329ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">749.399µs</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.08693ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.8105ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">29.6152ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.0598ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.89388ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.58303ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.7574ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.37625ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.19027ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.1939ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.24688ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.87157ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.89388ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.87028ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.03842ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.2041ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.89388ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.58303ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.87028ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.41608ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">24.2767ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.68645ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.59073ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">13.0515ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">13.5418ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.45765ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">12.134ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">18.6644ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.5367ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.11955ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">13.1135ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">39.3206ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">13.5418ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.8403ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.36644ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.00506ms</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">13.5418ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.45765ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.8403ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.3996ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="10">Rel Error</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.44e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.44e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.44e-16</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.44e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.44e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.44e-16</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">open_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.44e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.44e-16</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_seq_omp# </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi1_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#     </td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.55e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.55e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.55e-16</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp1</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.55e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.55e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.55e-16</td>
  </tr>
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">intel_mpi#_omp#</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.66e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.55e-16</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.55e-16</td>
  </tr>
</table>



