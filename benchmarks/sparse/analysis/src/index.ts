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

_OpenMP results:_

${ompTable}

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
