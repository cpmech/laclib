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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Analyze</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Factorize</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Solve</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Total</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Rel Error</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Analyze</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Factorize</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Solve</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Total</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Rel Error</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Analyze</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Factorize</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Solve</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Total</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Rel Error</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Analyze</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Factorize</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Solve</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Total</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Rel Error</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Analyze</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Factorize</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Solve</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Total</th>
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
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;" rowspan="5">Rel Error</th>
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
</table>



