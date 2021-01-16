import { formatLongNumber } from '@cpmech/util';
import { genTable } from './genTable';
import { readReport } from './readReport';

const fmtNum = (n: number): string => formatLongNumber(n.toString());

const mat2group = {
  bfwb62: 'Bai',
  inline_1: 'GHS_psdef',
  tmt_unsym: 'CEMW',
  pre2: 'ATandT',
  twotone: 'ATandT',
  Flan_1565: 'Janna',
  av41092: 'Vavasis',
  helm2d03: 'GHS_indef',
  oilpan: 'GHS_psdef',
};

async function run() {
  const matrices: string[] = [
    'inline_1',
    'Flan_1565',
    'pre2',
    // 'av41092',
    // 'bfwb62',
    // 'helm2d03',
    // 'oilpan',
    'tmt_unsym',
    'twotone',
  ];

  const nums: number[] = [1, 2, 3, 4];

  matrices.forEach((mat) => {
    const mpiReports = nums.map((n) => readReport(mat, n));
    const ompReports = nums.map((n) => readReport(mat, 1, n));
    const mpiTable = genTable(mat, mpiReports);
    const ompTable = genTable(mat, ompReports, true);
    const r0 = mpiReports[0];
    const strSym = r0.Symmetric ? 'Symmetric matrix' : 'General matrix (unsymmetric)';
    const group = (mat2group as any)[mat];
    const readme = `## ${mat} matrix

Reference: https://sparse.tamu.edu/${group}/${mat}


* ${strSym}
* Dimension = ${fmtNum(r0.NumberOfRows)}
* Number of non-zero values = ${fmtNum(r0.NumberOfNonZeros)}

_MPI results:_

${mpiTable}

[MUMPS log / MPI np1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/log_${mat}_np1.txt)
[MUMPS log / MPI np2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/log_${mat}_np2.txt)
[MUMPS log / MPI np3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/log_${mat}_np3.txt)
[MUMPS log / MPI np4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/log_${mat}_np4.txt)

_OpenMP results:_

${ompTable}

[MUMPS log / OMP nt1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/log_${mat}_np1_omp1.txt)
[MUMPS log / OMP nt2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/log_${mat}_np1_omp2.txt)
[MUMPS log / OMP nt3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/log_${mat}_np1_omp3.txt)
[MUMPS log / OMP nt4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/log_${mat}_np1_omp4.txt)

`;
    console.log(readme);
  });
}

(async () => {
  try {
    await run();
  } catch (e) {
    console.log(e);
  }
})();
