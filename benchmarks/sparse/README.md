# Benchmarks using the code for sparse matrices

The code here tests the perfomance of the MUMPS Sparse Solver.

## av41092 matrix

### MPI

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">av41092</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analysis</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.39951s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.31268s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.35917s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.39481s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">481.821ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5m9.04225s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6m56.6839s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7m19.4561s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">44.6441ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">496.452ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.99088s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.85401s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.92578s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5m11.8511s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7m1.03369s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7m24.7046s</td>
  </tr>
</table>

### OpenMP

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">av41092</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analysis</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.39922s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.42125s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.41825s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.4237s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">345.972ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">267.96ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">232.725ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">256.901ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">41.0224ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">43.8068ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">44.9475ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">44.1882ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.786s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.73279s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.69568s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.72456s</td>
  </tr>
</table>




## bfwb62 matrix

### MPI

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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.80809ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.81306ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.00488ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.41254ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.21992ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.49581ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">792.171µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">794.798µs</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">792.976µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.04824ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">486.713µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">567.59µs</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.31327ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.55436ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.72893ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.28262ms</td>
  </tr>
</table>

### OpenMP

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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">868.475µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.80773ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">988.832µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.97759ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">525.743µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.87533ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.02093ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.43028ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">311.35µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.05603ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">545.566µs</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.13628ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.50045ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.15991ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.26693ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.91171ms</td>
  </tr>
</table>




## Flan_1565 matrix

### MPI

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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.4411s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">14.9851s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">15.2928s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.4877s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2m9.76431s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m11.4047s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m48.6214s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m57.9532s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.51801s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.07976s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.82637s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.38244s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2m23.7232s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m28.4692s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2m7.74029s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2m13.823s</td>
  </tr>
</table>

### OpenMP

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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.4394s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.4412s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.4263s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.4222s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m37.0259s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">59.7054s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">47.5242s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">45.8605s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.69644s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.19568s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.0989s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.22253s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m50.1615s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m12.3421s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m0.0491428s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">58.505s</td>
  </tr>
</table>




## helm2d03 matrix

### MPI

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">helm2d03</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analysis</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.95103s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.46159s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.4881s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.01107s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.15376s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">672.322ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.77667s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.76977s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">258.697ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">195.44ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">184.749ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">218.86ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.36326s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.329s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.44923s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.99896s</td>
  </tr>
</table>

### OpenMP

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">helm2d03</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analysis</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.91794s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.9112s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.90177s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.89705s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.02862s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.00142s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">980.095ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.02557s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">421.214ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">427.731ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">433.867ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">436.937ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.36751s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.34014s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.31551s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.35934s</td>
  </tr>
</table>




## inline_1 matrix

### MPI

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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.41209s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.75043s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.8965s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.95938s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.48734s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.7252s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.8682s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.9677s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">574.194ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">384.304ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">765.076ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">961.168ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">13.4735s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.8597s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">17.5056s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">15.8854s</td>
  </tr>
</table>

### OpenMP

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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.40272s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.40776s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.41565s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.60179s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.34973s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.63095s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.9858s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.5146s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">373.016ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">360.805ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">357.592ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">412.189ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.1252s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.39928s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.75879s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.52826s</td>
  </tr>
</table>




## oilpan matrix

### MPI

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">oilpan</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analysis</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">107.706ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">327.912ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">329.752ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">323.017ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">409.078ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">244.909ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">491.37ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">902.724ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">46.0264ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">29.9166ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">52.0522ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">33.4064ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">562.634ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">602.46ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">872.387ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.25801s</td>
  </tr>
</table>

### OpenMP

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">oilpan</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analysis</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">112.571ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">108.435ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">108.702ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">105.743ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">310.838ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">267.727ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">252.442ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">265.752ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">37.8728ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">38.755ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">39.8651ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">38.8496ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">461.03ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">414.671ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">400.754ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">410.096ms</td>
  </tr>
</table>




## pre2 matrix

### MPI

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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.15617s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.81036s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.87386s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.2478s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.40795s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">26.7075s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">55.4426s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3m54.4212s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">619.713ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">644.264ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.31635s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.75931s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">12.1836s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">33.1073s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1m3.59555s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4m3.42784s</td>
  </tr>
</table>

### OpenMP

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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.35177s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.19765s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.20024s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.42464s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.43039s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.72507s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.23335s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.12062s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">868.907ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">877.036ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">885.499ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">909.746ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.6508s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.79953s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.31885s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.45473s</td>
  </tr>
</table>




## tmt_unsym matrix

### MPI

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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.02098s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.15608s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.20829s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.07969s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.11528s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.83104s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">6.43269s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.22648s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">747.478ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">523.983ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">599.682ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">660.369ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">7.88354s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">5.51081s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">10.2022s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">9.96623s</td>
  </tr>
</table>

### OpenMP

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
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.17553s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.09602s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.22757s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.22117s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.81818s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.53009s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.50812s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.58696s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.57886s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.6068s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.63536s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.63298s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.57233s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.23258s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.3708s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">8.44086s</td>
  </tr>
</table>




## twotone matrix

### MPI

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">twotone</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">MPI np 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analysis</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.03795s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.06499s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.08967s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">969.054ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.30934s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">3.79013s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">11.361s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">19.9647s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">107.496ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">115.29ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">451.29ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">430.174ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.45457s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">4.97018s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">12.9017s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">21.3621s</td>
  </tr>
</table>

### OpenMP

<table style="border: 1px solid #979797; border-collapse: collapse;">
  <tr>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">twotone</td>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 1</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 2</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 3</th>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">OMP nt 4</th>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Analysis</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.03317s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.05279s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.02657s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.02791s</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Factorize</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.10043s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">778.771ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">656.337ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">660.461ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Solve</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">133.052ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">140.841ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">136.446ms</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">154.255ms</td>
  </tr>
  <tr>
    <th style="border: 1px solid #979797; border-collapse: collapse; text-align: right; padding: 5px;">Total</th>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">2.26644s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.97215s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.81912s</td>
    <td style="border: 1px solid #979797; border-collapse: collapse; text-align: center; padding: 5px;">1.84238s</td>
  </tr>
</table>




