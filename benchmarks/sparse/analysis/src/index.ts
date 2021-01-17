import { formatLongNumber } from '@cpmech/util';
import { genFnkey } from './genFnkey';
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
    'bfwb62',
    // 'av41092',
    // 'helm2d03',
    // 'oilpan',
    // 'tmt_unsym',
    // 'twotone',
  ];

  const nums: number[] = [1, 2, 3, 4];

  matrices.forEach((mat) => {
    const mpiFnkeys = nums.map((n) => genFnkey(mat, n));
    const ompFnkeys = nums.map((n) => genFnkey(mat, 1, n));
    const mpiReports = mpiFnkeys.map((k) => readReport(k));
    const ompReports = ompFnkeys.map((k) => readReport(k));
    const mpiTable = genTable(mat, mpiReports);
    const ompTable = genTable(mat, ompReports, true);
    const r0 = mpiReports[0];
    const strSym = r0.Symmetric ? 'Symmetric matrix' : 'General matrix (unsymmetric)';
    const group = (mat2group as any)[mat];
    const [m0, m1, m2, m3] = mpiFnkeys;
    const [o0, o1, o2, o3] = ompFnkeys;
    const readme = `## ${mat} matrix

Reference: https://sparse.tamu.edu/${group}/${mat}


* ${strSym}
* Dimension = ${fmtNum(r0.NumberOfRows)}
* Number of non-zero values = ${fmtNum(r0.NumberOfNonZeros)}

_MPI results:_

${mpiTable}

Log files: [MPI-np1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/${m0}.txt), 
[MPI-np2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/${m1}.txt), 
[MPI-np3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/${m2}.txt), 
[MPI-np4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/${m3}.txt)

_OpenMP results:_

${ompTable}

Log files: [OMP-nt1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/${o0}.txt), 
[OMP-nt2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/${o1}.txt), 
[OMP-nt3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/${o2}.txt), 
[OMP-nt4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/${o3}.txt)

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
